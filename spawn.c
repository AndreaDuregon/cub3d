/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 09:48:27 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 12:02:52 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		spawn_n(t_spawn *sp)
{
	sp->dirx = 0;
	sp->diry = -1;
	sp->planex = -0.66;
	sp->planey = 0;
}

void		spawn_e(t_spawn *sp)
{
	sp->dirx = 1;
	sp->diry = 0;
	sp->planex = 0;
	sp->planey = -0.66;
}

void		spawn_s(t_spawn *sp)
{
	sp->dirx = 0;
	sp->diry = 1;
	sp->planex = 0.66;
	sp->planey = 0;
}

void		spawn_w(t_spawn *sp)
{
	sp->dirx = -1;
	sp->diry = 0;
	sp->planex = 0;
	sp->planey = 0.66;
}

void		set_dir(t_spawn *sp, char c)
{
	sp->lr = 0;
	sp->fb = 0;
	sp->sm = 0;
	sp->jump = 0;
	sp->appo = 0;
	sp->swjp = 0;
	sp->sprint = 0;
	sp->hit_sprite = 0;
	if (c == 'N')
		spawn_n(sp);
	else if (c == 'E')
		spawn_e(sp);
	else if (c == 'S')
		spawn_s(sp);
	else if (c == 'W')
		spawn_w(sp);
}
