#include <iostream>
#include<vector>
using namespace std;

#include <iostream>
using namespace std;
#include <limits.h>


#define V 6  //use todefine V-->Number of Vertices

// A utility function to find the vertex with minimum timeance value, from the set of vertices not yet included in shortest path tree
int mintimeance(int time[], bool sptSet[])
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && time[v] <= min)
			min = time[v], min_index = v;

	return min_index;
}


void printSolution(int time[])
{    
    vector<int> timearr;
	cout << "Vertex \t timeance from Source" << endl;
	for (int i = 0; i < V; i++){
        cout << i << " \t\t" << time[i] << endl;
        timearr.push_back(time[i]);
    }
    int sum=0;
    for (int j=0;j<int(timearr.size());j++){

          sum+=timearr[j];
    }
    float avg=sum/5.0;
    cout<<"The average time is: "<<avg<<endl;
		
}




//Dijkstra Algorithm Function
void dijkstra(int graph[V][V], int src)
{
	int time[V]; // The output array. time[i] will hold the
				// shortest
	// timeance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is
					// included in shortest
	// path tree or shortest timeance from src to i is
	// finalized

	// Initialize all timeances as INFINITE and stpSet[] as
	// false
	for (int i = 0; i < V; i++)
		time[i] = INT_MAX, sptSet[i] = false;

	
	time[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum timeance vertex from the set of
		// vertices not yet processed. u is always equal to
		// src in the first iteration.
		int u = mintimeance(time, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update time value of the adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update time[v] only if is not in sptSet,
			// there is an edge from u to v, and total
			// weight of path from src to v through u is
			// smaller than current value of time[v]
			if (!sptSet[v] && graph[u][v]
				&& time[u] != INT_MAX
				&& time[u] + graph[u][v] < time[v])
				time[v] = time[u] + graph[u][v];
	}

	// print the constructed timeance array
	printSolution(time);
}




int main()
{

	/* Let us create the example graph discussed above */
	int graph[V][V] = {{0,10,0,0,15,5 },
                       {10,0,10,30,0,0},
                       {0,10,0,12,5,0 },   
                       {0,30,12,0,0,20},
                       {15,0,5,0,0,0  }, 
                       {5,0,0,20,0,0  } };

	
	dijkstra(graph, 0);
    dijkstra(graph, 1);
    dijkstra(graph, 2);
    dijkstra(graph, 3);
    dijkstra(graph, 4);
    dijkstra(graph, 5);

	return 0;
}


