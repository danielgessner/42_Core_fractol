/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:51:06 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 11:21:24 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = tmp;
		i++;
	}
	return (color_from_iter(i));
}

int	julia(t_fractal *f, t_complex z)
{
	double	tmp;
	int		i;

	i = 0;
	while (z.re * z.re + z.im * z.im <= 4 && i < MAX_ITER)
	{
		tmp = z.re * z.re - z.im * z.im + f->c.re;
		z.im = 2 * z.re * z.im + f->c.im;
		z.re = tmp;
		i++;
	}
	return (color_from_iter(i));
}
