/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsavry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 21:07:18 by nsavry            #+#    #+#             */
/*   Updated: 2016/04/12 20:48:57 by nsavry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

char	**ft_build_env(void);
int		ft_search_env(char **env, char *str);
char	*ft_env_by_index(char **env, int i);
char	*ft_build_var(char *name, char *value);
char	**ft_build_path(char **env);

int		ft_check_cmd(char **path, char **cmd, char *cmd_i);
int		ft_found_cmd(char **path, char **cmd, char *cmd_i);
void	ft_fork_cmd(char **cmd, char **env);
int		ft_exec(char ***env, char *line, char **av, char **pr);
int		ft_read_cmd(char ***env, char **av, int i, char **pr);

int		ft_builtin(char ***cmd, char ***env, char **pr);
int		ft_cd(char **cmd, char ***env);
int		ft_env(char **cmd, char **env);
int		ft_setenv(char **cmd, char ***env);
int		ft_unsetenv(char **cmd, char ***env);

void	ft_cd_two(char ***env);
int		ft_setenv_two(void);
int		ft_setprompt(char **cmd, char **env, char **pr);

void	ft_env_integrity(char ***env);
void	ft_build_var_path(char ***env);
void	ft_build_var_pwd(char ***env, char *str);

void	ft_generate_prompt(char *pr);

#endif