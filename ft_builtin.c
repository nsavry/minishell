#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"

int		ft_cd(char **cmd, char ***env)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

	if (cmd[1] == NULL)
		tmp = ft_env_by_index(*env, ft_search_env(*env, "HOME"));
	else if (ft_strcmp(cmd[1], "-") == 0)
		tmp = ft_env_by_index(*env, ft_search_env(*env, "OLDPWD"));
	else
		tmp = ft_strdup(cmd[1]);
	if (chdir(tmp) == 0)
	{
		free(tmp);
		i = ft_search_env(*env, "OLDPWD");
		j = ft_search_env(*env, "PWD");
		tmp = *((*env) + i);
		tmp2 = ft_env_by_index(*env, j);
		*((*env) + i) = ft_build_var("OLDPWD", tmp2);
		free(tmp);
		free(tmp2);
		tmp = *((*env) + j);
		tmp2 = getcwd(NULL, 0);
		*((*env) + j) = ft_build_var("PWD", tmp2);
		free(tmp2);
	}
	else
		ft_printf("cd: file not found: %s\n", cmd[1]);
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
	}
	else
		ft_printf("setenv: arguments invalid\nUsage: setenv var value\n");
	return (2);
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
