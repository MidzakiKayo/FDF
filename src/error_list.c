/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchytter <bchytter@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 06:30:58 by bchytter          #+#    #+#             */
/*   Updated: 2022/02/12 06:30:58 by bchytter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_error_fd(void)
{
	write(1, "error open file discriptor\n", 28);
	exit(EXIT_FAILURE);
}

void	error_argc(void)
{
	write(1, "error or problem with arguments\n", 33);
	exit(EXIT_FAILURE);
}

void	error_extension_map(void)
{
	write(1, "error extansion map. Check map on .FDF extansion\n", 50);
	exit(EXIT_FAILURE);
}

void	error_alloc(void)
{
	write(1, "error allocarion memmory\n", 26);
	exit(EXIT_FAILURE);
}
