CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -I. -std=c++11
PATH_SRC = ./
HEADERS = header.hpp
SRCS = phonybook.cpp
EXECS = $(SRCS:%.cpp=%)

all: $(EXECS)

%: $(PATH_SRC)%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(EXECS)

fclean: clean
	rm -f phonybook
re: fclean all

.PHONY: all clean fclean re