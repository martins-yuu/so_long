/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:59:11 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/23 00:00:00 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "MLX42/MLX42.h"

# define WIDTH 720
# define HEIGHT 480
# define TITLE "So Long"

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}				t_data;

void			handle_keys(void *param);

#endif
