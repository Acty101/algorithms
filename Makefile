# Compiler type
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic

# set source
SOURCE = buyAndSellStock.cpp

# set executable
EXECUTABLE = main

debug: CXXFLAGS += -g3 -DDEBUG -fsanitize=undefined -D_GLIBCXX_DEBUG
debug: 
	$(CXX) $(CXXFLAGS) $(SOURCE) -o $(EXECUTABLE)