/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:06:21 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/29 21:38:15 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "color.h"

void	put_gradient(mlx_image_t *img, t_color a, t_color b)
{
	uint32_t	i;
	uint32_t	size;
	t_color		c;

	i = 0;
	size = img->width * img->height;
	while (i < size)
	{
		c = lerp(a, b, (double)i / size);
		mlx_put_pixel(img, i % img->width, i / img->width, c.value);
		i++;
	}
}
