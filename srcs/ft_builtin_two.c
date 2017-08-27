/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 19:58:58 by nsavry            #+#    #+#             */
/*   Updated: 2017/08/26 16:47:38 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

void	ft_cd_two(char ***env)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;

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
	free(tmp);
}

int		ft_setenv_two(void)
{
	ft_printf("setenv: arguments invalid\nUsage: setenv var value\n");
	return (2);
}
