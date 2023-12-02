CFLAGS= -g
FILE_OUTPUT_NAME= a.out

default: all

.PHONY: all
all: main.cpp
	g++ $(CFLAGS) main.cpp -o $(FILE_OUTPUT_NAME)

.PHONY: clean
clean:
	rm $(FILE_OUTPUT_NAME)