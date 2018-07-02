# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcollard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:51:47 by tcollard          #+#    #+#              #
# **************************************************************************** #

.PHONY: all clean fclean re build

NAME = libftprintf.a

PATH_SRC = ./srcs/
PATH_INCS = ./includes
PATH_OBJ = ./obj/
PATH_LIB = lib/

SRC =	apply_flag_hashtag.c \
		apply_flag_minus.c \
		apply_flag_space.c \
		apply_flag_plus.c \
		apply_flag_zero.c \
		check_all.c \
		conversion.c \
		conversion_nb.c \
		conversion_nb2.c \
		conversion_str.c \
		conversion_wchar.c \
		mask_wchar.c \
		flag.c \
		modifier.c \
		ft_printf.c \
		precision.c \
		struct.c \
		$(PATH_LIB)ft_atoi.c \
		$(PATH_LIB)ft_atoi_base.c \
		$(PATH_LIB)ft_isalpha.c \
		$(PATH_LIB)ft_isdigit.c \
		$(PATH_LIB)ft_itoa.c \
		$(PATH_LIB)ft_itoa_base.c \
		$(PATH_LIB)ft_itoa_base_neg.c \
		$(PATH_LIB)ft_itoa_base_ull.c \
		$(PATH_LIB)ft_itoa_ll.c \
		$(PATH_LIB)ft_memalloc.c \
		$(PATH_LIB)ft_memdel.c \
		$(PATH_LIB)ft_memset.c \
		$(PATH_LIB)ft_putchar.c \
		$(PATH_LIB)ft_putstr.c \
		$(PATH_LIB)ft_strcpy.c \
		$(PATH_LIB)ft_strdup.c \
		$(PATH_LIB)ft_strjoin.c \
		$(PATH_LIB)ft_strlen.c \
		$(PATH_LIB)ft_strncpy.c \
		$(PATH_LIB)ft_strsub.c \
		$(PATH_LIB)ft_tolower.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

#SRC := $(filter $(addprefix %, .c), $(SRC))
SRCS = $(addprefix $(PATH_SRC), $(SRC))
OBJS = $(addprefix $(PATH_OBJ), $(OBJ))
#OBJS_DIR = $(sort $(dir $(OBJS)))

INCS_DIR = $(addsuffix /, $(PATH_INCS))
INCS = $(addprefix -I, $(INCS_DIR))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $(OBJS)
	ranlib $@

$(PATH_OBJ)%.o : $(PATH_SRC)%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_LIB) 2> /dev/null || true
	gcc -c -o $@ $^ $(INCS) $(CFLAGS) 

clean :
	/bin/rm -fv $(OBJS)
	@rmdir $(PATH_OBJ)$(PATH_LIB) 2> /dev/null || true
	@rmdir $(PATH_OBJ) 2> /dev/null || true

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
