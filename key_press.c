/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:37:52 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/20 12:38:28 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			unset_key(int keycode, t_hook *h)
{
	if (keycode == 123)
		h->sp->lr = 0;
	if (keycode == 124)
		h->sp->lr = 0;
	if (keycode == 13)
		h->sp->fb = 0;
	if (keycode == 1)
		h->sp->fb = 0;
	if (keycode == 0)
		h->sp->sm = 0;
	if (keycode == 2)
		h->sp->sm = 0;
	if (keycode == 257)
	{
		h->sp->jump = 0;
		h->sp->appo = 0;
	}
	if (keycode == 12)
		h->sp->sprint = 0;
	if (keycode == 14)
		h->sp->displayminimap = 0;
	return (0);
}

void		key_exit(int keycode, t_hook *h)
{
	if (keycode == 53)
	{
		free_all(h);
		exit(0);
	}
}

int			set_key(int keycode, t_hook *h)
{
	key_exit(keycode, h);
	if (keycode == 123)
		h->sp->lr = 1;
	if (keycode == 124)
		h->sp->lr = -1;
	if (keycode == 13)
		h->sp->fb = 1;
	if (keycode == 1)
		h->sp->fb = -1;
	if (keycode == 2)
		h->sp->sm = 1;
	if (keycode == 0)
		h->sp->sm = -1;
	if (keycode == 49)
		h->sp->jump = 1;
	if (keycode == 257)
		h->sp->jump = -1;
	if (keycode == 12)
		h->sp->sprint = 1;
	if (keycode == 14)
		h->sp->displayminimap = 1;
	if (keycode == 126)
		h->sp->shoot = 1;
	return (0);
}

int			close_win(t_hook *h)
{
	free_all(h);
	exit(0);
}
