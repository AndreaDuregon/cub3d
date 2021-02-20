/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:36:16 by forsili           #+#    #+#             */
/*   Updated: 2021/02/20 12:08:43 by aduregon         ###   ########.fr       */
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

void	file_err(void)
{
	printf("Error\nFile doesn't exist\n");
	exit(0);
}
