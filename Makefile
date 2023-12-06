CFLAGS= -g -Isrc/
FILE_OUTPUT_NAME= a.out

default: all

all: main.o preparebuild mytools.o day1.o day2.o day3.o day4.o day5.o day6.o
	g++ $(CFLAGS) -o build/$(FILE_OUTPUT_NAME) build/main.o build/mytools.o \
	build/day1.o \
	build/day2.o \
	build/day3.o \
	build/day4.o \
	build/day5.o \
	build/day6.o \

main.o: src/main.cpp
	g++ $(CFLAGS) -c src/main.cpp -o build/main.o

day1.o: src/day1/day1.cpp
	
	g++ $(CFLAGS) -c src/day1/day1.cpp -o build/day1.o

day2.o: src/day2/day2.cpp
	g++ $(CFLAGS) -c src/day2/day2.cpp -o build/day2.o

day3.o: src/day3/day3.cpp
	g++ $(CFLAGS) -c src/day3/day3.cpp -o build/day3.o

day4.o: src/day4/day4.cpp
	g++ $(CFLAGS) -c src/day4/day4.cpp -o build/day4.o

day5.o: src/day5/day5.cpp
	g++ $(CFLAGS) -c src/day5/day5.cpp -o build/day5.o

day6.o: src/day6/day6.cpp
	g++ $(CFLAGS) -c src/day6/day6.cpp -o build/day6.o

mytools.o: src/mytools.cpp
	g++ $(CFLAGS) -c src/mytools.cpp -o build/mytools.o

preparebuild:
	mkdir build -p

.PHONY: clean
clean:
	rm $(FILE_OUTPUT_NAME) -f
	rm build/*.out -f
	rm build/*.o -f