# Makefile

BUILD = boost_test

LDFLAGS =
LDLIBS = -lboost_unit_test_framework \
	../objects/position.o
CXXFLAGS = -Wall -I./../includes
RM = rm -rf

OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))

OBJECTS = $(OBJS)

all: clean $(BUILD)
	./$(BUILD)

$(BUILD): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

.PHONY: $(BUILD)