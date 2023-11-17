#include<stdio.h>
#include<iostream>

using namespace std;

class heap{
    
    private:
    int heapvar;

    /*int left = 2*heapvar;
    int right = 2*heapvar + 1;
    int parent = heapvar / 2 ;
    int maxheap[10];*/

    int maxheap[10];

    public:

    heap(){
        heapvar = 0;
        for(int i=0; i<10; i++){
            maxheap[i] = 0;
        }
    }

    bool isempty(){
    /* int cnt;
        for(int i=0; i<10; i++){
            if(maxheap[i] == 0 ){
                cnt++;
            }
        }
        if (cnt == 10){
            return true;
        }
        else{
            return false;
        }

    */
    if (heapvar != 0){
        return false;
    }
    else{
        return true;
    }
    }



    void hpinsert(int val){
        if (isempty() == true){
            cout << "Entered Empty ";
            maxheap[0] = val;
            heapvar++;
        }
        else{
            heapvar++;
            int parent = heapvar/2 ;
            if(maxheap[parent] < val){
                int temp;
                temp = maxheap[parent];
                maxheap[parent] = val;
                maxheap[heapvar] = temp;
            }
            
        }
    }

    void display(){
        for(int i =0; i<10; i++){
            cout << maxheap[i] << " " ;
        }
        cout << endl;
    }


};

int main(){
    cout << "This is a Heap problem "<<endl;
    heap s;
    s.hpinsert(11);
    s.hpinsert(10);
    s.hpinsert(7);
    s.hpinsert(9);
    s.hpinsert(5);
    s.hpinsert(6);
    s.hpinsert(4);
    s.hpinsert(8);
    s.hpinsert(2);
    s.hpinsert(3);
    
    s.display();

}