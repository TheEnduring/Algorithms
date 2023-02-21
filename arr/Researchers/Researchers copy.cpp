#include <iostream>
#include <fstream>

using namespace std;




    // void appendNode(Node *newNode)
    // {
    //     if(root == NULL) 
    //     {
    //         root = newNode;
    //     }
    //     else
    //     {
    //         int amount = root->amount;
    //         Node *checking = root;
    //         while(checking->parent != newNode->parent)
    //         {
    //             checking = checking->leftChild;
    //             if(checking == NULL)
    //             {
    //                 root->leftChild = newNode;
    //             }
    //             for(int i=1; i<amount; i++)
    //             {
    //                 if(checking->rightSibling != NULL)
    //                 {
    //                     checking = checking->rightSibling;
    //                 }
    //                 else newNode->parent = checking->parent;
    //             }
    //         }
    //     }
    // }


class Node
{
public:
    short amount, generation;
    string name;
    Node *next;
    Node *previous;
    Node *parent;
    Node *child;
    Node *sibling;

    Node()
    {
        amount = 0;
        generation = 0;
        name = 'null';
        next = NULL;
        previous = NULL;
        parent = NULL;
        child = NULL;
        sibling = NULL;
    }
};




class List
{
    public:
    Node *head;


    List()
    {
        head = NULL;
    }




    void appendNode(Node *newNode)
    {
        if(head == NULL) 
        {
            head = newNode;
        }
        else
        {
            Node *checking = head;
            while(checking->next != NULL)
            {
                checking = checking->next;
                cout << "chuj2";
            }
            checking->next = newNode;
            newNode->previous = checking;
        }
    }


    void prependNode(Node *newNode)
    {
        if(head == NULL) head = newNode;
        else
        {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        }
    }

    void insertNode(Node *newNode, string name)
    {
        if(head == NULL) head = newNode;
        else
        {
            Node *checking = head;
            while (name != checking->name)
            {
                checking = checking->next;
            }
            Node *checking2 = checking->next;
            cout << "chuj3";
            if (checking2 == NULL) 
            {
                checking->next = newNode;
                newNode->previous = checking;
            }
            else
            {
                checking2->previous = newNode;
                newNode->next = checking2;
                newNode->previous = checking;
                checking->next = newNode;                
            }
        }
    }

    void print()
    {
        cout << endl;
        Node *current = head;
        while (current != NULL)
        {
            cout << "(" << current->name << ", " << current->amount << ")" << " --> ";
            current = current->next;
        }
        cout << "null" << endl;
    }

};


void print2(Node *printing)
{

    
    if(printing->child != NULL) 
        print2(printing->child);
    cout << printing->name << "    ";
    if (printing->sibling != NULL)
        print2(printing->sibling);

}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ifstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;

    int n, generations=0;
    short managementAmount;
    string nickname;
    List management;
    file >> n;
    

    for (int i = 0; i < n; i++)
    {
        Node *current = new Node();

        file >> managementAmount;
        file >> nickname;
        current->amount = managementAmount;
        current->name = nickname;

        management.appendNode(current);
    }

    management.print();
    cout << endl;

    if(management.head != NULL)
    {
        Node *current = management.head->next;
        Node *parent = management.head;

        while(current != NULL)
        {
            int amount = parent->amount;
            for (int i=0; i<amount; i++)
            {
                current->parent = parent;

                cout << i << endl;
                cout << "aktualny: " << current->name << endl;

                if(current->parent != NULL) cout << "parent: " << current->parent->name << endl;
                else cout << "null" << endl;

                if (parent->child == NULL) parent->child = current;
                cout << "first child: " << parent->child->name << endl;

                current->generation=parent->generation+1;
                cout << "Generacja: " << current->generation << endl;
                current = current->next;
                if(current == NULL) break;
            }
            cout << "imie nastepnego rodzica: " << parent->next->name << endl;
            generations = parent->generation+1;
            parent = parent->next;
            
        }

        

        current = management.head;
        cout << endl << endl << "chuj" << endl << endl;

        while (current != NULL)
        {
            if(current->next != NULL && current->parent == current->next->parent) 
                    current->sibling = current->next;
                
                cout << "aktualny: " << current->name << endl;

                cout << "parent: ";
                if(current->parent != NULL) cout << current->parent->name << endl;
                else cout << "null" << endl;

                cout << "first child: ";
                if (current->child == NULL) cout << "null" << endl;
                else cout << current->child->name << endl;

                cout << "Generacja: " << current->generation << endl;

                cout << "Blizniak: ";
                if(current->sibling == NULL) cout << "null" << endl;
                else cout << current->sibling->name << endl;

                cout << endl << endl;

                current = current->next;
        }

    }

    cout << "ilosc pokolen: " << generations << endl;

    Node *current = management.head;

    print2(current);

    return 0;
}