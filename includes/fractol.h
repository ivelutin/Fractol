/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 22:00:53 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/22 00:37:24 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "../Libft/libft.h"

# define WIDTH		720
# define HEIGHT		480

typedef struct		s_mlx
{
	void			*win;
	void			*mlx;
}					t_mlx;

typedef struct		s_mv
{
double				zoom;
double				movex;
double				movey;
double				xfactor;
double				yfactor;
}					t_mv;

typedef struct		s_p
{
	long double		pr;
	long double		pi;
	long double		nre;
	long double		ore;
	long double		nim;
	long double		oim;
	int				maxi;
	unsigned int	colormax;
	int				color;
	int				mouse_on;
}					t_p;

typedef struct		s_frac
{
	int				mandela;
	int				julia;
	int				ship;
	char			**tmp;
}					t_frac;

typedef struct		s_alpha
{
	t_mlx			mlx;
	t_frac			frac;
	t_p				p;
	t_mv			mv;
}					t_alpha;

/*
** main.c
*/
int 			main(int argc, char **argv);
void			ft_draw(t_alpha *vz);
int	 			ft_ladilla(t_alpha *vz);

/*
** color.c
*/
unsigned int	draw_color(int i, int maxi, t_alpha *vz);

/*
** mandelbrot.c
*/
void			ft_mandela(t_alpha *vz, intmax_t x, intmax_t y);

/*
** key.c
*/
//int				my_key_(int key, t_alpha *vz);
int				key_hook(int key, t_alpha *vz);
int				mouse_move(int x, int y, t_alpha *vz);

/*
** zoom.c
*/
void			zoomit(t_alpha *vz, int key);
void			move(t_alpha *vz, int key);

#endif
