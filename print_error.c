/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:00:24 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 17:40:01 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	miss_rule_err(char *reg)
{
	printf("Error\nMissing rules\n");
	free(reg);
	exit(0);
}

void	exist_rule_err(char *line, char *reg)
{
	printf("Error\nRule already exists\n");
	free(line);
	free(reg);
	exit(0);
}

void	forb_rule_err(char *line, char *reg)
{
	printf("Error\nRule forbidden\n");
	free(line);
	free(reg);
	exit(0);
}

void	invalid_map_err(char **map)
{
	printf("Error\nInvalid Map\n");
	free(map);
	exit(0);
}

void	floceal_err(char *reg)
{
	printf("Error\nYou can't manage floor and ceiling in different mode\n");
	free(reg);
	exit(0);
}
