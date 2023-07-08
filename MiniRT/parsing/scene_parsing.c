#include "../incs/minirt.h"

/* A 	0.2			255,255,255*/
int	ambiance_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}

/* L 	-40,0,30	0.7 */
int	light_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}

/* C 	-50,0,20	0,0,0 70 */
int	camera_parsing(char *line, t_rt *rt)
{
	(void) line;
	(void) rt;
	return (1);
}
