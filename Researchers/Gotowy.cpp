#include <iostream>

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
};

void printArr(Node *printing)
{

    if (printing->child != NULL)
        printArr(printing->child);
    cout << printing->name << "\n";
    if (printing->sibling != NULL)
        printArr(printing->sibling);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    short managementAmount;
    string nickname;
    cin >> n;

    Node *nodes = new Node[n];

    for (int i = 0; i < n; i++)
    {
        cin >> managementAmount;
        cin >> nickname;
        nodes[i].amount = managementAmount;
        nodes[i].name = nickname;
        nodes[i].parent = NULL;
        nodes[i].child = NULL;
        nodes[i].sibling = NULL;
    }

        int parentInd = 0, current = 1;

        while (current < n)
        {
            int amount = nodes[parentInd].amount;
            for (int i = 0; i < amount; i++)
            {
                nodes[current].parent = &nodes[parentInd];
                if (nodes[parentInd].child == NULL)
                    nodes[parentInd].child = &nodes[current];

                current++;
                if (current == n)
                    break;
            }
            parentInd++;
            if (current == n)
                break;
        }

        for (int current = 0; current < n; current++)
        {
            if (nodes[current].parent == nodes[current + 1].parent)
                nodes[current].sibling = &nodes[current + 1];
        }

    printArr(&nodes[0]);

    delete[] nodes;
    return 0;
}