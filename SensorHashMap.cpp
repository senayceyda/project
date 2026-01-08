#include "SensorHashMap.h"

SensorHashMap::SensorHashMap(int size) {
    tableSize = size;
    buckets = new HashNode*[tableSize];
    for (int i = 0; i < tableSize; i++)
        buckets[i] = nullptr;
}

SensorHashMap::~SensorHashMap() {
    for (int i = 0; i < tableSize; i++) {
        HashNode* curr = buckets[i];
        while (curr) {
            HashNode* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] buckets;
}

int SensorHashMap::hashFunction(const std::string& key) {
    int hash = 0;
    for (char c : key)
        hash = (hash * 31 + c) % tableSize;
    return hash;
}

void SensorHashMap::insert(const std::string& key,
                           SensorGraph::SensorNode* value) {
    int index = hashFunction(key);
    HashNode* node = new HashNode{key, value, buckets[index]};
    buckets[index] = node;
}


SensorGraph::SensorNode* SensorHashMap::get(const std::string& key) {
    int index = hashFunction(key);
    HashNode* curr = buckets[index];
    while (curr) {
        if (curr->key == key)
            return curr->value;
        curr = curr->next;
    }
    return nullptr;
}

