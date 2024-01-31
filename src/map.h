/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 23:06:28 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/29 21:16:23 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "MLX42/MLX42.h"

typedef struct s_map
{
	char		**grid;
	uint32_t	width;
	uint32_t	height;
}				t_map;

t_map			parse_map(const char *str);

#endif
