#include <iostream>
#include <heap.h>

int main()
{
	gen::Heap *h = new gen::Heap();
	h->push(10);
	h->push(9);
	h->push(22);
	h->push(1);
	std::cout << h->top() << std::endl;
	h->pop();
	std::cout << h->top() << std::endl;
	h->pop();
	std::cout << h->top() << std::endl;
	h->pop();
	std::cout << h->top() << std::endl;
}
