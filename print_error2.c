/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 15:36:16 by forsili           #+#    #+#             */
/*   Updated: 2021/02/19 15:36:30 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	format_rule_err(char *line, char *reg)
{
	perror("Error\nWrong rules format");
	free(line);
	free(reg);
	exit(0);
}
