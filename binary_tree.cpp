#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(struct node* root ){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if (root == NULL ){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void postorder(struct node* root){
    if (root == NULL ){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root -> data << " ";
}

void levelorder(node* root){
    if (root == NULL){
        return;
    }   
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int cnt = 0;

    while(!q.empty()){
        node* node = q.front();
        q.pop();
        if(node != NULL){
            cout << node->data << " ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int sumatk(node* root, int pos){
    if (root == NULL){
        return -1;
    }   
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int total = 0, level = 0;

    while(!q.empty()){
        node* node = q.front();
        q.pop();

        if(node != NULL){
            if(pos == level ){
                total += node->data;
            }
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return total;
}

int main(){

    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    levelorder(root);
    int sum = sumatk(root , 2);
    cout << "\n" << sum << endl; 


    // cout << "preorder is ";
    // preorder(root);
    // cout << endl;
    // cout << "Inorder is ";
    // inorder(root);
    // cout << endl;
    // cout << "Postorder is ";
    // postorder(root);
}