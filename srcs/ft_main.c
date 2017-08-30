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

int		main(int ac, char **av, char **env_o)
{
	char	**env;
	char	*pr;

	(void)ac;
	ft_signal();
	if (*env_o == NULL || !ft_check_env_integrity(&env))
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
