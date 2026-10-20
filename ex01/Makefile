
NAME = span

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors -std=c++98
INCLUDE = -I .

SRC = main.cpp Span.cpp

OBJS = $(SRC:.cpp=.o)

RM = rm -f

all: $(NAME)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
