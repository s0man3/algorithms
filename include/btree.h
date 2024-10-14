namespace gen {
	class BTree;

	class BNode {
		public:
			BTree* tree;

			bool is_root;
			bool is_bottom;
			int nr_elem;

			int l;
			int r;

			BNode* left;
			BNode* center;
			BNode* right;

			int ll;
			int lc;
			int lr;

			BNode(BTree* tree, int val);
			BNode(BTree* tree, int v1, int v2);

			BNode(BTree* tree, BNode* n1, BNode* n2);

			BNode* insert(int val);
	};

	class BTree {
		public:
			BNode* root;
			int nr_leaf;

			BTree();
			void insert(int val);
	};
}
