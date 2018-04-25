/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_family.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:00:29 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:47:40 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

inline __attribute__((always_inline)) void			*parent(t_rbtree *n)
{
	return (n->parent);
}

inline __attribute__((always_inline)) void			*grandparent(t_rbtree *n)
{
	t_rbtree *p;

	if (!(p = parent(n)))
		return (NULL);
	return (parent(p));
}

inline __attribute__((always_inline)) void			*sibling(t_rbtree *n)
{
	t_rbtree *p;

	if (!(p = parent(n)))
		return (NULL);
	if (n == p->left)
		return (p->right);
	return (p->left);
}

inline __attribute__((always_inline)) void			*uncle(t_rbtree *n)
{
	t_rbtree *p;
	t_rbtree *g;

	if (!(p = parent(n)))
		return (NULL);
	if (!(g = grandparent(n)))
	{
		printf(RED "Failed to find Grandparent\n" RESET);
		return (NULL);
	}
	printf(RED "Got here tho\n" RESET);
	return (sibling(p));
}
