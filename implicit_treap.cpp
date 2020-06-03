struct node {
	int key = 0, val = 0, sz = 0, lazy = 0;
	node *l = NULL,  *r = NULL;
	
	
	node (int x) {
		l = r = NULL;
		val = x, lazy = 0, key = rand(), sz = 1;
	}
	
	void propagate() {
		if( (lazy%2) == 0) return;
		swap(l, r);
		if(l) l->lazy++;
		if(r) r->lazy++;
		lazy = 0;
		return;
	}
	
};

node *root = NULL;

int Sz(node *root) {
	return root ? root->sz : 0;
}

void upd(node *root) {
	if(!root) return;
	root->sz = Sz(root->l) + Sz(root->r) + 1;
}

void split(node *root, node *&l, node *&r, int k) {
	if(!root) l = r = NULL;
	else {
		root->propagate();
		int pa = Sz(root->l)+1;
		if(pa <= k) split(root->r, root->r, r, k-pa), l = root;
		else split(root->l, l, root->l, k), r = root;
		upd(root);
	}
}

void merge(node *&root, node *l, node *r) {
	if(!l or !r) root = l ? l : r;
	else {
		l->propagate();
		r->propagate();
		if(l->key > r->key) merge(l->r, l->r, r), root = l;
		else merge(r->l, l, r->l), root = r;
		upd(root);
	}
}

void insert(int i, int x) {
	node *left = NULL, *right = NULL, *kappa = new node(x);
	split(root, left, right, i-1);
	merge(left, left, kappa);
	merge(root, left, right);
}

void print(node *root) {
	if(!root) return;
	root->propagate();
	print(root->l);
	cout << root->val << " ";
	print(root->r);
	return;
}
