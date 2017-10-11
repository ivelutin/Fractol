/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:10:07 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/21 23:34:37 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void		ft_mandela(t_alpha *vz, intmax_t x, intmax_t y)
{
	int i;
	int	color;

	i = 0;
	vz->p.nre = 0 + vz->mv.xfactor;
	vz->p.nim = 0 + vz->mv.yfactor;
	vz->p.pr = 1.5 * (x - WIDTH / 2) / (0.5 * vz->mv.zoom * WIDTH) + vz->mv.movex;
	vz->p.pi = (y - HEIGHT / 2) / (0.5 * vz->mv.zoom * HEIGHT) + vz->mv.movey;
	while(i < vz->p.maxi && vz->p.nre * vz->p.nre + vz->p.nim * vz->p.nim < 4)
	{
		vz->p.ore = vz->p.nre;
		vz->p.oim = vz->p.nim;
		vz->p.nre = vz->p.ore * vz->p.ore - vz->p.oim * vz->p.oim + vz->p.pr;
		vz->p.nim = 2 * vz->p.ore * vz->p.oim + vz->p.pi;
		i++;
	}
	color = draw_color(i, vz->p.maxi, vz);
	mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x, y, color);
}

// void	ft_mandela(t_alpha *vz, intmax_t x, intmax_t y)
// {
// 	unsigned int	i;
// 	long double		pr;
// 	long double		pi;
// 	long double		tmp;
// 	int				color;
//
// 	i = 0;
// 	pr = 0.0;
// 	pi = 0.0;
//
// 	vz->p.pr = 1.5 * (x - W_WIDTH / 2) / (0.5 * 1 * W_WIDTH) + (0.5 / W_WIDTH / 1.32) - 0.5;
// 	vz->p.pi = (y - W_HEIGHT / 2) / (0.5 * 1 * W_HEIGHT) - (0.5 / W_HEIGHT / 1.92);
// 	while (pr * pr + pi * pi < 4 && i < 100)
// 	{
// 		tmp = pr;
// 		pr = tmp * tmp - pi * pi + vz->p.pr;
// 		pi = 2 * tmp * pi + vz->p.pi;
// 		++i;
// 	}
// 	printf("%d\n", i);
// 	color = draw_color(i, 100, vz);
// 	mlx_pixel_put(vz->mlx.mlx, vz->mlx.win, x, y, color);
// }
