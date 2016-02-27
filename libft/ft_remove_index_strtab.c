/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <nsavry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:24 by nsavry            #+#    #+#             */
/*   Updated: 2014/04/26 14:06:14 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_remove_index_strtab(char **otab, int index)
{
	char	**tab;
	int		i;

	i = 0;
	while (otab[i] != NULL)
		i++;
	tab = malloc(sizeof(char *) * i);
	i = 0;
	while (i < index)
	{
		tab[i] = ft_strdup(otab[i]);
		i++;
	}
	while (otab[i + 1] != NULL)
	{
		tab[i] = ft_strdup(otab[i + 1]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
