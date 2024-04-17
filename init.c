
#include "so_long.h"

char	*take_arg(char **av)
{
	char	*str;
	char	c;
	int		fd;
	int		ret;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ret = 1;
	str = NULL;
	c = 0;
	ret = read(fd, &c, 1);
	while (ret > 0)
	{
		tmp = str;
		if (c)
			str = ft_stradchar(tmp, c);
		free(tmp);
		ret = read(fd, &c, 1);
	}
	close(fd);
	return (str);
}

char	**creat_tab(char **av, t_vars *vars)
{
	char	**tab;
	char	*str;
	int		i;

	i = 0;
	str = take_arg(av);
	if (!str)
		return (NULL);
	if (str[0] == '\n')
		vars->error = 2;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] && str[i + 1] == '\n')
			vars->error = 2;
		i++;
	}
	tab = ft_split(str, '\n');
	free(str);
	return (tab);
}

void	init_pointeur(t_vars *v)
{
	v->mlx = NULL;
	v->win = NULL;
	v->p = NULL;
	v->w = NULL;
	v->i = NULL;
	v->f = NULL;
	v->e = NULL;
	v->a = NULL;
	v->pf = NULL;
	v->mlx = mlx_init();
	if (!v->mlx)
		exit_propre(v);
	v->win = mlx_new_window(v->mlx, 40 * v->x_win, 40 * v->y_win, "So_long");
	if (!v->win)
		exit_propre(v);
}

void	init_win(t_vars *v)
{
	int	s;

	s = 40;
	init_pointeur(v);
	v->p = mlx_xpm_file_to_image (v->mlx, "xpm/homer.xpm", &s, &s);
	if (!v->p)
		exit_propre(v);
	v->w = mlx_xpm_file_to_image (v->mlx, "xpm/mur.xpm", &s, &s);
	if (!v->w)
		exit_propre(v);
	v->i = mlx_xpm_file_to_image (v->mlx, "xpm/donut.xpm", &s, &s);
	if (!v->i)
		exit_propre(v);
	v->f = mlx_xpm_file_to_image (v->mlx, "xpm/sol.xpm", &s, &s);
	if (!v->f)
		exit_propre(v);
	v->e = mlx_xpm_file_to_image (v->mlx, "xpm/canape.xpm", &s, &s);
	if (!v->e)
		exit_propre(v);
	v->a = mlx_xpm_file_to_image(v->mlx, "xpm/flanders.xpm", &s, &s);
	if (!v->a)
		exit_propre(v);
	v->pf = mlx_xpm_file_to_image(v->mlx, "xpm/homer_flip.xpm", &s, &s);
	if (!v->pf)
		exit_propre(v);
}

void	exit_propre(t_vars *vars)
{
	free_tout(vars);
	exit(0);
}
