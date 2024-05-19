//
// Created by Lazar on 03/13/2024.
//

#include "BellmanFord.h"
BF::BF()
= default;

void BF::readGraph(const string& filename)
{
    ifstream graph;
    vector<int> row;
    int temp, N;
    graph.open(filename);
    graph >> N;

    if (N > 0)
        clearMatrix();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            graph >> temp;
            row.push_back(temp);
        }
        node_matrix.push_back(row);
        row.clear();
    }
    graph.close();
}

int BF::startAlgorithm(int source)
{
    if (!node_matrix.size())
        return -1;
    paths.clear();
    Node temp;
    int N = node_matrix.size();
    for (int i = 0; i < N; i++) {
        if (i != source) temp.distance = INT_MAX/2 -1;
        else temp.distance = 0;
        temp.prev = -1;
        paths.push_back(temp);
    }
    for (int v = 1; v < N; v++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (paths[i].distance + node_matrix[i][j] < paths[j].distance) {
                    paths[j].distance = paths[i].distance + node_matrix[i][j];
                    paths[j].prev = i;
                }
            }
        }
    }

    for (int v = 1; v < N; v++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (paths[i].distance + node_matrix[i][j] < paths[j].distance)
                {
                    cout << "GRE�KA: Negativan ciklus.";
                    return 0;
                }
            }
        }
    }
    return 0;
}

int BF::printAttribute(int node_num)
{
    if (!node_matrix.size())
        return -1;
    else if (!paths.size())
        return -1;
    cout << "Cena poti: " << paths[node_num].distance << endl;
    cout << "Predhodnik: " << paths[node_num].prev << endl;
    return 0;
}

int BF::printShortestPath(int destination)
{
    if (!node_matrix.size())
        return -1;
    else if (!paths.size())
        return -2;
    if (destination > paths.size()-1) {
        cout << "Node doesn't exist" << endl;
        return 0;
    }
    vector<int> path;
    path.push_back(destination);
    int cnt = destination;
    while (paths[cnt].prev != -1) {
        path.push_back(paths[cnt].prev);
        cnt = paths[cnt].prev;
    }
    for (int i = path.size()-1; i >=0; i--){
        if (!i) {
            cout << path[i] << endl;
            break;
        }
        cout << path[i] << "->";
    }



    return 0;
}

void BF::generateRandGraph(int N, int lower_lim, int upper_lim)
{
    clearMatrix();
    vector<int> row;
    int temp;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i == j)
                temp = 0;
            else temp = rand() % (upper_lim - lower_lim + 1) + lower_lim;
            row.push_back(temp);
        }
        node_matrix.push_back(row);
        row.clear();
    }
}


void BF::clearMatrix()
{
    for (int i = 0; i < node_matrix.size(); i++)
        node_matrix[i].clear();
    node_matrix.clear();
}


