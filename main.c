#include "solong.h"

void	putpix(t_i *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	initplayer(t_params *p)
{
	int	y;
	int	x;

	y = 0;
	while (y < p->mapy)
	{
		x = 0;
		while (x < p->mapx)
		{
			if (p->map[y * p->mapx + x] == 'P')
			{
				p->playerx = x;
				p->playery = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	destroy(t_params *p)
{
	mlx_destroy_image(p->mlx, p->i.img);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}

void	printsquare(t_params *p, int x, int y)
{
	int		i;
	int		j;
	char	currentsquare;

	if (p->beginy + y < 0 || p->beginx + x < 0 || p->beginy + y >= p->mapy || p->beginx + x >= p->mapx)
		currentsquare = '1';
	else
	{
		currentsquare = p->map[(p->beginy + y) * p->mapx + p->beginx + x];
	}
	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			if (y == VSIZE / 2 && x == HSIZE / 2)
				putpix(&p->i, x * 64 + j, y * 64 + i, 0x0000FF);
			else if (currentsquare == 'E')
				putpix(&p->i, x * 64 + j, y * 64 + i, 0xFF00FF);
			else if (currentsquare == 'C')
				putpix(&p->i, x * 64 + j, y * 64 + i, 0xFFFF00);
			else if (currentsquare == '1')
				putpix(&p->i, x * 64 + j, y * 64 + i, 0x000000);
			else
				putpix(&p->i, x * 64 + j, y * 64 + i, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

int	printmap(t_params *p)
{
	int y;
	int x;

	p->beginy = p->playery - VSIZE / 2;
	printf("\n");
	y = 0;
	while (y < VSIZE)
	{
		p->beginx = p->playerx - HSIZE / 2;
		x = 0;
		while (x < HSIZE)
		{
			printsquare(p, x, y);
			x++;
		}
		y++;
		printf("\n");
	}
	mlx_put_image_to_window(p->mlx, p->win, p->i.img, 0, 0);
	return (1);
}

int	keyhandler(int key, t_params *p)
{
	if (key == W)
	{
		if (p->map[(p->playery - 1) * p->mapx + p->playerx] != '1')
			p->playery -= 1;
	}
	if (key == S)
	{
		if (p->map[(p->playery + 1) * p->mapx + p->playerx] != '1')
			p->playery += 1;
	}
	if (key == A)
	{
		if (p->map[p->playery * p->mapx + p->playerx - 1] != '1')
			p->playerx -= 1;
	}
	if (key == D)
	{
		if (p->map[p->playery * p->mapx + p->playerx + 1] != '1')
			p->playerx += 1;
	}
	else if (key == ESC)
	{
		destroy(p);
	}
	printmap(p);
	return (1);
}

int main(void)
{
	t_params p;
	char	map[] = {
		'1','1','1','1','1','1','1','1',
		'1','0','1','0','0','0','0','1',
		'1','0','1','C','0','0','0','1',
		'1','0','1','0','0','0','0','1',
		'1','0','0','E','0','0','0','1',
		'1','0','0','P','0','1','0','1',
		'1','0','0','0','0','0','0','1',
		'1','1','1','1','1','1','1','1', 0
	};
	p.map = map;
	p.mapx = 8;
	p.mapy = 8;
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "so_long");
	p.i.img = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.i.addr = mlx_get_data_addr(p.i.img, &p.i.bits_per_pixel, &p.i.line_length, &p.i.endian);
	initplayer(&p);
	printmap(&p);
	mlx_hook(p.win, 17, 0L, destroy, &p);
	mlx_hook(p.win, 02, (1L<<0), keyhandler, &p);
	mlx_loop(p.mlx);
	return (0);
}