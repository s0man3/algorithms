#include <vector>
#include <string>
namespace gen {
	int integer(int min, int max);
	std::vector<int> int_array(int n, int min, int max);
	std::string string(int min, int max);
	std::vector<std::string> str_array(int n, int min, int max);
}
