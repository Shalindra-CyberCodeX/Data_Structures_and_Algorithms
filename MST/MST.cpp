#include <iostream>

using namespace std;

// Number of vertices in the graph
#define V 6

//finding the minimum key
int minKey(int key[], bool mstSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// A utility function to print the
// constructed MST stored in MSTarr[]
void printMST(int MSTarr[], int graph[V][V])
{
    int total=0;
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++){
        cout << MSTarr[i] << " - " << i << " \t"
			<< graph[i][MSTarr[i]] << " \n";
            
            total+=graph[i][MSTarr[i]];
            }
		
    cout<<"The minimum cost is : "<<total<<endl;

}

//prims algorithm
void primMST(int graph[V][V])
{
	// Array to store constructed MST
	int MSTarr[V];

	// Key values used to pick minimum weight edge in cut
	int key[V];

	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	
	key[0] = 0;

	// First node is always root of MST
	MSTarr[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		
		for (int v = 0; v < V; v++)

			
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				MSTarr[v] = u, key[v] = graph[u][v];
	}

	// Print the constructed MST
	printMST(MSTarr, graph);
}


int main()
{
	int graph[V][V] = { { 0,3,0,0,0,1},
						{ 3,0,2,1,10,0},
						{ 0,2,0,3,0,5},
						{ 0,1,3,0,5,0},
						{ 0,10,0,5,0,4},
                        { 1,0,5,0,4,0 } };

	
	primMST(graph);

	return 0;
}




