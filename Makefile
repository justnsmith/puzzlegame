CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SOURCES = $(SRC_DIR)/main.cpp $(SRC_DIR)/Board.cpp $(SRC_DIR)/Game.cpp
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/Board.o $(BUILD_DIR)/Game.o
TARGET = $(BUILD_DIR)/main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean run
