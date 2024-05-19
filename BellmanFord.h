//
// Created by Lazar on 03/13/2024.
//

#ifndef BF_BELLMANFORD_H
#define BF_BELLMANFORD_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node {
    int prev;
    int distance;
};


class BF {
public:
    BF();
    void readGraph(const string& filename);
    int startAlgorithm(int source);
    int printAttribute(int node_num);
    int printShortestPath(int destination);
    void generateRandGraph(int N, int lower_lim, int upper_lim);

    vector<vector<int>> node_matrix;
private:
    void clearMatrix();

    vector<Node> paths;
};






#endif //BF_BELLMANFORD_H
