#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

class node{
    public:
    int data;
    node * next ;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insertail(node* &head, int val){
    node * n = new node(val);    
    //check for the null condition of the linkedlist
    if(head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    if(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void insertathead(node* &head, int val){
    node * n = new node(val);
    //check for the null condition of the linkedlist
    if(head == NULL){
        head = n;
        return;
    }
    node *temp = head;
    head = n;
    n->next = temp;
}

void insertatmid(node* &head, int val, int pos) {
    node* n = new node(val);
    node* temp = head;
    node* temp2;
    cout << "Entered mid " << endl;
    int cnt = 0;

    while (temp != NULL && cnt < pos - 1) {
        temp = temp->next;
        cnt = cnt + 1;
    }

    if (cnt < pos - 1 || temp == NULL) {
        cout << " Unfortunately it is not possible " << endl;
    } else {
        temp2 = temp->next;
        temp->next = n;
        n->next = temp2;
    }
}

void deletion(node* head ,int pos){
    node * temp = head;
    node* temp2;
    int cnt=0;
    while (temp != NULL && cnt < pos-1){
        temp = temp->next;
        cnt = cnt +1;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
}       

int main(){
    node * head = NULL;
    insertail(head, 5);
    insertail(head, 6);
    insertail(head, 7);

    insertathead(head, 10);

    insertatmid(head, 11 , 3);

    deletion(head , 2);
    display(head);
    cout << "-------Done------";
}
