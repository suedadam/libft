/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:37:26 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:48:34 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline __attribute__((always_inline)) void			do_case1(t_rbtree *n)
{
	if (!parent(n))
		n->color = 0;
}

inline __attribute__((always_inline)) void			do_case3(t_rbtree *n)
{
	t_rbtree	*g;
	t_rbtree	*p;
	t_rbtree	*u;

	if (!(g = grandparent(n)))
		return ;
	p = parent(n);
	u = uncle(n);
	p->color = 0;
	u->color = 0;
	g->color = 1;
	repair_tree(g);
}

static __attribute__((always_inline)) inline void	do_caes4_s2(t_rbtree *n)
{
	t_rbtree	*p;
	t_rbtree	*g;

	p = parent(n);
	g = grandparent(n);
	if (n == p->left)
		rotate_right(g);
	else
		rotate_left(g);
	p->color = 0;
	g->color = 1;
}

inline __attribute__((always_inline)) void			do_case4(t_rbtree *n)
{
	t_rbtree	*p;
	t_rbtree	*g;

	p = parent(n);
	g = grandparent(n);
	if (n == g->left->right)
	{
		rotate_left(p);
		n = n->left;
	}
	else if (n == g->right->left)
	{
		rotate_right(p);
		n = n->right;
	}
	do_caes4_s2(n);
}
