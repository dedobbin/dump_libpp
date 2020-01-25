#include <random>
#include <algorithm>
#include <stdexcept> 
#include <sstream>
#include <assert.h>

#include "dump_lib.hpp"

bool randomInit = false;

void dump_lib::seed_random(int seed) 
{
    randomInit = true;
    srand(seed);
}

int dump_lib::random_int_range(int min, int max) 
{
    if (!randomInit)
        dump_lib::seed_random(time(NULL));
    return rand() % (max + 1 - min) + min;
}

dump_lib::RandomUnique::RandomUnique(int min, int max) 
{
    assert(max > min);

    uniques = std::vector<int>(max - min + 1);
    std::iota(uniques.begin(), uniques.end(), min);
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(uniques.begin(), uniques.end(), generator);
}

int dump_lib::RandomUnique::generate_int() 
{
    if (uniques.empty()){
        throw std::runtime_error("No more unique ints to generate...");
	}

    int result = uniques.back();
    uniques.pop_back();
    return result;
}

std::vector<std::string> dump_lib::str_split(std::string str, int index)
{
	std::vector<std::string> words;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ' ')) {
        words.push_back(token);
    }
	return words;
}

// #include <iostream>
// int main()
// {
// 	std::cout << "testing dump_lib" << std::endl;
	
// 	/* generate_random_int */
// 	for (int i = 0; i < 100; i++){
// 		std::cout <<  dump_lib::random_int_range(-10, 10) << " ";
// 	}
// 	std::cout << std::endl;

// 	/* RandomUnique */
// 	dump_lib::RandomUnique r = dump_lib::RandomUnique(0, 10);
// 	try{
// 		for (int i = 0; i < 100; i++){
// 			std::cout << r.generate_int() << " ";
// 		}
// 	}catch(std::exception &e){
// 		std::cout << e.what();
// 	}
// 	std::cout << std::endl;

// 	// /* str_split */
// 	std::string str =  "this string has multiple words, this is_one_word";
// 	auto words = dump_lib::str_split(str, ' ');
// 	for (auto word : words){
// 		std::cout << word << std::endl;
// 	}
// }