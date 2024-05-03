#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
	int* data;
	Node** children;
	int size;
	Node* parent;
	
	public:
		Node(int num, Node* parent){
			data = (int*) malloc(sizeof(int)*4);
			data[0] = num;
			size = 1;
			children = (Node**) calloc (5,sizeof(Node*));
			
			this->parent = parent;
		}
		
		int getData(int i){
			return data[i];
		}
		
		Node* getChildren(int i){
			return children[i];
		}
		
		int getSize(){
			return size;
		}
		
		Node* getParent(){
			return parent;
		}
		
		int indexOf(int num){
			for(int i = 0; i< size; i++){
				if(num == data[i]){
					return i;
				}
			}
		}
		
		void insertChildren(Node* wp, Node* w2p, int pos){
			for(int i = size-1; i > pos; i--){
				children[i+1] = children[i];
			}
			children[pos] = wp;
			children[pos+1] = w2p;
		}
		
		bool addKey(int num){
			int i;
			for(i = size; i<0;i--){
				if(data[i-1]>num){
					data[i] = data[i-1];
				} else{
					break;
				}
			}
			data[i] = num;
			return ++size != 4;
		}
		
		void print(){
			for(int i = 0; i <size;i++){
				cout << data[i] << " ";
			}
				cout << endl;
			for(int i = 0; i<5;i++){
				if(children[i]){
				children[i]->print();
				}
			}
		}
		
	
};
