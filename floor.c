#include "cub3d.h"

void  ft_helper(t_hook *h, int y)
{
	int tx;
	int ty;
	int cellx;
	int celly;
	int x = 0;

	while(x < h->var.rx)
	{
		// the cell coord is simply got from the integer parts of floorX and floorY
		cellx = (int)(h->floceal->floorx);
		celly = (int)(h->floceal->floory);

		// get the texture coordinate from the fractional part
		tx = (int)(h->tex[6]->width * (h->floceal->floorx - cellx)) & (h->tex[6]->width - 1);
		ty = (int)(h->tex[6]->height * ((h->floceal->floory - celly)) & (h->tex[6]->height - 1);

		h->floceal->floorx += h->floceal->floorstepx;
		h->floceal->floory += h->floceal->floorstepy;

		// choose texture and draw the pixel

		// floor
		h->floceal->color = h->tex[6]->buff[h->tex[6]->width * ty + tx];
		h->floceal->color = (h->floceal->color >> 1) & 8355711; // make a bit darker
		h->img.addr[y][x] = h->floceal->color;

		//ceiling (symmetrical, at screenHeight - y - 1 instead of y)
		h->floceal->color = h->tex[7][h->tex[7]->width * ty + tx];
		h->floceal->color = (h->floceal->color >> 1) & 8355711; // make a bit darker
		h->img.img[h->var.ry - y - 1][x] = h->floceal->color;
		x++;
	}
}

void  ft_print_floceal(t_hook *h)
{
	int y;
	y = 0;

	while(y < h)
	{
			// rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
		h->floceal->raydirxa = h->sp->dirx - h->sp->planex;
		h->floceal->raydirya = h->sp->diry - h->sp->planey;
		h->floceal->raydirxb = h->sp->dirx + h->sp->planex;
		h->floceal->raydiryb = h->sp->diry + h->sp->planey;

			// Current y position compared to the center of the screen (the horizon)
		h->floceal->p = y - h->var.ry / 2;

			// Vertical position of the camera.
		h->floceal->posz = 0.5 * h->var.ry;

			// Horizontal distance from the camera to the floor for the current row.
			// 0.5 is the z position exactly in the middle between floor and ceiling.
	 	h->floceal->rowdistance = h->floceal->posz / h->floceal->p;

			// calculate the real world step vector we have to add for each x (parallel to camera plane)
			// adding step by step avoids multiplications with a weight in the inner loop
		h->floceal->floorstepx = h->floceal->rowdistance * (h->floceal->raydirxb - h->floceal->raydirxa) /  h->var.ry;
		h->floceal->floorstepy = h->floceal->rowdistance * (h->floceal->raydiryb - h->floceal->raydirya) /  h->var.ry;

			// real world coordinates of the leftmost column. This will be updated as we step to the right.
		h->floceal->floorx = h->sp->posx + h->floceal->rowdistance * h->floceal->raydirxa;
		h->floceal->floory = h->sp->posy + h->floceal->rowdistance * h->floceal->raydirya;

		ft_helper(h, y);
		y++;
	}
}