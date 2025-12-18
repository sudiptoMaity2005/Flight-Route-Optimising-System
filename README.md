Flight Route Optimization System -
A high-performance C++ implementation of the A Search Algorithm* designed to find the most efficient flight path between global waypoints. This project simulates a navigation engine that calculates optimal routes based on geographic coordinates and interconnected flight networks.

Features -
1. A Search Algorithm: Uses a weighted cost function f(n)=g(n)+h(n) to ensure
mathematical optimality in pathfinding.
2. Euclidean Heuristic: Implements a geographic distance-based heuristic (h) to prioritize nodes moving toward the destination, significantly reducing search space.
3. Dynamic Graph Representation: Waypoints are represented as a graph of Node objects, allowing for complex, non-linear flight networks.
4. Modern C++ Practices: Utilizes C++17 features, smart memory management with pointers, and the Standard Template Library (STL).
5. CMake Build System: Cross-platform configuration for seamless compilation on macOS, Linux, and Windows.

Tech Stacks -
Language: C++17
Build Tool: CMake
Compiler: Clang (macOS) / GCC (Linux/MinGW)
Algorithm: A* (A-Star) Search

Project Structure -
1. main.cpp: The entry point and user interface for defining the flight network.
2. RoutePlanner.cpp/h: The core optimization engine and path reconstruction logic.
3. Node.h: Data structure for airports/waypoints, containing coordinates and neighbor links.
4. CMakeLists.txt: Build configuration and linking instructions.

Installation & Running -
1. Clone the repository: 
git clone https://github.com/sudiptoMaity2005/Flight-Route-Optimising-System
cd FlightPlanner
2. Build the project:
mkdir build && cd build
cmake ..
make
3. Run the executable:
./FlightPlanner

Future Scope & Improvements -
This project is built to be extensible. Planned improvements include:
1. Data Integration: Replacing hardcoded nodes with a CSV/JSON parser to load real-world Global Airport Data (IATAs).
2. Multi-Objective Optimization: Factoring in fuel consumption rates, wind speeds, and varying aircraft performance metrics.
3. Obstacle Avoidance: Implementing "No-Fly Zones" to simulate restricted airspace or severe weather conditions.
4. Graphical Interface: Integrating a mapping API or a 2D visualization tool to render the flight paths.
