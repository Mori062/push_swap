NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

SRC_PATH	= srcs
SRC			= $(shell ls $(SRC_PATH))
SRCS		= $(addprefix $(SRC_PATH)/, $(SRC))

OBJ_PATH	= obj
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH)/, $(OBJ))

INC_PATH	= includes

RM			= rm -f

CHECK		= \033[32m[✔]\033[0m
REMOVE		= \033[31m[✘]\033[0m
BLUE		= \033[1;34m
RESET		= \033[0m

all : $(NAME)

$(NAME) : $(OBJS)
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(CHECK) $(BLUE)Compiling push_swap... $(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@ mkdir -p $(OBJ_PATH)
	@ $(CC) $(CFLAGS) -o $@ -c $< -I $(INC_PATH)

clean:
	@ $(RM) $(OBJS)
	@ $(RM) -r $(OBJ_PATH)
	@echo "$(REMOVE) $(BLUE)Remove push_swap objects... $(RESET)"

fclean: clean
	@ $(RM) $(NAME)
	@echo "$(REMOVE) $(BLUE)Remove push_swap... $(RESET)"

re: fclean all

tester: all
	@ bash shell_script/test.sh

visual: all
	@ bash shell_script/pain.sh

.PHONY : all clean fclean re