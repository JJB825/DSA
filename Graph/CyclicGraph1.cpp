#include <bits/stdc++.h> 
#include <queue>
using namespace std;
class DSU { 
    int* parent; 
    int* rank; 
  
public: 
    DSU(int n) 
    { 
        parent = new int[n]; 
        rank = new int[n]; 
  
        for (int i = 0; i < n; i++) { 
            parent[i] = -1; 
            rank[i] = 1; 
        } 
    } 
  
    int find(int i) 
    { 
        if (parent[i] == -1) 
            return i; 
  
        return parent[i] = find(parent[i]); 
    } 

    void unite(int x, int y) 
    { 
        int s1 = find(x); 
        int s2 = find(y); 
  
        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    } 
}; 
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
    nodelist *par;
    nodelist(int x)
    {
        this->vertex=x;
        this->next=NULL;
        this->List=NULL;
        this->vis=false;
        this->par=NULL;
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
bool kruskal(int V, vector<vector <int> > edges)
{
    DSU s(V);
    sort(edges.begin(),edges.end());
    for (auto edge : edges)
    {
        int x=edge[0];
        int y=edge[1];
        if(s.find(x)==s.find(y))
        {
            return true;
            break;
        }
        if (s.find(x)!=s.find(y))
        {
            s.unite(x,y);
        }
    }
    return false;
}
int main()
{
    int V,v,num,e;
    vector<vector<int> > edges; 
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
            edges.push_back({v,e});
        }
    }
    cout<<"Graph : \n";
    display();
    bool isCyclic = kruskal(V, edges);
    if(isCyclic)
    {
        cout<<"Graph contains a cycle\n";
    }
    else
    {
        cout<<"Graph doesn't contain cycles\n";
    }
    return 0;
}