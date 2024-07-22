#include <iostream>
using namespace std;
int Search(int v[], int size, int k)
{
    for (int i = 0; i < size; i++)
    {
        if (v[i] == k)
        {
            return i;
            break;
        }
    }
    return -1;
}
void Sorting(int v[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    cout << "After Sorting : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void Insert(int v[], int &size)
{
    int number;
    cout << "Enter the number : ";
    cin >> number;
    cout << "Enter the index at which it should be inserted : ";
    int ind;
    cin >> ind;
    if (ind < 0 || ind >= size)
    {
        cout << "Invalid index for insertion." << endl;
        return;
    }
    size++;
    for (int i = size - 2; i >= ind; i--)
    {
        v[i + 1] = v[i];
    }
    v[ind] = number;
    cout << "After Insertion : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void Delete_element(int v[], int &size, int k)
{
    int index = Search(v, size, k);
    if (index == -1)
    {
        cout << "Please enter proper number.\n";
        return;
    }
    for (int i = index; i < size; i++)
    {
        v[i] = v[i + 1];
    }
    size--;
    cout << "After Deletion : \n";
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int num, size;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter elements of array : " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int code;
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "Choose any one option : \n1. Searching\t2. Sorting\t3. Inserting\t4. Deleting\nEnter Code : ";
        cin >> code;
        switch (code)
        {
        case 1:
        {
            int k;
            cout << "Enter the number : ";
            cin >> k;
            int index = Search(arr, size, k);
            if (index != -1)
            {
                cout << "The number " << k << " is present at index " << index << endl;
            }
            else
            {
                cout << "The number " << k << " is not present in the given list." << endl;
            }
            break;
        }
        case 2:
        {
            Sorting(arr, size);
            break;
        }
        case 3:
        {
            Insert(arr, size);
            break;
        }
        case 4:
        {
            int k;
            cout << "Enter the number : ";
            cin >> k;
            Delete_element(arr, size, k);
            break;
        }
        default:
        {
            cout << "Enter proper code.\n";
            break;
        }
        }
        cout << "Do you wish to continue ? (y/n) : ";
        cin >> ch;
    }
    return 0;
}