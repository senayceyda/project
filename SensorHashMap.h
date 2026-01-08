#ifndef SENSOR_HASH_MAP_H
#define SENSOR_HASH_MAP_H

#include <string>
#include "SensorGraph.h"


class SensorHashMap {
public:
    struct HashNode {
        std::string key;
        SensorGraph::SensorNode* value;
        HashNode* next;
    };

    SensorHashMap(int size);
    ~SensorHashMap();
    
    SensorHashMap(const SensorHashMap&) = delete;
    SensorHashMap& operator=(const SensorHashMap&) = delete;

    void insert(const std::string& key,
                SensorGraph::SensorNode* value);

    SensorGraph::SensorNode* get(const std::string& key);

private:
    HashNode** buckets;
    int tableSize;

    int hashFunction(const std::string& key);
};

#endif

