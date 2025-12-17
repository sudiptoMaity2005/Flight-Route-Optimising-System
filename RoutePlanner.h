#ifndef ROUTEPLANNER_H
#define ROUTEPLANNER_H

#include "Node.h"
#include <vector>

using namespace std;

class RoutePlanner {
public:
    RoutePlanner(vector<Node*>& nodes, Node* start, Node* end);
    void AStarSearch();
    float GetTotalDistance() { return total_distance; }
    vector<Node*> GetPath() { return path; }

private:
    vector<Node*> open_list;
    Node* start_node;
    Node* end_node;
    float total_distance = 0;
    vector<Node*> path;

    Node* NextNode();
    void AddNeighbors(Node* current_node);
};

#endif