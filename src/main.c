/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:16 by ngonzale          #+#    #+#             */
/*   Updated: 2022/12/19 19:15:50 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_print_container(t_container *container)
{
	ft_printf("\nA: %d elements\n", container->count_a);
	ft_print_stack(container->stack_a);
	ft_printf("\nB: %d elements\n", container->count_b);
	ft_print_stack(container->stack_b);
}

void	ft_step1(t_container *container)
{
	while (container->stack_a && container->stack_a->next
		&& container->stack_a->next->next
		&& container->stack_a->next->next->next)
	{
		// TODO: posible fallo
		if (container->stack_a->index < (container->count_a + container->count_b) / 2 + (container->count_a + container->count_b) % 2)
			ft_pb(container, 1);
		else
			ft_ra(container, 1);
	}
}

int	main(int argc, char **argv)
{
	t_container	*container;
	char		**strs;

	strs = ft_get_strs(argc, argv);
	if (!strs)
		return (1);
	container = ft_create_container(strs);
	ft_print_container(container);
	ft_step1(container);
	ft_printf("everything except 3 pushed to b\n");
	ft_printf("order a\n");
	ft_print_container(container);
	return (0);
}
