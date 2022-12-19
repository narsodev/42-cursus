/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:32:17 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/18 21:09:59 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

int	ft_count_stack(t_stack *stack);

t_container	*ft_create_container(char **strs)
{
	t_container	*container;

	container = ft_calloc(1, sizeof(t_container));
	if (!container)
		return (NULL);
	container->stack_a = ft_create_stack(strs);
	if (!container->stack_a)
	{
		free(container);
		return (NULL);
	}
	container->count_a = ft_count_stack(container->stack_a);
	container->count_b = 0;
	return (container);
}

int	ft_count_stack(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
