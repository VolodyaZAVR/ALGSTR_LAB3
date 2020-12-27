#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    Tree* bst = new Tree();
	bst->insert(8);
	bst->insert(3);
	bst->insert(6);
	bst->insert(1);
	bst->insert(7);
	bst->insert(4);
	bst->insert(10);
	bst->insert(13);
	bst->insert(14);

	Iterator* bst_iterator = bst->create_bft_iterator();
	while (bst_iterator->has_next())
		cout << bst_iterator->next() << ' ';
}
