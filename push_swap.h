/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:30:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/09/29 21:52:44 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack {
	int				value;
	int				index;
	int				position;
	struct s_stack	*next;
}				t_stack;

// Move
t_stack	*ft_move_rotate(t_stack *stack);
t_stack	*ft_move_rotate_reverse(t_stack *stack);

// Check
int		check_num(int n, char *num_str);

// Stack
t_stack	*ft_create_stack(int n_strs, char **nums_strs);
void	ft_print_stack(t_stack *stack);

// Sort
void	ft_sort_three(t_stack *s1);

#endif