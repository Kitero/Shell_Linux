##
## Makefile for Makefile in /home/Cisarius/delivery/CPE_2016_BSQ
## 
## Made by Guillaume Balestreri
## Login   <Cisarius@epitech.net>
## 
## Started on  Wed Dec  7 14:48:15 2016 Guillaume Balestreri
## Last update Wed May 31 15:21:16 2017 Theo Clement
##

CC		=	gcc

CFLAGS		=	-g3 -Wall -Wextra -Werror

CPPFLAGS	=	-I header

SRCS		=	main.c \
			src/mod_env.c \
			src/free_all.c \
			src/main_loop.c \
			src/my_separator.c \
			src/my_env.c \
			src/my_putstr.c \
			src/my_strcat.c \
			src/my_tab_clear.c \
			src/my_new_env.c \
			src/my_str_to_tab.c \
		  	src/my_str_to_tab_exec.c \
			src/alloc_str.c \
			src/get_path.c \
			src/my_cd2.c \
			src/my_point.c \
			src/my_check.c \
			src/my_check_perm.c \
			src/my_cmp.c \
			src/my_cut.c \
			src/my_exec.c \
			getnextline/get_next_line.c \
			getnextline/get_next_line2.c \
			src/my_pipe.c \
			src/my_error.c \
			src/my_cd.c	\
			src/my_unsetenv.c	\
			src/my_unsetenv2.c	\
			src/create_basic_env.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	42sh

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
