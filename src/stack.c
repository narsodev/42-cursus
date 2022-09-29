/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:55 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/29 22:03:11 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*ft_create_stack_item(char *num_str);
void	ft_assign_index(t_stack *stack, t_stack *item);
void	ft_free_stack(t_stack *stack);

void	ft_print_stack(t_stack *stack)
{
	t_stack	*stack_cur;

	ft_printf("Stack contains:\n");
	stack_cur = stack;
	ft_printf("\tvalue:\t");
	while (stack_cur)
	{
		ft_printf("\t%d", stack_cur->value);
		stack_cur = stack_cur->next;
	}
	ft_printf("\n\tindex:\t");
	stack_cur = stack;
	while (stack_cur)
	{
		ft_printf("\t[%d]", stack_cur->index);
		stack_cur = stack_cur->next;
	}
	stack_cur = stack;
	ft_printf("\n\tposition:");
	while (stack_cur)
	{
		ft_printf("\t<%d>", stack_cur->position);
		stack_cur = stack_cur->next;
	}
	ft_printf("\n");
}

t_stack	*ft_create_stack(int n_strs, char **nums_strs)
{
	t_stack	*stack;
	t_stack	*stack_cur;
	t_stack	*stack_last;
	int		i;

	stack = ft_create_stack_item(nums_strs[0]);
	stack_last = stack;
	i = 1;
	while (i < n_strs)
	{
		stack_cur = ft_create_stack_item(nums_strs[i]);
		if (!stack_cur)
		{
			ft_free_stack(stack);
			return (NULL);
		}
		ft_assign_index(stack, stack_cur);
		stack_last->next = stack_cur;
		stack_last = stack_last->next;
		i++;
	}
	return (stack);
}

t_stack	*ft_create_stack_item(char *num_str)
{
	t_stack	*stack;
	int		n;

	n = ft_atoi(num_str);
	if (!check_num(n, num_str))
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->value = n;
	stack->index = 1;
	stack->position = 0;
	return (stack);
}

void	ft_assign_index(t_stack *stack, t_stack *item)
{
	while (stack && stack != item)
	{
		if (stack->value > item->value)
			stack->index += 1;
		else
			item->index += 1;
		stack = stack->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_stack	*next;
	t_stack	*stack_cur;

	stack_cur = stack;
	while (stack_cur)
	{
		next = stack_cur->next;
		free(stack_cur);
		stack_cur = next;
	}
}
