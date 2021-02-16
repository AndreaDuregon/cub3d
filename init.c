/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:20:27 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/16 14:45:43 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ar_length(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

char			**minimap_init(char **minimap, char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		if (!(minimap[i] = (char *)malloc((((int)ft_strlen(map[i]) + 1) * sizeof(char)))))
			exit(0);
		i++;
	}
	minimap[i] = 0;
	return (minimap);
}

t_hook			hook_init(char **map, t_var var, t_spawn spawn, t_vars vars, t_spr sprt)
{
	t_hook		h;
	int			width;
	int			height;
	t_floceal	flcl;

	h.tex[0] = mlx_xpm_file_to_image(vars.mlx, var.no, &width, &height);
	h.tex[1] = mlx_xpm_file_to_image(vars.mlx, var.so, &width, &height);
	h.tex[2] = mlx_xpm_file_to_image(vars.mlx, var.ea, &width, &height);
	h.tex[3] = mlx_xpm_file_to_image(vars.mlx, var.we, &width, &height);
	h.tex[4] = mlx_xpm_file_to_image(vars.mlx, var.s, &width, &height);
	h.tex[5] = mlx_xpm_file_to_image(vars.mlx, "./texture/quarzo.xpm", &width, &height);
	h.tex[6] = mlx_xpm_file_to_image(vars.mlx, "./texture/WALL1.xpm", &width, &height);
	h.tex[7] = mlx_xpm_file_to_image(vars.mlx, "./texture/gun.xpm", &width, &height);
	h.floceal = &flcl;
	h.map = map;
	h.var = var;
	h.sp = &spawn;
	h.spr = &sprt;
	if (!(h.minimap = malloc((ar_length(map) + 1) * sizeof(char *))))
		exit(0);
	h.minimap = minimap_init(h.minimap, h.map);
	h.sp->displayminimap = 0;
	return (h);
}

int				count_sprite(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void			set_pos(char **map, t_spawn *sp, int i[3])
{
	set_dir(sp, map[i[0]][i[1]]);
	sp->posy = (double)i[0] + 0.5;
	sp->posx = (double)i[1] + 0.5;
}

int				set_sprite(t_sprite **s, int i[3], int count)
{
	if (!(s[i[2]] = malloc(sizeof(t_sprite) * (count + 1))))
		return (0);
	s[i[2]]->x = (double)i[1] + 0.5;
	s[i[2]]->y = (double)i[0] + 0.5;
	s[i[2]]->movex = 0.07;
	s[i[2]]->movey = 0.07;
	s[i[2]]->life = 100;
	s[i[2]]->k = 1;
	i[2]++;
	return (i[2]);
}

t_sprite		**init_spawn(char **map, t_spawn *sp, t_sprite **s)
{
	int i[3];
	int count;

	count = count_sprite(map);
	if (!(s = malloc(sizeof(t_sprite *) * (count + 1))))
		return (NULL);
	i[0] = 0;
	i[2] = 0;
	while (map[i[0]])
	{
		i[1] = 0;
		while (map[i[0]][i[1]])
		{
			if (map[i[0]][i[1]] == 'N' || map[i[0]][i[1]] == 'S'
				|| map[i[0]][i[1]] == 'E' || map[i[0]][i[1]] == 'W')
				set_pos(map, sp, i);
			else if (map[i[0]][i[1]] == '2')
				i[2] = set_sprite(s, i, count);
			i[1]++;
		}
		i[0]++;
	}
	s[i[2]] = NULL;
	return (s);
}
