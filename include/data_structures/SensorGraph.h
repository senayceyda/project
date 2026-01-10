#ifndef SENSOR_GRAPH_H
#define SENSOR_GRAPH_H

#include <string>


class SensorGraph {
public:
	
    struct SensorNode;

    struct AdjNode {
        SensorNode* neighbor;
        AdjNode* next;
    };

    struct SensorNode {
        std::string id;
        double x, y;
        int population;
        bool visited;

        AdjNode* adjList;
        SensorNode* next;
    };

    SensorGraph();
    ~SensorGraph();
    
    SensorGraph(const SensorGraph&) = delete;
    SensorGraph& operator=(const SensorGraph&) = delete;

    SensorNode* addSensor(const std::string& id,
                          double x,
                          double y,
                          int population);

    void addEdge(SensorNode* a, SensorNode* b);

    void dfs(SensorNode* start);
    void bfs(SensorNode* start);

    void resetVisited();
    SensorNode* getHead();
    int getSensorCount() const;
    void dfsPrint(SensorNode* start);


private:
    SensorNode* head;
    int count;
};

#endif

