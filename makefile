CXX := clang++
CXXFLAGS ?= -std=c++20 -Wall -Weffc++ -Wextra -Wsign-conversion -pedantic-errors
INCLUDES ?= -Iinclude

EXE = $(BINDIR)/chip8
TEST = $(BINDIR)/test
OBJS = $(addprefix $(OBJDIR)/, main.o chip8.o args.o log.o memory.o cpu.o)

BINDIR = bin
SRCDIR = src
TSTDIR = tests
OBJDIR = $(SRCDIR)/obj

$(EXE): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(INCLUDES) -o $@ $^

test: $(filter-out $(OBJDIR)/main.o, $(OBJS))
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(wildcard $(TSTDIR)/*.cpp) $^ -o $(TEST)

clean:
	rm -rf $(BINDIR) $(OBJDIR)

.PHONY: clean
