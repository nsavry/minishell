/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:12:13 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/12 20:52:13 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_prompt(char *str, char *cmd, char **env)
{
	if (ft_strcmp(cmd, "user") == 0)
		ft_prompt_user(&str, env);				
	else if (ft_strcmp(cmd, "current") == 0)
		ft_prompt_current(&str, env);				
	else if (ft_strcmp(cmd, "folder") == 0)
		ft_prompt_folder(&str, env);				
	else if (ft_strcmp(cmd, "date") == 0)
		ft_prompt_date(&str, env);				
	else if (ft_strcmp(cmd, "time") == 0)
		ft_prompt_time(&str, env);				
	else if (ft_strcmp(cmd, "space") == 0)
		ft_printf("%c", ' ');
	else if (ft_strcmp(cmd, "dollar") == 0)
		ft_printf("%c", '$');
	else if (ft_strcmp(cmd, "chevron") == 0)
		ft_printf("%c", '>');
	else if (ft_strcmp(cmd, "modulo") == 0)
		ft_printf("%c", '%');
	else if (ft_strcmp(cmd, "colon") == 0)
		ft_printf("%c", ':');
	else if (ft_strcmp(cmd, "slash") == 0)
		ft_printf("%c", '/');
}

void	ft_generate_prompt(char *pr, char **env)
{
	char	**cmd;
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("");
	cmd = ft_strsplit(pr, ' ');
	if (pr[0] == 0)
		ft_printf("$> ");
	else
	{
		while (cmd[i])
		{
			ft_parse_prompt(str, cmd[i], env);
			i++;
		}
		ft_printf(" ");
	}
	free(str);
	ft_free_tab(&cmd);
}

void	ft_delete_empty(char ***cmd, int i, int len)
{
	char	**new;
	char	**tmp;

	while ((*cmd)[i] != NULL)
	{
		if ((*cmd)[i][0] != 0)
			len++;
		i++;
	}
	new = malloc(sizeof(char *) * (len + 1));
	i = 0;
	len = 0;
	while ((*cmd)[i] != NULL)
	{
		if ((*cmd)[i][0] != 0)
		{
			new[len] = ft_strdup((*cmd)[i]);
			len++;
		}
		i++;
	}
	new[len] = NULL;
	tmp = *cmd;
	*cmd = new;
	ft_free_tab(&tmp);
}
