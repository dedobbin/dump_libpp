#ifndef __RANDOM_H_
#define __RANDOM_H_

#include <vector>
#include <string>

namespace dump_lib 
{
    void seed_random(int seed);
    int random_int_range(int min = 0, int max = 500);

    class RandomUnique;

	std::vector<std::string> str_split(std::string str, char delimiter);
};

class dump_lib::RandomUnique 
{
	public:
		RandomUnique(int min, int max);
		int generate_int();
	private:
		std::vector<int> uniques;
};

#endif
