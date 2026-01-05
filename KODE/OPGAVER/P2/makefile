# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iinclude

# Executable name
TARGET = main

# Source and object files
SRC = src/maintest.cpp src/P2E.cpp src/hashMap.cpp  src/BinarySearchTree.cpp
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Link executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compile .cpp → .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean built files
clean:
	rm -f $(OBJ) $(TARGET)

# Run convenience target
run: $(TARGET)
	./$(TARGET)
