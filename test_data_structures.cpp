#include <iostream>
#include <cassert>
#include "SensorGraph.h"
#include "SensorHashMap.h"

void testSensorGraph() {
    SensorGraph graph;

    auto* s1 = graph.addSensor("S1", 0, 0, 100);
    auto* s2 = graph.addSensor("S2", 1, 1, 200);
    auto* s3 = graph.addSensor("S3", 2, 2, 300);

    graph.addEdge(s1, s2);
    graph.addEdge(s2, s3);

    assert(s1 != NULL);
    assert(s2 != NULL);
    assert(s3 != NULL);

    std::cout << "[OK] SensorGraph test passed\n";
    std::cout << "DFS helper output:\n";
    graph.dfsPrint(s1);
}


void testSensorHashMap() {
    SensorGraph graph;
    SensorHashMap map(10);

    auto* s1 = graph.addSensor("S1", 0, 0, 100);
    auto* s2 = graph.addSensor("S2", 1, 1, 200);

    map.insert("S1", s1);
    map.insert("S2", s2);

    assert(map.get("S1") == s1);
    assert(map.get("S2") == s2);
    assert(map.get("S3") == NULL);

    std::cout << "[OK] SensorHashMap test passed\n";
}

void testSensorHashMapCollision() {
    // Force all keys into the same bucket
    SensorHashMap map(1);

    SensorGraph graph;

    auto* s1 = graph.addSensor("S1", 0, 0, 100);
    auto* s2 = graph.addSensor("S2", 1, 1, 200);
    auto* s3 = graph.addSensor("S3", 2, 2, 300);

    map.insert("S1", s1);
    map.insert("S2", s2);
    map.insert("S3", s3);

    assert(map.get("S1") == s1);
    assert(map.get("S2") == s2);
    assert(map.get("S3") == s3);

    std::cout << "[OK] SensorHashMap collision test passed\n";
}


int main() {
    testSensorGraph();
    testSensorHashMap();
    testSensorHashMapCollision();




    return 0;
}

