/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:46:19 by ipetruni          #+#    #+#             */
/*   Updated: 2023/09/20 15:03:49 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* Write , Read , Close , Access, Pipe, Dup, Dup2, Execve, Fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* Malloc, Free , Exit*/
# include <stdlib.h>

/* Open, Unlink */
# include <fcntl.h>

/* Waitpid, Wait */
# include <sys/wait.h>

/* Strerror */
# include <string.h>

/* Perror */
# include <stdio.h>

/* Our Get Next Line Program */
# include "../gnl/get_next_line.h"

/* Some Error Definitions */
# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid amount of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*cmd;
	char	*paths;
	char	**cmd_path;
	char	**cmd_args;
}				t_pipex;

/* pipex_childs.c */

void	first_child(t_pipex pipex, char *argv[], char *env[]);
void	second_child(t_pipex pipex, char *argv[], char *env[]);

/* pipex_error.c */

int		msg(char *err);
void	msg_error(char *err);

/* pipex_free.c */

void	child_free(t_pipex *pipex);
void	parent_free(t_pipex *pipex);

/* functions */

char	*ft_strdup(char *src);
char	**ft_split(char *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif
