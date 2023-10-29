#include "adjacency_list.h"
#include <iostream>
#include <unordered_set>
#include <stack>
#include <queue>

namespace adjacency_list
{
  void print_graph(const std::map<int, std::list<int>>& graph, const char** const labels) {
    for (const auto& node : graph) {
      std::cout << labels[node.first] << ": ";
      for (auto neighbour : node.second) {
        std::cout << labels[neighbour];
        if (neighbour != node.second.back()) std::cout << ',';
      }
      std::cout << std::endl;
    }
  }

  void bfs(std::map<int, std::list<int>>& graph, const char** const labels) {
    std::unordered_set<int> visited;
    std::queue<int> nodes;
    nodes.push(0);
    while (!nodes.empty()) {
      auto current = nodes.front();
      nodes.pop();
      if (visited.find(current) == visited.end()) {
        visited.insert(current);
        std::cout << labels[current];
        if (visited.size() < graph.size()) std::cout << "->"; else std::cout << std::endl;
        for (auto neighbour : graph[current]) {
          nodes.push(neighbour);
        }
      }
    }
  }

  void dfs(std::map<int, std::list<int>>& graph, const char** const labels) {
    std::unordered_set<int> visited;
    std::stack<int> nodes;
    nodes.push(0);
    while (!nodes.empty()) {
      auto current = nodes.top();
      nodes.pop();
      if (visited.find(current) == visited.end()) {
        visited.insert(current);
        std::cout << labels[current];
        if (visited.size() < graph.size()) std::cout << "->"; else std::cout << std::endl;
        for (auto neighbour : graph[current]) {
          nodes.push(neighbour);
        }
      }
    }
  }

}
