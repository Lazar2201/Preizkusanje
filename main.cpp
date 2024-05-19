#include <iostream>
#include "BellmanFord.h"
#include <iostream>
#include <string>
using namespace std;

void printMenu() {
    cout << "Bellman-Fordov algoritem - izbira:" << endl << endl;
    cout << "1) Preberi graf iz datoteke" << endl;
    cout << "2) Generiraj nakljucni graf z n vozlisci in cenami od a do b" << endl;
    cout << "3) Poženi algoritem" << endl;
    cout << "4) Ispisi seznam vozlisc" << endl;
    cout << "5) Ispisi najkrajso pot" << endl;
    cout << "6) Konec" << endl;
}

void initGraph() {
    cout << "Error: graph not initialized! Choose options 1 or 2, and then 3, before attempting 4!" << endl;
}

void BF_app() {
    cout << "Error: Bellman-Ford algorithm wasn't applied! Choose option 3 before attempting 4!" << endl;
}
int main() {
    int select = 0;
    int a, b, N, node, error, destination, source;
    string file_name = "";
    BF program;


    while (1) {
        printMenu();
        cin >> select;
        switch (select) {
            case 1:
                cout << "File name:" << endl;
                cin >> file_name;
                program.readGraph(file_name);
                break;

            case 2:
                cout << "N:" << endl;
                cin >> N;
                cout << "a:" << endl;
                cin >> a;
                cout << "b:" << endl;
                cin >> b;
                program.generateRandGraph(N, a, b);
                break;
            case 3:
                cout << "Source: " << endl;
                cin >> source;
                error = program.startAlgorithm(source);
                if (error == -1)
                    initGraph();
                break;
            case 4:
                cout << "Node number:" << endl;
                cin >> node;
                error = program.printAttribute(node);
                if (error == -1)
                    initGraph();
                else if (error == -2)
                    BF_app();
                break;
            case 5:
                cout << "Destination:" << endl;
                cin >> destination;
                error = program.printShortestPath(destination);
                if (error == -1)
                    initGraph();
                else if (error == -2)
                    BF_app();
                break;
            case 6:
                return 0;
                break;
            default: break;
        }
    }

}