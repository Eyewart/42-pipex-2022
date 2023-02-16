/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:44 by Hassan            #+#    #+#             */
/*   Updated: 2023/02/16 14:39:04 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_getpath(char *cmd, char **envp)
{
	char	*path;
	char	*bin;
	char	*dir;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (cmd);
	path = envp[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = ft_strndup(path, ft_strichr(path, ':'));
		bin = ft_dirjoin(dir, cmd);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (cmd);
}

void	ft_exec(char *cmd, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(cmd, ' ');
	path = ft_getpath(args[0], envp);
	execve(path, args, envp);
	write(STDERR, "pipex: ", 7);
	write(STDERR, cmd, ft_strlen(cmd));
	write(STDERR, ": command not found\n", 20);
	exit(127);
}

void	ft_process(char *cmd, char **env)
{
	int		end[2];
	pid_t	pid;

	pipe(end);
	pid = fork();
	if (pid)
	{
		close(end[1]);
		dup2(end[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(end[0]);
		dup2(end[1], STDOUT_FILENO);
		ft_exec(cmd, env);
	}
}

int	ft_open(char *filename, int mode)
{
	if (mode == INFILE)
	{
		if (access(filename, F_OK))
		{
			write(STDERR, "pipex: ", 7);
			write(STDERR, "no such file or directory: ", 27);
			write(STDERR, filename, ft_strlen(filename));
			exit(1);
		}
		return (open(filename, O_RDONLY));
	}
	else
		return (open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644));
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
	{
		write(STDERR, "Invalid number of arguments.\n", 29);
		exit(1);
	}
	else
	{
		f1 = ft_open(argv[1], INFILE);
		f2 = ft_open(argv[4], OUTFILE);
		dup2(f1, STDIN_FILENO);
		dup2(f2, STDOUT_FILENO);
		ft_process(argv[2], envp);
		ft_exec(argv[3], envp);
	}
	return (1);
}
