#include "RoutePlanner.h"
#include <algorithm>

using namespace std;

// Constructor
RoutePlanner::RoutePlanner(vector<Node*>& nodes, Node* start, Node* end) 
    : start_node(start), end_node(end) {}

// Calculate next best node based on f = g + h
Node* RoutePlanner::NextNode() {
    sort(open_list.begin(), open_list.end(), [](const auto* a, const auto* b) {
        return (a->g_value + a->h_value) < (b->g_value + b->h_value);
    });

    Node* lowest = open_list.front();
    open_list.erase(open_list.begin());
    return lowest;
}

// Expand the search to nearby airports
void RoutePlanner::AddNeighbors(Node* current_node) {
    for (auto neighbor : current_node->neighbors) {
        if (!neighbor->visited) {
            neighbor->parent = current_node;
            neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
            neighbor->h_value = neighbor->distance(*end_node);
            neighbor->visited = true;
            open_list.push_back(neighbor);
        }
    }
}

// The core A* Optimization Loop
void RoutePlanner::AStarSearch() {
    start_node->visited = true;
    open_list.push_back(start_node);

    while (!open_list.empty()) {
        Node* current = NextNode();

        if (current == end_node) {
            while (current != nullptr) {
                path.push_back(current);
                if (current->parent) total_distance += current->distance(*current->parent);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return;
        }
        AddNeighbors(current);
    }
}