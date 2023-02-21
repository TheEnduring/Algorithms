#include <iostream>
#include <fstream>

using namespace std;

struct sample
{
    int value, stability;
    string descript;
};


bool ifEquals(const string& a, const string& b)
{
    unsigned int size = a.size();
    if (b.size() != size)
        return false;
    for (unsigned int i = 0; i < size; ++i)
        if (tolower(a[i]) != tolower(b[i]))
            return false;
    return true;
}

void mergeValue(sample *a, int low, int high, int mid)
{
    cout << "chuj2";
	int i, j, k;
    sample *temp = new sample[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
 
	while (i <= mid && j <= high)
	{
		if (a[i].value > a[j].value)
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}
 
void mergeSortValue(sample *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		mergeSortValue(a, low, mid);
		mergeSortValue(a, mid+1, high);
		mergeValue(a, low, high, mid);
	}
}


void mergeString(sample *a, int low, int high, int mid)
{
	int i, j, k;
    sample *temp = new sample[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i].descript < a[j].descript)
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
        
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
    cout << "chuj";
}
 
void mergeSortString(sample *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		mergeSortString(a, low, mid);
		mergeSortString(a, mid+1, high);
		mergeString(a, low, high, mid);
	}
}


int main()
{
    ios_base::sync_with_stdio(false); 
    fstream file("test.txt");
    if(file.is_open()) cout << "Plik otwarty." << endl;


    //deklaracja zmiennych
    int t, n, begin;
    bool sortByValue;
    file >> t;


    //pętla - ilość grup do posortowania
    for (int k=0; k<t; k++)
    {
        file >> n;
        sample* samples = new sample[n];

        //pętla - ilość próbek do posortowania w grupie
        cout << "Przed sortowaniem: " << endl;
        for (int i=0; i<n; i++)
        {
            file >> samples[i].descript;
            file >> samples[i].value;
            samples[i].stability = i;
            cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
        }
        cout << endl;


        //względem których segmentów sortować
        file >> sortByValue;

        //jeśli dla liczb
        if(sortByValue)
        {
            mergeSortValue(samples, 0, n-1);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
            }
            cout << endl;

            for (int i=1; i<n; i++)
            {
                cout << "chuj3";
                if(samples[i-1].value == samples[i].value) 
                {
                    begin=i-1;

                while(samples[i-1].value == samples[i].value) 
                {
                    i++;
                }
                cout << "chuj4";
                mergeSortString(samples, begin, i-1);
                cout << "Drugie sortowanie: " << endl;
                for (int i=0; i<n; i++)
                {
                    cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
                }
                cout << endl;
                }
            }
        }


        //jeśli dla stringów
        else
        {
            mergeSortString(samples, 0, n-1);
            cout << "Pierwsze sortowanie: " << endl;
            for (int i=0; i<n; i++)
            {
                cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
            }
            cout << endl;
            for (int i=1; i<n; i++)
            {
                if(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    begin=i-1;
                
                while(ifEquals(samples[i-1].descript, samples[i].descript))
                {
                    i++;
                }
                mergeSortValue(samples, begin, i-1);
                cout << "Drugie sortowanie: " << endl;
                for (int i=0; i<n; i++)
                {
                    cout << samples[i].descript << "-" << samples[i].value << "-" << samples[i].stability << " ";
                }
                cout << endl;
                }
            }
        }
        


        //wynik
        cout << "wynik" << endl;
        for (int i=0; i<n; i++)
        {
            cout << samples[i].descript << "-";
            cout << samples[i].value << "-" << samples[i].stability << " ";
        }
        if(k != t-1) cout << "\n";
        delete [] samples;

        cout << endl;
    }

    cout << endl << endl;



    return 0;
}