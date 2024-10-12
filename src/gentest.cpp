#include <iostream>
#include <vector>
#include <generator.h>

int main()
{
	int i, j=0;
	std::vector<int> v = gen::int_array(100, 0, 99);
	std::cout << "length:" << v.size() << std::endl;

	for (i=0;i<v.size();i++) {
		std::cout << v[i] << "  ";
		j++;
		if (j % 10 == 0)
			std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << gen::string(10, 11) << std::endl << std::endl;

	std::vector<std::string> s = gen::str_array(10, 5, 15);
	for (i=0;i<s.size();i++) {
		std::cout << s[i] << std::endl;
	}
	return 0;
}
