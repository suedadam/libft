/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyed <asyed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 11:38:10 by asyed             #+#    #+#             */
/*   Updated: 2018/04/24 20:53:13 by asyed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*save;

	save = NULL;
	if (s && f)
	{
		new = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
		if (!new)
			return (save);
		ft_bzero(new, ft_strlen(s) + 1);
		save = new;
		while (*s)
			*new++ = f(*s++);
		*new = '\0';
	}
	return (save);
}
