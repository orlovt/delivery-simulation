# Project Description:

The project is a web based 3D simulation. Its map represents the campus of the University of Minnesota Twin Cities in Minneapolis, MN. The simulation involves the following entities: helicopters, humans, robots, drones, packages and porch pirates.

The Helicopter navigates the map and keeps notifying the user of the amount of miles it has traveled. The humans also walk around on the map and will notify the user when they get within close distance of the Keller Hall building. 

The major features involve robots, drones, packages and porch pirates. The simulation allows the user to simulate a drone fleet delivery service. The user can select a pick up and drop off location for a package as well as a movement strategy out of a few famous path finding algorithms, the list includes the A-Star algorithm, the breadth first search algorithm, the depth first search algorithm and Dijkstra’s algorithm. Once the pick up location, drop off location and movement strategy are selected, the drone will move towards the pick up location in a beeline fashion, pick up the package and move towards the drop off location with the selected movement strategy. The robots represent the package owners (or customers waiting for their package) but they are not always by the drop off location to receive their package. Once the drone gets to a drop off location, it will drop off the package and the robot will head towards the drop off location to receive its package. However porch pirates exist and they usually wander around the map. When they are within close proximity of packages they will also move towards the drop off location to attempt to steal the package before its owner (the robot) arrives. If they succeed in their theft, porch pirates will go to a specific mississippi bank where they gather all their loot. 

## How to run the simulation:

## To run locally:

Clone the project from github: `git clone https://github.umn.edu/umn-csci-3081-s24/team-010-29-finalproject.git`

In a unix terminal run the command: `make -j`

In a unix terminal run the command: `make run`

Open a browser at the following address: `localhost:8081`

### You can view the simulation at: 

Use the control box on the upper right hand of the screen to add entities, change the speed of the simulation, show routes, change your view, and most importantly schedule packages. When scheduling a package, give it a name in the given ‘name’ field. Afterwards select a pickup and dropoff location for the package, you can do this by selecting the points directly on the map. The Pick-up spot is represented by a yellow beam while the green beam is the destination.

#### Simulation Specifics 

- Entities & Interactions:

  - Drones: Autonomous flying vehicles that deliver packages using navigation strategies: A*, Dijkstra, Beeline, bfs, dfs

  - Robots: Ground entities that receive packages.

  - Humans: Individuals who walk the map, and interact with simulation.

  - Porch Pirates: Thieves who attempt to steal packages before delivery.

  - Packages: Items to be delivered, tracked throughout the delivery process.

* Simulation Management:

  - Trip Scheduling: Users schedule deliveries by specifying pickup/drop-off locations and navigation strategies.

  - Observers & Publishers:

  - IPublisher & IObserver: Interfaces for package delivery notifications.

  - IPackagePublisher & IPackageObserver: Interfaces for tracking package delivery status.

  - 3D Visualization: 

  - Three.js for immersive 3D visualization, JSon, and jquery

  - UI Buttons: Add/remove entities and schedule trips via UI, html, typescript (scheduleTrip)

  - Factories:

    - EntityFactory & Specific Factories: Create entities per user input. Exists for all entities.

  - Main Extensions:

    - Porch Pirates: Attempt to intercept packages before delivery to robots. 

  - Data Collection: 

#### New Features: 

**Porch Pirates**: A  Porch Pirate is just that, they are pirating packages from a “porch”, in our case the delivery spot. This is a new entity type in the simulation, and it attempts to steal packages before they reach their delivery points. These pirates initially roam the simulation map, listening for package delivery notifications, and try to intercept the package once the drone drops it off… if they are close enough of course. Once they intercept the packages they bring it back to a certain position on the map called Caribbean position in our code base.

- ##### Why is it significantly interesting?

    This is a realistic situation and it adds a sense of  challenge to the simulation by simulating the real-world problem of package theft. The porch pirate is the first character that is sort of like a villain, it is adding an aspect to the project to test its compatibility to the real world. Introduces dynamic and unpredictable behavior into the simulation, making it more engaging.This allows users to plan their deliveries strategically and also for developers to understand an important hurdle in the delivery system. 

- ##### What does it do?

    What this adds is more entities in the simulation, making it more comprehensive. It also integrates with the existing observer pattern (IPackagePublisher and IPackageObserver), allowing porch pirates to receive notifications and act upon them. This truly tests the abilities of all the other entities, making it better for real world application and for developers.

### Data Collection: 

![Plot1](plots/plot1.png)

The plot shows that we have significantly fat tails in the distribution of deviveries, this imples that we can increase efficiency by repositioning them back to local hotspots. 

![Plot2](plots/plot2.png)

The plot shows the counts of stolen packages, which indicates the presence of the problem. 

![Plot3](plots/plot3.png)
This heatmap plots the coordinates of the packages before they were stolen, this will largely help our business, since these areas will be avoided in future in order to save money. 


![Plot4](plots/plot4.png)
The next heatmap plots the clusters of the dropoff locations, this graph in itself imples the fact that there are a couple of major hubs to which people order their deliveries, most likely dorms or apartment buildings. 

![Plot5](plots/plot5.png)

The heatmap of Pickup location clearly shows that most of the oncampus deliveries are from one area, in order to make out deliveries more efficient we might make the drones reposition themselfes at this location to decrease delivery times. 


Links: 

- Youtube: https://youtu.be/H7HjxuxqyaE

- Docker Link: https://hub.docker.com/repository/docker/hans8136/final_project/general

- UML: https://lucid.app/lucidchart/7ef312d0-1317-4dfa-ba4b-193d6badac6a/edit?viewport_loc=630%2C-1339%2C6357%2C3043%2C.Q4MUjXso07N&invitationId=inv_ac4dee1d-1796-4de0-a8d9-407667c24c0c

		 	 	 		

			

				

					

						

					
 							

						 					

				

			

		
