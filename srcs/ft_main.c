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
			if (ft_strcmp(cmd[i], "user") == 0)
				ft_prompt_user(&str, env);				
			else if (ft_strcmp(cmd[i], "current") == 0)
				ft_prompt_current(&str, env);				
			else if (ft_strcmp(cmd[i], "folder") == 0)
				ft_prompt_folder(&str, env);				
			else if (ft_strcmp(cmd[i], "date") == 0)
				ft_prompt_date(&str, env);				
			else if (ft_strcmp(cmd[i], "time") == 0)
				ft_prompt_time(&str, env);				
			else if (ft_strcmp(cmd[i], "space") == 0)
				ft_printf("%c", ' ');
			else if (ft_strcmp(cmd[i], "dollar") == 0)
				ft_printf("%c", '$');
			else if (ft_strcmp(cmd[i], "chevron") == 0)
				ft_printf("%c", '>');
			else if (ft_strcmp(cmd[i], "modulo") == 0)
				ft_printf("%c", '%');
			else if (ft_strcmp(cmd[i], "colon") == 0)
				ft_printf("%c", ':');
			else if (ft_strcmp(cmd[i], "slash") == 0)
				ft_printf("%c", '/');
			i++;
		}
		ft_printf(" ");
	}
	free(str);
	ft_free_tab(&cmd);
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
