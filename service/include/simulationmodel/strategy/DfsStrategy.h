#ifndef DFS_STRATEGY_H_
#define DFS_STRATEGY_H_

#include "PathStrategy.h"
#include "Graph.h"

/**
 * @brief this class inhertis from the PathStrategy class and is responsible for
 * generating the depth first search path that the drone will take.
 */
class DfsStrategy : public PathStrategy {
 public:
  /**
   * @brief Construct a new Astar Strategy object
   *
   * @param position Current position
   * @param destination End destination
   * @param graph Graph/Nodes of the map
   */
  DfsStrategy(Vector3 position, Vector3 destination,
              const routing::Graph* graph);
};
#endif  // DFS_STRATEGY_H_
