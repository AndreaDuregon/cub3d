/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:22:32 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 17:14:18 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sort_sprite(int *spr_ord, double *spr_dist)
{
	int		i;
	double		temp;

	i = 0;
	while (spr_dist[i])
	{
		if (spr_dist[i] < spr_dist[i + 1])
		{
			temp = spr_dist[i];
			spr_dist[i] = spr_dist[i + 1];
			spr_dist[i + 1] = temp;
			temp = spr_ord[i];
			spr_ord[i] = spr_ord[i + 1];
			spr_ord[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void		sprite_var(t_hook *h, int i, int *spr_ord, double *spr_dist)
{
	h->spr->spritex = h->sprite[spr_ord[i]]->x - h->sp->posx;
	h->spr->spritey = h->sprite[spr_ord[i]]->y - h->sp->posy;
	h->spr->invcam = 1.0 / (h->sp->planex * h->sp->diry -
							h->sp->dirx * h->sp->planey);
	h->spr->transx = -h->spr->invcam * (h->sp->diry * h->spr->spritex
									- h->sp->dirx * h->spr->spritey);
	h->spr->transy = h->spr->invcam * (-(h->sp->planey) * h->spr->spritex
										+ h->sp->planex * h->spr->spritey);
	h->spr->screenx = (int)((h->var.rx / 2) *
					(1 + h->spr->transx / h->spr->transy));
	h->spr->sprheight = abs((int)(h->var.ry / (h->spr->transy)));
	h->spr->sprdrawstarty = -(h->spr->sprheight) / 2 + h->var.ry / 2;
	if (h->spr->sprdrawstarty < 0)
		h->spr->sprdrawstarty = 0;
	h->spr->sprdrawendy = h->spr->sprheight / 2 + h->var.ry / 2;
	if (h->spr->sprdrawendy >= h->var.ry)
		h->spr->sprdrawendy = h->var.ry - 1;
	h->spr->sprwidth = abs((int)(h->var.ry / (h->spr->transy)));
	h->spr->sprdrawstartx = -(h->spr->sprwidth) / 2 + h->spr->screenx;
	if (h->spr->sprdrawstartx < 0)
		h->spr->sprdrawstartx = 0;
	h->spr->sprdrawendx = h->spr->sprwidth / 2 + h->spr->screenx;
	if (h->spr->sprdrawendx >= h->var.rx)
		h->spr->sprdrawendx = h->var.rx - 1;
	h->spr->stripe = h->spr->sprdrawstartx;
}

int			fill_spr(int *spr_ord, double *spr_dist, int i, t_hook *h)
{
	spr_ord[i] = i;
	spr_dist[i] = ((h->sprite[i]->y - h->sp->posy) *
					(h->sprite[i]->y - h->sp->posy) +
					(h->sprite[i]->x - h->sp->posx) *
					(h->sprite[i]->x - h->sp->posx));
	printf("%f %f %f |%f %f|\n", spr_dist[i], h->sp->posx, h->sp->posy, h->sprite[i]->x, h->sprite[i]->y);
	return (++i);
}

void		sprite_calc(t_hook *h)
{
	int i;
	int count;
	int *spr_ord;
	double *spr_dist;

	i = 0;
	while (h->sprite[i])
		i++;
	count = i;
	if (!(spr_ord = malloc(sizeof(int) * (count + 1))) ||
		!(spr_dist = malloc(sizeof(double) * (count + 1))))
		return ;
	i = 0;
	while (i < count)
		i = fill_spr(spr_ord, spr_dist, i, h);
	spr_ord[i] = 0;
	spr_dist[i] = 0;
	sort_sprite(spr_ord, spr_dist);
	i = 0;
	while (i < count)
	{
		sprite_var(h, i, spr_ord, spr_dist);
		print_sprite(h);
		i++;
	}
}
