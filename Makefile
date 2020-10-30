CC = g++

all: dump_lib.cpp
	$(CC) -c -fPIC dump_lib.cpp -o libdump_lib.so
install:
	cp libdump_lib.so /usr/local/lib/
	cp dump_lib.hpp /usr/local/include/
uninstall:
	rm /usr/local/lib/libdump_lib.so /usr/local/include/dump_lib.hpp
static:
	$(CC) -c dump_lib.cpp -o dump_lib.o
	ar crf libdump_lib.a dump_lib.o
tests:	tests.cpp
	$(CC) tests.cpp -o tests -ldump_lib
clean:
	rm -fr *.o *.so *.a



