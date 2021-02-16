/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:01:19 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/16 12:10:19 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		call_func(t_hook *h, int x)
{
	ray_calc(h->sp, h->var, x);
	var_dda(h->sp);
	dda(h->sp, h->map);
	pwd_calc(h->sp);
	height_calc(h->sp, h->var);
	tex_coord(h->sp, h->var);
	print_wall(h, x);
	if (!h->sp->sprint)
		set_speed(h->sp);
}

void		ft_save_img(char *img, t_hook *h)
{
	int i;
	int fd;

	i = 0;
	fd = open("img.bmp", O_CREAT | O_WRONLY);
	while (img[i])
	{
		if (i % h->var.rx == 0)
			write(fd, &"\n", 1);
		write(fd, &img[i], 1);
		i++;
	}
	write(fd, 0, 1);
	close(fd);
}

int			raycasting(t_hook *h)
{
	int x;

	h->img.img = mlx_new_image(h->vars.mlx, h->var.rx, h->var.ry);
	h->img.addr = mlx_get_data_addr(h->img.img, &h->img.bits_per_pixel,
									&h->img.line_length, &h->img.endian);
	print_floor(h);
	x = 0;
	while (x < h->var.rx)
	{
		call_func(h, x);
		x++;
	}
	movement_sprite(h);
	sprite_calc(h);
	if (h->sp->sw == 1)
	{
		screenshot(h->img, h->var);
		h->sp->sw = 0;
	}
	gunprinter(h);
	if (h->sp->shoot)
		shoot(h);
	h->sp->shoot = 0;
	if (h->sp->displayminimap)
		printmap(h);
	if (h->sp->life <= 0)
	{
		printf("gameover\n");
		exit(0);
	}
	mlx_put_image_to_window(h->vars.mlx, h->vars.win, h->img.img, 0, 0);
	if (!(mlx_destroy_image(h->vars.mlx, h->img.img)))
		return (0);
	return (0);
}
