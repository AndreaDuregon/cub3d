/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 09:46:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/02/10 12:03:08 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# include "./libft/libft.h"

# define BUFFER_SIZE 1

typedef struct		s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
}					t_vars;

typedef struct		s_var
{
	int				rx;
	int				ry;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				f[3];
	char			*fpat;
	int				c[3];
	char			*cpat;
}					t_var;

typedef struct		s_spawn
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			wallx;
	double			texpos;
	double			step;
	double			texx;
	double			texy;
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				lr;
	int				fb;
	int				sm;
	int				jump;
	int				appo;
	int				swjp;
	int				sprint;
	int				hit_sprite;
	double			movspeed;
	double			rotspeed;
	double			*zbuff;
}					t_spawn;

typedef struct		s_spr
{
	double			spritex;
	double			spritey;
	double			invcam;
	double			transx;
	double			transy;
	int				screenx;
	int				sprheight;
	int				sprwidth;
	int				sprdrawstartx;
	int				sprdrawstarty;
	int				sprdrawendx;
	int				sprdrawendy;
	int				stripe;
	int				texx;
	int				texy;
}					t_spr;

typedef struct		s_tex
{
	int				width;
	int				height;
	char			*buff;
}					t_tex;

typedef	struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_hook
{
	t_spawn			*sp;
	t_spr			*spr;
	t_sprite		**sprite;
	t_var			var;
	char			**map;
	t_data			img;
	t_vars			vars;
	t_tex			*tex[5];
}					t_hook;

void				var_parsing(int fd, t_var *var);
char				**map_parsing(int fd);
void				insert_value(char *temp, t_var *var);
void				parse_value(char *line, char *reg, t_var *var);
void				parse_template_no(char *line, char *reg, t_var *var);
void				parse_template_so(char *line, char *reg, t_var *var);
void				parse_template_we(char *line, char *reg, t_var *var);
void				parse_template_ea(char *line, char *reg, t_var *var);
void				parse_template_s(char *line, char *reg, t_var *var);
void				parse_rgb_f(char *line, char *reg, t_var *var);
void				parse_rgb_c(char *line, char *reg, t_var *var);
int					is_digit_space(char *line, int i);
int					is_space(char *line, int i);
int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *s1, char const *s2);
int					is_line(char *str);
size_t				ft_strlen(const char *s);
void				check_map(char **map);
int					valid_char_no_one(char c);
int					valid_char(char c);
int					is_char(char c);
int					manage_map(char **map);
void				format_rule_err(char *line, char *reg);
void				miss_rule_err(char *reg);
void				exist_rule_err(char *line, char *reg);
void				forb_rule_err(char *line, char *reg);
void				exist_file_err(void);
void				name_file_err(char *str);
void				invalid_map_err(char **map);
void				rendering(char **map, t_var var);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					create_trgb(int t, int r, int g, int b);
t_hook				hook_init(char **map, t_var var, t_spawn spawn,
								t_vars vars, t_spr sprt);
int					set_key(int keycode, t_hook *h);
t_sprite			**init_spawn(char **map, t_spawn *sp, t_sprite **s);
int					raycasting(t_hook *h);
void				draw_dot(t_hook *h, int x, int y, int color);
int					getcolor(t_tex *tex, int x, int y, int fade);
int					key_hook(int keycode);
void				print_background(t_var var, t_data img);
void				sprite_calc(t_hook *h);
void				pwd_calc(t_spawn *sp);
void				height_calc(t_spawn *sp, t_var var);
void				set_speed(t_spawn *sp);
void				print_wall(t_hook *h, int x);
void				ray_calc(t_spawn *sp, t_var var, int x);
void				var_dda(t_spawn *sp);
void				dda(t_spawn *sp, char **map);
void				tex_coord(t_spawn *sp, t_var var);
int					print_stripe(t_hook *h, int d, int y, int c);
void				print_sprite(t_hook *h);
void				set_dir(t_spawn *sp, char c);

#endif
