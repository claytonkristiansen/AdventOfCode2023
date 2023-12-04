CFLAGS= -g -Isrc/
FILE_OUTPUT_NAME= a.out

default: clean all

all: main.o preparebuild usefulfunctions.o day1.o day2.o day3.o 
	g++ $(CFLAGS) build/main.o build/day1.o build/day2.o build/day3.o build/usefulfunctions.o -o build/$(FILE_OUTPUT_NAME)

main.o: src/main.cpp
	g++ $(CFLAGS) -c src/main.cpp -o build/main.o

day1.o: src/day1/day1.cpp
	
	g++ $(CFLAGS) -c src/day1/day1.cpp -o build/day1.o

day2.o: src/day2/day2.cpp
	g++ $(CFLAGS) -c src/day2/day2.cpp -o build/day2.o

day3.o: src/day3/day3.cpp
	g++ $(CFLAGS) -c src/day3/day3.cpp -o build/day3.o

usefulfunctions.o: src/usefulfunctions.cpp
	g++ $(CFLAGS) -c src/usefulfunctions.cpp -o build/usefulfunctions.o

preparebuild:
	mkdir build -p

.PHONY: clean
clean:
	rm $(FILE_OUTPUT_NAME) -f
	rm build/*.out -f
	rm build/*.o -f