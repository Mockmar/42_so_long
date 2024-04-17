#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx_linux/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*w;
	void	*p;
	void	*i;
	void	*f;
	void	*e;
	void	*a;
	void	*pf;
	int		flip;
	int		size_img;
	int		persox;
	int		persoy;
	char	**map;
	int		x_win;
	int		y_win;
	int		gagner;
	int		nb_move;
	int		error;
}				t_vars;

/*init*/
void	init_win(t_vars *v);
char	*take_arg(char **av);
char	**creat_tab(char **av, t_vars *vars);
void	exit_propre(t_vars *vars);
void	init_pointeur(t_vars *v);
/*libft*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
void	free_tab(char **tab);
int		ft_strlen(char *str);
char	*ft_stradchar(char *s1, char c);
/*check_map*/
int		good_content(char **tab);
int		map_ouverte(char **tab);
int		error_content(int cpt_c, int cpt_e, int cpt_p);
int		min_content(char **tab);
int		check_len_map(char **tab);
/*split*/
char	**ft_split(char const *s, char c);
/*check_input*/
int		check_map(char **tab);
int		check_arg(int ac, char **av);
void	error_map(t_vars *vars);
void	error_map_2(t_vars *vars);
void	error_arg(int ac, char **av, t_vars *vars);
/*print*/
void	affiche_map(t_vars *vars);
void	ft_putnbr_base(long long nbr, char *base, int nb_char);
void	ft_putchar(char c);
void	print_nb_move(t_vars *vars);
void	put_image_win(t_vars *v, int i, int j);
/*action*/
int		close_bis(t_vars *vars);
int		action(int keycode, t_vars *vars);
void	free_tout(t_vars *vars);
void	print_move_win(t_vars *v);
/*move*/
void	press_w(t_vars *vars);
void	press_s(t_vars *vars);
void	press_a(t_vars *vars);
void	press_d(t_vars *vars);
/*strjoin*/
char	*ft_strjoin(char *s1, char *s2);
/*itoa*/
char	*ft_itoa(int n);

#endif
