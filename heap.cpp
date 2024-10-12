#include "heap.h"
#include <vector>
#include <utility>

namespace gen {
	Heap::Heap() {
		t = std::vector<int>();
	}

	void Heap::push(int val) {
		t.push_back(val);
		int num = t.size() - 1;

		while (num > 0) {
			int parent = (num - 1) / 2;

			if (t[num] >= t[parent])
				break;

			if (t[num] < t[parent])
				std::swap(t[num], t[parent]);

			num = parent;
		}
	}

	void Heap::pop() {
		int val = t.back();
		t.pop_back();
		
		t[0] = val;
		int idx = 0;
		while (2 * idx + 1 < t.size()) {
			for (int i=0;i<2;i++) {
				if (t[idx] > t[2 * idx + i]) {
					std::swap(t[idx], t[2 * idx + i]);
					idx = 2 * idx + i;
					continue;
				}
			}

			break;
		}
	}

	int Heap::top() {
		return t[0];
	}
}
