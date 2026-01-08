#include "SensorGraph.h"
#include <iostream>


SensorGraph::SensorGraph() {
    head = nullptr;
    count = 0;
}

SensorGraph::~SensorGraph() {
    SensorNode* curr = head;
    while (curr) {
        AdjNode* adj = curr->adjList;
        while (adj) {
            AdjNode* tempAdj = adj;
            adj = adj->next;
            delete tempAdj;
        }
        SensorNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

SensorGraph::SensorNode* SensorGraph::addSensor(
        const std::string& id,
        double x,
        double y,
        int population) {

    SensorNode* node = new SensorNode;
    node->id = id;
    node->x = x;
    node->y = y;
    node->population = population;
    node->visited = false;
    node->adjList = nullptr;
    node->next = head;

    head = node;
    count++;
    return node;
}

void SensorGraph::addEdge(SensorNode* a, SensorNode* b) {
    AdjNode* ab = new AdjNode{b, a->adjList};
    a->adjList = ab;

    AdjNode* ba = new AdjNode{a, b->adjList};
    b->adjList = ba;
}

void SensorGraph::resetVisited() {
    SensorNode* curr = head;
    while (curr) {
        curr->visited = false;
        curr = curr->next;
    }
}

SensorGraph::SensorNode* SensorGraph::getHead() {
    return head;
}

int SensorGraph::getSensorCount() const {
    return count;
}

/* DFS helper */
void SensorGraph::dfs(SensorNode* start) {
    if (!start || start->visited)
        return;

    start->visited = true;

    AdjNode* adj = start->adjList;
    while (adj) {
        if (!adj->neighbor->visited)
            dfs(adj->neighbor);
        adj = adj->next;
    }
}

/* BFS helper (linked-list queue, no STL) */
void SensorGraph::bfs(SensorNode* start) {
    if (!start) return;

    struct QueueNode {
        SensorNode* data;
        QueueNode* next;
    };

    QueueNode* front = new QueueNode{start, nullptr};
    QueueNode* rear = front;
    start->visited = true;

    while (front) {
        SensorNode* current = front->data;

        AdjNode* adj = current->adjList;
        while (adj) {
            if (!adj->neighbor->visited) {
                adj->neighbor->visited = true;
                rear->next = new QueueNode{adj->neighbor, nullptr};
                rear = rear->next;
            }
            adj = adj->next;
        }

        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
}

void SensorGraph::dfsPrint(SensorNode* start) {
    if (start == NULL) return;

    std::cout << "Visited sensor: " << start->id << std::endl;

    AdjNode* current = start->adjList;
    while (current != NULL) {
        std::cout << "  -> Neighbor: "
                  << current->neighbor->id << std::endl;
        current = current->next;
    }
}
