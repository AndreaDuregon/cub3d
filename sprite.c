/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:22:32 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/18 14:31:43 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sort_sprite(int *spr_ord, double *spr_dist)
{
	int			i;
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

int			fill_spr(int *spr_ord, double *spr_dist, int i, t_hook *h)
{
	spr_ord[i] = i;
	spr_dist[i] = ((h->sprite[i]->y - h->sp->posy) *
					(h->sprite[i]->y - h->sp->posy) +
					(h->sprite[i]->x - h->sp->posx) *
					(h->sprite[i]->x - h->sp->posx));
	return (++i);
}

void		slitta_array(t_hook *h, int i)
{
	int j;
	int k;

	j = i + 1;
	k = i;
	while (h->sprite[k])
	{
		h->sprite[k] = h->sprite[j];
		k++;
		if (h->sprite[j])
			j++;
	}
}

void		elimina_morte(t_hook *h)
{
	int	i;

	i = 0;
	while (h->sprite[i])
	{
		if (!h->sprite[i]->life)
		{
			slitta_array(h, i);
			h->sp->life += 2;
			if (h->sp->life > 100)
				h->sp->life = 100;
		}
		if (h->sprite[i])
			i++;
	}
}

void		free_sprite(t_hook *h)
{
	int i;
	int k;

	i = 0;
	while (i < h->nsprite)
	{
		free(h->sprite[i]);
		i++;
	}
	free(h->sprite);
}

void		reset_sprite(t_hook *h)
{
	t_sprite **s;

	free_sprite(h);
	next_level(h);
	h->sprite = init_spawn(h->map, h->sp, s);
}

void		sprite_calc(t_hook *h)
{
	int		i;
	int		count;
	int		*spr_ord;
	double	*spr_dist;

	i = 0;
	elimina_morte(h);
	while (h->sprite[i])
		i++;
	count = i;
	if (!count)
	{
		reset_sprite(h);
		return ;
	}
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
		manage_sprite(h, i, spr_ord, spr_dist);
		i++;
	}
	free(spr_ord);
	free(spr_dist);
}
