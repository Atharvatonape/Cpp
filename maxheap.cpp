#include<stdio.h>
#include<vector>
#include<iostream>

using namespace std;

class maxheap{
    
    private:

    int size = 0;
    vector <int> vect = {-1};
    int parent(int i) { return i/2;};
    int left(int i) { return 2*i;};
    int right(int i) {return 2*i+1;};

    public:
    
    bool const isempty(){
        if(size == 0){
            return true;
        }
    }
 
    int const getmax(){
        return vect[1];
    } 

    void insertitem(int val){
        vect.push_back(val); // Push the new value to the end of the vector
        size++;
        shiftup(size);
        display();
    }

    void shiftup(int pos){
        while(pos > 1 && vect[parent(pos)] < vect[pos]){
            swap(vect[parent(pos)], vect[pos]);
            pos = parent(pos);
        }
    }

    void shiftdown(int i) {

        int leftChild = left(i);
        int rightChild = right(i);
        int swapId = i;

        if (leftChild <= size && vect[leftChild] > vect[i]) {
            swapId = leftChild;
        }

        if (rightChild <= size && vect[rightChild] > vect[swapId]) {
            swapId = rightChild;
        }

        if (swapId != i) {
            swap(vect[i], vect[swapId]);
            shiftdown(swapId);
        }
    }


    int extractmax(){
        int max = vect[1];
        swap(vect[1], vect[size]);
        vect.pop_back();
        size--;
        shiftdown(1);
        return max;

    }

    void display(){
        for (int i = 0; i < vect.size(); ++i) {
            cout << vect[i] << " ";
        }
            cout << endl;
    }

};

int main(){
    cout << "Welcome to Max Heap problem : " << endl;
    
    maxheap m;
    
    m.insertitem(100);
    m.insertitem(75);
    m.insertitem(95);
    m.insertitem(60);
    m.insertitem(65);
    m.insertitem(90);

    
    //m.display();

    m.extractmax();
    m.display();
}