#include <iostream>
#include "node.h"
#include "list.h"
using namespace std;
class LinkedList : public List{
    node* head;
    node* tail;
    

    public:

    int size=0;

    void addFirst(int num){
        node* curr = new node;
        curr->elem = num;
        if(size==0){
            head = curr;
            tail = curr;
            cout << "wow" <<endl;
        }
        else{
        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;
        }
        size++;
    }

    void addLast(int num){
        node* curr = new node;
        curr->elem = num;
        if(size==0){
            head=curr;
            tail=curr;
        }
        else{
        curr->prev = tail;
        tail->next = curr;
        curr->next = nullptr;
        tail = curr;
        }
        size++;
    }

    void removeFirst(){
        cout << "yawa";
        node* curr = head;
        int temp = curr->elem;
        if(size==0){
            cout << size;
            cout << "List is empty" << endl;
        }
        else{
            if(size==1){
                head=nullptr;
                tail=nullptr;
                size--;  
                cout << "Removed: " << temp << endl;
            }
            else{
                curr = curr->next;
                curr->prev = nullptr;
                head = curr;
                size--;
                cout << "Removed: " << temp << endl;
            }
            
        delete curr;
        }
    }

    int removeLast(){
        return 0;
    }

    int get(int pos){
        return 0;
    }

    void print(){
        node* curr = new node;
        node* trav = new node;
        curr = head;
        trav = tail;
        cout << size << endl;
        if(size == 0){
            cout << "Empty" << endl;
        }
        else{
        while(curr!=tail->next){
            cout << curr->elem;
            if(curr){
                cout << " -> ";
            }
            else{
                cout << endl;
            }
            curr = curr->next;
        }
        cout << endl;
        while(trav!=head->prev){
            cout << trav->elem;
            if(trav){
                cout << " -> ";
            }
            else{
                cout << endl;
            }
            trav = trav->prev;
        }
        }
        cout << endl;
    }
};