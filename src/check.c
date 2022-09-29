/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:50:15 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/29 21:56:14 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_num(int n, char *num_str)
{
	size_t	str_len;
	size_t	i;

	if (*num_str != '-' && !ft_isdigit(*num_str))
		return (0);
	str_len = ft_strlen(num_str);
	if (*num_str == '-' && str_len > 11)
		return (0);
	if (str_len > 10)
		return (0);
	i = 1;
	while (ft_isdigit(num_str[i]))
		i++;
	if (i != str_len)
		return (0);
	if ((n > 0 && *num_str == '-')
		|| (n < 0 && ft_isdigit(*num_str)))
		return (0);
	return (1);
}
