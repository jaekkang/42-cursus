# **************************************************************************** #
# ProgramName && Files                                                         #
# **************************************************************************** #
NAME		=   program
INC_FILES	=   whatever.hpp

SRC_FILES	=	main.cpp

# **************************************************************************** #
# Directories && Paths                                                         #
# **************************************************************************** #

INC_DIR =	include/
SRC_DIR =
OBJ_DIR =	.obj/
DEP_DIR =	.dep/
SRCS	=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS	=	$(SRC_FILES:%.cpp=$(OBJ_DIR)%.o)
DEPS	=	$(SRC_FILES:%.cpp=$(DEP_DIR)%.d)
# **************************************************************************** #
# Compiler && flags                                                            #
# **************************************************************************** #
CXX			=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98
CPPFLAGS	=	-I$(INC_DIR)
DEPFLAGS	=	-MMD -MP -MF $(@:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
RM			=	rm -rf
# **************************************************************************** #
# Debug options                                                                #
# **************************************************************************** #
ifdef DEBUG
	CXXFLAGS += -pedantic -g -fsanitize=address,undefined
endif
ifdef C
	CXX = c++-7
endif
Q = @
ifdef PRINT
	Q =
endif
# **************************************************************************** #
# Output controls                                                              #
# **************************************************************************** #
NAME_LEN = $(shell echo $(NAME) | tr -d '\n' | wc -c)
ifeq ($(shell echo "$(NAME_LEN)-6" | bc | grep -c '-'), 1)
	N = 6
else
	N = $(NAME_LEN)
endif
RST =	\033[0m
GRN =	\033[1;32m
CYN =	\033[1;36m
BCY =	\033[1;96m
HOM =	\033[A
CLR =	\033[K
# **************************************************************************** #
# Rules                                                                        #
# **************************************************************************** #
.DEFAULT_GOAL	=	all
-include $(DEPS)
all				:	$(NAME)
$(NAME)			:	$(OBJS)
	$Q$(CXX) $(CXXFLAGS) -o $@ $(OBJS)
	@printf   "$(CLR)$(GRN)%$Ns is Ready ✅\\n$(RST)" $(NAME)
$(OBJ_DIR)%.o   :   $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	@printf \
	"$(CLR)$(GRN)%$Ns is Ready : $<$(RST)$(HOM)\\n" $(NAME)
	$Q$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<
clean		:
	$Q$(RM) $(OBJ_DIR) $(DEP_DIR) *.dSYM
	@printf "$(CYN)%$Ns Objects! 🗑$(RST)\\n" Remove
fclean	:	clean
	$Q$(RM) $(NAME)
	@printf "$(BCY)%$Ns Program! 🗑$(RST)\\n" Remove
re			:	fclean
	@make all
.PHONY		:	all clean fclean re