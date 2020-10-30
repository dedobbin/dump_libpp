#include <iostream>
#include <chrono>
#include <dump_lib.hpp>
int main(int argc, char *argv[])
{
	std::cout << "testing dump_lib" << std::endl << std::endl;

	int rand_min = -10;
	int rand_max = 10;

	/* generate_random_int */
	std::cout << "Generating random numbers frome " << rand_min << " to " << rand_max << std::endl;
	for (int i = 0; i < 100; i++){
		std::cout <<  dump_lib::random_int_range(-10, 10) << " ";
	}
	std::cout << std::endl << std::endl;

	/* RandomUnique */
	std::cout << "Generating random numbers from " << rand_min << " to " << rand_max  << " (unique)" << std::endl;
	dump_lib::RandomUnique r = dump_lib::RandomUnique(rand_min, rand_max);
	try{
		for (int i = 0; i < 100; i++){
			std::cout << r.generate_int() << " ";
		}
	}catch(std::exception &e){
		std::cout << e.what();
	}
	std::cout << std::endl << std::endl;

	// /* str_split */
	std::string str =  "constellations-in-the heavens";
	char delimiter = '-';
	std::cout << "Splitting string '" << str << "', delimiter: " << delimiter << std::endl;

	auto words = dump_lib::str_split(str, delimiter);
	for (auto word : words){
		std::cout << word << ", ";
	}
	std::cout << std::endl;

	return 0;
}
