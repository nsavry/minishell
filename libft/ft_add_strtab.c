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

char	**ft_add_strtab(char **otab, char *str)
{
	int		i;
	char	**tab;

	i = 0;
	while (otab[i] != NULL)
		i++;
	tab = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (otab[i] != NULL)
	{
		tab[i] = ft_strdup(otab[i]);
		i++;
	}
	tab[i] = ft_strdup(str);
	tab[i + 1] = NULL;
	return (tab);
}
