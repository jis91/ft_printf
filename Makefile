NAME := libftprintf.a
CC := gcc
CFLAGS :=  -Werror -Wextra -Wall
SRCS := ft_printf.c ft_printf_utils.c ft_print_pointer.c ft_print_hex.c ft_print_unsigned.c ft_itoa.c
OBJS := $(SRCS:%.c=%.o)
HEADER := ft_printf.h
AR:= ar -rcs
RM:= rm -rf

%.o:	%.c $(HEADER) 
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re libft
