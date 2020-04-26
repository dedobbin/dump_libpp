CC = g++
OUTPUT_NAME=libdump_lib.so

all: dump_lib.cpp
	$(CC) -c -fPIC dump_lib.cpp -o $(OUTPUT_NAME)
install: all
	sudo cp $(OUTPUT_NAME) /usr/local/lib/
	sudo cp dump_lib.hpp /usr/local/include/
uninstall:
	sudo rm /usr/local/lib/$(OUTPUT_NAME) /usr/local/include/dump_lib.hpp
clean:
	rm *.o



