/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:36:16 by forsili           #+#    #+#             */
/*   Updated: 2021/02/19 17:38:15 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	format_rule_err(char *line, char *reg)
{
	printf("Error\nWrong rules format\n");
	free(line);
	free(reg);
	exit(0);
}

void	extension_err(char *line, char *reg)
{
	printf("Error\nNot valid texture extension\n");
	free(line);
	free(reg);
	exit(0);
}
