# Makefile

BUILD = snake

LDFLAGS =
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CXXFLAGS = -Wall -I./includes
RM = rm -rf

OBJ_DIR = objects/
SRC_DIR = sources/

OBJS = screen.o welcomescreen.o gamescreen.o scorescreen.o directorapp.o director.o snake.o menu.o

OBJECTS =  main.o $(addprefix $(OBJ_DIR), $(OBJS))



.PHONY: clean $(BUILD)

all: $(BUILD)

$(BUILD): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $(BUILD) $(LDLIBS) $(OBJECTS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(OBJ_DIR)
	mkdir $(OBJ_DIR)