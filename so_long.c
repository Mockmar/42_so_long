
#include "so_long.h"

void	find_perso(t_vars *vars)
{
	int		i;
	int		j;
	char	**tab;

	tab = vars->map;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				vars->persox = i;
				vars->persoy = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	nbr_item(t_vars *vars)
{
	int		i;
	int		j;
	char	**tab;
	int		cpt;

	cpt = 0;
	tab = vars->map;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
			{
				cpt++;
			}
			j++;
		}
		i++;
	}
	vars->gagner = cpt;
}

int	sizey(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.gagner = 0;
	vars.nb_move = 0;
	vars.flip = 0;
	error_arg(ac, av, &vars);
	vars.map = creat_tab(av, &vars);
	error_map(&vars);
	nbr_item(&vars);
	vars.x_win = check_len_map(vars.map);
	vars.y_win = sizey(vars.map);
	init_win(&vars);
	find_perso(&vars);
	affiche_map(&vars);
	print_move_win(&vars);
	mlx_hook(vars.win, 2, 1L << 0, action, &vars);
	mlx_hook(vars.win, 17, 1L << 17, close_bis, &vars);
	mlx_loop(vars.mlx);
	free_tout(&vars);
	return (0);
}
