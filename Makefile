AR = ar -rcs
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
INCLUDE = -Iinclude -Ilib
NAME = push_swap
PUSHSWAP_LIB = push_swap.a
BONUS_DIR = ./bonus
LIBFT_DIR = ./lib
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
TEST_DIR = tests
OBJS_DIR = obj

CFILES = main.c \
	core/ft_sort.c \
	core/ft_sort_utils.c \
	core/ft_sort_units.c \
	core/algorithm_move.c\
	core/algorithm_move_utils.c\
	core/algorithm_small_utils.c\
	core/metadata/metadata_cheapest.c \
	core/metadata/metadata_cost.c \
	core/metadata/metadata_index.c \
	core/metadata/metadata_position.c \
	core/metadata/metadata_target_a.c \
	core/metadata/metadata_target_b.c \
	core/metadata/metadata.c \
	core/complex/sort_radix.c\
	core/medium/sort_chunk_utils.c\
	core/medium/sort_chunk.c\
	core/simple/sort_insertion.c\
	core/simple/sort_turk.c\
	operations/push/ft_push.c \
	operations/rotate/ft_rotate.c \
	operations/swap/ft_swap.c \
	operations/reverse/ft_reverse.c \
	parse/ft_valid_args.c \
	parse/ft_parse.c \
	parse/ft_parse_flags.c \
	parse/ft_parse_integers.c \
	parse/ft_parse_utils.c \
	stack/ft_stack_init.c \
	stack/ft_stack_list_utils.c \
	stack/ft_stack_utils.c \
	stack/ft_stack_print.c \
	bench/ft_bench.c \
	errors/ft_errors.c

TESTFILES = tests/test_disorder.c \
tests/test_helper.c \
tests/test_strcmp.c \
tests/test_parser.c \
tests/test_sort.c \



OFILES = $(CFILES:%.c=%.o)

SRCS = $(addprefix $(SRC_DIR)/, $(CFILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(OFILES))

all: $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE) $^ -L./lib -lft -c -o $@

$(PUSHSWAP_LIB) : $(OBJS)
	$(AR) $(PUSHSWAP_LIB) $^

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(PUSHSWAP_LIB) $(LIBFT)
	$(CC) $(FLAGS) $(INCLUDE) $(PUSHSWAP_LIB) $(LIBFT) -o $@ 

bonus: $(BONUS_OBJS)
	$(CC) $(FLAGS) $(INCLUDE) -I./bonus $(OBJS) $^ -L./lib -lft -o $(CHECKER)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(BONUS_DIR) fclean
	$(RM) $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(BONUS_DIR) fclean
	$(RM) $(NAME) $(CHECKER) $(PUSHSWAP_LIB)

re: fclean all

.PHONY: all bonus clean fclean re libft

