#include "solong.h"

int	destroy(t_params *p)
{
	mlx_destroy_image(p->mlx, p->i.img);
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}


int main(void)
{
	t_params p;

	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIDTH, HEIGHT, "so_long");
	p.i.img = mlx_new_image(p.mlx, WIDTH, HEIGHT);
	p.i.addr = mlx_get_data_addr(p.i.img, &p.i.bits_per_pixel, &p.i.line_length, &p.i.endian);
	mlx_hook(p.win, 17, 0L, destroy, &p);
	mlx_loop(p.mlx);
	return (0);
}