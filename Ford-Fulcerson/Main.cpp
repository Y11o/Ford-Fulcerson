#include <iostream>
#include "FordFulcerson.h"

int main()
{
    FordFulcerson graph;
    graph.readFromFile("input2.txt");
    int ans = graph.findMaxFlow();
    cout << endl;
    cout << ans << endl;
}