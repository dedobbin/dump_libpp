#include <iostream>
#include <dump_lib.hpp>
int main()
{
	std::cout << "testing dump_lib" << std::endl;
	
	/* generate_random_int */
	for (int i = 0; i < 100; i++){
		std::cout <<  dump_lib::random_int_range(-10, 10) << " ";
	}
	std::cout << std::endl;

	/* RandomUnique */
	dump_lib::RandomUnique r = dump_lib::RandomUnique(0, 10);
	try{
		for (int i = 0; i < 100; i++){
			std::cout << r.generate_int() << " ";
		}
	}catch(std::exception &e){
		std::cout << e.what();
	}
	std::cout << std::endl;

	// /* str_split */
	std::string str =  "this string has multiple words, this is_one_word";
	auto words = dump_lib::str_split(str, ' ');
	for (auto word : words){
		std::cout << word << std::endl;
	}
}