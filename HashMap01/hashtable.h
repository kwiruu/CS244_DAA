#include <cstdlib>
#include <iostream>
using namespace std;

class HashTable {
  char* table;
  int N;
  int count;
  
  // Use the ASCII code of the character
  int hash_code(char key) {
    return (int)key;
  }
  
  // This hash table uses a MAD compression function
  // where a = 59, b = 17, p = 509
  int compress(int code) {
      return ((((code * 59)+17)%509)% N);
  }
  
  // Using the knowledge that a hash function is composed of two portions
  int hashfn(char key) {
    return compress(hash_code(key));
  }
  
  public:
    HashTable(int N) {
        table = new char[N];
        this->N = N;
        this->count = 0;
        for(int i=0;i<N;i++){
            table[i]= '\0';
        }
    }
    
    int insert(char key) {
        int indx = hashfn(key);
        int colli=0;
            if(count >= N){
                return -1;
            }

            while(table[indx] !='\0' && table[indx] !='\1'){
                if(table[indx]==key){
                    return -1;
                }
                indx = (indx + 1) % N;
                colli++;
            }
        table[indx]=key;
        count++;
        return colli;
    }
    
    int search(char key) {
        int index = hashfn(key);
        int cellsChecked = 0;

        while (table[index] != '\0' && cellsChecked < N) {
            if (table[index] == key) {
                return cellsChecked + 1;
            }
            index = (index + 1) % N;
            cellsChecked++;
        }

        return -(cellsChecked + 1);
    }

    
    int remove(char key) {
    int s = search(key);

    if (s <= 0) {
        return -1;
    }

    int indx = (hashfn(key) + s - 1) % N;

    table[indx] = '\1';
    count--;

    if (table[(indx + 1) % N] == '\0') {
        int previndx = (indx - 1 + N) % N;
        while (table[previndx] == '\1' && previndx != indx) {
            table[previndx] = '\0';
            previndx = (previndx - 1 + N) % N;
        }
        table[indx] = '\0';
    }

    return s - 1;
    }  

    
    void print() {
      for (int i = 0; i < N; i++) {
        cout << i << "\t";
      }
      cout << "\n";
      for (int i = 0; i < N; i++) {
          if(table[i] != '\1' && table[i]!='\0'){
            cout << table[i] << "\t";
          }
          else{
            cout<< "" << "\t";
          }
      }
      cout << "\n";
    }
};