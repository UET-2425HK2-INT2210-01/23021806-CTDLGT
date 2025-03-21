#include <iostream>

using namespace std;

const int TABLE_SIZE = 11;
const int EMPTY = -1;

int hashFunction(int key){
    return (2 * key + 5) % TABLE_SIZE;
}

void insertLinearProbing(int hashTable[], int key){
    int index = hashFunction(key);
    while (hashTable[index] != EMPTY){ 
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

void printHashTable(int hashTable[]){
    for (int i = 0; i < TABLE_SIZE; i++){
        cout << i << " -> ";
        if (hashTable[i] == EMPTY) cout << "NULL\n";
        else cout << hashTable[i] << "\n";
    }
}

int main(){
    int keys[] ={12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};
    int hashTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = EMPTY;
    }

    for (int key : keys){
        insertLinearProbing(hashTable, key);
    }

    cout << "Bảng băm 11 phần tử (Linear Probing):\n";
    printHashTable(hashTable);

    return 0;
}
