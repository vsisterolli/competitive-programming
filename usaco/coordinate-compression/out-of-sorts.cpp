#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

struct Entry {
	int val;
	int index;
};

int main() {
	//std::ifstream read("sort.in");
	int n;
	std::cin >> n;
	vector<Entry> entries(n);
	for (int i = 0; i < n; i++) {
		std::cin >> entries[i].val;
		entries[i].index = i;
	}

	std::sort(entries.begin(), entries.end(), [](const Entry &e1, const Entry &e2) {
		return e1.val == e2.val ? e1.index < e2.index : e1.val < e2.val;
	});

	// count the # of bubbles needed to sort the array
	int moo_amt = 1;
	for (int i = 0; i < n; i++) {
		// add 1 to account for the final iteration of the algorithm
		moo_amt = std::max(moo_amt, 1 + entries[i].index - i);
	}

	cout << moo_amt << endl;
}