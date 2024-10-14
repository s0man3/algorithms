#include <btree.h>

namespace gen {

	BNode* BNode::insert(int val) {
		BNode* created;
		BNode* toparent;

		if (is_bottom) {
			if (nr_elem == 2) {
				if (val < ll) {
					lr = lc;
					lc = ll;
					ll = val;

					r = lr;
					l = lc;
				} else if (val < lc) {
					lr = lc;
					lc = val;

					r = lc;
					l = val;
				} else {
					lr = val;

					r = val;
					l = lc;
				}
				nr_elem++;
				return nullptr;
			}
			if (nr_elem == 3) {
				if (val <  ll) {
					toparent = new BNode(tree, lc, lr);
					lc = ll;
					ll = val;
					l = lc;
				} else if (val < lc) {
					toparent = new BNode(tree, lc, lr);
					lc = val;
					l = lc;
				} else
					toparent = new BNode(tree, val, lr);

				nr_elem = 2;

				if (is_root) {
					BNode* new_root = new BNode(tree, this, toparent);
					new_root->is_root = true;
					is_root = false;
					tree->root = new_root;
					return nullptr;
				}

				return toparent;
			}
		}

		if (nr_elem == 2) {
			if (val < l) {
				created = left->insert(val);
				if (created) {
					right = center;
					center = created;

					r = right->l;
					l = center->l;
					return nullptr;
				}
			} else {
				created = center->insert(val);
				if (created) {
					right = created;

					r = right->l;
					return nullptr;
				}
			}
		}

		if (nr_elem == 3) {
			if (val < l) {
				created = left->insert(val);

				if (created) {
					toparent = new BNode(tree, center, right);
					center = created;
					nr_elem = 2;
				}
			} else if (val < r) {
				created = center->insert(val);

				if (created) {
					toparent = new BNode(tree, created, right);
					nr_elem = 2;
				}
			} else {
				created = right->insert(val);

				if (created) {
					toparent = new BNode(tree, right, created);
					nr_elem = 2;
				}
			}

			if (is_root) {
				BNode* new_root = new BNode(tree, this, toparent);
				new_root->is_root = true;
				is_root = false;
				tree->root = new_root;
				return nullptr;
			}

			return toparent;
		}

		return nullptr;
	}

	BNode::BNode(BTree* t, int val) {
		tree = t;
		is_root = true;
		is_bottom = true;
		nr_elem = 1;
		ll = val;
	}

	BNode::BNode(BTree* t, int v1, int v2) {
		tree = t;
		is_root = false;
		is_bottom = true;
		nr_elem = 2;

		int tmp;
		if (v1 >= v2) {
			tmp = v1;
			v1 = v2;
			v2 = tmp;
		}

		ll = v1;
		lc = v2;
		l = lc;

	}

	BNode::BNode(BTree* t, BNode* n1, BNode* n2) {
		tree = t;
		is_root = false;
		is_bottom = false;
		nr_elem = 2;

		BNode *tmp;
		if (n1->l >= n2->l) {
			tmp = n1;
			n1 = n2;
			n2 = tmp;
		}

		l = n2->l;

		left = n1;
		center = n2;
	}

	void BTree::insert(int val) {
		if (nr_leaf == 0) {
			root = new BNode(this, val);
			nr_leaf++;
			return;
		}

		if (nr_leaf == 1) {
			root->nr_elem = 2;

			if (val >= root->ll) {
				root->l = val;
				root->lc = val;
			} else {
				int tmp = root->ll;
				root->ll = val;
				root->lc = tmp;
				root->l = tmp;
			}

			nr_leaf++;
			return;
		}

		root->insert(val);
		nr_leaf++;
	}

	BTree::BTree() {
		root = nullptr;
		nr_leaf = 0;
	}

};
