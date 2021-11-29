#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>

# define HSIZE 5
# define VSIZE 3
# define WIDTH HSIZE * 64
# define HEIGHT VSIZE * 64
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

typedef struct s_i
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_i;

typedef struct s_params
{
	void	*mlx;
	void	*win;
	char	*map;
	int		mapx;
	int		mapy;
	int		beginx;
	int		beginy;
	int		playerx;
	int		playery;
	t_i		i;
}				t_params;

#endif