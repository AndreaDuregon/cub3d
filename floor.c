/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:15:28 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/12 17:48:30 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_background(t_hook *h, t_var var, t_data img, unsigned int **buffer)
{
	int x;
	int y;

	x = 0;
	while (x < var.rx)
	{
		y = 0;
		while (y < (var.ry/2))
		{
			draw_dot(h, x, y, buffer[y][x]);
			y++;
		}
		x++;
	}
}

void		ft_helper(t_hook *h, int y, unsigned int **buffer, int x)
{
	int tx;
	int ty;
	int cellx;
	int celly;

	while (x < h->var.rx)
	{
		cellx = (int)(h->floceal->floorx);
		celly = (int)(h->floceal->floory);
		tx = (int)(64 * (h->floceal->floorx - cellx)) & (63);
		ty = (int)(64 * (h->floceal->floory - celly)) & (63);
		h->floceal->floorx += h->floceal->floorstepx;
		h->floceal->floory += h->floceal->floorstepy;
		h->floceal->cbpatt = (int)(cellx + celly) & 1;
		if (h->floceal->cbpatt == 0)
			h->floceal->floortex = 4;
		h->floceal->ceiltex = 6;
		h->floceal->color = h->tex[0]->buff[64 * ty + tx];
		//buffer[y][x] = h->floceal->color;
		h->floceal->color = h->tex[0]->buff[64 * ty + tx];
		//buffer[h->var.ry - y - 1][x] = h->floceal->color;
		//h->sp->texy = (int)h->sp->texpos & (h->tex[4]->height - 1);
		if (buffer[y][x] == 0)
			buffer[y][x] = getcolor(h->tex[4], tx, ty, 1000);
		x++;
	}
}

unsigned int		**buff_alloc(int x, int y)
{
	unsigned int	**buff;
	int				i;
	int				j;

	if (!(buff = ft_calloc((y + 1), sizeof(unsigned int *))))
		return (NULL);
	i = 0;
	while (i < y)
		if (!(buff[i++] = ft_calloc((x + 1), sizeof(unsigned int))))
			return (NULL);
	buff[i] = 0;
	return (buff);
}

void		print_floor(t_hook *h)
{
	int				y;
	unsigned int	**buffer;

	buffer = buff_alloc(h->var.rx, h->var.ry);
	y = 0;
	while (y < h->var.ry)
	{
		h->floceal->raydirya = h->sp->dirx - h->sp->planex;
		h->floceal->raydirxa = h->sp->diry - h->sp->planey;
		h->floceal->raydiryb = h->sp->dirx + h->sp->planex;
		h->floceal->raydirxb = h->sp->diry + h->sp->planey;
		h->floceal->p = y - h->var.ry / 2;
		h->floceal->posz = 0.5 * h->var.ry;
		h->floceal->rowdistance = h->floceal->posz / h->floceal->p;
		h->floceal->floorstepx = h->floceal->rowdistance *
				(h->floceal->raydirxb - h->floceal->raydirxa) /
													h->var.ry;
		h->floceal->floorstepy = h->floceal->rowdistance *
			(h->floceal->raydiryb - h->floceal->raydirya) / h->var.ry;
		h->floceal->floorx = h->sp->posx + h->floceal->rowdistance *
												h->floceal->raydirxa;
		h->floceal->floory = h->sp->posy + h->floceal->rowdistance *
												h->floceal->raydirya;
		ft_helper(h, y, buffer, 0);
		y++;
	}
	print_background(h, h->var, h->img, buffer);
}
