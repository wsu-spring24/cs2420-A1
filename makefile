all: clean test

appTests: DateTesting.cpp
	g++ -Wall --std=c++17 DateTesting.cpp catch_amalgamated.cpp -o appTests

test: appTests
	# executes all tests
	./appTests

clean:
	rm -f appTests
