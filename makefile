all: bin/main bin/main-test
bin/main: build/main.o build/core.o
	gcc -Wall -Werror build/main.o build/core.o -o bin/main -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/core.o: src/core.c
	gcc -Wall -Werror -c src/core.c -o build/core.o -lm

bin/main-test: build/test/main.o build/core.o build/test/input.o
	gcc -Wall -Werror build/test/main.o build/test/input.o build/core.o -o bin/main-test -lm

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/input.o: test/input.c
	gcc -I thirdparty -Wall -Werror -c test/input.c -o build/test/input.o

.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
