/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 23:42:21 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/01 14:18:16 by jpedro-f         ###   ########.fr       */
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