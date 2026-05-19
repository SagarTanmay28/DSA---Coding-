#include<iostream>
using namespace std;

void display(int a[], int size){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
    return;
}

void change(int b[], int size){
    b[0] = 123;
    cout<<endl;
    
}

// Array Pass by Reference Aahe &
// Vector Pass by Value Aahe 

int main(){
    int arr[5]={1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]); // size is in main function only not in above function 
    // we pass size also with the array in function 
    // if we write this in above function then 
    //error :: sizeof(a) will return the size of the pointer, not the array itself
    cout<<size<<endl;

    display(arr,size);
    change(arr,size);
    display(arr,size);
}