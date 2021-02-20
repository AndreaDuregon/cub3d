/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:53:49 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 17:59:02 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		side_zero(t_hook *h, int x, int y)
{
	if ((y + h->sp->appo) < h->var.ry && (y + h->sp->appo) > 0)
	{
		h->sp->texy = (int)h->sp->texpos & (h->tex[0]->height - 1);
		draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[0],
			h->sp->texx, h->sp->texy, h->sp->perpwalldist));
	}
}

void		side_one(t_hook *h, int x, int y)
{
	if ((y + h->sp->appo) < h->var.ry && (y + h->sp->appo) > 0)
	{
		h->sp->texy = (int)h->sp->texpos & (h->tex[1]->height - 1);
		draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[1],
			h->sp->texx, h->sp->texy, h->sp->perpwalldist));
	}
}

void		side_two(t_hook *h, int x, int y)
{
	if ((y + h->sp->appo) < h->var.ry && (y + h->sp->appo) > 0)
	{
		h->sp->texy = (int)h->sp->texpos & (h->tex[3]->height - 1);
		draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[3],
			h->sp->texx, h->sp->texy, h->sp->perpwalldist));
	}
}

void		side_three(t_hook *h, int x, int y)
{
	if ((y + h->sp->appo) < h->var.ry && (y + h->sp->appo) > 0)
	{
		h->sp->texy = (int)h->sp->texpos & (h->tex[2]->height - 1);
		draw_dot(h, x, y + h->sp->appo, getcolor(h->tex[2],
			h->sp->texx, h->sp->texy, h->sp->perpwalldist));
	}
}

void		print_wall(t_hook *h, int x)
{
	int	y;
	int	color;

	color = 0;
	if (h->map[h->sp->mapy][h->sp->mapx] == '1')
	{
		y = h->sp->drawstart;
		while (y < h->sp->drawend)
		{
			h->sp->texpos += h->sp->step;
			if (h->sp->side == 0)
				side_zero(h, x, y);
			else if (h->sp->side == 1)
				side_one(h, x, y);
			else if (h->sp->side == 2)
				side_two(h, x, y);
			else if (h->sp->side == 3)
				side_three(h, x, y);
			y++;
		}
	}
	h->sp->zbuff[x] = h->sp->perpwalldist;
}
