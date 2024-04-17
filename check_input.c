
#include "so_long.h"

int	check_arg(int ac, char **av)
{
	int	len;
	int	fd;

	if (ac != 2)
		return (1);
	len = ft_strlen(av[1]);
	if (av[1][len - 1] != 'r' || av[1][len - 2] != 'e'
		|| av[1][len - 3] != 'b' || av[1][len - 4] != '.' )
		return (2);
	fd = open(av[1], O_DIRECTORY);
	if (fd > 0)
	{
		close (fd);
		return (3);
	}
	close(fd);
	return (0);
}

/*1 : le fichier est vide*/
/*2 : la map n'est pas rectangulaire*/
/*3 : la map n'est pas ferme*/
/*4 : pas d'item, 5 : pas de sortie, 6 : pas de perso, 7 : trop de perso*/
int	check_map(char **tab)
{
	if (!tab)
		return (1);
	if (!check_len_map(tab))
		return (2);
	if (!map_ouverte(tab))
		return (3);
	if (!good_content(tab))
		return (8);
	return (min_content(tab));
}

void	error_arg(int ac, char **av, t_vars *vars)
{
	vars->error = check_arg(ac, av);
	if (vars->error == 1)
		write(1, "Error\nnombre argument invalide\n", 31);
	if (vars->error == 2)
		write(1, "Error\nnom fichier invalide\n", 27);
	if (vars->error == 3)
		write(1, "Error\nle fichier est un dossier\n", 32);
	if (vars->error)
		exit(0);
}

void	error_map(t_vars *vars)
{
	if (vars->error == 2)
	{
		write(1, "Error\nla map n'est pas rectangulaire\n", 37);
		exit(0);
	}
	vars->error = check_map(vars->map);
	error_map_2(vars);
	if (vars->error)
	{
		free_tab(vars->map);
		exit(0);
	}
}

void	error_map_2(t_vars *vars)
{
	if (vars->error == 1)
		write(1, "Error\nfichier vide\n", 19);
	if (vars->error == 2)
		write(1, "Error\nla map n'est pas rectangulaire\n", 37);
	if (vars->error == 8)
		write(1, "Error\nla map contient des carcteres illisible\n", 46);
	if (vars->error == 4)
		write(1, "Error\nla map contient pas d'items\n", 34);
	if (vars->error == 3)
		write(1, "Error\nla map n'est pas ferme\n", 29);
	if (vars->error == 5)
		write(1, "Error\nla map contient pas de sortie\n", 36);
	if (vars->error == 6)
		write(1, "Error\nla map contient pas de perso\n", 35);
	if (vars->error == 7)
		write(1, "Error\nla map contient trop de perso\n", 36);
}
