
#include "cub3d.h"

void		var_dda_gun(t_spawn *sp)
{
	sp->mapy = (int)sp->posy;
	sp->mapx = (int)sp->posx;
	sp->deltadistx = fabs(1 / sp->dirx);
	sp->deltadisty = fabs(1 / sp->diry);
	sp->hit = 0;
	if (sp->raydirx < 0)
	{
		sp->stepx = -1;
		sp->sidedistx = (sp->posx - sp->mapx) * sp->deltadistx;
	}
	else
	{
		sp->stepx = 1;
		sp->sidedistx = (sp->mapx + 1.0 - sp->posx) * sp->deltadistx;
	}
	if (sp->raydiry < 0)
	{
		sp->stepy = -1;
		sp->sidedisty = (sp->posy - sp->mapy) * sp->deltadisty;
	}
	else
	{
		sp->stepy = 1;
		sp->sidedisty = (sp->mapy + 1.0 - sp->posy) * sp->deltadisty;
	}
}

int		dda_gun(t_spawn *sp, char **map, int *x, int *y)
{
	while (1)
	{
		if (sp->sidedistx <= sp->sidedisty)
		{
			sp->sidedistx += sp->deltadistx;
			sp->mapx += sp->stepx;
			if (sp->stepx == 1)
				sp->side = 0;
			else if (sp->stepx == -1)
				sp->side = 2;
		}
		else if (sp->sidedistx > sp->sidedisty)
		{
			sp->sidedisty += sp->deltadisty;
			sp->mapy += sp->stepy;
			if (sp->stepy == 1)
				sp->side = 1;
			else if (sp->stepy == -1)
				sp->side = 3;
		}
		if (map[sp->mapy][sp->mapx] == '2')
		{
			*x = sp->mapx;
			*y = sp->mapy;
			return (1);
		}
		if (map[sp->mapy][sp->mapx] == '1')
			return (0);
	}
}

int		search_sprite(t_hook *h, int x, int y)
{
	int i;

	i = 0;
	while (h->sprite[i])
	{
		if ((int)h->sprite[i]->x == x && (int)h->sprite[i]->y == y)
			return (i); 
		i++;
	}
	return (-1);
}

void		shoot(t_hook *h)
{
	int x;
	int y;
	int i;

	var_dda_gun(h->sp);
	if (dda_gun(h->sp, h->map, &x, &y))
	{
		if ((i = search_sprite(h, x, y)) == -1)
			return ;
		h->sprite[i]->life -=  50;
		printf("life %d\n", h->sprite[i]->life);
		if (h->sprite[i]->life <= 0)
		{
			h->sprite[i]->k = 0;
			h->map[(int)h->sprite[i]->y][(int)h->sprite[i]->x] = '0';
		}
	}
	h->sp->shoot = 0;
}