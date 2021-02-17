/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:16:07 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/17 11:50:16 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	follow_player(t_hook *h, double *movex, double *movey, int i)
{
	if (h->sprite[i]->y < h->sp->posy)
		*movey *= -(h->sprite[i]->y - h->sp->posy);
	else
		*movey *= -(h->sprite[i]->y - h->sp->posy);
	if (h->sprite[i]->x < h->sp->posx)
		*movex *= -(h->sprite[i]->x - h->sp->posx);
	else
		*movex *= -(h->sprite[i]->x - h->sp->posx);
	if ((int)h->sprite[i]->y == (int)h->sp->posy)
		*movey *= 0;
	if ((int)h->sprite[i]->x == (int)h->sp->posx)
		*movex *= 0;
}

double	distance_punti(double x1, double x2, double y1, double y2)
{
	return (sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2))));
}

int		can_move(t_sprite *spr, t_hook *h, double movex, double movey)
{
	double sicx;
	double sicy;

	sicy = 0.5;
	sicx = 0.5;
	if (movex < 0)
		sicx *= 1;
	if (movey < 0)
		sicy *= 1;
	if (!spr->k)
		return (0);
	if (distance_punti(spr->x + movex, h->sp->posx, spr->y +
						movey, h->sp->posy) < 1)
		h->sp->life -= 1;
	if (h->map[(int)(spr->y + movey + sicy)][(int)(spr->x + movex + sicx)]
	!= '1' && h->map[(int)(spr->y + movey)][(int)(spr->x + movex)] != '1')
	{
		if ((int)(spr->y + movey) == (int)h->sp->posy &&
					(int)(spr->x + movex) == (int)h->sp->posx)
			return (0);
		return (1);
	}
	else
		return (0);
	return (0);
}

void	movement_sprite(t_hook *h)
{
	int i;

	i = 0;
	while (h->sprite[i])
	{
		//if ((rand() % 80) <= 55)
		//	random_gen(&h->sprite[i]->movex, &h->sprite[i]->movey);
		//else
		if (distance_punti(h->sprite[i]->x, h->sp->posx, h->sprite[i]->y, h->sp->posy) < 13)
		{
			h->sprite[i]->movex = 0.03;
			h->sprite[i]->movey = 0.03;
			follow_player(h, &h->sprite[i]->movex, &h->sprite[i]->movey, i);
		}
		if (can_move(h->sprite[i], h, h->sprite[i]->movex, h->sprite[i]->movey))
		{
			h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '0';
			//if (((int)(h->sprite[i]->x + h->sprite[i]->movex) != (int)h->sprite[i]->x ||
			//	(int)(h->sprite[i]->y + h->sprite[i]->movey) != (int)h->sprite[i]->y))
			//	gest_scie(h, i);
			h->sprite[i]->x += h->sprite[i]->movex;
			h->sprite[i]->y += h->sprite[i]->movey;
			h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '2';
		}
		i++;
	}
}
