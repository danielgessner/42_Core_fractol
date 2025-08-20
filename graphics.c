/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 10:57:08 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 11:25:37 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_from_iter(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == MAX_ITER)
		return (0x000000FF);
	r = (iter * 23) % 256;
	g = (iter * 2) % 256;
	b = (iter * 6) % 256;
	return (r << 24 | g << 16 | b << 8 | 255);
}

static t_complex	pixel_to_complex(t_fractal *f, int x, int y)
{
	t_complex	c;
	double		scale;

	scale = 4.0 / WIDTH / f->zoom;
	c.re = (x - WIDTH / 2) * scale + f->shift_x;
	c.im = (y - HEIGHT / 2) * scale + f->shift_y;
	return (c);
}

void	draw_fractal(t_fractal *f)
{
	int			x;
	int			y;
	t_complex	c;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(f, x, y);
			if (f->type == 0)
				color = mandelbrot(c);
			else if (f->type == 1)
				color = julia(f, c);
			mlx_put_pixel(f->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	init_fractal(t_fractal *f, int type)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "dgessner 42 fract-ol", false);
	if (!f->mlx)
		return (1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (1);
	f->type = type;
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->c.re = -0.4;
	f->c.im = 0.6;
	return (0);
}

int	init_julia_fractal(t_fractal *f, int type, char *s1, char *s2)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "dgessner 42 fract-ol", false);
	if (!f->mlx)
		return (1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img || mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
		return (1);
	f->type = type;
	f->zoom = 1.0;
	f->shift_x = 0.0;
	f->shift_y = 0.0;
	f->c.re = ft_atof(s1);
	f->c.im = ft_atof(s2);
	return (0);
}
