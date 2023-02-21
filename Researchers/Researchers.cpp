#include <iostream>
#include <fstream>

using namespace std;



struct Node
{
public:
    short amount;
    string name;
    Node *next;
    Node *parent;
    Node *child;
    Node *sibling;

    Node()
    {
        amount = 0;
        name = 'null';
        next = NULL;
        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
};

void print2(Node *printing)
{

    
    if(printing->child != NULL) 
        print2(printing->child);
    cout << printing->name << "\n";
    if (printing->sibling != NULL)
        print2(printing->sibling);

}

void printArr(Node *arr, int n)
{
    cout << endl;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "(" << arr[i].name << ", " << arr[i].amount << ")"
             << " --> ";
    }
    cout << "null" << endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ifstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;

    int n;
    short managementAmount;
    string nickname;
    file >> n;

    Node *nodes = new Node[n];
    

    for (int i = 0; i < n; i++)
    {
        file >> managementAmount;
        file >> nickname;
        nodes[i].amount = managementAmount;
        nodes[i].name = nickname;
        nodes[i].parent = NULL;
        nodes[i].child = NULL;
        nodes[i].sibling = NULL;
    }


    printArr(nodes, n);
    cout << endl;


    

    if(n > 0)
    {
        //Node *current = management.head->next;
        //Node *parent = management.head;

        int parentInd = 0, current = 1;

        while(current<n)
        {
            int amount = nodes[parentInd].amount;
            for (int i=0; i<amount; i++)
            {
                nodes[current].parent = &nodes[parentInd];

                cout << i << endl;
                cout << "aktualny: " << nodes[current].name << endl;

                if(nodes[current].parent != NULL) cout << "parent: " << nodes[current].parent->name << endl;
                else cout << "null" << endl;

                if (nodes[parentInd].child == NULL) nodes[parentInd].child = &nodes[current];
                cout << "first child: " << nodes[parentInd].child->name << endl;

                current++;
                if(current == n) break;
                
            }
            cout << "imie nastepnego rodzica: " << nodes[parentInd+1].name << endl;
            parentInd++;  
            if(current == n) break;
        }
    

        

        cout << endl << endl << "chuj" << endl << endl;

        for (int current=0; current<n; current++)
        {
            if(nodes[current].parent == nodes[current+1].parent) 
                    nodes[current].sibling = &nodes[current+1];
                
                cout << "aktualny: " << nodes[current].name << endl;

                cout << "parent: ";
                if(nodes[current].parent != NULL) cout << nodes[current].parent->name << endl;
                else cout << "null" << endl;

                cout << "first child: ";
                if (nodes[current].child == NULL) cout << "null" << endl;
                else cout << nodes[current].child->name << endl;


                cout << "Blizniak: ";
                if(nodes[current].sibling == NULL) cout << "null" << endl;
                else cout << nodes[current].sibling->name << endl;

                cout << endl << endl;

        }

    }

    print2(&nodes[0]);

    delete [] nodes;
    
    

    return 0;
}