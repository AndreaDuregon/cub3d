#include "cub3d.h"

void  ft_helper()
{
    int tx;
    int ty;
    int cellX;
    int cellY;
    int x = 0;

while(x < h->var.rx)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        cellX = (int)(floorX);
        cellY = (int)(floorY);

        // get the texture coordinate from the fractional part
        h->floceal->tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
        h->floceal->ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

        h->floceal->floorX += floorStepX;
        h->floceal->floorY += floorStepY;

        // choose texture and draw the pixel

        // floor
        h->floceal->color = h->tex[3][h->tex[3]->width * ty + tx];
        h->floceal->color = (color >> 1) & 8355711; // make a bit darker
        h->img[y][x] = h->floceal->co lor;

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        h->floceal->color = texture[6][texWidth * ty + tx];
        h->floceal->color = (h->floceal->color >> 1) & 8355711; // make a bit darker
        h->img[screenHeight - y - 1][x] = h->floceal->color;
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
    h->floceal->rayDirX0 = dirX - planeX;
    h->floceal->rayDirY0 = dirY - planeY;
    h->floceal->rayDirX1 = dirX + planeX;
    h->floceal->rayDirY1 = dirY + planeY;

      // Current y position compared to the center of the screen (the horizon)
    h->floceal->p = y - screenHeight / 2;

      // Vertical position of the camera.
    h->floceal->posZ = 0.5 * screenHeight;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
   h->floceal->rowDistance = posZ / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
    h->floceal->floorStepX = rowDistance * (rayDirX1 - rayDirX0) / screenWidth;
    h->floceal->floorStepY = rowDistance * (rayDirY1 - rayDirY0) / screenWidth;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
    h->floceal->floorX = posX + rowDistance * rayDirX0;
    h->floceal->floorY = posY + rowDistance * rayDirY0;

    ft_helper(h);
    y++;
  }
}