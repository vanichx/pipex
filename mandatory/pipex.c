/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:45:55 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 15:05:31 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_path(char **env)
{
	while(ft_strncmp("PATH=", *env, 5))
		env++;
	return (*env + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipex pipex;
	
	if (argc != 5)
		return (msg(ERR_INPUT));
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		msg_error(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (pipex.outfile < 0)
		msg_error(ERR_OUTFILE);
	if (pipe(pipex.tube) < 0)
		msg_error(ERR_PIPE);
	pipex.paths = find_path(env);
	printf("Pipex paths :%s\n", pipex.paths);//DEBUG//
	pipex.cmd_path = ft_split(pipex.paths, ':');
	printf("Pipex cmd.path :%s\n", pipex.paths);//DEBUG//
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		first_child(pipex, argv, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		second_child(pipex, argv, env);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}
