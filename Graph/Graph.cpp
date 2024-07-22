#include<iostream>
#include <queue>
using namespace std;
struct edgelist
{
    int v;
    edgelist *next;
    edgelist(int x)
    {
        this->v=x;
        this->next=NULL;
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
        this->vertex=x;
        this->next=NULL;
        this->List=NULL;
        this->vis=false;
    }
};
nodelist *head=NULL;
nodelist *search(int x)
{
    nodelist *temp=head;
    while (temp && temp->vertex!=x)
    {
        temp=temp->next;
    }
    return temp;
}
void addEdge(int x,int y)
{
    nodelist *u=search(x);
    edgelist *temp=u->List;
    while (temp && temp->next)
    {
        temp=temp->next;
    }
    if(!temp)
    {
        temp=new edgelist(y);
        u->List=temp;
    }
    else
    {
        temp->next=new edgelist(y);
    }
}
void display()
{
    nodelist *temp=head;
    while (temp)
    {
        cout<<temp->vertex<<" --> ";
        edgelist *temp2=temp->List;
        while (temp2)
        {
            cout<<temp2->v<<" ";
            temp2=temp2->next;
        }
        cout<<endl;
        temp=temp->next;
    }
}
void BFS()
{
    queue<int> q;
    nodelist *temp = head;
    temp->vis = true;
    cout << temp->vertex << " ";
    q.push(temp->vertex);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        nodelist *ptr = search(u);
        edgelist *temp2=ptr->List;
        while (temp2)
        {
            nodelist *ptr1 = search(temp2->v);
            if (!ptr1->vis)
            {
                ptr1->vis = true;
                cout << ptr1->vertex << " ";
                q.push(ptr1->vertex);
            }
            temp2=temp2->next;
        }
        ptr->vis = true;
    }
    cout << endl;
}
void DFSvisit(nodelist *ptr)
{
    ptr->vis = true;
    cout << ptr->vertex << " ";
    edgelist *temp2=ptr->List;
    while (temp2)
    {
        nodelist *ptr1 = search(temp2->v);
        if (!ptr1->vis)
        {
            DFSvisit(ptr1);
        }
        temp2=temp2->next;
    }
    ptr->vis = true;
}
void DFS()
{
    nodelist *temp = head;
    int count = 0;
    while (temp != nullptr)
    {
        if (!temp->vis)
        {
            count++;
            DFSvisit(temp);
        }
        temp = temp->next;
    }
    if (count > 1)
    {
        cout << "\nGraph is not connected\n";
    }
    else
    {
        cout << "\nGraph is connected\n";
    }
}
bool isConnected()
{
    nodelist *temp = head;
    while (temp)
    {
        if (!temp->vis)
        {
            return false;
            break;
        }
        temp = temp->next;
    }
    return true;
}
int main()
{
    int V,v,num,e;
    cout<<"Enter number of vertices : ";
    cin>>V;
    for (int i = 0; i < V; i++)
    {
        cout<<"Enter vertex : ";
        cin>>v;
        nodelist *temp=new nodelist(v);
        if(!head)
        {
            head=temp;
        }
        else
        {
            nodelist *temp2=head;
            while (temp2->next)
            {
                temp2=temp2->next;
            }
            temp2->next=temp;
        }
        cout<<"Enter number of adjacent vertices : ";
        cin>>num;
        if (num==0)
        {
            continue;
        }
        cout<<"Enter adjacent vertices : ";
        for (int i = 0; i < num; i++)
        {
            cin>>e;
            addEdge(v,e);
        }
    }
    cout<<"Graph : \n";
    display();
    // cout<<"\nBFS traversal of Graph : ";
    // BFS();
    // if(isConnected())
    // {
    //     cout<<"Graph is connected\n";
    // }
    // else
    // {
    //     cout<<"Graph is not connected\n";
    // }
    cout<<"\nDFS traversal of Graph : ";
    DFS();
    return 0;
}