/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:52:20 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/04 20:53:29 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_container *container)
{
	t_stack	*sa;
	int		v1;
	int		v2;
	int		v3;

	sa = container->stack_a;
	v1 = sa->value;
	v2 = sa->next->value;
	v3 = sa->next->next->value;
	if (v1 < v2 && v1 < v3)
	{
		ft_rra(container, 1);
		ft_sa(container, 1);
	}
	else if (v1 > v2 && v1 < v3)
		ft_sa(container, 1);
	else if (v1 < v2 && v1 > v3)
		ft_rra(container, 1);
	else if (v1 > v2 && v2 < v3)
		ft_ra(container, 1);
	else if (v1 > v2 && v2 > v3)
	{
		ft_ra(container, 1);
		ft_sa(container, 1);
	}
}
