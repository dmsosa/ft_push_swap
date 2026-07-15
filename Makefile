AR = ar -rcs
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
RM = rm -rf
INCLUDE = -Iinclude -Ilib
NAME = push_swap.out
PUSHSWAP_LIB = push_swap.a
LIBFT_DIR = ./lib
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = src
TEST_DIR = tests
OBJS_DIR = obj

CFILES = main.c \
	core/ft_sort.c \
	core/ft_sort_utils.c \
	core/ft_sort_units.c \
	core/simple/ft_sort_simple.c \
	core/medium/ft_sort_medium.c \
	core/metadata/metadata_cheapest.c \
	core/metadata/metadata_cost.c \
	core/metadata/metadata_index.c \
	core/metadata/metadata_position.c \
	core/metadata/metadata_target_a.c \
	core/metadata/metadata_target_b.c \
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
	bench/ft_bench_utils.c \
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
	$(RM) $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re libft

