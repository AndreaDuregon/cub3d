/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunprinter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:36:41 by forsili           #+#    #+#             */
/*   Updated: 2021/02/18 18:37:13 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mirino(t_hook *h)
{
	int x;
	int y;

	x = -7;
	y = -7;
	while (x < 7)
	{
		my_mlx_pixel_put(&h->img, (h->var.rx / 2) + x,
						(h->var.ry / 2), create_trgb(0, 255,
		0, 0));
		x++;
	}
	while (y < 7)
	{
		my_mlx_pixel_put(&h->img, (h->var.rx / 2),
						(h->var.ry / 2) + y, create_trgb(0, 255,
		0, 0));
		y++;
	}
}

void	print_life(t_hook *h)
{
	int x;
	int y;

	x = 10;
	y = 10;
	while (x < ((h->sp->life * 2) + 10))
	{
		y = 10;
		while (y < 25)
		{
			if (h->sp->life < 30)
				draw_dot(h, x, y, create_trgb(0, 255, 0, 0));
			else if (h->sp->life < 70)
				draw_dot(h, x, y, create_trgb(0, 255, 255, 0));
			else
				draw_dot(h, x, y, create_trgb(0, 0, 255, 0));
			y++;
		}
		x++;
	}
}
