NAME = AbstractAnimal
CXX = c++
CPPFLAGS = -MMD -MP
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RMFLAGS = -rf
INC_DIR = ./
OBJ_DIR = obj/
FILENAME = main Animal Dog Cat Brain
SRC_FILES = $(addsuffix .cpp, $(FILENAME))
OBJ_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILENAME)))
DEP_FILES = $(addprefix $(OBJ_DIR), $(addsuffix .d, $(FILENAME)))

-include $(DEP_FILES)

$(OBJ_FILES): $(OBJ_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ -I $(INC_DIR)

$(NAME) : $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)


all : $(OBJ_DIR) $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@$(RM) $(RMFLAGS) $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all

.DEFAULT_GOAL = all
