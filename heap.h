#include <vector>
namespace gen {
	class Heap
	{
		public:
			std::vector<int> t;

			Heap();

			void push(int val);

			void pop();

			int top();
	};
}
