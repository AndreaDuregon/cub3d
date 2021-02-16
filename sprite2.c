/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:31:37 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 09:31:57 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			print_stripe(t_hook *h, int d, int y, int c)
{
	d = (y) * 256 - h->var.ry * 128 + h->spr->sprheight * 128;
	h->spr->texy = ((d * 64) / h->spr->sprheight) / 256;
	c = ((unsigned int *)(h->tex[4]->buff))[(int)(h->tex[4]->height
									* h->spr->texy + h->spr->texx)];
	if (c != 13490999)
	{
		draw_dot(h, h->spr->stripe, y + h->sp->appo,
					getcolor(h->tex[4], h->spr->texx, h->spr->texy,
											h->sp->perpwalldist));
	}
	return (++y);
}

void		print_sprite(t_hook *h)
{
	int d;
	int y;
	int	c;

	while (h->spr->stripe < h->spr->sprdrawendx)
	{
		h->spr->texx = (int)(256 * (h->spr->stripe -
				(-(h->spr->sprwidth) / 2 + h->spr->screenx))
				* 64 / h->spr->sprwidth) / 256;
		if (h->spr->transy > 0 && h->spr->stripe > 0 &&
			h->spr->stripe < h->var.rx &&
			h->spr->transy < h->sp->zbuff[h->spr->stripe])
		{
			y = h->spr->sprdrawstarty;
			while (y < h->spr->sprdrawendy)
				y = print_stripe(h, d, y, c);
		}
		h->spr->stripe++;
	}
}
