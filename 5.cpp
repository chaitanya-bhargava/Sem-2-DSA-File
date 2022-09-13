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
    cout<<"Enter number of elements in array 1"<<endl;
    int size1;
    cin>>size1;
    int a1[size1];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size1;i++){
        cin>>a1[i];
    }
    cout<<"Enter number of elements in array 2"<<endl;
    int size2;
    cin>>size2;
    int a2[size2];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size2;i++){
        cin>>a2[i];
    }
    int a3[size1+size2];
    cout << "Sorting array 1 now \n";
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size1 - i - 1; j++)
        {
            if (a1[j + 1] < a1[j])
            {
                swap(j + 1, j, a1);
            }
        }
    }
    cout << "Sorting array 2 now \n";
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size2 - i - 1; j++)
        {
            if (a2[j + 1] < a2[j])
            {
                swap(j + 1, j, a2);
            }
        }
    }
    cout << "Merging array \n";
    for (int i = 0, j = 0, k = 0; i < size1+size2; i++)
    {
        if(j==size1){
            while(k<size2){
                a3[i]=a2[k];
                i++;
                k++;
            }
            break;
        }
        else if(k==size2){
            while(j<size1){
                a3[i]=a1[j];
                i++;
                j++;
            }
            break;
        }
        if (a1[j] > a2[k])
        {
            a3[i] = a2[k];
            k++;
        }
        else if (a1[j] < a2[k])
        {
            a3[i] = a1[j];
            j++;
        }
        else
        {
            a3[i] = a1[j];
            a3[i+1]=a2[k];
            i++;
            j++;
            k++;
        }
    }
    cout<<"The merged array is \n";
    for (int i = 0; i < size1+size2; i++)
    {
        cout<<a3[i]<<endl;
    }
    

    return 0;
}