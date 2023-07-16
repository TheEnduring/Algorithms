#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int dest;
    node* next;
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream file("test.txt");
    if (file.is_open()) cout << "File opened." << endl;

    short placesAmount;
    int waysAmount, sendValue, maxh;
    
    file >> placesAmount;
    file >> waysAmount;
    file >> sendValue;
    file >> maxh;
    //Adjacency list to store graph
    vector<int> *list = new vector<int>[placesAmount];

    //Arrays
    char *visited = new char[placesAmount];
    int *distance = new int[placesAmount];

    //Read Graph
    //First read number of vertices (placesAmount) and edges (waysAmount)
    //Then read the (undirected) edges
    //Note that vertices are zero-indexed

    for (int i = 0; i < waysAmount; i++)
    {
        int connect1, connect2;
        file >> connect1;
        file >> connect2;
        list[connect1].push_back(connect2);
        list[connect2].push_back(connect1);
    }

    //Now do the BFS from vertex 0 to find distances to all vertices
    //Start by initialising all visited values as 0 and distances as -1
    for (int i = 0; i < placesAmount; i++)
    {
        visited[i] = 0;
        distance[i] = -1;
    }

    //Create the BFS queue and put the start vertex in
    visited[0] = 1;
    distance[0] = 0;

    queue<int> queue;
    queue.push(0);

    //BFS
    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        //Now look at all neighbours of current
        for (int value : list[current])
        {
            //If value has not been processed yet, do that now
            if (!visited[value])
            {
                visited[value] = 1;
                distance[value] = distance[current] + 1;
                queue.push(value);
            }
        }
    }
    cout << "done." << endl;
//We are done. We have the reachability and distances to all vertices 



    
    return 0;
}
