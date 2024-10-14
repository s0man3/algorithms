#include <iostream>
#include <btree.h>
#include <queue>

void debug(gen::BTree *b) {
	std::queue<gen::BNode*> q;
	q.push(b->root);
	while(!q.empty()) {
		gen::BNode* node;
		node = q.front();
		q.pop();

		if (node->is_bottom) {
			switch (node->nr_elem) {
				case 0:
					break;
				case 1:
					std::cout << node->ll << " ";
					break;
				case 2:
					std::cout << node->l << "|" << std::endl;
					std::cout << node->ll << " ";
					std::cout << node->lc << " " << std::endl;
					break;
				case 3:
					std::cout << node->l << "|" << node->r << std::endl;
					std::cout << node->ll << " ";
					std::cout << node->lc << " ";
					std::cout << node->lr << " " << std::endl;
					break;
			}
		} else {
			switch (node->nr_elem) {
				case 0:
					break;
				case 1:
					q.push(node->left);
					break;
				case 2:
					std::cout << node->l << "|" << std::endl;
					q.push(node->left);
					q.push(node->center);
					break;
				case 3:
					std::cout << node->l << "|" << node->r << std::endl;
					q.push(node->left);
					q.push(node->center);
					q.push(node->right);
					break;
			}
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	gen::BTree *b = new gen::BTree();
	b->insert(1);
	debug(b);
	b->insert(10);
	debug(b);
	b->insert(11);
	debug(b);
	b->insert(12);
	debug(b);
	b->insert(30);
	debug(b);

	return 0;
}
