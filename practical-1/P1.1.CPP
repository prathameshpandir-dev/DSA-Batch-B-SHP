#include <iostream>
using namespace std;

int main(){
    int i,no=0,rot;


    cout<<"Enter the number of elements in array: ";
    cin>>no;

    int arr[n];

    for(i=0;i<no;i++){
        cout<<"Enter the "<<i+1<<" element: ";
        cin>>arr[i];
    }
    cin>>rot;
    for(i=rot;i<no;i++){

        cout<<arr[i] ;
        cout<<" ";
    }
    for(i=0;i<rot;i++){
        cout<<arr[i];
        cout<<" ";
    }
    return 0;
}
