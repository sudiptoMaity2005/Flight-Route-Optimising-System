#ifndef NODE_H
#define NODE_H

#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct Node {
    string name;
    float x, y;
    float g_value = 0;
    float h_value = 0;
    bool visited = false;
    Node* parent = nullptr;
    vector<Node*> neighbors;

    Node(string n, float x_coord, float y_coord) : name(n), x(x_coord), y(y_coord) {}

    float distance(const Node& other) const {
        return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
    }
};

#endif