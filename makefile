all: main
	make clean

main: main.o
	g++ -o build/main build/main.o

main.o:
	g++ -c src/main.cpp -o build/main.o

clean:
	rm -rf build/*.o

run:
	build/./main
