/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hassan <hrifi-la@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 17:54:44 by Hassan            #+#    #+#             */
/*   Updated: 2023/02/04 01:10:56 by Hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESIGN
file1 cmd1 cmd2 file2

-arg main() != 5 : ft_exit()
-read infile & store 
-dup2(infile, stdin)
-dup2(outfile, stdout)
-ft_fork (pipe, fork, ..)
 -pipe creation
 -fork()
 -for parent: -close(pipefd[1]), -dup2(pipe_end[1], STDIN), -waitpid()
 -for child: -close(pipefd[0]), -dup2(pipe_end[0], STDOUT)
-ft_exec
 -ft_split for args
 -findPath
 -dup2(pipe_end[0], STDIN_FILEN0)
 -exceve();
-access() function to verify if the cmd exists
*/

 #include "pipex.h"

void	ft_exit(void)
{
	char	*str;

	str = "Error\n";
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_open()
{
	
}

void	ft_exec(int fd, char *cmd)
{
	
}

void	ft_process(char *cmd, char **env)
{
	int end[2];
	pid_t pid;
	
	pipe(end);
	pid = fork();
	if (pid)
	{
		close(end[1]); 
		dup(end[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(end[0]);
		dup(end[1], STDOUT_FILENO);
		ft_exec(cmd, env);
	}
}

int main	(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;

	if (argc != 5)
		ft_exit;
	f1 = ft_open(argv[1], O_RDONLY);
	f2 = ft_open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(f1, STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	ft_process(argv[2], envp);
	ft_exec(argv[3], envp);
	return (0);
}