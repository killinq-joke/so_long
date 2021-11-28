#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>

# define WIDTH 9 * 64
# define HEIGHT 7 * 64

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
	t_i		i;
}				t_params;

#endif