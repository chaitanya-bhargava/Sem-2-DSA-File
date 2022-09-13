#include<iostream>
using namespace std;

int main(){
    int arr[10][5];
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
        cout<<"Enter marks of student "<<i+1<<" in subject "<<j+1<<endl;
        cin>>arr[i][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
        cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}