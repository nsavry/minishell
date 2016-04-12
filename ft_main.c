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

#include "libft.h"
#include "minishell.h"

int		main(int ac, char **av, char **env_o)
{
	char	**env;

	(void)ac;
	if (*env_o == NULL)
		env = ft_build_env();
	else
		env = ft_tabdup(env_o);
	while (1)
	{
		if (ft_read_cmd(&env, av) == 1)
			break ;
	}
	ft_free_tab(&env);
	return (0);
}
