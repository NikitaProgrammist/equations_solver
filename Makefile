CC=g++
CFLAGS=-c -Wall
LDFLAGS=-I ./headers
FILES=main.cpp in_out_func.cpp my_printf.cpp solve_func.cpp unit_tests.cpp print_errors.cpp
FILES_DIR=sources
OBJECTS_DIR=build
SOURCES=$(addprefix $(FILES_DIR)/, $(FILES))
OBJECTS=$(addprefix $(OBJECTS_DIR)/, $(patsubst %.cpp, %.o, $(FILES)))
EXECUTABLE=build/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@

$(OBJECTS_DIR)/%.o: $(FILES_DIR)/%.cpp
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
