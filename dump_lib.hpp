#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <vector>
#include <string>

namespace dump_lib 
{
    void seed_random(int seed);
    int random_int_range(int min = 0, int max = 500);

    class RandomUnique;

	std::vector<std::string> str_split_one(std::string str, char delimiter);
	std::vector<std::string> str_split_two(std::string str);
}

class dump_lib::RandomUnique 
{
	public:
		RandomUnique(int min, int max);
		int generate_int();
	private:
		std::vector<int> uniques;
};

#endif
