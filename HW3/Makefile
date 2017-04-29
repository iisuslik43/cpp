CXX = g++
CXXFLAGS = -O0 -Wall -Werror -std=gnu++11 -fprofile-arcs -ftest-coverage -Iinclude -pthread
LDFLAGS = -fprofile-arcs -ftest-coverage

EXE = huffman
SRCDIR = src
BINDIR = bin

OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BINDIR)/%.o,$(wildcard $(SRCDIR)/*.cpp))

all: $(EXE)

$(EXE): $(BINDIR) $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXE) $(LDFLAGS)

$(BINDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o $@ $<

include $(wildcard $(BINDIR)/*.d)

$(BINDIR):
	mkdir -p $(BINDIR)

test: $(BINDIR)/test.o $(BINDIR)/huffman.o
	$(CXX) $(BINDIR)/test.o $(BINDIR)/huffman.o $(CXXFLAGS) -o test

(BINDIR)/huffman.o: src/huffman.cpp
		$(CXX) $(CXXFLAGS) -c -MMD -o bin/huffman.o src/huffman.cpp

(BINDIR)/test.o: test/test.cpp
	$(CXX) $(CXXFLAGS) -c -MMD -o bin/test.o test/test.cpp -lgtest

clean:
	rm -rf $(BINDIR) $(EXE)

.PHONY: clean all
