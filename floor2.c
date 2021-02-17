/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:51:22 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/17 09:53:58 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_floceal2(t_floceal *fl, int cellx, int celly)
{
	fl->floorx += fl->floorstepx;
	fl->floory += fl->floorstepy;
	fl->cbpatt = (int)(cellx + celly) & 1;
}

void		set_floceal(t_hook *h, int y)
{
	h->floceal->raydirya = -h->sp->diry - h->sp->planey;
	h->floceal->raydirxa = -h->sp->dirx - h->sp->planex;
	h->floceal->raydiryb = -h->sp->diry + h->sp->planey;
	h->floceal->raydirxb = -h->sp->dirx + h->sp->planex;
	h->floceal->p = y - h->var.ry / 2;
	h->floceal->posz = 0.5 * h->var.ry;
	h->floceal->rowdistance = -h->floceal->posz / h->floceal->p;
	h->floceal->floorstepx = h->floceal->rowdistance *
			(h->floceal->raydirxb - h->floceal->raydirxa) /
												h->var.rx;
	h->floceal->floorstepy = h->floceal->rowdistance *
		(h->floceal->raydiryb - h->floceal->raydirya) / h->var.rx;
	h->floceal->floorx = h->sp->posx + h->floceal->rowdistance *
											h->floceal->raydirxa;
	h->floceal->floory = h->sp->posy + h->floceal->rowdistance *
											h->floceal->raydirya;
}
