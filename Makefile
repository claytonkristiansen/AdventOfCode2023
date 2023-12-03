CFLAGS= -g
FILE_OUTPUT_NAME= a.out

default: clean day1

.PHONY: day1
day1: day1/day1.cpp
	mkdir build -p
	g++ $(CFLAGS) day1/day1.cpp -o build/$(FILE_OUTPUT_NAME)

.PHONY: day2
day2: day2/day2.cpp
	mkdir build -p
	g++ $(CFLAGS) day2/day2.cpp -o build/$(FILE_OUTPUT_NAME)

.PHONY: day3
day3: day3/day3.cpp
	mkdir build -p
	g++ $(CFLAGS) day3/day3.cpp -o build/$(FILE_OUTPUT_NAME)

.PHONY: clean
clean:
	rm $(FILE_OUTPUT_NAME) -f
	rm build/*.out -f