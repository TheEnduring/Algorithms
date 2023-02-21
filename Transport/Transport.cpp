#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

//nie wszystkie wezly sa polaczone, czyli moze byc taka sytuacja ze nie do wszystkich placowek mozemy sie dostac
//wtedy nie bierzemy ich pod uwage, zajmujemy  sie tymi ktore sa powiazane z wezlem startowym, placowka moze na siebie wskazywac,
//ale przy odpowiednim zaimplementowaniu kodu nie powinno to miec znaczenia bo wezel byl juz odwiedzony
//vertice = nodes

class Graph
{
    public:
    int placesAmount;
    vector<int> *glist;

    Graph(int placesAmount)
    {
        this->placesAmount = placesAmount;
        glist = new vector<int>[placesAmount];
    }

    void addWay(int place1, int place2)
    {
        glist[place1].push_back(place2);
        glist[place2].push_back(place1);
    }

    void bfs(int sendValue, int maxh)
    {
        int *level = new int[placesAmount], maxPlaces = -1;
        bool *visited = new bool[placesAmount];
        for (int i = 0; i < placesAmount; i++)
        {
            visited[i] = 0;
        }

        level[sendValue] = 0;
        visited[sendValue] = 1;
        queue<int> queue;
        queue.push(sendValue);

        list<int>::iterator i;
        while(!queue.empty()) 
        { 
            sendValue = queue.front(); 
            if(level[sendValue]*2 <= maxh) maxPlaces++;

            queue.pop(); 
            for (vector<int>::iterator i = glist[sendValue].begin(); i != glist[sendValue].end(); ++i) 
            {
                if (!visited[*i])
                {
                    level[*i] = level[sendValue]+1;
                    visited[*i] = true; 
                    queue.push(*i); 
                }
            }
        }
        cout << level[sendValue] << " " << maxPlaces;
        delete [] level;
        delete [] visited;
    }

    ~Graph()
    {
        delete [] glist;
    }

};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream file("test.txt");
    if(file.is_open()) cout << "otwarty." << endl;

    short placesAmount;
    int roadsAmount, sendValue, maxh, vertex1, vertex2;
    
    file >> placesAmount;
    file >> roadsAmount;
    file >> sendValue;
    file >> maxh;

    Graph graph(placesAmount);

    for (int i=0; i<roadsAmount; i++)
    {
        file >> vertex1;
        file >> vertex2;
        graph.addWay(vertex1, vertex2);
    }

    graph.bfs(sendValue, maxh);
    
//     //Adjacency list to store graph
//     vector<int> *list = new vector<int>[placesAmount];

//     //Arrays
//     char *visited = new char[placesAmount];
//     int *distance = new int[placesAmount];

//     //Read Graph
//     //First read number of vertices (placesAmount) and edges (waysAmount)
//     //Then read the (undirected) edges
//     //Note that vertices are zero-indexed

//     for (int i = 0; i < waysAmount; i++)
//     {
//         int connect1, connect2;
//         file >> connect1;
//         file >> connect2;
//         list[connect1].push_back(connect2);
//         list[connect2].push_back(connect1);
//     }

//     //Now do the BFS from vertex 0 to find distances to all vertices
//     //Start by initialising all visited values as 0 and distances as -1
//     for (int i = 0; i < placesAmount; i++)
//     {
//         visited[i] = 0;
//         distance[i] = -1;
//     }

//     //Create the BFS queue and put the start vertex in
//     visited[0] = 1;
//     distance[0] = 0;

//     queue<int> queue;
//     queue.push(0);

//     //BFS
//     while (!queue.empty())
//     {
//         int current = queue.front();
//         queue.pop();

//         //Now look at all neighbours of current
//         for (int value : list[current])
//         {
//             //If value has not been processed yet, do that now
//             if (!visited[value])
//             {
//                 visited[value] = 1;
//                 distance[value] = distance[current] + 1;
//                 queue.push(value);
//             }
//         }
//     }
//     cout << "done." << endl;
// //We are done. We have the reachability and distances to all vertices 



    
    return 0;
}