
#include "so_long.h"

void	put_image_win(t_vars *v, int i, int j)
{
	char	**tab;

	tab = v->map;
	if (tab[i][j] == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->w, 40 * j, 40 * i);
	if (tab[i][j] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->f, 40 * j, 40 * i);
	if (tab[i][j] == 'P' && !v->flip)
		mlx_put_image_to_window(v->mlx, v->win, v->p, 40 * j, 40 * i);
	if (tab[i][j] == 'P' && v->flip)
		mlx_put_image_to_window(v->mlx, v->win, v->pf, 40 * j, 40 * i);
	if (tab[i][j] == 'C')
		mlx_put_image_to_window(v->mlx, v->win, v->i, 40 * j, 40 * i);
	if (tab[i][j] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->e, 40 * j, 40 * i);
	if (tab[i][j] == 'A')
		mlx_put_image_to_window(v->mlx, v->win, v->a, 40 * j, 40 * i);
}

void	affiche_map(t_vars *v)
{
	char	**tab;
	int		i;
	int		j;

	tab = v->map;
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			put_image_win(v, i, j);
			j++;
		}
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(long long nbr, char *base, int nb_char)
{
	int			sizeb;
	long long	nb;

	nb = nbr;
	sizeb = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		nb_char++;
	}
	if (nb < sizeb)
	{
		ft_putchar(base[nb]);
		nb_char++;
	}
	else
	{
		ft_putnbr_base(nb / sizeb, base, nb_char);
		ft_putchar(base[nb % sizeb]);
		nb_char++;
	}
}

void	print_nb_move(t_vars *vars)
{
	vars->nb_move += 1;
	if (vars->nb_move >= 2147483647)
	{
		free_tout(vars);
		write(1, "Nombre de coup maximal autorise\n", 32);
		exit(0);
	}
	write(1, "coup: ", 6);
	ft_putnbr_base((long long)vars->nb_move, "0123456789", 0);
	write(1, "\n", 1);
}
