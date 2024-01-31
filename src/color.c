/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:01:31 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/29 21:38:05 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "color.h"
#include <stdlib.h>

t_color	color(uint32_t v)
{
	return ((t_color){.value = v});
}

t_color	rgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return ((t_color){.red = r, .green = g, .blue = b, .alpha = a});
}

t_color	lerp(t_color a, t_color b, double t)
{
	t_color	c;

	c.red = a.red + (b.red - a.red) * t;
	c.green = a.green + (b.green - a.green) * t;
	c.blue = a.blue + (b.blue - a.blue) * t;
	c.alpha = a.alpha + (b.alpha - a.alpha) * t;
	return (c);
}
