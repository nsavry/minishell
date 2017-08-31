/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 17:30:18 by nsavry            #+#    #+#             */
/*   Updated: 2017/08/28 17:30:20 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_prompt_user(char **str, char **env)
{
	int		i;
	char	*tmp;

	i = ft_search_env(env, "LOGNAME");
	if (i < 0) {
		ft_printf("anonymous");
	}
	else
	{
		tmp = ft_env_by_index(env, i);
		ft_printf("%s", tmp);
		free(tmp);
	}
}

void	ft_prompt_current(char **str, char **env)
{
	int		i;
	char	*tmp;
	char	**tab;

	i = ft_search_env(env, "PWD");
	tmp = ft_env_by_index(env, i);
	tab = ft_strsplit(tmp, '/');
	i = 0;
	while (tab[i] != NULL)
		i++;
	if (i == 0)
		ft_printf("/");
	else
		ft_printf("%s", tab[i - 1]);
	free(tmp);
	ft_free_tab(&tab);
}

void	ft_prompt_folder(char **str, char **env)
{
	int		i;
	char	*tmp;

	i = ft_search_env(env, "PWD");
	tmp = ft_env_by_index(env, i);
	ft_printf("%s", tmp);
	free(tmp);
}

void	ft_prompt_time(char **str, char **env)
{
	time_t t;
	struct tm tm;

	t = time(NULL);
	tm = *localtime(&t);
	ft_printf("%dh:%dm:%ds", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void	ft_prompt_date(char **str, char **env)
{
	time_t t;
	struct tm tm;

	t = time(NULL);
	tm = *localtime(&t);
	ft_printf("%d-%d-%d", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
}
