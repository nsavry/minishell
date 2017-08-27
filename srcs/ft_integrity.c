/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integrity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:12:08 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/07 21:12:08 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

void	ft_env_integrity(char ***env)
{
	if (ft_search_env(*env, "PATH") == -1)
		ft_build_var_path(env);
	if (ft_search_env(*env, "PWD") == -1)
		ft_build_var_pwd(env, "PWD");
	if (ft_search_env(*env, "OLDPWD") == -1)
		ft_build_var_pwd(env, "OLDPWD");
	if (ft_search_env(*env, "HOME") == -1)
		ft_build_var_pwd(env, "HOME");
}

void	ft_build_var_path(char ***env)
{
	char	**ttmp;

	ttmp = *env;
	*env = ft_add_strtab(ttmp, "PATH=/bin:/usr/bin");
	ft_free_tab(&ttmp);
}

void	ft_build_var_pwd(char ***env, char *str)
{
	char	**ttmp;
	char	*tmp1;
	char	*tmp2;

	ttmp = *env;
	tmp1 = ft_strjoin(str, "=");
	tmp2 = ft_strjoin(tmp1, getcwd(NULL, 0));
	*env = ft_add_strtab(ttmp, tmp2);
	free(tmp1);
	free(tmp2);
	ft_free_tab(&ttmp);
}
