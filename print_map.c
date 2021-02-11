/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:30:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 19:56:02 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		max_line(t_hook *h)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (h->minimap[i])
	{
		if ((int)ft_strlen(h->minimap[i]) > max)
			max = (int)ft_strlen(h->minimap[i]);
		i++;
	}
	return (max);
}

void	color_calc(t_hook *h, int x[2], int y[2])
{
	if (h->minimap[x[1]][y[1]] == '1')
		my_mlx_pixel_put(&h->img, y[0], x[0], create_trgb(0, 255,
							0, 0));
	else
		my_mlx_pixel_put(&h->img, y[0], x[0], create_trgb(0, 0,
							0, 0));
}

void	put_img_minimap(t_hook *h)
{
	int x[2];
	int y[2];
	int sizex;
	int sizey;

	x[0] = 0;
	x[1] = 0;
	sizex = (h->var.ry / 6) / max_line(h);
	sizey = (h->var.rx / 6) / ar_length(h->map);
	while (x[0] < (h->var.rx / 6))
	{
		y[0] = h->var.ry - 1;
		y[1] = 0;
		while (y[0] > (h->var.ry / 6))
		{
			if ((y[0] % sizey) == 0 && h->minimap[x[1]][y[1] + 1])
				y[1]++;
			color_calc(h, x, y);
			y[0]--;
		}
		if ((x[0] % sizey) == 0 && h->minimap[x[1] + 1])
			x[1]++;
		x[0]++;
	}
}

void	printmap(t_hook *h)
{
	int i;
	int k;

	i = 0;
	while (h->map[i])
	{
		k = 0;
		while (h->map[i][k])
		{
			if (i != (int)h->sp->posy || k != (int)h->sp->posx)
				h->minimap[i][k] = h->map[i][k];
			else
				h->minimap[i][k] = 'X';
			k++;
		}
		h->minimap[i][k] = 0;
		i++;
	}
	put_img_minimap(h);
}
