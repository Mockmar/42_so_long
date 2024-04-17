
#include "so_long.h"

int	action(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		free_tout(vars);
		exit(0);
	}
	if (keycode == 119)
		press_w(vars);
	if (keycode == 115)
		press_s(vars);
	if (keycode == 97)
		press_a(vars);
	if (keycode == 100)
		press_d(vars);
	mlx_clear_window(vars->mlx, vars->win);
	affiche_map(vars);
	print_move_win(vars);
	return (0);
}

int	close_bis(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
	return (0);
}

void	free_tout(t_vars *vars)
{
	if (vars->e)
		mlx_destroy_image(vars->mlx, vars->e);
	if (vars->w)
		mlx_destroy_image(vars->mlx, vars->w);
	if (vars->p)
		mlx_destroy_image(vars->mlx, vars->p);
	if (vars->f)
		mlx_destroy_image(vars->mlx, vars->f);
	if (vars->i)
		mlx_destroy_image(vars->mlx, vars->i);
	if (vars->a)
		mlx_destroy_image(vars->mlx, vars->a);
	if (vars->pf)
		mlx_destroy_image(vars->mlx, vars->pf);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_display(vars->mlx);
	if (vars->map)
		free_tab(vars->map);
	if (vars->mlx)
		free(vars->mlx);
}

void	print_move_win(t_vars *v)
{
	char	*str;

	str = ft_strjoin("Nombre coup: ", ft_itoa(v->nb_move));
	mlx_string_put(v->mlx, v->win, 10, 10, 1000000, str);
	free(str);
}
