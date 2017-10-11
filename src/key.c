/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 15:49:21 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/22 00:47:37 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

int			mouse_move(int x, int y, t_alpha *vz)
{
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || vz->p.mouse_on != 1)
		return (0);
	vz->mv.xfactor = x;
	vz->mv.yfactor = y;
	printf("%d\n", vz->p.mouse_on);
	ft_draw(vz);
	return(0);
}

int				key_hook(int key, t_alpha *vz)
{
	// if (key == KEY_M)
	// 	vz->p.mouse_on = 1;
	if (key == ESC)
		exit(0);
	else if (key == KEY_PAGEUP || key == KEY_PAGEDOWN ||
		key == PADPLUS || key == PADMINUS)
		zoomit(vz, key);
	else if (key == UPARROW || key == DOWNARROW ||
		key == RIGHTARROW || key == LEFTARROW)
		move(vz, key);
	ft_draw(vz);
	return(0);
}
// int			mouse_zoom(int key, int x, int y, t_alpha *vz)
// {
// 	if (key == MOUSE_IN)
// }

// int		mouse_move_hook(int x, int y, t_env *e)
// {
// 	if (x < 0 || x >= e->win_width || y < 0 || y >= e->win_height ||
// 			e->mouse_stop == 1)
// 		return (0);
// 	e->option_x = x;
// 	e->option_y = y;
// 	e->fractal(e);
// 	return (0);
// }
//
// int		mouse_click_hook(int k, int x, int y, t_env *e)
// {
// 	if (k == MOUSE_ZOOM_IN)
// 	{
// 		e->x += x / 5;
// 		e->y += y / 5;
// 		e->z = e->z * 1.2;
// 		e->y = e->y * 1.2;
// 		e->x = e->x * 1.2;
// 	}
// 	if (k == MOUSE_ZOOM_OUT)
// 	{
// 		e->x -= x / 5;
// 		e->y -= y / 5;
// 		e->z = e->z / 1.2;
// 		e->y = e->y / 1.2;
// 		e->x = e->x / 1.2;
// 	}
// 	e->fractal(e);
// 	return (0);
// }
