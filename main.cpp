#include <iostream>
#include <vector>
#include "RoutePlanner.h"

using namespace std;

int main() {
    // 1. Setup Airports
    Node n1("JFK", 0, 0);
    Node n2("ORD", 2, 2);
    Node n3("LHR", 5, 1);
    Node n4("LAX", 5, 5);

    // 2. Setup Connections
    n1.neighbors = {&n2, &n3};
    n2.neighbors = {&n4};
    n3.neighbors = {&n4};

    vector<Node*> map = {&n1, &n2, &n3, &n4};

    // 3. Run Optimization
    cout << "--- Flight Planner ---" << endl;
    RoutePlanner planner(map, &n1, &n4);
    planner.AStarSearch();

    // 4. Output results
    cout << "Shortest Distance: " << planner.GetTotalDistance() << " units" << endl;
    cout << "Path: ";
    for (auto node : planner.GetPath()) {
        cout << node->name << " ";
    }
    cout << endl;

    return 0;
}