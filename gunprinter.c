/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:37:19 by sgiovo            #+#    #+#             */
/*   Updated: 2021/02/17 10:00:41 by aduregon         ###   ########.fr       */
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

void	print_level(t_hook *h)
{
	int x;
	int y;
	int j;
	int z;

	x = h->var.rx - 5;
	y = 15;
	j = h->level;
	while (j > 0)
	{
		z = 0;
		while (z < 5)
		{
			y = 5;
			while (y < 20)
			{
				draw_dot(h, x, y, create_trgb(0, 255, 0, 0));
				y++;
			}
			z++;
			x--;
		}
		z = 0;
		while (z < 5)
		{
			y = 5;
			while (y < 20)
			{
				y++;
			}
			z++;
			x--;
		}
		j--;
	}
}

void	gunrender(t_hook *h)
{
	int x;
	int y;
	int color;
	int texn;

	texn = 7;
	if (h->sp->shoot)
		texn = 8;
	x = -128;
	while (x < 128)
	{
		y = -128;
		while (y < 128)
		{
			color = getcolor(h->tex[texn],
							(x + 128) / 4, (y + 128) / 4, 0);
			if (color != -3351495)
				draw_dot(h, (h->var.rx / 2) + x + 85,
						(h->var.ry * 0.78) + y, color);
			y++;
		}
		x++;
	}
}

void	gunprinter(t_hook *h)
{
	print_life(h);
	print_level(h);
	mirino(h);
	gunrender(h);
}
