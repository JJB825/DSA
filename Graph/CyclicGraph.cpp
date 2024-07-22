#include <iostream>
using namespace std;
struct edgelist
{
    int v;
    edgelist *next;
    edgelist(int x)
    {
        this->v = x;
        this->next = NULL;
    }
};
struct nodelist
{
    int vertex;
    nodelist *next;
    edgelist *List;
    bool vis;
    nodelist(int x)
    {
        this->vertex = x;
        this->next = NULL;
        this->List = NULL;
        this->vis = false;
    }
};
nodelist *head = NULL;
nodelist *search(int x)
{
    nodelist *temp = head;
    while (temp && temp->vertex != x)
    {
        temp = temp->next;
    }
    return temp;
}
void addEdge(int x, int y)
{
    nodelist *u = search(x);
    edgelist *temp = u->List;
    while (temp && temp->next)
    {
        temp = temp->next;
    }
    if (!temp)
    {
        temp = new edgelist(y);
        u->List = temp;
    }
    else
    {
        temp->next = new edgelist(y);
    }
}
void display()
{
    nodelist *temp = head;
    while (temp)
    {
        cout << temp->vertex << " --> ";
        edgelist *temp2 = temp->List;
        while (temp2)
        {
            cout << temp2->v << " ";
            temp2 = temp2->next;
        }
        cout << endl;
        temp = temp->next;
    }
}
bool isCyclicUtil(nodelist *curr, nodelist *parent)
{
    curr->vis = true;
    edgelist *temp2 = curr->List;
    while (temp2)
    {
        nodelist *adj = search(temp2->v);
        if (!adj->vis)
        {
            if (isCyclicUtil(adj, curr))
                return true;
        }
        else if (adj != parent)
            return true;
        temp2 = temp2->next;
    }
    return false;
}
bool isCyclic()
{
    nodelist *temp = head;
    while (temp)
    {
        if (!temp->vis)
        {
            if (isCyclicUtil(temp, NULL))
                return true;
        }
        temp = temp->next;
    }
    return false;
}
int main()
{
    int V, v, num, e;
    cout << "Enter number of vertices : ";
    cin >> V;
    for (int i = 0; i < V; i++)
    {
        cout << "Enter vertex : ";
        cin >> v;
        nodelist *temp = new nodelist(v);
        if (!head)
        {
            head = temp;
        }
        else
        {
            nodelist *temp2 = head;
            while (temp2->next)
            {
                temp2 = temp2->next;
            }
            temp2->next = temp;
        }
        cout << "Enter number of adjacent vertices : ";
        cin >> num;
        if (num == 0)
        {
            continue;
        }
        cout << "Enter adjacent vertices : ";
        for (int i = 0; i < num; i++)
        {
            cin >> e;
            addEdge(v, e);
        }
    }
    cout << "Graph : \n";
    display();
    if (isCyclic())
    {
        cout << "Graph is cyclic\n";
    }
    else
    {
        cout << "Graph is acyclic\n";
    }
    return 0;
}