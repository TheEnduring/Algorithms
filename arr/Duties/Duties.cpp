#include <iostream>
#include <fstream>

using namespace std;

class Employee
{
    public:
    string name;
    int id;
    Employee *next;
//    Employee *previous;

    Employee()
    {
        next = NULL;
//       previous = NULL;
    }


};




class ListEmp
{
    public:
    Employee *head;


    ListEmp()
    {
        head = NULL;
    }




    void appendNode(Employee *newNode)
    {
        if(head == NULL) 
        {
            head = newNode;
            head->next = head;
//            head->previous = head;
        }
        else
        {
            Employee *checking = head;
            while(checking->next != head)
            {
                checking = checking->next;
            }
            checking->next = newNode;
//            newNode->previous = checking;
            newNode->next = head;
//            head->previous = newNode;
            
        }
    }

    void deleteNode(int id)
    {
        Employee *previousEmp = head;
        Employee *currentEmp = previousEmp->next;
        if (head->id == id)
        {
                head = head->next;

            cout << "Node UNLINKED with keys value : " << id << endl;
        }

        else
        {
            cout << "else" << endl;
            do
            {
                if (currentEmp->id == id)
                {
                    break;
                }
                previousEmp = previousEmp->next;
                currentEmp = currentEmp->next;
            } while (currentEmp->next != head);
        }
    }


    void editNode(int id, string name)
    {
        cout << "orze" << endl;
        
        if(head->id == id)
        {
            head->name = name;
            return;
        }
        
        Employee *checking = head;
        while (checking->id != id && checking->next != head)
        {
            checking = checking->next;
        }
        if(checking->id == id)
            checking->name = name;
    }

    Employee *searchNode(int id)
    {

        Employee *checking = head;
        if (head != NULL)
        {
            while (checking->id != id && checking->next != head)
            {
                checking = checking->next;
            }
            if(checking->id == id)
                return checking;
            else return NULL;
        }
        else
        {
            return NULL;
        }
        
        
    }

        void print()
    {
        Employee *current = head;
        if(head != NULL)
        {
            do 
            {     
                    cout << "(" << current->name << ", " << current->id << ")" << " --> ";
                    current = current->next;
            } while (current->next != head);
        }
        cout << "null" << endl;
    }


    // void prependNode(Employee *newNode)
    // {
    //     if(head == NULL) head = newNode;
    //     else
    //     {
    //         newNode->next = head;
    //         head->previous = newNode;
    //         head = newNode;
    //     }
    // }

    // void insertNode(Employee *newNode, string name)
    // {
    //     if(head == NULL) head = newNode;
    //     else
    //     {
    //         Employee *checking = head;
    //         while (name != checking->name)
    //         {
    //             checking = checking->next;
    //         }
    //         Employee *checking2 = checking->next;
    //         if (checking2 == NULL) 
    //         {
    //             checking->next = newNode;
    //             newNode->previous = checking;
    //         }
    //         else
    //         {
    //             checking2->previous = newNode;
    //             newNode->next = checking2;
    //             newNode->previous = checking;
    //             checking->next = newNode;                
    //         }
    //     }
    // }

    // void print(int value)
    // {

    // }

};



class Duty
{
public:
    string name;
    int value;
    Duty *next;
    ListEmp *employment;

    Duty()
    {
        employment = new ListEmp();
        next = NULL;
    }
};



class ListDuty
{
    public:
    Duty *head;


    ListDuty()
    {
        head = NULL;
    }

   void newDuty(Duty *newNode)
    {
        if(head == NULL) 
        {
            head = newNode;
        }
        else
        {
            Duty *checking = head;
            while(checking->next != NULL)
            {
                checking = checking->next;
            }
            checking->next = newNode;
        }
    }

    void insertEmp(Employee *newEmployee, string name)
    {
        Duty *checking = head;
        while(checking->name != name)
        {
            checking = checking->next;
        }
        checking->employment->appendNode(newEmployee);
    }


    void print()
    {
        Duty *current = head;
        while (current != NULL)
        {
            cout << "(" << current->name << ", " << current->value << ")" << " --> ";
            
            if(current->employment->head != NULL)
            {
                Employee *currentEmp = current->employment->head;

                do
                {
                    cout << "(" << currentEmp->name << ", " << currentEmp->id << ")" << " --> ";
                    currentEmp = currentEmp->next;
                } while (currentEmp != current->employment->head);
            }

            current = current->next;
        }
        cout << "null" << endl;
    }


    void editNode(string name, string newName, int newValue)
    {
        Duty *checking = head;
        while (checking->name != name)
        {
            checking = checking->next;
        }

        checking->name = newName;
        checking->value = newValue;
    }

    void editEmployee(int id, string name)
    {
        Duty *checking = head;
        while (checking != NULL)
        {
            checking->employment->editNode(id, name);
            checking = checking->next;
        }
    }


    void deleteEmployee(int id, ListEmp freeEmp)
    {

        Duty *checking = head;
        Employee *moving = NULL;
        moving = freeEmp.searchNode(id);
        while (checking != NULL)
        {
            checking->employment->deleteNode(id);
            checking = checking->next;
        }
    }



    void moveEmployee(int id, string name, ListEmp freeEmp)
    {
        
        Duty *checking = head;
        Employee *moving = NULL;
        moving = freeEmp.searchNode(id);
        if(moving == NULL)
        {
            while (checking != NULL && moving == NULL)
            {
                moving = checking->employment->searchNode(id);
                checking = checking->next;
            }
        }
        
        checking = head;
        while (checking->name != name)
        {
            checking = checking->next;
        }
        insertEmp(moving, checking->name);
        
    }


    void deleteNode(string name, ListEmp &e)
    {
        Duty *previousDuty = head;
        Duty *currentDuty = previousDuty->next;
        if (head->name == name)
        {
            Employee *checking = head->employment->head;
            do
            {
                e.appendNode(checking);
                checking = checking->next;
            } while (checking->next != head->employment->head);
            if(head->next == NULL)
            {
                head = NULL;
            }
            else 
                head = head->next;

            cout << "Node UNLINKED with keys value : " << name << endl;
        }

        else
        {
            cout << "else" << endl;
            while (currentDuty != NULL)
            {
                if (currentDuty->name == name)
                {
                    Employee *checking = currentDuty->employment->head;
                    do
                    {
                        e.appendNode(checking);
                        checking = checking->next;
                    } while (checking->next != head->employment->head);
                    break;
                }
                previousDuty = previousDuty->next;
                currentDuty = currentDuty->next;
            }
        }
    }


     void print(int value)
    {
        int currentAmount = 0;
        Duty *current = head;
        while (current != NULL)
        {
            
            //czy dyzur ma pracownikow
            if(current->employment->head != NULL)
            {
                
                Employee *currentEmp = current->employment->head;
                do
                {
                    currentEmp = currentEmp->next;
                    currentAmount++;
                    cout << currentAmount << endl;
                    if(currentAmount == current->value) break;
                } while (currentEmp != current->employment->head);
                
                if(currentAmount < current->value)
                    cout << "(niedobor pracownikow)";
                
                //wyswietlenie dyzuru
                cout << "(" << current->name << ", " << current->value << ")" << " --> ";

                currentEmp = current->employment->head;
                //przesuniecie o wartosc s
                for (int i=0; i<value*current->value; i++)
                {
                    current->employment->head = current->employment->head->next;
                }
                currentEmp = current->employment->head;

                do
                {
                    cout << "(" << currentEmp->name << ", " << currentEmp->id << ")" << " --> ";
                    currentEmp = currentEmp->next;
                    currentAmount--;
                    cout << currentAmount;
                } while (currentEmp != current->employment->head && currentAmount != 0);
            }
            else 
            {
                cout << "(niedobor pracownikow)" << "(" << current->name << ", " << current->value << ")" << " --> " ;
            }
            currentAmount = 0;
            current = current->next;
            cout << endl;
        }
    }

};






//oddzialy skladaja sie na liste,
//poszczegolne oddzialy sa listami, pracownicy elementami list

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //otwarcie pliku testowego
    ifstream file("test.TXT");
    if(file.is_open()) cout << "Plik otwarty." << endl;

    //ilosc operacji do wykonania
    ListDuty duties;
    ListEmp freeEmp;
    char command, argument;
    string dutyName, emplName, newName;
    int value, id = 0, n;


    file >> n;
    for (int i=0; i<n; i++)
    {
        file >> command;
        switch(command)
        {
            //komenda dodanie do systemu
            case 'a':
            file >> argument;
            //dodanie oddzialu
            if (argument == 'w')
            {
                cout << "a w" << endl;
                file >> dutyName;
                file >> value;
                Duty *newDuty = new Duty();
                newDuty->name = dutyName;
                newDuty->value = value;
                duties.newDuty(newDuty);
                //duties.print();
            }
            //dodanie pracownika
            else
            {
                cout << "a e" << endl;
                file >> emplName;
                file >> dutyName;
                Employee *employee = new Employee();
                employee->name = emplName;
                employee->id = id;
                duties.insertEmp(employee, dutyName);
                id++;
            }
            
            break;






            //komenda usuniecie z systemu
            case 'd':
            file >> argument;
            //usuniecie oddzialu
            if (argument == 'w')
            {
                cout << "d w" << endl;
                file >> dutyName;
                duties.deleteNode(dutyName, freeEmp);
                freeEmp.print();
            }
            //usuniecie pracownika
            else
            {
                cout << "d e" << endl;
                file >> value;
                duties.deleteEmployee(value, freeEmp);
            }
            

            break;





            //komenda przemianowanie
            case 'e':
            file >> argument;
            //przemianowanie oddzialu wraz ze zmiana ilosci osob na dyzurze
            if (argument == 'w')
            {
                cout << "e w" << endl;
                file >> dutyName;
                file >> newName;
                file >> value;

                duties.editNode(dutyName, newName, value);

            }
            //zmiana nazwy pracownika o podanym id
            else
            {
                file >> value;
                file >> newName;
                cout << "e e " << value << " " << newName << endl;
                duties.editEmployee(value, newName);
            }
            

            break;


            case 'm':
            cout << "m" << endl;
            file >> value;
            file >> dutyName;
            duties.moveEmployee(value, dutyName, freeEmp);

            break;



            //wyświetlenie informacji odnosnie pracownikow znajdujacych sie na dyzurach po wykonaniu podanej ilosci zmian
            case 's':
            file >> value;
            cout << "s: " << value << endl;
            Duty *current = duties.head;
            int k=1;
            while (current != NULL)
            {
                cout << "w" << k << ": " << current->value << endl;
                k++;
                current = current->next;
            }
            duties.print(value);
            cout << endl << endl;
            
            break;


            

        }    


    }
    cout << "do konca. " << endl;
    //duties.print();


    return 0;
}