# Compiler
CXX = c++

# Compiler flags
CXXFLAGS = -Wall -Wextra -Werror -std=c++17

# Target executable
TARGET = PmergeMe

# Source files
SRCS = main.cpp PmergeMe.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	@echo "Linking object files to create executable..."
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp
	@echo "Compiling $< to $@..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS)

# Clean up build files and the executable
fclean: clean
	rm -f $(TARGET)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re