/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 12:08:12 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/20 12:08:45 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all(t_hook *h)
{
	int i;

	i = 0;
	free(h->sp->zbuff);
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
	i = 0;
	while (h->map[i])
		free(h->map[i++]);
	i = 0;
	while (h->minimap[i])
		free(h->minimap[i++]);
	free(h->floceal);
}

void	free_sc(t_hook *h)
{
	int i;

	i = 0;
	free(h->sp->zbuff);
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
	i = 0;
	while (h->map[i])
		free(h->map[i++]);
	i = 0;
	while (h->minimap[i])
		free(h->minimap[i++]);
}

void	free_tex(t_hook *h)
{
	int i;

	i = 0;
	free(h->sprite);
	while (i < 10)
		free(h->tex[i++]);
}
