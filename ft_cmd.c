/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:11:28 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/12 20:24:55 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

int		ft_check_cmd(char **path, char **cmd, char *cmd_i)
{
	struct stat	*buf;
	int			i;

	i = 0;
	buf = malloc(sizeof(struct stat));
	if (cmd[0][0] == '/' || (cmd[0][0] == '.' && cmd[0][1] == '/'))
	{
		if (stat(*cmd, buf) != 0)
			i = -1;
	}
	else
		i = ft_found_cmd(path, cmd, cmd_i);
	free(buf);
	if (path[i] == NULL)
		return (-1);
	return (i);
}

int		ft_found_cmd(char **path, char **cmd, char *cmd_i)
{
	char		*tmp;
	struct stat	*buf;
	int			i;

	i = 0;
	buf = malloc(sizeof(struct stat));
	while (path[i])
	{
		tmp = *cmd;
		*cmd = ft_strjoin("/", cmd_i);
		ft_free(&tmp);
		tmp = *cmd;
		*cmd = ft_strjoin(path[i], tmp);
		ft_free(&tmp);
		if (stat(*cmd, buf) == 0)
			break ;
		i++;
	}
	free(buf);
	return (i);
}

void	ft_fork_cmd(char **cmd)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd[0], cmd, NULL);
		exit(0);
	}
	wait(NULL);
}

int		ft_exec(char ***env, char *line, char **av)
{
	char	**cmd;
	char	**path;
	char	*cmd_i;
	int		ret;

	cmd = ft_strsplit(line, ' ');
	if (cmd[0] == NULL)
	{
		ft_free_tab(&cmd);
		return (0);
	}
	if ((ret = ft_builtin(&cmd, env)) == 1)
		return (1);
	else if (ret == 2)
		return (0);
	cmd_i = ft_strdup(cmd[0]);
	path = ft_build_path(*env);
	if (ft_check_cmd(path, &cmd[0], cmd_i) < 0)
		ft_printf("%s: command not found: %s\n", av[0], cmd_i);
	else
		ft_fork_cmd(cmd);
	ft_free(&cmd_i);
	ft_free_tab(&path);
	ft_free_tab(&cmd);
	return (0);
}

int		ft_read_cmd(char ***env, char **av, int i)
{
	int		ret;
	char	*line;

	ft_printf("$> ");
	ret = ft_get_next_line(0, &line);
	if (!line || ret == -1 || ret == 0)
	{
		ft_free(&line);
		return (1);
	}
	while (line[i++])
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
	if (line[0] != 0)
	{
		if (ft_exec(env, line, av))
		{
			ft_free(&line);
			return (1);
		}
	}
	ft_free(&line);
	return (0);
}
