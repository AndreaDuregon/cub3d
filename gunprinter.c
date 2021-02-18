/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gunprinter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:37:19 by sgiovo            #+#    #+#             */
/*   Updated: 2021/02/18 16:14:58 by sgiovo           ###   ########.fr       */
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

int		resizer(t_hook *h, int mod)
{
	int x;
	int n;
	int i;

	x = h->var.rx / 7;
	i = 1;
	n = 0;
	while (n < (x * 2))
	{
		n = 64 * i;
		i++;
	}
	if (!mod)
		return (n / 2);
	return (i - 1);
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
	x = -resizer(h, 0);
	while (x < resizer(h, 0))
	{
		y = -resizer(h, 0);
		while (y < resizer(h, 0))
		{
			color = getcolor(h->tex[texn],
							(x + resizer(h, 0)) / resizer(h, 1), (y + resizer(h, 0)) / resizer(h, 1), 0);
			if (color != -3351495)
				draw_dot(h, (h->var.rx / 2) + x + (h->var.rx / 6),
						(h->var.ry - resizer(h, 0)) + y, color);
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
