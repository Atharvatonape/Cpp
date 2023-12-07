#include<iostream>
#include<stdio.h>
#include<map>

using namespace std;

int main(){
    map<char,int> mp = {
        {'T', 5},
        {'a', 6},
        {'s', 7}, 
        {'T', 10}
    };

    cout << mp['T'] <<endl;
}