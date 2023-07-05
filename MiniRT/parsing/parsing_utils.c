#include "../incs/minirt.h"

int count_elements(char *line)
{
	char **tab;
    int count;

	count = 0;
	tab = ft_split(line, ' ');
    while (tab != NULL) {
        count++;
    }
	free (line);
	free (tab);
    return count;
}

int	cmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
