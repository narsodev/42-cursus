/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:32:53 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/18 21:52:17 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_pa(t_container *container, int print)
{
	ft_push(&container->stack_b, &container->stack_a);
	// TODO: posible error en checker
	container->count_a++;
	container->count_b--;
	if (print)
		ft_printf("pa\n");
}

void	ft_pb(t_container *container, int print)
{
	ft_push(&container->stack_a, &container->stack_b);
	// TODO: posible error en checker
	container->count_b++;
	container->count_a--;
	if (print)
		ft_printf("pb\n");
}

void	ft_sa(t_container *container, int print)
{
	ft_swap(&container->stack_a);
	if (print)
		ft_printf("sa\n");
}

void	ft_sb(t_container *container, int print)
{
	ft_swap(&container->stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ft_ra(t_container *container, int print)
{
	ft_move_rotate(&container->stack_a);
	if (print)
		ft_printf("ra\n");
}

void	ft_rb(t_container *container, int print)
{
	ft_move_rotate(&container->stack_b);
	if (print)
		ft_printf("rb\n");
}

void	ft_rra(t_container *container, int print)
{
	ft_move_rotate_reverse(&container->stack_a);
	if (print)
		ft_printf("rra\n");
}

void	ft_rrb(t_container *container, int print)
{
	ft_move_rotate_reverse(&container->stack_b);
	if (print)
		ft_printf("rrb\n");
}
