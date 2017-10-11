/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <ivelutin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 16:13:16 by ivelutin          #+#    #+#             */
/*   Updated: 2017/07/20 18:33:19 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../includes/keys.h"

void		zoomit(t_alpha *vz, int key)
{
	if(key == KEY_PAGEUP && vz->mv.zoom > 0)
		vz->mv.zoom *= 1.3;
	else if(key == KEY_PAGEDOWN && vz->mv.zoom > 0)
		vz->mv.zoom /= 1.3;
	else if (key == PADPLUS)
		vz->p.maxi *= 1.2;
	else if (key == PADMINUS)
		vz->p.maxi /= 1.2;
	else if(vz->mv.zoom <= 0)
		vz->mv.zoom = 1;
}

void		move(t_alpha *vz, int key)
{
	if (key == UPARROW)
		vz->mv.movey -= 0.1 / vz->mv.zoom;
	else if (key == DOWNARROW)
		vz->mv.movey += 0.1 / vz->mv.zoom;
	else if (key == LEFTARROW)
		vz->mv.movex -= 0.1 / vz->mv.zoom;
	else if (key == RIGHTARROW)
		vz->mv.movex += 0.1 / vz->mv.zoom;
}
