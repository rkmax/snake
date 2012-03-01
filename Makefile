# Makefile

BUILD = snake

LDFLAGS =
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CXXFLAGS = -Wall
RM = rm -rf

OBJECTS =  main.o $(addprefix $(OBJ_DIR), screen.o director.o)

OBJ_DIR = objects/
SRC_DIR = sources/

.PHONY: clean

all: clean $(BUILD)

$(BUILD): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(BUILD) $(LDLIBS) $(OBJECTS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(OBJ_DIR)
	mkdir $(OBJ_DIR)