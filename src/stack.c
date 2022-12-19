/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:47:55 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/04 20:54:28by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_stack	*ft_create_stack_item(char *num_str, int position);
void	ft_assign_index(t_stack *stack, t_stack *item);
void	ft_free_stack(t_stack *stack);
int		ft_is_repeated(t_stack *stack, t_stack *item);

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

t_stack	*ft_create_stack(char **nums_strs)
{
	t_stack	*stack;
	t_stack	*stack_cur;
	t_stack	*stack_last;
	int		i;

	stack = ft_create_stack_item(nums_strs[0], 1);
	// check here
	stack_last = stack;
	i = 1;
	while (nums_strs[i])
	{
		stack_cur = ft_create_stack_item(nums_strs[i], i + 1);
		if (!stack_cur || ft_is_repeated(stack, stack_cur))
		{
			ft_putstr_fd("Error\n", 2);
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

t_stack	*ft_create_stack_item(char *num_str, int position)
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
	stack->position = position;
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

int	ft_is_repeated(t_stack *stack, t_stack *item)
{
	while (stack)
	{
		if (stack->value == item->value)
		{
			free(item);
			return (1);
		}
		stack = stack->next;
	}
	return (0);
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
