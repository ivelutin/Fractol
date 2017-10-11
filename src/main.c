/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 21:58:09 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/22 00:47:46 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void		set(t_alpha *vz)
{
	vz->mv.zoom = 1;
	vz->mv.movex = -0.5;
	vz->mv.movey = 0;
	vz->p.maxi = 100;
	vz->p.colormax = 0X00000000;
	vz->p.color = 1;
	vz->p.mouse_on = 1;
	// vz->mv.xfactor = WIDTH / 2;
	// vz->mv.yfactor = ;

}
int 		main(int argc, char **argv)
{
	t_alpha *vz;

	if (!(vz = (t_alpha*)ft_memalloc(sizeof(t_alpha))))
		return (0);
	set(vz);
	vz->frac.tmp = argv;
	if (argc == 2)
	{
		ft_ladilla(vz);
		vz->mlx.mlx = mlx_init();
		vz->mlx.win = mlx_new_window(vz->mlx.mlx, WIDTH, HEIGHT, "FRACTOL");
		ft_draw(vz);
		mlx_hook(vz->mlx.win, 2, 3, mouse_move, vz);
		//mlx_mouse_hook(vz->mlx.win, mouse_zoom, vz);
		mlx_key_hook(vz->mlx.win, key_hook, vz);
		mlx_loop(vz->mlx.mlx);
	}
	else
		write(1, "usage: ./fractol [mandelbrot / julia / burningship]\n", 52);
	return(0);
}
