compile:
	g++ -o ./bin/main ./src/main.cpp

run:
	./bin/main

clean:
	rm -rf ./bin

all:
	compile
	run

.PHONY: compile run clean all
