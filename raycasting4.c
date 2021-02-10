/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:01:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 15:39:22 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		call_func(t_hook *h, int x)
{
	ray_calc(h->sp, h->var, x);
	var_dda(h->sp);
	dda(h->sp, h->map);
	pwd_calc(h->sp);
	height_calc(h->sp, h->var);
	tex_coord(h->sp, h->var);
	print_wall(h, x);
	if (!h->sp->sprint)
		set_speed(h->sp);
}

int			raycasting(t_hook *h)
{
	int x;

	x = 0;
	h->img.img = mlx_new_image(h->vars.mlx, h->var.rx, h->var.ry);
	h->img.addr = mlx_get_data_addr(h->img.img, &h->img.bits_per_pixel,
									&h->img.line_length, &h->img.endian);
	print_background(h->var, h->img);
	x = 0;
	while (x < h->var.rx)
	{
		call_func(h, x);
		x++;
	}
	x = 0;
	sprite_calc(h);
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->img.img, 0, 0);
	if (!(mlx_destroy_image(h->vars.mlx, h->img.img)))
		return (0);
	return (0);
}
