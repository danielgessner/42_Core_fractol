/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgessner <dgessner@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:13:17 by dgessner          #+#    #+#             */
/*   Updated: 2025/06/14 12:39:12 by dgessner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	parse_sign(char *str, int i, int *sign)
{
	*sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

int	parse_int_part(char *str, int i, int *int_part)
{
	*int_part = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*int_part = *int_part * 10 + (unsigned)(str[i] - '0');
		i++;
	}
	return (i);
}

int	parse_frac_part(char *str, int i, float *frac_part, float *divisor)
{
	*frac_part = 0.0f;
	*divisor = 1.0f;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			*frac_part = *frac_part * 10.0f + (float)(str[i] - '0');
			*divisor = *divisor * 10.0f;
			i++;
		}
	}
	return (i);
}

float	ft_atof(char *str)
{
	int		i;
	int		sign;
	int		int_part;
	float	frac_part;
	float	divisor;

	i = 0;
	i = skip_whitespace(str, i);
	i = parse_sign(str, i, &sign);
	i = parse_int_part(str, i, &int_part);
	i = parse_frac_part(str, i, &frac_part, &divisor);
	return (sign * ((float)int_part + frac_part / divisor));
}
