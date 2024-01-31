/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:01:07 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/31 03:43:47 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "error.h"
#include "game.h"
#include "utils/file.h"
#include "window.h"
#include <stdlib.h>

#define FILE_EXTENSION ".ber"

int32_t	main(int32_t argc, const char *argv[])
{
	mlx_t	*mlx;

	if (argc != 2)
		error_( "Usage: ./so_long <map>" );
	if (!check_extension(argv[1], FILE_EXTENSION))
		error_("Error\nInvalid file extension.");
	mlx = mlx_init(WIDTH, HEIGHT, TITLE, true);
	if (!mlx)
		error_(mlx_strerror(mlx_errno));
	init_game(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
