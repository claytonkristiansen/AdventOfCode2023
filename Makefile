CFLAGS= -g
FILE_OUTPUT_NAME= a.out

default: clean day1

.PHONY: day1
day1: day1/day1.cpp
	mkdir build -p
	g++ $(CFLAGS) day1/day1.cpp -o build/$(FILE_OUTPUT_NAME)

.PHONY: clean
clean:
	rm $(FILE_OUTPUT_NAME) -f
	rm build/*.out -f