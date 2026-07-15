CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf
INCLUDE = -I./include -I../lib -I../include
NAME = checker.out
PUSHSWAP_LIB_DIR = ..
PUSHSWAP_LIB = $(PUSHSWAP_LIB_DIR)/push_swap.a
SRC_DIR = src
OBJS_DIR = obj

CFILES = main.c \
error.c \

OFILES = $(CFILES:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OFILES))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) -c $^ -o $@

$(PUSHSWAP_LIB):
	$(MAKE) -C $(PUSHSWAP_LIB_DIR)

$(NAME): $(PUSHSWAP_LIB) $(OBJS)
	$(CC) $(FLAGS) $(INCLUDE) $(OBJS) $(PUSHSWAP_LIB) -L../lib -lft -o $@ 

clean:
	@make -C $(PUSHSWAP_LIB_DIR) clean
	$(RM) $(OBJS_DIR)

fclean: clean
	@make -C $(PUSHSWAP_LIB_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re

