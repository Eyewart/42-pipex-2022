/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:50 by Hassan            #+#    #+#             */
/*   Updated: 2023/02/16 14:42:12 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h> //TO DELETE

# define INFILE 0
# define OUTFILE 1
# define STDERR 2

char	*ft_getpath(char *cmd, char **envp);
void	ft_exec(char *cmd, char **envp);
void	ft_process(char *cmd, char **env);
int		ft_open(char *filename, int mode);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *c);
int		ft_strichr(char *s, char c);
char	*ft_dirjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strndup(char	*str1, int n);

#endif