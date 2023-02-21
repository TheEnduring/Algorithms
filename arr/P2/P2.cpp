#include <iostream>

using namespace std;



int main() 
{
    ios_base::sync_with_stdio(false); 
    int acidGroupsAmount, acidTypesAmount, particle=0, length=0;

    cout << "Ilosc grup: " << endl;
    cin >> acidGroupsAmount;                            //ilosc grup aminokwasow
    bool *result = new bool[acidGroupsAmount];

    for(int currentGroup=0; currentGroup<acidGroupsAmount; currentGroup++)      //petla wykonujaca powtorzenie dla wszystkich grup danych
    {
        result[currentGroup] = 1;                                               //Z gory zalozona jest prawda

        cout << "Ilosc typow w grupie " << currentGroup << endl;
        cin >> acidTypesAmount;                         //ilosc typow aminokwasow
        int *acidAmount = new int [acidTypesAmount];    //deklaracja tablicy: ilosc aminokwasow poszczegolnych typow
        for (int currentAcidType=0; currentAcidType<acidTypesAmount; currentAcidType++)
        {
            acidAmount[currentAcidType]=0;
        }


        do                         //petla deklarujaca wartosci: ilosc aminokwasow poszczegolnych typow
        {
            cout << "1 ciag: " << endl;
            do                                          //czy miesci sie w przedziale od -1 do ilosci aminokwasow
            { cin >> particle; }
            while(particle >= acidTypesAmount || particle < -1);


            if(particle != -1)                                  //jesli nie jest to koniec ciagu, 
            {
                length++;                                           //iteracja dlugosci 
                acidAmount[particle]++;                             //i ilosci poszczegolnych typow
                cout << "   " << acidAmount[particle] << "length  " << length << endl;
            }
            
        } while (particle != -1); 

        cout << endl << endl;


        


        do                                                 //Petla sprawdzajaca: ilosc aminokwasow w drugim ciagu nie jest wieksza
        {
            cout << "2 ciag:  " << endl;
            do                                          //czy miesci sie w przedziale od -1 do ilosci aminokwasow
            { cin >> particle;    }
            while(particle >= acidTypesAmount || particle < -1);
            
            if(particle != -1)                                          //jesli nie jest to koniec ciagu,
            {
                acidAmount[particle]--;                                 //iteracja dlugosci 
                length--;                                               //i ilosci poszczegolnych typow
                cout << "   " << acidAmount[particle] << "length  " << length << endl;
            }
            if((acidAmount[particle]<0 || length<0) && particle != -1) 
            {
                cout << "sjdbfiskfndjb1";
                result[currentGroup] = 0;
                
            }

            if(!result[currentGroup]) {cout << "sjdbfiskfndjb2";break;}

        } while (particle != -1);




        for (int currentAcidType=0; currentAcidType < acidTypesAmount; currentAcidType++)   //Petla sprawdzajaca: ilosc aminokwasow w drugim ciagu nie jest mniejsza
        {
            if(!result[currentGroup]) {cout << "sjdbfiskfndjb3";break;}
            if (acidAmount[currentAcidType] !=0 || length>0)
            {cout << "sjdbfiskfndjb4";
                result[currentGroup] = 0;
                break;
            }
        }
            

        delete [] acidAmount;
        
    }


        for (int currentGroupResult=0; currentGroupResult<acidGroupsAmount; currentGroupResult++)
    {
        if (result[currentGroupResult]) cout << "TAK" << "\n";
        else cout << "NIE" << "\n";
    }

    delete [] result;

    return 0;
}