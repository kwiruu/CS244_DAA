#include <iostream>
#include "tree24.h"

int main(int argc, char** argv){
	Tree24* tree = new Tree24();
	
	tree->insert(4);
	tree->insert(5);
	tree->insert(13);
	tree->insert(17);
	cout << "searching 5: ";
	tree->search(5)->print();
	
	
	cout << endl;
	
	tree->print();
	return 0;
}
