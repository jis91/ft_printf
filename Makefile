NAME := libftprintf.a
CC := gcc
CFLAGS :=  -Werror -Wextra -Wall
SRCS := ft_printf.c ft_printf_utils.c ft_print_pointer.c ft_print_hex.c ft_print_unsigned.c
OBJS := $(SRCS:%.c=%.o)
HEADER := ft_printf.h
LIBFT_PATH := ./libft
LIBFT := $(LIBFT_PATH)/libft.a
AR:= ar -rcs
RM:= rm -rf

%.o:	%.c $(HEADER) 
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

bonus: 	all

$(NAME):	$(LIBFT) $(OBJS) $(HEADER)
	cp	$(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)

$(LIBFT):
		make -C $(LIBFT_PATH) all

clean:
		make -C $(LIBFT_PATH) clean
		$(RM) $(OBJS)

fclean:		clean
		make -C $(LIBFT_PATH) fclean
		$(RM) $(NAME)

re: fclean all

.PHONY:		all bonus clean fclean re libft
