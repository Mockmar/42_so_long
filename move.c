
#include "so_long.h"

void	press_w(t_vars *vars)
{
	char	**tab;

	tab = vars->map;
	if (tab[vars->persox - 1][vars->persoy] == 'A')
	{
		free_tout(vars);
		exit(0);
	}
	else if (tab[vars->persox - 1][vars->persoy] != '1'
		&& tab[vars->persox - 1][vars->persoy] != 'E')
	{
		tab[vars->persox][vars->persoy] = '0';
		vars->persox -= 1;
		if (tab[vars->persox][vars->persoy] == 'C')
			vars->gagner -= 1;
		tab[vars->persox][vars->persoy] = 'P';
		vars->nb_move += 1;
	}
	else if (tab[vars->persox - 1][vars->persoy] == 'E' && !vars->gagner)
	{
		vars->nb_move += 1;
		free_tout(vars);
		exit(0);
	}
}

void	press_s(t_vars *vars)
{
	char	**tab;

	tab = vars->map;
	if (tab[vars->persox + 1][vars->persoy] == 'A')
	{
		free_tout(vars);
		exit(0);
	}
	else if (tab[vars->persox + 1][vars->persoy] != '1'
		&& tab[vars->persox + 1][vars->persoy] != 'E')
	{
		tab[vars->persox][vars->persoy] = '0';
		vars->persox += 1;
		if (tab[vars->persox][vars->persoy] == 'C')
			vars->gagner -= 1;
		tab[vars->persox][vars->persoy] = 'P';
		vars->nb_move += 1;
	}
	else if (tab[vars->persox + 1][vars->persoy] == 'E' && !vars->gagner)
	{
		vars->nb_move += 1;
		free_tout(vars);
		exit(0);
	}
}

void	press_a(t_vars *vars)
{
	char	**tab;

	tab = vars->map;
	vars->flip = 1;
	if (tab[vars->persox][vars->persoy - 1] == 'A')
	{
		free_tout(vars);
		exit(0);
	}
	if (tab[vars->persox][vars->persoy - 1] != '1'
		&& tab[vars->persox][vars->persoy - 1] != 'E')
	{
		tab[vars->persox][vars->persoy] = '0';
		vars->persoy -= 1;
		if (tab[vars->persox][vars->persoy] == 'C')
			vars->gagner -= 1;
		tab[vars->persox][vars->persoy] = 'P';
		vars->nb_move += 1;
	}
	else if (tab[vars->persox][vars->persoy - 1] == 'E' && !vars->gagner)
	{
		vars->nb_move += 1;
		free_tout(vars);
		exit(0);
	}
}

void	press_d(t_vars *vars)
{
	char	**tab;

	tab = vars->map;
	vars->flip = 0;
	if (tab[vars->persox][vars->persoy + 1] == 'A')
	{
		free_tout(vars);
		exit(0);
	}
	if (tab[vars->persox][vars->persoy + 1] != '1'
		&& tab[vars->persox][vars->persoy + 1] != 'E')
	{
		tab[vars->persox][vars->persoy] = '0';
		vars->persoy += 1;
		if (tab[vars->persox][vars->persoy] == 'C')
			vars->gagner -= 1;
		tab[vars->persox][vars->persoy] = 'P';
		vars->nb_move += 1;
	}
	else if (tab[vars->persox][vars->persoy + 1] == 'E' && !vars->gagner)
	{
		vars->nb_move += 1;
		free_tout(vars);
		exit(0);
	}
}
