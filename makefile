all: bin/Bulls-Cows bin/Bulls-Cows-test
bin/Bulls-Cows: build/main.o build/core.o
	gcc -Wall -Werror build/main.o build/core.o -o bin/Bulls-Cows -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/core.o: src/core.c
	gcc -Wall -Werror -c src/core.c -o build/core.o -lm

bin/Bulls-Cows-test: build/test/main.o build/core.o build/test/input.o
	gcc -Wall -Werror build/test/main.o build/test/input.o build/core.o -o bin/Bulls-Cows-test -lm

build/test/main.o: test/main.c
	gcc -I thirdparty -Wall -Werror -c test/main.c -o build/test/main.o

build/test/input.o: test/input.c
	gcc -I thirdparty -Wall -Werror -c test/input.c -o build/test/input.o

.PHONY: clean
clean: build/*.o
	rm -rf build/*.o
