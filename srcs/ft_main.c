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
		if ((*cmd)[i][0] == 0)
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
	tmp = *cmd;
	*cmd = new;
	// ft_free_tab(&tmp);
}

void	ft_escape_dollar(char ***cmd, char **env)
{
	int		i;
	int		a;
	char	*tmp;

	i = 0;
	while ((*cmd)[i] != NULL)
	{
		if ((*cmd)[i][0] == '$')
		{
			a = ft_search_env(env, (*cmd)[i] + 1);
			if (a >= 0)
			{
				tmp = (*cmd)[i];
				(*cmd)[i] = ft_env_by_index(env, a);
				free(tmp);
			}
			else
			{
				tmp = (*cmd)[i];
				(*cmd)[i] = ft_strdup("");
				free(tmp);
			}
		}
		i++;
	}
	ft_delete_empty(cmd, 0, 0);
}

int		main(int ac, char **av, char **env_o)
{
	char	**env;
	char	*pr;

	(void)ac;
	if (*env_o == NULL)
		env = ft_build_env();
	else
		env = ft_tabdup(env_o);
	pr = ft_strdup("");
	while (1)
	{
		ft_generate_prompt(pr, env);
		if (ft_read_cmd(&env, av, 0, &pr) == 1)
			break ;
	}
	ft_printf("exit\n");
	ft_free(&pr);
	ft_free_tab(&env);
	return (0);
}
