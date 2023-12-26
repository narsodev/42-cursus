/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:11:56 by ngonzale          #+#    #+#             */
/*   Updated: 2022/06/22 22:44:20 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_is_wall(size_t i, char c)
{
	(void)i;
	return (c == '1');
}

int	char_is_position(size_t i, char c)
{
	(void)i;
	return (c == 'P');
}

int	char_is_exit(size_t i, char c)
{
	(void)i;
	return (c == 'E');
}

int	char_is_collectible(size_t i, char c)
{
	(void)i;
	return (c == 'C');
}

int	char_is_valid(size_t i, char c)
{
	(void)i;
	return (ft_strchr("01CEP", c) != NULL);
}
