#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int arr[] = {1,0,1,0,0,0};

    int cost = 0;

    for(int i=0; i<6; i++){
        
        if (cost%2 == 1){
            if(arr[i] == 0){
                arr[i] = 1;
            }
            else if(arr[i] == 1){
                arr[i] =0;
            }
        }

        if(arr[i] % 2 == 0){
            cost++;
        }
    }
    cout << cost <<"\n";

    int cost2 = 0;

    for(int i=0; i<6; i++){
        if(arr[i] % 2 == 0){
            continue;
        }
        else if(arr[i] % 2 ==1){
            cost2++;
        }
    }
    cout << cost2 <<"\n";

}
