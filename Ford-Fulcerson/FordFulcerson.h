#pragma once
#include <iostream>
using namespace std;
class FordFulcerson
{
private:
    int vertices;
    int** graphMatrix;
    int fromV, toV;
    int maxFlow;
    char* vName;
    int dfsTravers(int, int, bool*);
public:
    void readFromFile(string);
    int findMaxFlow();
};