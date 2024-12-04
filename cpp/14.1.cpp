#include <iostream>
#include <stdexcept>
#include <limits> 

using namespace std;

int accessElement(int arr[], int size, int index)
{
    if (index < 0 || index >= size)
    {
        throw out_of_range("Array index out of bounds error!");
    }

    return arr[index];
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    cout << "Enter an index to access (0 to 4): ";
    cin >> index;

    try
    {
        if (cin.fail())
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            throw invalid_argument("Non-integer input error!");
        }

        int value = accessElement(arr, 5, index);
        cout << "Element at index " << index << " is: " << value << endl;
    }
    catch (const out_of_range &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
