/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redblack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:10:21 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:52:42 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
** Int comparison BST.
*/

int						default_bst(void *curr, void *newc)
{
	if (*(int *)newc >= *(int *)curr)
		return (1);
	return (0);
}

void					*ft_rbnew(void *content)
{
	t_rbtree *new;

	if (!(new = ft_memalloc(sizeof(t_rbtree))))
		return (NULL);
	new->content = content;
	if (!(new->right = n_sentinal(new)))
	{
		free(new);
		return (NULL);
	}
	if (!(new->left = n_sentinal(new)))
	{
		free(new->right);
		free(new);
		return (NULL);
	}
	return (new);
}

inline void				repair_tree(t_rbtree *n)
{
	t_rbtree	*p;
	t_rbtree	*u;

	if (!(p = parent(n)))
		do_case1(n);
	else if (!p->color)
		return ;
	else if ((u = uncle(n)) && u->color)
		do_case3(n);
	else
		do_case4(n);
}

static uint8_t			ft_rbadd(t_rbtree *tree, void *content,
								int (*bst)(void *curr, void *newc))
{
	if (!tree)
		return (EXIT_FAILURE);
	if (!bst)
		bst = &default_bst;
	if (!tree->content)
	{
		tree->content = content;
		tree->color = 1;
		if (!(tree->right = n_sentinal(tree)))
			return (EXIT_FAILURE);
		if (!(tree->left = n_sentinal(tree)))
			return (EXIT_FAILURE);
		repair_tree(tree);
		return (EXIT_SUCCESS);
	}
	if (bst(tree->content, content))
		return (ft_rbadd(tree->right, content, bst));
	else
		return (ft_rbadd(tree->left, content, bst));
}

/*
** BST should return 0 on left and 1 on right.
** Color = 1 for red.
** Color = 0 for black.
*/

uint8_t					ft_rbinsert(t_rbtree **tree, void *content,
							int (*bst)(void *curr, void *newc))
{
	t_rbtree	*tmp;
	uint8_t		res;

	if (!tree || !*tree || !content)
	{
		printf("Failed wtf? %p %p\n", tree, content);
		return (EXIT_FAILURE);
	}
	if ((res = ft_rbadd(*tree, content, bst)) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while ((tmp = parent(*tree)))
		*tree = tmp;
	return (res);
}
