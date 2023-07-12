# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwallage <mwallage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 17:51:07 by mwallage          #+#    #+#              #
#    Updated: 2023/07/12 17:40:10 by mwallage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= cc
CFLAGS	:= -Wall -Werror -Wextra
SRCDIR	:= src
OBJDIR	:= obj
SRC 	:= $(SRCDIR)/lower_ops.c $(SRCDIR)/print.c $(SRCDIR)/main.c \
			$(SRCDIR)/sort.c $(SRCDIR)/check_sort.c $(SRCDIR)/utils.c \
			$(SRCDIR)/disc.c $(SRCDIR)/args.c $(SRCDIR)/higher_ops.c \
			$(SRCDIR)/try_ops.c $(SRCDIR)/cost.c
SRC2	:= $(SRCDIR)/checker.c $(SRCDIR)/lower_ops.c $(SRCDIR)/print.c \
			$(SRCDIR)/sort.c $(SRCDIR)/check_sort.c $(SRCDIR)/utils.c \
			$(SRCDIR)/disc.c $(SRCDIR)/args.c $(SRCDIR)/higher_ops.c \
			$(SRCDIR)/try_ops.c $(SRCDIR)/cost.c
OBJ		:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
OBJ2	:= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC2))
NAME	:= push_swap
NAME2	:= checker
LIBDIR	:= Libft
LIBFT	:= $(LIBDIR)/libft.a

all: $(NAME)

bonus: $(NAME2)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $@ -L$(LIBDIR) -lft

$(NAME2): $(OBJDIR) $(OBJ2)
	$(CC) $(OBJ2) -o $@ -L$(LIBDIR) -lft

$(OBJDIR):
	mkdir -p $(OBJDIR)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

$(LIBFT):
	make -C$(LIBDIR)

clean:
	rm -rf $(OBJDIR)
	make clean -C$(LIBDIR)

fclean: clean 
	rm -f $(NAME) $(NAME2)
	make fclean -C$(LIBDIR)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re
