#include <iostream>
#define MAX 100
using namespace std;
struct object
{
    int info, priority;
};
class priorityQueue
{
    object obj[MAX];
    int size = -1;

public:
    void insert(int d, int p)
    {
        size++;
        obj[size].info = d;
        obj[size].priority = p;
    }
    int peek() // this becomes min or max based on ascending or descending priority queue
    {
        int hP = INT16_MIN;
        int ind = -1;
        if (size == -1)
        {
            return -1;
        }
        for (int i = 0; i <= size; i++)
        {
            if ((hP < obj[i].priority) || (hP == obj[i].priority && obj[ind].info < obj[i].info))
            {
                hP = obj[i].priority;
                ind = i;
            }
        }
        return ind;
    }
    int extract() // this becomes extractmin or extractmax based on ascending or descending priority queue
    {
        int ind = peek();
        if (ind == -1)
        {
            return -1;
        }
        int x = obj[ind].info;
        for (int i = ind; i <= size; i++)
        {
            obj[i] = obj[i + 1];
        }
        size--;
        return x;
    }
    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << obj[i].info << " ";
        }
    }
};
int main()
{
    priorityQueue pQ;
    int num, val, p;
    cout << "Enter number of elements to be inserted : ";
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        cout << "Enter value : ";
        cin >> val;
        cout << "Enter priority : ";
        cin >> p;
        pQ.insert(val, p);
    }
    if (pQ.extract() == -1)
    {
        cout << "Empty queue\n";
    }
    cout << "The value of having maximum priority is : " << pQ.extract() << endl;
    pQ.display();
    return 0;
}