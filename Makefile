# Makefile

BUILD = snake

LDFLAGS =
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CXXFLAGS = -Wall -I./includes
RM = rm -rf

OBJ_DIR = objects/
SRC_DIR = sources/

OBJS = $(patsubst $(SRC_DIR)%, \
	$(OBJ_DIR)%, \
	$(patsubst %.cpp,%.o,$(wildcard $(SRC_DIR)*.cpp)))

OBJECTS =  main.o $(OBJS)

all: $(BUILD)

test:
	cd test; $(MAKE)

$(BUILD): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(OBJ_DIR)
	mkdir $(OBJ_DIR)

.PHONY: test