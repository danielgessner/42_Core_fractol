/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:56:37 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 12:24:33 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_math(void)
{
	char	*s1;

	s1 = "Iterationsgleichung: z_{n+1} = z_n^2 + c";
	ft_printf("-------------------------------------------\n");
	ft_printf("%s\n", s1);
	ft_printf("-------------------------------------------\n");
	s1 = "For Mandelbrot: z_0 = 0 (always); c variiert";
	ft_printf("%s\n", s1);
	ft_printf("-------------------------------------------\n");
	s1 = "For Julia: z_0 variiert; c is always the same";
	ft_printf("%s\n c is definded by the two float values\n", s1);
	ft_printf("-------------------------------------------\n");
}

static void	print_error(char *s)
{
	ft_printf("-------------------------------------------\n");
	ft_printf("This Input is not possible: '%s'\n", s);
	ft_printf("-------------------------------------------\n");
	ft_printf("For Mandelbrot-Fractol write: 'mandelbrot'\n");
	ft_printf("For Julia-Fractol write: 'julia'\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("or modify Julia by adding two float values\n");
	ft_printf("e.g. 'julia 0.834 0.267'\n");
	ft_printf("-------------------------------------------\n");
}

static int	parse_args(t_fractal *f, int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc == 4 && ft_strncmp(argv[1], "julia", 6) == 0)
			return (init_julia_fractal(f, 1, argv[2], argv[3]));
		else
			return (1);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		return (init_fractal(f, 0));
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		return (init_fractal(f, 1));
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	frac;

	if (ft_strncmp(argv[1], "explain", 8) == 0)
	{
		print_math();
		return (0);
	}
	if (parse_args(&frac, argc, argv))
	{
		print_error(argv[1]);
		return (1);
	}
	draw_fractal(&frac);
	mlx_key_hook(frac.mlx, key_hook, &frac);
	mlx_scroll_hook(frac.mlx, scroll_hook, &frac);
	mlx_loop(frac.mlx);
	mlx_terminate(frac.mlx);
	return (0);
}
