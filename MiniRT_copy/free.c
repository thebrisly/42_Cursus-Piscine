
#include "incs/minirt.h"

void    free_structures(t_rt *rt)
{
    free (rt->sc);
    free (rt);
}

void    free_tab(char **tab)
{
    int i;

    i = 0;
    if (tab)
    {
        while (tab[i])
        {
            free (tab[i]);
            i++;
        }
        free (tab);
    }
}