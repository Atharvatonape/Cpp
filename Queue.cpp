#include<iostream>
#include<stdio.h>

using namespace std;

class queue{
    public:
    
    int front;
    int rear;
    int arr[5];

    queue(){
        front = -1;
        rear = -1;
        for(int i=0; i<5; i++){
            arr[i] = 0;
        }
    }

    bool isfull(){
        if(rear == 4){
            return true;
        }
        else{
            return false;
        }
    }

    bool isempty(){
        if (front == 5 || rear == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int val){
        if (isfull() == true ){
            cout << "Queue overflow " << endl;
        }
        else{
            if(isempty() == true){
                front++;
                rear++;
                arr[front] = val;                 
            }
            else{
            rear++;
            arr[rear] = val;
            cout << "Enqueue Done " << val << endl;

            }

        }
    }

    void dequeue(){
        if (isempty() == true ){
            cout << "Queue Underflow " << endl;
        }
        else{
            cout << arr[front] << endl;
            arr[front] = 0;
            front++;
        }
    }

    void peek(){

        for(int i=0; i<5; i++){
            cout << arr[i] << "->";
        }
        cout << endl;
    }
};

int main(){

    cout << "Entered the queue program " << endl;
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    //q.enqueue(6);

    q.peek();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.peek();


}