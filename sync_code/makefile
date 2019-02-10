############ COMPILE ############
CXX := g++
CCX := #-Wall #-std=c++11
############ FILES ############
BIN := sync
SRC := $(wildcard ./src/*.cpp)
OBJ := $(SRC:./src/%.cpp=./obj/%.o)

INC_P := #-I./include
############ FUNCTIONS ############
.PHONY: all clean clean_all dirs debug
all: clean ../$(BIN)

../$(BIN): $(OBJ)
	$(CXX) $< -o $@

./obj/%.o: ./src/%.cpp
	$(CXX) $(CCX) $(INC_P) $< -o $@

clean:
	@ECHO "Deleting object files..."
	@$(RM) $(OBJ)
	@ECHO "Deleting $(BIN)..."
	@$(RM) ../$(BIN)
clean_all: clean
	@ECHO "Deleting object folder..."
	@$(RMDIR) obj

dirs:
	@if [ ! -d "src" ]; then mkdir "src"; ECHO "Creating src directory..."; fi
	@if [ ! -d "obj" ]; then mkdir "obj"; ECHO "Creating obj directory..."; fi
	@if [ ! -d "include" ]; then mkdir "include"; ECHO "Creating include directory..."; fi

############ DEBUGGING ############
debug:
	@ECHO 'Project: $(BIN)'
	@ECHO 'Source: $(SRC)'
	@ECHO 'Objects: $(OBJ)'
