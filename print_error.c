/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:00:24 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 15:36:37 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	miss_rule_err(char *reg)
{
	perror("Error\nMissing rules");
	free(reg);
	exit(0);
}

void	exist_rule_err(char *line, char *reg)
{
	perror("Error\nRule already exists");
	free(line);
	free(reg);
	exit(0);
}

void	forb_rule_err(char *line, char *reg)
{
	perror("Error\nRule forbidden");
	free(line);
	free(reg);
	exit(0);
}

void	invalid_map_err(char **map)
{
	perror("Error\nInvalid Map");
	free(map);
	exit(0);
}

void	floceal_err(char *reg)
{
	perror("Error\nYou can't manage floor and ceiling in different mode");
	free(reg);
	exit(0);
}
