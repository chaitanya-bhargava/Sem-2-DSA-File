#include <iostream>
using namespace std;

void swap(int i, int j, int *arr)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int main()
{
    cout<<"Enter number of elements"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j+1] < arr[j])
            {
                swap(j+1, j, arr);
            }
        }
    }
    float mean=0;
    for(int i=0;i<size;i++){
        mean+=arr[i];
    }
    mean/=size;
    float median;
    if(size%2==0){
        median=(float)(arr[(size)/2-1]+arr[size/2])/2;
    }else{   
        median=arr[(size+1)/2-1];
    }
    cout<<"Mean: "<<mean<< " Median : "<< median<<endl;
    return 0;
}