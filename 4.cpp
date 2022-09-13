#include <iostream>
using namespace std;

int main()
{
    cout<<"Enter number of elements"<<endl;
    int size;
    cin>>size;
    int array[size];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    int temp;
    for (int i = 1; i < size; i++)
    {
        temp = array[i];
        int j = i - 1;
        while ((j >= 0) && (array[j] > temp))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    return 0;
}
