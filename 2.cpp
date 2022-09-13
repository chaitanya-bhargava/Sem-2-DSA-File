#include<iostream>
using namespace std;

void startinsert(int n,int * arr,int *size){
    for(int i=*size;i>-1;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=n;
    (*size)++;
}
void endinsert(int n,int * arr,int *size){
    arr[*size]=n;
    (*size)++;
}
void midinsert(int n,int * arr,int k,int *size){
    for(int i=*size;i>k-1;i--){
        arr[i+1]=arr[i];
    }
    arr[k]=n;
    (*size)++;
}
void startdelete( int *arr,int* size)
{
    for (int  i = 0; i < *size; i++)
    {
        arr[i] = arr[ i+1];
        
        
    }
    (*size)--;
    
}
void enddelete( int *arr,int* size)
{
    (*size)--;
}
void middelete( int *arr, int k,int * size)
{
    for (int  i = k; i < *size; i++)
    {
        arr[i] = arr[ i + 1 ];
        
    }
    (*size)-- ;
}
int main(){
    cout<<"Enter number of elements"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans;
    while(1){
    cout<<"------------------------------\n1.Insert element at start\n2.Insert element at end\n3.Insert element at an index\n4.Delete element at start\n5.Delete element at end\n6.Delete element at an index\n7.Quit\n------------------------------\nChoose operation{1,2,3,4,5,6,7}:\n";
    cin>>ans;
    int n;
    switch (ans)
    {
    case 1:
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        startinsert(n,arr,&size);
        break;
    case 2:
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        endinsert(n,arr,&size);
        break;
    case 3:
        int index1;
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        cout<<"Enter the index to be inserted at:\n";
        cin>>index1;
        midinsert(n,arr,index1,&size);
        break;
    case 4:
        startdelete(arr,&size);
        break;
    case 5:
        enddelete(arr,&size);
        break;
    case 6:
        int index2;
        cout << "Enter the index to be deleted at:\n";
        cin >> index2;
        middelete(arr,index2,&size);
        break;
    case 7:
        cout<<"Quitting...";
        exit(0);
    default:
        cout<<"Wrong entry..."<<endl;
        break;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    }
    return 0;
}