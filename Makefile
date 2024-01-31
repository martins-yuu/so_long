# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuuko <yuuko@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 10:09:46 by yuuko             #+#    #+#              #
#    Updated: 2024/01/31 01:54:27 by yuuko            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long

LIBS		:=	\
	lib/libft/libft.a \
	lib/MLX42/build/libmlx42.a \

INCS		:=	\
	lib/libft/include \
	lib/MLX42/include \

SRC_DIR		:=	src
BUILD_DIR	:=	build

SRCS		:=	\
	main.c \
	window.c \
	game.c \
	render.c \
	map.c \
	validation.c \
	error.c \
	color.c \
	utils/file.c \

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		:=	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:=	$(OBJS:.o=.d)

CC			:=	cc
# CFLAGS		:=	-Wall -Wextra -Werror
CPPFLAGS	:=	$(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS		:=	$(addprefix -L,$(dir $(LIBS)))
LDLIBS		:=	-lft -lmlx42 -ldl -lglfw -pthread -lm

RM			:=	rm -f
MAKEFLAGS	+=	--silent --no-print-directory

RED			:=	$(shell tput setaf 1)
GREEN		:=	$(shell tput setaf 2)
YELLOW		:=	$(shell tput setaf 3)
BLUE		:=	$(shell tput setaf 4)
MAGENTA		:=	$(shell tput setaf 5)
RESET		:=	$(shell tput sgr0)
TITLE		:=	$(YELLOW)$(basename $(NAME))$(RESET)
message		=	$(info [$(TITLE)] $(3)$(1)$(RESET) $(2))

ifdef WITH_DEBUG
	TITLE += $(MAGENTA)debug$(RESET)
	CFLAGS += -g
endif

ifdef WITH_SANITIZER
	TITLE += $(MAGENTA)sanitizer$(RESET)
	CFLAGS += -fsanitize=address
endif

all: $(NAME)

$(NAME): $(LIBS) $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(call message,CREATED,$(NAME),$(BLUE))

$(LIBS): lib/MLX42/build
	$(MAKE) -C $(@D) -j4

lib/MLX42/build:
	cmake lib/MLX42 -B lib/MLX42/build

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(call message,CREATED,$(basename $(notdir $@)),$(GREEN))

clean:
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib clean; done
	$(RM) -r $(BUILD_DIR)
	$(call message,DELETED,$(BUILD_DIR),$(RED))

fclean: clean
	for lib in $(dir $(LIBS)); do $(MAKE) -C $$lib fclean; done
	$(RM) $(NAME)
	$(call message,DELETED,$(NAME),$(RED))

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
.SILENT:
.IGNORE: clean fclean

-include $(DEPS)
