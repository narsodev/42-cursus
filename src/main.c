/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:16 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/29 22:03:26 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = ft_create_stack(argc - 1, argv + 1);
	if (!stack)
		return (1);
	ft_print_stack(stack);
	stack = ft_move_rotate(stack);
	ft_print_stack(stack);
	stack = ft_move_rotate_reverse(stack);
	ft_print_stack(stack);
	return (0);
}
