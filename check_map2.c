/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:17:50 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 17:56:57 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			manage_map(char **map)
{
	size_t	size;
	int		j;

	size = 0;
	while (map[size])
	{
		j = 0;
		while (map[size][j] != 0)
		{
			if (map[size][j] == 32)
				map[size][j] = 32;
			j++;
		}
		size++;
	}
	return (size);
}

int			valid_char_no_one(char c)
{
	return (c == '0' || c == '2' || c == 'N' ||
			c == 'E' || c == 'S' || c == 'W');
}

int			valid_char(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' ||
			c == 'E' || c == 'S' || c == 'W' || c == ' ');
}

int			valid_char2(char c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' ||
			c == 'E' || c == 'S' || c == 'W');
}

int			is_char(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}
