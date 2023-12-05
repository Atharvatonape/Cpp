#include <iostream>
#include <list>
using namespace std;

struct Hash {
    int bucket;
    list<int> *table;

    Hash(int b) {
        bucket = b;
        table = new list<int>[b];
    }

    ~Hash() {
        delete[] table;
    }

    void insert(int value) {
        int key = hashFunction(value);
        table[key].push_back(value);
    }

    void remove(int value) {
        int key = hashFunction(value);
        table[key].remove(value);
    }

    int hashFunction(int value) {
        return value % bucket;
    }

    void displayHash() {
        for (int i = 0; i < bucket; i++) {
            cout << "Bucket " << i << ": ";
            for (int value : table[i])
                cout << value << " -> ";
            cout << "NULL" << endl;
        }
    }
};

int main() {
    Hash h(10); // Create a hash table with 10 buckets
    cout << "Enter to Hashing Program" << endl;

    // Example usage
    h.insert(15);
    h.insert(25);
    h.insert(35);
    h.insert(1);
    h.insert(2);   
    h.insert(3);
    h.insert(4);
    h.insert(6);
    h.insert(7);
    h.insert(8);

    h.displayHash(); // Display the hash table

    return 0;
}
