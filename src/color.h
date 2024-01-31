/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:01:27 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/29 21:37:10 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "MLX42/MLX42.h"

typedef union u_color
{
	uint32_t	value;
	struct
	{
		uint8_t	alpha;
		uint8_t	blue;
		uint8_t	green;
		uint8_t	red;
	};
}				t_color;

t_color			color(uint32_t v);
t_color			rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
t_color			lerp(t_color a, t_color b, double t);

#endif
