/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:14:20 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/02/03 18:17:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//cc *.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext
int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = ft_atodbl(argv[2]);
			fractal.julia_y = ft_atodbl(argv[3]);
		}
		ft_fractal_init(&fractal);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}