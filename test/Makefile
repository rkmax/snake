# Makefile

LDFLAGS =
LDLIBS = -lboost_unit_test_framework -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
CXXFLAGS = -Wall -I./../includes
RM = rm -rf

DEPS = position.o

all: clean

clean:
	$(RM) *.o *_test

%_test: %.o unit_test_%.o $(DEPS)
	$(CXX) $(LDFLAGS) $(LDLIBS) $? -o $@
	./$@

unit_test_%.o: unit_test_%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: ../sources/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
