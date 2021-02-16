/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:16:07 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/12 12:16:09 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		random_gen(double *movex, double *movey)
{
	int n;

	n = rand() % 80;
	if (n <= (80 / 8))
	{
		*movex *= 1;
		*movey *= 1;
	}
	else if (n > 10 && n <= 20)
	{
		*movex *= 1;
		*movey *= -1;
	}
	else if (n > 20 && n <= 30)
	{
		*movex *= -1;
		*movey *= 1;
	}
	else if (n > 30 && n <= 40)
	{
		*movex *= -1;
		*movey *= -1;
	}
	else if (n > 40 && n <= 50)
	{
		*movex *= 1;
		*movey *= 0;
	}
	else if (n > 50 && n <= 60)
	{
		*movex *= -1;
		*movey *= 0;
	}
	else if (n > 60 && n <= 70)
	{
		*movex *= 0;
		*movey *= -1;
	}
	else if (n > 70 && n <= (80))
	{
		*movex *= 0;
		*movey *= 1;
	}
}

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

int		can_move(t_sprite *spr, t_hook *h, double movex, double movey)
{
	double sicx;
	double sicy;

	sicy = 0.2;
	sicx = 0.2;
	if (movex < 0)
		sicx *= 1;
	if (movey < 0)
		sicy *= 1;
	if (!spr->k)
		return (0);
	if (h->map[(int)(spr->y + movey + sicy)][(int)(spr->x + movex + sicx)] != '1' && 
		h->map[(int)(spr->y + movey)][(int)(spr->x + movex)] != '1')
		return (1);
	if (((int)h->sp->posx == (int)(spr->x + movex + sicx) &&
		(int)(spr->y + movey + sicy) != (int) h->sp->posy))
		return (1);
	else if ((int)(spr->y + movey + sicy) == (int) h->sp->posy &&
		(int)h->sp->posx != (int)(spr->x + movex + sicx))
		return (1);
	else if (((int)h->sp->posx != (int)(spr->x + movex + sicx) &&
		(int)(spr->y + movey + sicy) != (int) h->sp->posy))
		return (1);
	return (0);
}

void	movement_sprite(t_hook *h)
{
	int i;

	i = 0;
	while (h->sprite[i])
	{
		h->sprite[i]->movex = 0.009;
		h->sprite[i]->movey = 0.009;
		if ((rand() % 80) % 2 == 0)
			random_gen(&h->sprite[i]->movex, &h->sprite[i]->movey);
		else
			follow_player(h, &h->sprite[i]->movex, &h->sprite[i]->movey, i);
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