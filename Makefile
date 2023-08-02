NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_PATH	= srcs
SRC			= check_args.c \
				main.c \
				put_stack.c
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH	= includes
INC			= push_swap.h
INCS		= $(addprefix $(INC_PATH)/, $(INC))

LIB_PATH	= libft
LIB			= libft.a
LIBS		= $(addprefix $(LIB_PATH)/, $(LIB))

RM			= rm -f

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
BLUE		= \033[1;34m
RESET		= \033[0m

all : $(NAME)

$(LIBS):
	@ make -C $(LIB_PATH)

$(NAME) : $(OBJS) $(LIBS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(CHECK) $(BLUE)Compiling push_swap... $(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INCS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

test: all bonus
	bash test.sh

visual: all
	bash pain.sh

.PHONY : all clean fclean re