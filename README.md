# Delivery Simulation Project

## Project Description:

This project is a web-based 3D simulation representing the campus of the University of Minnesota Twin Cities in Minneapolis, MN. It involves various entities including helicopters, humans, robots, drones, packages, and porch pirates. The primary objective is to simulate a drone fleet delivery service with dynamic interactions and pathfinding algorithms.

### Aim of the Project:

The aim of this project was to create a complex system with multiple codependencies and interacting entities, while utilizing design patterns and C++ best practices. The goal is to build a robust, maintainable, and efficient simulation framework that demonstrates the power of combining various software design techniques.

### Entities & Interactions:

- **Helicopters**: Navigate the map, notifying users of the distance traveled.
- **Humans**: Walk around the map and notify users when near the Keller Hall building.
- **Drones**: Deliver packages using selected pathfinding algorithms.
- **Robots**: Represent customers waiting for their packages.
- **Porch Pirates**: Attempt to steal packages before delivery.
- **Packages**: Items to be delivered, tracked throughout the delivery process.

### Key Features:

1. **Drone Fleet Delivery Service**:
   - Users can select pickup and drop-off locations for packages.
   - Choose from various pathfinding algorithms (A*, BFS, DFS, Dijkstra).
   - Drones deliver packages using the selected strategy.

2. **Interactive Simulation**:
   - Real-time 3D visualization using Three.js.
   - Control panel to add entities, schedule deliveries, and adjust simulation speed.
   - Notifications for package status and entity interactions.

3. **Porch Pirates**:
   - New entity type that adds a challenge by attempting to steal packages.
   - Pirates move towards packages upon delivery notification.
   - If successful, they return stolen packages to a designated location.

### Running the Simulation:

#### To Run Locally:

1. Clone the project from GitHub: 
   ```sh
   git clone https://github.com/orlovt/delivery-simulation.git
   ```
2. In a Unix terminal, run the following commands:
   ```sh
   make -j
   make run
   ```
3. Open a browser and navigate to:
   ```sh
   localhost:8081
   ```

### Simulation Controls:

- **Control Box**: Add entities, adjust speed, show routes, change views.
- **Schedule Packages**:
  - Name the package.
  - Select pickup and drop-off locations directly on the map.
  - Choose a pathfinding algorithm.
  - The simulation will visually represent the package's journey.

## Design Patterns:

### 1. **Factory Pattern**:

Used extensively to create entities like drones, robots, humans, packages, and porch pirates. This pattern helps manage and encapsulate the creation logic of complex objects.

- **Factories**:
  - `DroneFactory`, `RobotFactory`, `HumanFactory`, `PackageFactory`, `PorchPirateFactory`
  - `CompositeFactory` for managing multiple factories.

### 2. **Strategy Pattern**:

Applied to implement various pathfinding algorithms. The strategy pattern allows the simulation to select different algorithms at runtime.

- **Strategies**:
  - `AStarStrategy`, `BeelineStrategy`, `BfsStrategy`, `DfsStrategy`, `DijkstraStrategy`

### 3. **Observer Pattern**:

Used for event handling and notifications, especially for package delivery updates.

- **Observers & Publishers**:
  - `IPublisher`, `IObserver` for general notifications.
  - `IPackagePublisher`, `IPackageObserver` for package-specific notifications.

### 4. **Decorator Pattern**:

Enhances entities with additional behaviors without modifying their structure. This is used for adding dynamic attributes and behaviors to packages and other entities.

- **Decorators**:
  - `PackageColorDecorator`, `JumpDecorator`, `SpinDecorator`

## New Features: 

### Porch Pirates:

A realistic addition that simulates the problem of package theft. Porch pirates add unpredictability and challenge to the simulation, making it more engaging and reflective of real-world issues.

- **Integration**:
  - Porch pirates listen for package delivery notifications and attempt to intercept packages.
  - They enhance the observer pattern by acting on delivery notifications.
  - This feature tests the resilience of the delivery system and provides a realistic scenario for users to strategize against.

### Links:

- **Docker**: [Delivery Simulation Docker Image](https://hub.docker.com/repository/docker/hans8136/final_project/general)
- **UML**: [UML Diagram](https://lucid.app/lucidchart/7ef312d0-1317-4dfa-ba4b-193d6badac6a/edit?viewport_loc=630%2C-1339%2C6357%2C3043%2C.Q4MUjXso07N&invitationId=inv_ac4dee1d-1796-4de0-a8d9-407667c24c0c)
