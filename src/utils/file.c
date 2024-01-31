/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:06:38 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/29 21:09:44 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdbool.h>

bool	check_extension(const char *filename, const char *extension)
{
	const char	*dot = ft_strrchr(filename, '.');

	return (dot && !ft_strncmp(dot, extension, ft_strlen(extension)));
}
