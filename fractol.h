/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:10:34 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 13:24:15 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft_ex/src/libft.h"
# include "libft_ex/printf/ft_printf.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100
# define SHIFT_STEP 0.1
# define ZOOM_FACTOR 1.1

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			type;
	double		zoom;
	double		shift_x;
	double		shift_y;
	t_complex	c;
}	t_fractal;

// graphics
int		color_from_iter(int iter);
void	draw_fractal(t_fractal *f);
int		init_fractal(t_fractal *frac, int type);
int		init_julia_fractal(t_fractal *f, int type, char *s1, char *s2);
float	ft_atof(char *str);

// calculations
int		mandelbrot(t_complex c);
int		julia(t_fractal *f, t_complex z);

// hooks
void	key_hook(mlx_key_data_t keydata, void *param);
void	scroll_hook(double xdelta, double ydelta, void *param);

#endif