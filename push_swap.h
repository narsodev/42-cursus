/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:30:33 by ngonzale          #+#    #+#             */
/*   Updated: 2022/10/18 20:39:41 by ngonzale         ###   ########.fr       */
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

typedef struct s_container {
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count_a;
	int		count_b;
}				t_container;

// Move
void		ft_move_rotate(t_stack **stack);
void		ft_move_rotate_reverse(t_stack **stack);
void		ft_push(t_stack **src, t_stack **dst);
void		ft_swap(t_stack **stack);

// Move stacks
void		ft_pa(t_container *container, int print);
void		ft_pb(t_container *container, int print);
void		ft_sa(t_container *container, int print);
void		ft_sb(t_container *container, int print);
void		ft_ra(t_container *container, int print);
void		ft_rb(t_container *container, int print);
void		ft_rra(t_container *container, int print);
void		ft_rrb(t_container *container, int print);

// Check
int			check_num(int n, char *num_str);

// Input
char		**ft_get_strs(int argc, char **argv);

// Container
t_container	*ft_create_container(char **strs);

// Stack
t_stack		*ft_create_stack(char **nums_strs);
void		ft_print_stack(t_stack *stack);
void		ft_free_stack(t_stack *stack);

// Sort
void		ft_sort_three(t_container *container);

#endif