TARGET = main.exe

INCLUDE = -I./include

SRCDIR = ./src
SRCS = main.cpp LinkedList.cpp

OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/,$(SRCS:.cpp=.o))

CXX = g++
CXXFLAGS = -g -Wall -Wextra -Werror

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all
