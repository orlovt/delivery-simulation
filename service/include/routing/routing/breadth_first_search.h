#ifndef BFS_PATHING_H_
#define BFS_PATHING_H_

#include "routing_strategy.h"
#include <string>

namespace routing {

class BreadthFirstSearch : public RoutingStrategy {
public:
	virtual ~BreadthFirstSearch() {}

	std::vector<std::string> GetPath(const IGraph* graph, const std::string& from, const std::string& to) const;

	static const RoutingStrategy& Default() {
		static BreadthFirstSearch bfs;
		return bfs;
	}
};

}

#endif
