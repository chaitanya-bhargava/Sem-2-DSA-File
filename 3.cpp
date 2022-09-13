#include <iostream>
using namespace std;
int main()
{
    int k;
    cout<<"Enter number of elements"<<endl;
    int size;
    cin>>size;
    int arr[size];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout << "Enter element to be searched\n";
    cin >> k;
    int counter;
    for (counter = 0; counter < size; counter++)
    {
        if (arr[counter] == k)
        {
            break;
        }
    }
    if (counter == size)
    {
        cout << "The element could not be found\n";
    }
    else
    {
        cout << "The element was found at index " << counter << "\n";
    }
    cout<<"Quitting...";
    return 0;
}