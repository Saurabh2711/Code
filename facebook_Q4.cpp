#include <iostream>
#include <list>
#include<algorithm>
#include<cstdio>
using namespace std;
int cmp(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    // function to add an edge to graph
    void addEdge(int v, int w);
 
    // Prints greedy coloring of the vertices
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}
 
// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    int result[V];
 
    // Assign the first color to first vertex
    result[0]  = 0;
 
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u
 
    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++)
    {
        // Process all adjacent vertices and flag their colors
        // as unavailable
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = true;
 
        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;
 
        result[u] = cr; // Assign the found color
 
        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    int freq[100]={0};
    // print the result
    int count=0;
    for (int u = 0; u < V; u++)
    {
      if(freq[result[u]]==0)
	count++;
        freq[result[u]]++;
    }
    sort(freq,freq+count,greater<int>());
    int ans=0;
    for(int i=0;i<count;i++)
      ans+=freq[i]*(i+1);
    cout<<ans<<endl;
    
}
 
// Driver program to test above function
main()
{
  int t;
  int a,n;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d",&n);
    Graph g1(n);
    scanf("%d",&a);
    for(int i=1;i<n;i++)
    {
      scanf("%d",&a);
      g1.addEdge(a-1,i);
    }
    g1.greedyColoring();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  /*
  
  
    g1.addEdge(0, 1);
    g1.addEdge(1, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
 //   g1.addEdge(2, 3);
  //  g1.addEdge(3, 4);
    cout << "Coloring of Graph 1 \n";
    g1.greedyColoring();
 
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of Graph 2 \n";
    g2.greedyColoring();
*/ 
    return 0;
}