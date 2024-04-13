#include <iostream>
#include "linkedlist.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	LinkedList* list = new LinkedList();
	char op;
	int num, pos;
	do {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case 'f':
				cin >> num;
				list->addFirst(num);
				break;
			case 'l':   
				cin >> num;
				list->addLast(num);
				break;
			case 'F':
				list->removeFirst();
				break;
			case 'L':
				list->removeLast();
				break;
			case 'p':
				list->print();
				break;
			case 'g':
				cin >> num;
				cout << "Pos " << num << " is " << list->get(num) << endl;
				break;
			case 'x':
				cout << "Exiting";
				break;
		}
	} while (op != 'x');
	return 0;
}