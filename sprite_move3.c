/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_move3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:21:40 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/17 11:21:46 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_move1(double *movex, double *movey)
{
	*movex *= 1;
	*movey *= 1;
}

void		set_move2(double *movex, double *movey)
{
	*movex *= 1;
	*movey *= -1;
}

void		set_move3(double *movex, double *movey)
{
	*movex *= -1;
	*movey *= 1;
}

void		set_move4(double *movex, double *movey)
{
	*movex *= -1;
	*movey *= -1;
}
