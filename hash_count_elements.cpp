#include<iostream>

using namespace std;

int main(){
    int number_arr_elements;
    cin>> number_arr_elements;

    int arr[number_arr_elements];

    for(int i=0;i<number_arr_elements;i++){
        cin >> arr[i];
    }

    // Precompute
    int hash[13] = {0};
    for(int i=0;i<number_arr_elements;i++){
        hash[arr[i]]++;
    }


    int q;
    cin >> q;

    while(q--){
        int number;
        cin >> number;

        cout << hash[number] << endl;
    }

}