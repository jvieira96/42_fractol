/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:42:21 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/03 15:39:10 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Scales the image
 [0..800] -> [-2..+2]
*/
double	ft_map(double unscaled_num, double new_min, double new_max, double old_max)
{
	double	old_min;

	old_min = 0.0;
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

/*
	sum complex numbers
	vector addition
*/
t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

/*
	square complex numbers
	general formula : (x_real + y_imaginary)^2
					  (x + yi) * (x + yi)
					  x^2 + xyi + xyi + y^2 * i^2      (i^2 = -1)
					  x^2 + 2xyi - y^2
       real value <- (x^2 - y^2) + (2xyi) -> imaginary value
	real value = (x^2 - y^2)
	imaginary value = 2*x*y
*/
t_complex	ft_square_complex(t_complex	z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

double	ft_atodbl(char	*str)
{
	long	int_part;
	double	fractional_part;
	int		sign;
	double	power;

	power = 1;
	int_part = 0;
	fractional_part = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str<= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != '.' && *str)
	{
		int_part = (int_part * 10) + (*str - '0');
		str++;
	}	
	if (*str == '.')
		str++;
	while (*str)
	{
		power = power / 10;
		fractional_part = fractional_part + (*str - '0') * power;
		str++;
	}
	return((int_part + fractional_part) * sign);
}
