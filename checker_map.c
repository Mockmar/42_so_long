
#include "so_long.h"

/*return longueur de ligne*/
int	check_len_map(char **tab)
{
	int		len_map;
	int		len_tmp;
	int		i;

	len_tmp = 0;
	len_map = 0;
	i = 1;
	while (tab[0][len_map])
		len_map++;
	while (tab + i && tab[i])
	{
		len_tmp = 0;
		while (tab[i][len_tmp])
			len_tmp++;
		if (len_map != len_tmp)
			return (0);
		i++;
	}
	return (len_map);
}

int	min_content(char **tab)
{
	int		cpt_p;
	int		cpt_c;
	int		cpt_e;
	int		j;
	int		i;

	cpt_p = 0;
	cpt_c = 0;
	cpt_e = 0;
	i = -1;
	while (tab[++i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				cpt_p++;
			if (tab[i][j] == 'C')
				cpt_c++;
			if (tab[i][j] == 'E')
				cpt_e++;
			j++;
		}
	}
	return (error_content(cpt_c, cpt_e, cpt_p));
}

int	error_content(int cpt_c, int cpt_e, int cpt_p)
{
	if (!cpt_c)
		return (4);
	if (!cpt_p)
		return (6);
	if (cpt_p > 1)
		return (7);
	if (!cpt_e)
		return (5);
	return (0);
}

int	map_ouverte(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[0][i])
	{
		if (tab[0][i] != '1')
			return (0);
		i++;
	}
	i = 1;
	while (tab + i && tab[i + 1] && tab[i])
	{
		if (tab[i][0] != '1' || tab[i][check_len_map(tab) - 1] != '1')
			return (0);
		i++;
	}
	while (tab + i && tab[i][j])
	{
		if (tab[i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	good_content(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!ft_strchr("01ECPA", tab[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
