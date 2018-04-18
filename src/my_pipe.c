/*
** my_pipe.c for my_pipe in /home/Cisarius/delivery/PSU_2016_minishell2
** 
** Made by Guillaume Balestreri
** Login   <Cisarius@epitech.net>
** 
** Started on  Sat Apr  8 23:16:29 2017 Guillaume Balestreri
** Last update Fri May 19 16:19:33 2017 tudgwal
*/

#include "my.h"

int	my_check_pipe(char *line)
{
  int	a;

  a = 0;
  while (line[a] != '\0' && line[a] != ';'
	 && line[a] != '|')
    a = a + 1;
  if (line[a] == '|')
    return (1);
  return (0);
}

static int	wait_and_exit(pid_t pid)
{
  waitpid(pid, NULL, 0);
  return (0);
}

int	my_pipe(char *line, char **env, pid_t pid)
{
  int	pipefd[2];
  int	i;
  pid_t	pid2;

  i = 0;
  if (pipe(pipefd) == -1)
    return (84);
  if (!(pid = fork()))
    {
      close(pipefd[1]);
      dup2(pipefd[0], 0);
      while (line[i] != '|')
	i = i + 1;
      i = i + 1;
      while ((line[i] == '\t' || line[i] == ' ') && line[i] != '\0')
	i = i + 1;
      my_exec(&line[i], env);
    }
  if (!(pid2 = fork()))
    {
      close(pipefd[0]);
      dup2(pipefd[1], 1);
      my_exec(line, env);
    }
  return (wait_and_exit(pid2));
}
