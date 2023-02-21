#include <iostream>

using namespace std;

class Node
{
public:
    short amount;
    short currentAmount;
    string name;
    Node *next;
    Node *previous;
    Node *children;
    Node *parent;

    Node(short newAmount, string newName)
    {
        amount = newAmount;
        name = newName;
        currentAmount = 0;
        next = NULL;
        previous = NULL;
    }

    Node()
    {
        amount = 0;
        currentAmount = 0;
        name = 'null';
        next = NULL;
        previous = NULL;
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

    List(Node *newNode)
    {
        head = newNode;
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
        Node *current = head;
        while (current != NULL)
        {
            cout << "(" << current->name << ", " << current->amount << ")" << " --> ";
            current = current->next;
        }
    }

};
