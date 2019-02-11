############ COMPILE ############
CC := g++
CC_FLAGS := -Wall -std=c++17
############ FILES ############
BIN := zipline
SRC := $(wildcard ./src/*.cpp)
OBJ := $(SRC:./src/%.cpp=./obj/%.o)

INC_P := -I./include
############ FUNCTIONS ############
.PHONY: all clean clean_all dirs debug
all: clean ../$(BIN)

../$(BIN): $(OBJ)
	$(CXX) $^ -o $@

./obj/%.o: ./src/%.cpp
	$(CXX) $(CCX) $(INC_P) -c $< -o $@

clean:
	@echo "Deleting object files..."
	@$(RM) $(OBJ)
	@echo "Deleting $(BIN)..."
	@$(RM) ../$(BIN)
clean_all: clean
	@ECHO "Deleting object folder..."
	@$(RMDIR) obj

dirs:
	@if [ ! -d "src" ]; then mkdir "src"; echo "Creating src directory..."; fi
	@if [ ! -d "obj" ]; then mkdir "obj"; echo "Creating obj directory..."; fi
	@if [ ! -d "include" ]; then mkdir "include"; echo "Creating include directory..."; fi

############ DEBUGGING ############
debug:
	@echo 'Project: $(BIN)'
	@echo 'Source: $(SRC)'
	@echo 'Objects: $(OBJ)'
