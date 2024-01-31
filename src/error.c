/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:01:15 by yuuko             #+#    #+#             */
/*   Updated: 2024/01/23 00:01:16 by yuuko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdlib.h>
#include <unistd.h>

void	error_(const char *msg)
{
	ft_putendl_fd((char *)msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
