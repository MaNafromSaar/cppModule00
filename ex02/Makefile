CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -I. -std=c++11
PATH_SRC = ./
HEADERS = Account.hpp
SRCS = tests.cpp Account.cpp
OBJS = $(SRCS:.cpp=.o)
EXECS = tests

all: $(EXECS)

$(EXECS): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: $(PATH_SRC)%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXECS)

fclean: clean
	rm -f $(EXECS)
re: fclean all

.PHONY: all clean fclean re