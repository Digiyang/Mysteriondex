# Verzeichnisse
SOURCEDIR = src
BUILDDIR = build

# Dateien
PROG = prog
SRC = $(wildcard $(SOURCEDIR)/*.cpp)
DEP = $(wildcard $(SOURCEDIR)/*.h)
OBJ = $(SRC:$(SOURCEDIR)/%.cpp=$(BUILDDIR)/%.o)

# Compiler / Flags
CXXFLAGS += -W -Wall -Wextra -Werror -std=c++17
DFLAGS += -ggdb3 -fsanitize=address
RFLAGS += -fPIE -fstack-protector-all -O2

ifdef RELEASE
CXXFLAGS += $(RFLAGS)
else
CXXFLAGS += $(DFLAGS)
endif





$(PROG): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -c -o $@ $<





all: clean $(PROG) run

run:
	@./$(PROG)

clean:
	$(RM) $(PROG) $(OBJ)
