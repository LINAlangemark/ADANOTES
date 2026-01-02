# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Target
TARGET = main

# Source files
SRCS = \
    $(SRC_DIR)/main.cpp \
    $(SRC_DIR)/hashMap.cpp \
    $(SRC_DIR)/CuckooHashMap.cpp \
    $(SRC_DIR)/HopscotchHashMap.cpp \
    $(SRC_DIR)/BallsNBinsExperiment.cpp

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure build dir exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
