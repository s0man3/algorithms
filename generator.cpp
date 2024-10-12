#include "generator.h"
#include <random>
#include <string>

namespace gen {
	int integer(int min, int max) {
		std::random_device rd;
		std::mt19937 mt(rd());
		return mt();
	}

	std::vector<int> int_array(int n, int min, int max)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> uni(min, max);
		std::vector<int> vec(n, 0);

		for (int i=0;i<n;i++) {
			vec[i] = uni(mt);
		}

		return vec;
	}

	std::string string(int min, int max) 
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> uni_len(min, max);
		std::uniform_int_distribution<int> uni_str(0x61, 0x7a);

		int length = uni_len(mt);
		char* cstr = new char(length + 1);

		for (int i=0;i<length;i++) {
			cstr[i] = uni_str(mt);
		}
		cstr[length] = '\0';

		return std::string(cstr);
	}

	std::vector<std::string> str_array(int n, int min, int max)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> uni_len(min, max);
		std::uniform_int_distribution<int> uni_str(0x61, 0x7a);

		std::vector<std::string> ret;
		for (int i=0;i<n;i++) {
			int length = uni_len(mt);
			char* cstr = new char(length + 1);

			for (int i=0;i<length;i++) {
				cstr[i] = uni_str(mt);
			}
			cstr[length] = '\0';

			ret.push_back(std::string(cstr));
			delete cstr;
		}

		return ret;
	}
}
