# System Design Document

## Overview
This project implements an air quality monitoring system that processes
sensor readings from a spatial sensor network. The system computes air
quality indices (AQI), detects pollution hotspots, tracks their evolution
over time, and generates alerts to protect public health.

The design follows a modular architecture that separates data structures
from processing logic. This improves maintainability, clarity, and allows
individual components to be developed and tested independently.

## Class Diagram Explanation
The class diagram illustrates the core data structures and system components.
SensorGraph represents the spatial relationships between sensors using a
pointer-based adjacency list. SensorHashMap provides O(1) average-time access
to sensors by their identifiers. AlertQueue manages alert objects awaiting
dispatch.

Core logic classes such as AQICalculator, HotspotDetector, HotspotTracker,
and AlertManager operate on these data structures to perform analysis,
tracking, and alert generation without embedding logic inside the structures
themselves.

## Sequence Diagram Explanation
The sequence diagram depicts the main system workflow. Sensor data is loaded
by the DataLoader, which initializes sensors and stores them in the graph and
hash map. AQI values are computed for incoming readings, after which pollution
hotspots are detected and tracked over time.

When dangerous conditions are identified, alerts are generated and pushed
into the alert queue. Finally, the AlertManager dispatches alerts to notify
affected populations.
