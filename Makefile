CC = g++
OUTPUT_NAME=libdump_lib.o

all: dump_lib.cpp
	$(CC) -c dump_lib.cpp -o $(OUTPUT_NAME)
install: all
	cp $(OUTPUT_NAME) /usr/local/lib/
	cp dump_lib.hpp /usr/local/include/
uninstall:
	rm /usr/local/lib/$(OUTPUT_NAME) /usr/local/include/dump_lib.hpp
clean:
	rm *.o



