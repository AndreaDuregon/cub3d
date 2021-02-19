/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rule2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:51:31 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/19 15:33:51 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_rgb_f(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;

	i = is_space(line, 2);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	temp = ft_strtrim(&line[i], " \t");
	i = is_digit_space(line, i);
	i = is_comma(line[i], i, line, reg);
	i = is_space(line, i);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	i = is_digit_space(line, i);
	i = is_comma(line[i], i, line, reg);
	i = is_space(line, i);
	if (!ft_isdigit(line[i]))
		format_rule_err(line, reg);
	i = is_digit_space(line, i);
	if (line[i] != '\0')
		format_rule_err(line, reg);
	insert_rgb_f(temp, var);
	if (reg[6] == '0')
		reg[6] = '1';
	else
		exist_rule_err(line, reg);
}

void		parse_template_c(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;
	char	*newline;

	newline = line;
	i = 2;
	while (ft_isspace(newline[i]))
		i++;
	if (newline[i] < 33 || newline[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&newline[i], " \t");
	var->cpat = temp;
	if (reg[7] == '0')
		reg[7] = '1';
	else
		exist_rule_err(line, reg);
}

void		parse_c(char *line, char *reg, t_var **var)
{
	int i;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
	{
		parse_rgb_c(line, reg, *var);
		(*var)->swc = 0;
	}
	else if (line[i] >= 33 && line[i] <= 126)
	{
		parse_template_c(line, reg, *var);
		(*var)->swc = 1;
	}
	else
		format_rule_err(line, reg);
}

void		parse_template_f(char *line, char *reg, t_var *var)
{
	int		i;
	char	*temp;
	char	*newline;

	newline = line;
	i = 2;
	while (ft_isspace(newline[i]))
		i++;
	if (newline[i] < 33 || newline[i] > 126)
		format_rule_err(line, reg);
	temp = ft_strtrim(&newline[i], " \t");
	var->fpat = temp;
	if (reg[6] == '0')
		reg[6] = '1';
	else
		exist_rule_err(line, reg);
}

void		parse_f(char *line, char *reg, t_var **var)
{
	int i;

	i = 2;
	while (ft_isspace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
	{
		parse_rgb_f(line, reg, *var);
		(*var)->swf = 0;
	}
	else if (line[i] >= 33 && line[i] <= 126)
	{
		parse_template_f(line, reg, *var);
		(*var)->swf = 1;
	}
	else
		format_rule_err(line, reg);
}
