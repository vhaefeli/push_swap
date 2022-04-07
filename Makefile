# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 13:10:08 by vhaefeli          #+#    #+#              #
#    Updated: 2022/04/04 17:07:51 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS 			= -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
TARGET 			= push_swap
SRCS_DIR 		= ./src
OBJS_DIR 		= ./obj
LIBFT_DIR		= ./libft
INCLUDES_DIRS	= $(LIBFT_DIR) ./includes
INCLUDES		= $(addprefix -I,$(INCLUDES_DIRS))
LIBS			= $(LIBFT_DIR)/libft.a
_SRCS			= push_swap.c \
					listmanip.c\
					initpushswap.c\
					base_op.c\
					analysis_ft.c\
					analysis2.c\
					fillcheck.c\
					mix_op.c\
					sortsmall.c\
					sortbig.c
OBJS 			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS))
SRCS 			= $(patsubst %, $(SRCS_DIR)/%, $(_SRCS))
OBJS_BONUS 		= $(patsubst %.c, $(OBJS_DIR)/%.o, $(_SRCS_BONUS))

.PHONY : all clean fclean re bonus test norminette

all: $(TARGET)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(TARGET)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) -c $(CFLAGS) -o $@ $^ $(INCLUDES)

$(TARGET): $(LIBFT_DIR)/libft.a $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INCLUDES) $(LIBS)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -sC $(LIBFT_DIR) bonus

bonus: $(TARGET)

norminette:
	@make -sC $(LIBFT_DIR) norminette
	@norminette $(SRCS_DIR) includes


