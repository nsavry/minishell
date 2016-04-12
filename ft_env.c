/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:13:31 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/07 21:14:06 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"

char	**ft_build_env(void)
{
	char	**env;
	char	*str;

	env = malloc(sizeof(char *) * 5);
	str = getcwd(NULL, 0);
	env[0] = ft_strdup("PATH=/bin:/usr/bin");
	env[1] = ft_strjoin("HOME=", str);
	env[2] = ft_strjoin("PWD=", str);
	env[3] = ft_strjoin("OLDPWD=", str);
	env[4] = NULL;
	ft_free(&str);
	return (env);
}

int		ft_search_env(char **env, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		tab = ft_strsplit(env[i], '=');
		if (ft_strcmp(tab[0], str) == 0)
		{
			ft_free_tab(&tab);
			return (i);
		}
		ft_free_tab(&tab);
		i++;
	}
	return (-1);
}

char	*ft_env_by_index(char **env, int i)
{
	char	**tab;
	char	*str;

	tab = ft_strsplit(env[i], '=');
	str = ft_strdup(tab[1]);
	ft_free_tab(&tab);
	return (str);
}

char	*ft_build_var(char *name, char *value)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = ft_strjoin(name, "=");
	tmp2 = ft_strjoin(tmp1, value);
	free(tmp1);
	return (tmp2);
}

char	**ft_build_path(char **env)
{
	char	**tab;
	char	**path;
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		tab = ft_strsplit(env[i], '=');
		if (ft_strcmp(tab[0], "PATH") == 0)
			break ;
		i++;
		ft_free_tab(&tab);
	}
	path = ft_strsplit(tab[1], ':');
	ft_free_tab(&tab);
	return (path);
}
