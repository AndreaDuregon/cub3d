/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 12:47:08 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/11 18:59:03 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		print_ver(t_data img, t_var var, int fd)
{
	int		y;
	int		x;
	int		f;
	int		save;

	y = var.ry - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < var.rx)
		{
			save = (*(int *)(img.addr + (y * img.line_length + (x * 4))));
			write(fd, &save, 4);
			x++;
		}
		y--;
	}
}

void		set_info(t_data img, int fd, t_var var)
{
	int info_size;
	int plane_num;
	int count;
	int img_size;
	int color;

	info_size = 40;
	plane_num = 1;
	color = 0;
	img_size = var.rx * (var.ry - 1) * 4;
	write(fd, &info_size, 4);
	write(fd, &var.rx, 4);
	write(fd, &var.ry, 4);
	write(fd, &plane_num, 2);
	write(fd, &img.bits_per_pixel, 2);
	write(fd, "\0\0\0\0", 4);
	write(fd, &img_size, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
	write(fd, &color, 4);
}

void		screenshot(t_data img, t_var var)
{
	int fd;
	int file_size;
	int first_pix;

	fd = open("cub3d.bmp", O_CREAT | O_RDWR, 0700);
	file_size = 54 + (var.rx * var.ry) * 4;
	first_pix = 54;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	set_info(img, fd, var);
	print_ver(img, var, fd);
	close(fd);
}
