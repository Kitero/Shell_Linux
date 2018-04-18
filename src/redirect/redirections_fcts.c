/*
** redirections_fcts.c for  in /home/Kitero/delivery/PSU/PSU_2016_42sh/src/tab3
** 
** Made by Theo Clement
** Login   <Kitero@epitech.net>
** 
** Started on  Fri May 19 17:02:28 2017 Theo Clement
** Last update Fri Jun  9 14:14:45 2017 Theo Clement
*/

int	redir_right(char *name, char ***envp)
{
  int	fd;
  int	status;
  pid_t	pid;

  status = 0;
  pid = 0;
  line = my_clean(line);
  if ((pid = fork()))
    return (my_pid1(line, status, env));
  else
    {
      truncate(tab_2[0], 0);
      fd = open(tab_2[0], O_RDWR | O_CREAT, 0644);
      dup2(fd, 1);
      close(fd);
      my_exec(line, env);
    }
  return (0);
}

int	redir_double_right(char *line, char ***envp, char ***tab_o_tabs)
{
  int	fd;
  int	status;
  pid_t	pid;

  status = 0;
  pid = 0;
  line = my_clean(line);
  if ((pid = fork()))
    return (my_pid1(line, status, env));
  else
    {
      fd = open(tab_o_tabs[1][0], O_RDWR | O_CREAT | O_APPEND, 0644);
      dup2(fd, 1);
      close(fd);
      my_exec(line, env);
    }
  return (0);
}
