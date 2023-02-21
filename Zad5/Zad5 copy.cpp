#include <iostream>


using namespace std;

struct node
{
    int dest;
    node* next;
};

class list
{
    public:
    node *head;

    node *newNode(int dest)
{
    node *newNode = new node;
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
};

class graph
{
    public:
    int v;
    list *array;
    graph *createGraph(int v)
{
    graph *Graph = new graph;
    Graph->v = v;

    Graph->array = new list[v];

    for (int i=0; i<v; i++)
    {
        Graph->array[i].head = NULL;
    }
    return Graph;
}

};




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;


    
    return 0;
}