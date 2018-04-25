/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:03:46 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:48:03 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline __attribute__((always_inline)) void		rotate_left(t_rbtree *n)
{
	t_rbtree *new;

	new = n->right;
	n->right = new->left;
	new->left = n;
	new->parent = n->parent;
	n->parent = new;
}

inline __attribute__((always_inline)) void		rotate_right(t_rbtree *n)
{
	t_rbtree *new;

	new = n->left;
	n->left = new->right;
	new->right = n;
	new->parent = n->parent;
	n->parent = new;
}

inline __attribute__((always_inline)) t_rbtree	*n_sentinal(t_rbtree *parent)
{
	t_rbtree	*new;

	if (!(new = ft_memalloc(sizeof(t_rbtree))))
		return (NULL);
	new->parent = parent;
	return (new);
}
