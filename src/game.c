/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:17:44 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/31 06:40:35 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "color.h"
#include "error.h"
#include "render.h"
#include "window.h"

void	init_game(mlx_t *mlx)
{
	mlx_image_t	*image;
	mlx_image_t	*background;

	image = mlx_new_image(mlx, 16, 16);
	background = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!image || !background)
		error_(mlx_strerror(mlx_errno));
	put_gradient(background, color(0x000000FF), color(0x0000FFFF));
	put_gradient(image, color(0xFF00FFFF), color(0x000000FF));
	if (mlx_image_to_window(mlx, background, 0, 0) == -1)
		error_(mlx_strerror(mlx_errno));
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
		error_(mlx_strerror(mlx_errno));
	mlx_loop_hook(mlx, handle_keys, &(t_data){mlx, image});
	mlx_loop(mlx);
}
