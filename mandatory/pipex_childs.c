/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:56:10 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 15:05:57 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char *tmp;
	char *command;
	
	while(*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		paths++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char *argv[], char *env[])
{
	//pipex.tube[0](read end) pipex.tube[1] (write end)
	dup2(pipex.tube[1], STDOUT_FILENO); //redirecting the STDOUT to the write end of pipe
	close(pipex.tube[0]);//closing read end of pipe because we dont need it anymore
	dup2(pipex.infile, 0);//redirecting the STDIN to the read end of pipe
	pipex.cmd_args = ft_split(argv[2], ' ');//extract the commands from second argument
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);//get the cmd path
	if (!pipex.cmd)//if no just free and exit with err code
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, env);//executing needed command in needed directory
}

void	second_child(t_pipex pipex, char *argv[], char *env[])
{
	//pipex.tube[0](read end) pipex.tube[1] (write end)
	dup2(pipex.tube[0], STDIN_FILENO);//redirecting the STDIN to the read end of pipe
	close(pipex.tube[1]);//closing write end of pipe because we dont need it anymore
	dup2(pipex.outfile, 1);//redirecting the STDOUT to the write end of pipe
	pipex.cmd_args = ft_split(argv[3], ' ');//extract the commands from third argument
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);//get the cmd path
	if (!pipex.cmd)//if no just free and exit with err code
	{
		child_free(&pipex);
		msg(ERR_CMD);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, env);//executing needed command in needed directory
}