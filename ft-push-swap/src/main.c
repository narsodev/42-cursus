/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:26:16 by ngonzale          #+#    #+#             */
/*   Updated: 2023/01/18 21:19:41 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	ft_is_ordered(t_container *container)
{
	t_stack	*tmp;

	if (container->stack_b)
		return (0);
	tmp = container->stack_a;
	while (tmp)
	{
		if (tmp->index != tmp->position)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_radix(t_container *container, int size)
{
	int	i;
	int	j;

	i = 0;
	while (!ft_is_ordered(container))
	{
		j = 0;
		while (j < size)
		{
			if (container->stack_a->index >> i & 1)
				ft_ra(container, 1);
			else
				ft_pb(container, 1);
			j++;
		}
		while (container->stack_b)
			ft_pa(container, 1);
		i++;
	}
}

void	ft_order(t_container *container, int size)
{
	if (size == 2)
	{
		if (!ft_is_ordered(container))
			ft_sa(container, 1);
	}
	else if (size == 3)
		ft_sort_three(container);
	else if (size == 5)
		ft_sort_five(container);
	else
		ft_radix(container, size);
}

int	ft_count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_container	*container;
	char		**strs;

	strs = ft_get_strs(argc, argv);
	if (!strs)
		return (EXIT_FAILURE);
	if (!strs[0])
	{
		free(strs);
		return (EXIT_FAILURE);
	}
	container = ft_create_container(strs);
	if (!container)
		return (ft_free_strs(strs), EXIT_FAILURE);
	if (!ft_is_ordered(container))
	{
		if (argc == 2)
			ft_order(container, ft_count_words(argv[1], ' '));
		else
			ft_order(container, argc - 1);
	}
	ft_free_strs(strs);
	ft_free_container(container);
	return (0);
}
