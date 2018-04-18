/*
** redirection_fcts_left.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh/src/tab3
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Sat May 20 10:33:54 2017 Theo Clement
** Last update Sun Jun 11 01:27:09 2017 Theo Clement
*/

int	status_child;

void	handler(int sig)
{
  status_child = 0;
}

int	parent_process(int *fildes, char **envp, char ***tab_o_tabs)
{
  close (fildes[1]);
  dup2(fildes[0], 0);
  signal(SIGUSR1, handler);
  while (status_child);
  if (execve("/bin/cat", argv, envp) == -1) // replace "/bin/cat" et argv par les bons arg
    exit(84);
}

int	redir_double_left(char *line, char ***envp, char ***tab_o_tabs)
{
  int	*fildes;
  pid_t	pid;
  char	*line;

  status_child = 1;
  if ((fildes = malloc(sizeof(int) * 2)) == NULL)
    return (1);
  if (pipe(fildes) == -1 || (pid = fork()) == -1)
    return (1);
  else if (!pid)
    parent_process(fildes, envp, tab_o_tabs);
  else
    {
      close (fildes[0]);
      while (strcmp((line = get_next_line(0)), av[1]) != 0)
	write(fildes[1], line, my_strlen(line));
      if (kill(pid, SIGUSR1) == -1)
	return (84);
    }
  return (0);
}

int	redir_left(char *line, char ***envp, char ***tab_o_tabs)
{
  int	*fildes;
  pid_t	pid;
  char	*line;
  int	fd;

  status_child = 1;
  fildes = malloc(sizeof(int) * 2);
  if (pipe(fildes) == -1 || (pid = fork()) == -1)
    return (1);
  if ((fd = open("file", O_RDWR)) == -1)
    {
      printf("%s: No such file or directory.\n", line);
      return (2); // verifier si c'est la bonne valeur de retour
    }
  else if (!pid)
    parent_process(fildes, envp, tab_o_tabs);
  else
    {
      close (fildes[0]);
      while (strcmp((line = get_next_line(fd)), av[1]) != 0)
	write(fildes[1], line, my_strlen(line));
      if (kill(pid, SIGUSR1) == -1)
	return (84);
    }
  return (0);
}
