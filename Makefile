CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
BUILD_DIR := build
TARGET := $(BUILD_DIR)/ml_app
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

ifeq ($(strip $(SRC)),)
all:
	@echo "No C++ source files found in src/. Add .cpp files before building."

run:
	@echo "No C++ source files found in src/. Nothing to run."

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all run clean
else

all: $(TARGET)

$(BUILD_DIR):
	@mkdir -p $@

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all run clean
endif
