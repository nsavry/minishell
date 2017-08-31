/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:12:30 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/12 20:50:44 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_builtin(char ***cmd, char ***env, char **pr, char *line)
{
	int		i;

	i = 0;
	if (ft_strcmp(**cmd, "exit") == 0)
		i = 1;
	else if (ft_strcmp(**cmd, "cd") == 0)
		i = ft_cd(*cmd, env);
	else if (ft_strcmp(**cmd, "env") == 0)
		i = ft_env(*cmd, *env);
	else if (ft_strcmp(**cmd, "setenv") == 0)
		i = ft_setenv(*cmd, env);
	else if (ft_strcmp(**cmd, "unsetenv") == 0)
		i = ft_unsetenv(*cmd, env);
	else if (ft_strcmp(**cmd, "setprompt") == 0)
		i = ft_setprompt(line, *env, pr);
	if (i)
		ft_free_tab(cmd);
	return (i);
}

int		ft_cd(char **cmd, char ***env)
{
	char	*tmp;

	if (cmd[1] == NULL)
		tmp = ft_env_by_index(*env, ft_search_env(*env, "HOME"));
	else if (ft_strcmp(cmd[1], "-") == 0)
		tmp = ft_env_by_index(*env, ft_search_env(*env, "OLDPWD"));
	else
		tmp = ft_strdup(cmd[1]);
	if (tmp[0] == 0)
		ft_printf("cd: HOME or OLDPWD are not set correctly"\
			"in environment variable\n");
	else
	{
		if (chdir(tmp) == 0)
			ft_cd_two(env);
		else
			ft_printf("cd: file not found: %s\n", cmd[1]);	
	}
	free(tmp);
	return (2);
}

int		ft_env(char **cmd, char **env)
{
	if (cmd[1] != NULL)
		ft_printf("env: arguments invalide -- \"%s\"\n", cmd[1]);
	else
		ft_put_str_tab(env);
	return (2);
}

int		ft_setenv(char **cmd, char ***env)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	**ttmp;

	if (cmd[1] != NULL && cmd[2] != NULL && cmd[3] == NULL)
	{
		tmp = ft_strjoin(cmd[1], "=");
		if ((i = ft_search_env(*env, cmd[1])) >= 0)
		{
			free(*((*env) + i));
			*((*env) + i) = ft_strjoin(tmp, cmd[2]);
		}
		else
		{
			ttmp = *env;
			tmp2 = ft_strjoin(tmp, cmd[2]);
			*env = ft_add_strtab(ttmp, tmp2);
			free(tmp2);
			ft_free_tab(&ttmp);
		}
		free(tmp);
		return (2);
	}
	return (ft_printf("setenv: error\nUsage: setenv var value\n") - 36);
}

int		ft_unsetenv(char **cmd, char ***env)
{
	char	**ttmp;
	int		i;

	if (cmd[1] != NULL && cmd[2] == NULL)
	{
		if ((i = ft_search_env(*env, cmd[1])) >= 0)
		{
			ttmp = *env;
			*env = ft_remove_index_strtab(ttmp, i);
			ft_free_tab(&ttmp);
			ft_env_integrity(env);
		}
		else
			ft_printf("unsetenv: %s not found\n", cmd[1]);
	}
	else
		ft_printf("unsetenv: arguments invalid\nUsage: unsetenv var\n");
	return (2);
}
