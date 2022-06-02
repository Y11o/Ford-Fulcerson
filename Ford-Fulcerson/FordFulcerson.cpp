#include "FordFulcerson.h"
#include <fstream>

void FordFulcerson::readFromFile(string fileName) {
	fstream file;
	char firstV, secondV;
	int weight;
	int edge;
	int verticesCounter = 0;
	file.open(fileName, ios::in);

	file >> vertices >> edge;
	if (file.eof() || vertices == 0) throw out_of_range("No vertices in graph");

	
	vName = new char[vertices];
	int** arr;
	arr = (int**)malloc(sizeof(int*) * vertices);
	if (!arr) {
		throw out_of_range("Allocation error");
		return;
	}else {
		graphMatrix = arr;
	}
	for (size_t i = 0; i < vertices; i++)
	{
		arr[i] = (int*)malloc(vertices * sizeof(int));
		if (!arr[i]) { 
			throw out_of_range("Allocation error"); 
			return; 
		}	else graphMatrix[i] = arr[i];

		for (size_t j = 0; j < vertices; j++) {
			graphMatrix[i][j] = 0;
		}
	}

	int row, column;
	for (size_t i = 0; i < edge; i++)
	{
		file >> firstV >> secondV >> weight;

		row = -1;
		for (size_t j = 0; j < verticesCounter; j++)
			if (vName[j] == firstV)
				row = j;
		if (row == -1)
		{
			vName[verticesCounter] = firstV;
			row = verticesCounter;
			verticesCounter++;
		}

		column = -1;
		for (size_t j = 0; j < verticesCounter; j++)
			if (vName[j] == secondV)
				column = j;
		if (column == -1)
		{
			vName[verticesCounter] = secondV;
			column = verticesCounter;
			verticesCounter++;
		}
		graphMatrix[row][column] = weight; 
	}
	for (size_t i = 0; i < vertices; i++)  
	{
		if (vName[i] == 'S')
			fromV = i;
		if (vName[i] = 'T')
			toV = i;
	}
}

int FordFulcerson::findMaxFlow() {
	maxFlow = 0;
	int toAdd = 0;
	int bufVe, bufPrice;
	bool* visited = new bool[vertices];
	do
	{
		for (size_t i = 0; i < vertices; i++)
			visited[i] = false;
		toAdd = dfsTravers(fromV, INT_MAX, visited);
		maxFlow += toAdd;
	} while (toAdd > 0);
	return maxFlow;
}

int comparator(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int FordFulcerson::dfsTravers(int u, int Cmin, bool* visited) {
	if (u == toV)
		return Cmin;
	visited[u] = true;
	int delta;
	for (size_t v = 0; v < vertices; v++)
	{
		if (!visited[v] && (graphMatrix[u][v] > 0))
		{
			delta = dfsTravers(v, comparator(Cmin, graphMatrix[u][v]), visited);
			if (delta > 0)
			{
				graphMatrix[u][v] -= delta;
				graphMatrix[v][u] += delta;
				return delta;
			}
		}
	}
	return 0;
}