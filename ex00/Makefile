# # Memo
# VAR = val: Normal setting - values within are recursively expand when var used.
# VAR := val: Setting of var with simple expansion of values inside - values are expanded at decl time.
# VAR ?= val: Set var only if it doesn't have a value.
# VAR += val: Append val to existing value (or set if var didn't exist).
#
# $@: name of the target file (one before colon)
# $<: name of first prerequisite file (first one after colon)
# $^: names of all prerequisite files (space separated)
# $*: stem (bit which matches the % wildcard in rule definition)

# name
OUTPUT_DIR = 		.
NAME = 				$(OUTPUT_DIR)/megaphone

# dirs
INCL_DIR =			incl
SRCS_DIR =			srcs
OBJS_DIR =			objs

# Files
# INCL	=	$(wildcard $(INCL_DIR)/*.hpp)
SRCS	=	$(wildcard $(SRCS_DIR)/*.cpp)
OBJS 	=	$(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
UI_FLAGS :=	-I $(INCL_DIR)

# Link Targets
all:	$(NAME)

$(NAME): $(OBJS)
	@echo "--------------------------------"
	@echo "make OBJECTS done.\n"
	$(CC) $(UI_FLAGS) $^ -o $@
	@echo "--------------------------------"
	@echo "make $(NAME) done.\n"
	chmod 777 $(NAME)
	@echo "--------------------------------"
	@echo "change permission of $(NAME) done.\n"

# Compile Targets
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(UI_FLAGS) -c $< -o $@
$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS)
	rm -rfd $(OBJS_DIR)

fclean:		clean
	rm -rf $(NAME)

re:		fclean all

update:	fclean
	make

# # User Targets
# norm:
# 	norminette $(SRCS) $(INCL)
# memcheck:
# 	make
# 	valgrind --suppressions=valgrind_pref.txt ./minishell
# memcheck-full:
# 	make
# 	valgrind --suppressions=valgrind_pref.txt --leak-check=full --show-leak-kinds=all ./minishell

.PHONY = all clean fclean re update
