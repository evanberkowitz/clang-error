# COMPILER can be either gcc or clang (no trailing spaces).
# COMPILER=gcc
COMPILER=clang

CXXFLAGS =

ifeq ($(COMPILER),gcc)
CC=g++-9
CXXFLAGS += -Wmisleading-indentation \
            -Wduplicated-cond -Wduplicated-branches -Wlogical-op \
            -Wuseless-cast -Wdouble-promotion -Wformat=0
endif
ifeq ($(COMPILER),clang)
CC=clang++ --std=c++17
endif

CXXFLAGS += -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wpedantic \
            -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual \
            -Wconversion -Wsign-conversion -Wnull-dereference \
            -Wdouble-promotion

run: main.cc demo.h Makefile
	@$(CC) --version
	$(CC) $(CXXFLAGS) main.cc -o run

clean:
	$(RM) run

demo: clean run
	./run
