CC = gcc

.PHONY: all
all: lib test

.PHONY: lib
lib: libarrays.so
libarrays.so: arrays.c
	@$(CC) -std=c99 -shared arrays.c -o libarrays.so

.PHONY: test
test: test.a
test.a: test.c libarrays.so
	@$(CC) test.c -L. -larrays -o test.a -Wl,-rpath,.

.PHONY: clean
clean:
	@rm -f *.so *.a
