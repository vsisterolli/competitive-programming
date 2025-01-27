#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<ll, ll> pii;
typedef vector<vector<ll>> mat;
typedef pair<int, pii> piii;
const ll mod = 1e9+7;
const int MAXN = 1e5+5;

struct node  {
	int val, key, sz;
	node *l, *r;
	
	node (int x) {
		val = x, key = rand(), sz = 1;
		l = r = NULL;
	}
	
};

node *root = NULL;

int sz(node *root)  {
	return root ? root->sz : 0;
}

void upd(node *root)  {
	
	if(!root) return;
	
	root->sz = sz(root->l) + sz(root->r);
	
}

void Split(node *root, node *&l, node *&r, int x)  {
	
	if(!root) 
		l = r = NULL;
	
	else {
		if(root->val <= x) Split(root->r, root->r, root->r, x), l = root;
		
		else Split(root->l, root->l, root->l, x), r = root; 
		
		upd(root);
	}
	
}

void merge(node *&root, node *l, node *r)  {
	if(!l or !r) root = (l ? l : r);
	
	else {
		if(l->key > r->key) merge(l->r, l->r, r), root = l;
		
		else merge(r->l, l, r->l), root = r;
		
		upd(root);
	}
}

void insert(int x)  {
	node *kappa = new node(x);
	node *left = NULL;
	node *right = NULL;
	
	Split(root, left, right, x);
	
	merge(left, left, kappa);
	merge(root, left, right);
}

void print(node *root) {
	if(!root) return;
	cout << root->val << endl;
	print(root->l);
	cout << "voltou pra " << root->val << endl;
	print(root -> r);

}

int32_t main() 
{
	
	for(int i = 0; i < 10; i++) 
	{
		int x;
		cin >> x;
		insert(x);
		
	}
	print(root);
	
}
