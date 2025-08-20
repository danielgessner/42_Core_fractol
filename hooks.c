/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:43:52 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 12:39:48 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_LEFT)
			f->shift_x -= SHIFT_STEP / f->zoom;
		if (keydata.key == MLX_KEY_RIGHT)
			f->shift_x += SHIFT_STEP / f->zoom;
		if (keydata.key == MLX_KEY_UP)
			f->shift_y -= SHIFT_STEP / f->zoom;
		if (keydata.key == MLX_KEY_DOWN)
			f->shift_y += SHIFT_STEP / f->zoom;
	}
	draw_fractal(f);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	f = param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= ZOOM_FACTOR;
	else if (ydelta < 0)
		f->zoom /= ZOOM_FACTOR;
	draw_fractal(f);
}
