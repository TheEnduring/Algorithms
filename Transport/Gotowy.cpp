#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;


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

    short placesAmount;
    int roadsAmount, sendValue, maxh, vertex1, vertex2;
    
    cin >> placesAmount;
    cin >> roadsAmount;
    cin >> sendValue;
    cin >> maxh;

    Graph graph(placesAmount);

    for (int i=0; i<roadsAmount; i++)
    {
        cin >> vertex1;
        cin >> vertex2;
        graph.addWay(vertex1, vertex2);
    }

    graph.bfs(sendValue, maxh);
    
    return 0;
}