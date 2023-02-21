#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;

//nie wszystkie wezly sa polaczone, czyli moze byc taka sytuacja ze nie do wszystkich placowek mozemy sie dostac
//wtedy nie bierzemy ich pod uwage, zajmujemy  sie tymi ktore sa powiazane z wezlem startowym, placowka moze na siebie wskazywac,
//ale przy odpowiednim zaimplementowaniu kodu nie powinno to miec znaczenia bo wezel byl juz odwiedzony
//vertice = nodes


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream file("test.txt");
    if (file.is_open()) cout << "File opened." << endl;

    short placesAmount;
    int roadsAmount, sendValue, maxh, vertex1, vertex2;
    
    file >> placesAmount;
    file >> roadsAmount;
    file >> sendValue;
    file >> maxh; 
  
    // Adjacency matrix 
    int** matrix; 

    matrix = new int*[placesAmount];
    int connections = 0;
    for (int columns=0; columns<placesAmount; columns++)
    {
        matrix[columns] = new int[connections];
        connections++;
        for (int rows=0; rows<connections; rows++)
        {
            matrix[columns][rows] = 0;
            cout << matrix[columns][rows] << " ";
        }
        cout << endl;
    }
    

    int start, edges;
    for (int i=0; i<roadsAmount; i++)
    { 
        file >> start;
        file >> edges;
        if (edges > start) swap(edges, start);
        matrix[start][edges] = 1;  
    } 
    cout << endl;

    connections = 0;
    for (int columns=0; columns<placesAmount; columns++)
    {
        connections++;
        for (int rows=0; rows<connections; rows++)
        {
            cout << matrix[columns][rows] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Visited vector to so that 
    // a vertex is not visited more than once 
    // Initializing the vector to false as no 
    // vertex is visited at the beginning 
    int *level = new int[placesAmount];
    int maxPlaces = 0, result;

    vector<bool> visited(placesAmount, false); 
    vector<int> queue; 
    queue.push_back(sendValue); 
  
    // Set source as visited 
    visited[sendValue] = true; 
    level[sendValue] = 0;
  
    int visitedInt; 
    while (!queue.empty()) 
    { 
        visitedInt = queue[0]; 
  
        // Print the current node 
        cout << visitedInt << " "; 
        queue.erase(queue.begin()); 
        // For every adjacent vertex to the current vertex 
        for (int i = 0; i < placesAmount; i++) 
        { 
            if (matrix[visitedInt][i] == 1 && (!visited[i])) 
            { 
                // Push the adjacent node to the queue 
                queue.push_back(i); 

                // Set 
                visited[i] = true; 
                level[i] = level[visitedInt]+1;
                if (level[i]*2 <= maxh) maxPlaces++;
                cout << "level: " << level[i] << endl;
                result = level[i];
            } 
        } 
    } 

    cout << "wynik: " << result << " " << maxPlaces << endl;

    // delete [] level;
    // for (int i=0; i<placesAmount; i++)
    // {
    //     delete [] matrix[placesAmount];
    // }
    // delete [] matrix;
    return 0;
}