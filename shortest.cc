#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include<bits/stdc++.h> 

//İlayda Özel- 260201037       Göktay İncekara-250201012
using namespace std;

//finds the vertex index which has the minimum weight
int minDist(int distance[], bool helper[],int numOfVertices) {
	   int min = INT_MAX; 
           int min_index;
	   for (int i = 0; i < numOfVertices; i++) {
	   	if (helper[i] == false && distance[i] <= min) {
	   		min = distance[i];
			min_index = i;
		}
	   }
	   return min_index;
}

void shortestPath() {
	//gets the first input line and equalizes it to the number of vertices
	string line;
    	getline(cin, line);
    	int numOfVertices = stoi(line);
	vector<string> vertices;

	//creates a matrix with the size v x v and initializes it with zeros.
	int adjMat[numOfVertices][numOfVertices];

	for(int i = 0; i < numOfVertices; ++i){
        	for(int j = 0; j < numOfVertices; ++j){
            		adjMat[i][j] = 0;
        	}
    	}	

	
	for (int i =0; i<numOfVertices;i++) {
		string line;
		getline(cin,line);
		vector <string> items; 
        	stringstream strLine (line); 
        	string item;
		//tokenizes the input line and adds it to items vector.
		while(getline(strLine, item, ' ')) {
            		items.push_back(item); 
        	}

		//holds the vertex values with respect to addition order.
		vertices.insert(vertices.end(), items[0]);

		for(int j = 1; j < items.size(); j += 2){
			//fills in the matrix with the weight values.
            		adjMat[int(items[0][0]) - 97][int(items[j][0]) - 97] = stoi(items[j+1]);
        	}
		
	}


	int source = 0;
	int distance[numOfVertices];
	bool visited[numOfVertices];

	for (int i = 0; i < numOfVertices; i++) {
		distance[i] = INT_MAX;
		visited[i] = false;
		distance[source] = 0;
	}
	
	//calculates the minimum distance of a vertex with the help of previous vertices' minimum distances.
	for (int c = 0; c < numOfVertices- 1; c++) {
		int u = minDist(distance, visited, numOfVertices);
		visited[u] = true;
		for (int j = 0; j < numOfVertices; j++) {
			if (!visited[j] && adjMat[u][j] && distance[u] != INT_MAX && distance[u]+ adjMat[u][j] < distance[j]) {
				distance[j] = distance[u] + adjMat[u][j];
	        	}
		}
	}
	cout<< " \n";
	for (int i = 1; i < numOfVertices; i++) {
	   cout<< vertices[i]<< " " << distance[i] <<"\n";
	 }
}



int main(int argc, char** argv) {
	shortestPath();
	return EXIT_SUCCESS;
}



