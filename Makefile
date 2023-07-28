NAME		= push_swap
BONUS_NAME	= checker

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

SRC_DIR		= srcs
SRC			= 
SRCS		= $(addprefix $(SRC_DIR)/, $(SRC))

BONUS_SRC	= 
BONUS_SRCS	= $(addprefix $(SRC_DIR)/, $(BONUS_SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

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

bonus : $(BONUS_NAME)

$(LIBS):
	@ make -C $(LIB_PATH)

$(BONUS_NAME) : $(BONUS_OBJS) $(LIBS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

$(NAME) : $(OBJS) $(LIBS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(CHECK) $(BLUE)Compiling push_swap... $(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCS)
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INCS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

test: all bonus
	bash test.sh

visual: all
	bash pain.sh

.PHONY : all clean fclean re