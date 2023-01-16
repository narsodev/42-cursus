/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:13:16 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/01 13:15:30 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_get_strs(int argc, char **argv)
{
	char	**strs;
	int		i;
	int		j;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	strs = ft_calloc(argc, sizeof(char *));
	if (!strs)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
	{
		strs[i] = ft_strdup(argv[i + 1]);
		if (!strs[i])
		{
			j = -1;
			while (++j < i)
				free(strs[j]);
			return (free(strs), NULL);
		}
	}
	return (strs);
}
