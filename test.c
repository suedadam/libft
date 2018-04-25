/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:34:05 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:45:20 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */

void print_tree(t_rbtree *tree)
{
	if (!tree)
	{
		printf("Leaf\n");
		return ;
	}
	if (!tree->content)
	{
		if (tree->color)
			printf("red");
		printf("(%d) Sentinal node\n", (tree->parent) ? *(int *)tree->parent->content : -123);
		printf(RESET);
		return ;
	}
	if (tree->color)
		printf(RED);
	printf("content -> %d\n", *(int *)tree->content);
	printf(RESET);
	printf("\t left -> ");
	print_tree(tree->left);
	printf("\t right -> ");
	print_tree(tree->right);
}

void	print_start(t_rbtree *tree)
{
	t_rbtree *parent;

	if (!(parent = tree->parent))
		printf("Top = %d\n", *(int *)tree->content);
	while (parent->parent)
	{
		parent = parent->parent;
	}
	printf("Top = %d\n", *(int *)parent->content);
	printf("Right = %d\n", *(int *)parent->right->content);
}

int	main(void)
{
	int 		*content;
	t_rbtree	*tree;

	if (!(content = malloc(sizeof(int))))
	{
		printf("Failed to allocate int %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	*content = 1;
	if (!(tree = ft_rbnew(content)))
	{
		printf("Failed to create tree %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (!(content = malloc(sizeof(int))))
	{
		printf("Failed to allocate int %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	*content = 3;
	if (ft_rbinsert(&tree, content, NULL) == EXIT_FAILURE)
	{
		printf("Failed to add to tree %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (!(content = malloc(sizeof(int))))
	{
		printf("Failed to allocate int %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	*content = 23;
	if (ft_rbinsert(&tree, content, NULL) == EXIT_FAILURE)
	{
		printf("Failed to add to tree %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (!(content = malloc(sizeof(int))))
	{
		printf("Failed to allocate int %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	*content = -1;
	if (ft_rbinsert(&tree, content, NULL) == EXIT_FAILURE)
	{
		printf("Failed to add to tree %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	printf("All gucci!\n");
	// print_start(tree);
	printf("_BUT_ top ptr  = %d\n", *(int *)tree->content);
	print_tree(tree);
}