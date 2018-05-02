CC=gcc-6
CFLAGS=-std=c11 -fopenmp -lm -march=native -O3

cli: bin-dir
	$(CC) $(CFLAGS) cli.c -o bin/jpeg

cli-slow: bin-dir
	$(CC) $(CFLAGS) cli.c -fopenacc -D UNOPTIMIZED -o bin/jpeg

test: bin-dir
	$(CC) $(CFLAGS) test.c -o bin/test
	bin/test 100
	rm bin/test lena.jpg

test-slow: bin-dir
	$(CC) $(CFLAGS) test.c -fopenacc -D UNOPTIMIZED -o bin/test
	bin/test 1
	rm bin/test lena.jpg

test-pgi: bin-dir
	pgcc -c99 -acc -openmp -D UNOPTIMIZED -Minfo -fast -O3 -o bin/test test.c
	bin/test 1
	rm bin/test lena.jpg

bin-dir:
	mkdir -p bin

clean:
	$(RM) bin/test bin/jpeg lena.jpg