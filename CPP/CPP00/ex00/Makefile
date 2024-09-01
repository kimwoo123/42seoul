NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = megaphone.cpp
RMFLAGS = -rf

OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

$(OBJ): $(OBJ_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

all : $(OBJ_DIR) $(NAME)

clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(RM) $(RMFLAGS) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.DEFAULT_GOAL = all
