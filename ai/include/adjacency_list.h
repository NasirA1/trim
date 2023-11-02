#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#pragma once

#include <map>
#include <list>

namespace adjacency_list
{
  using graph_t = std::map<int, std::list<int>>;
  void print_graph(const graph_t& graph, const char** const labels);
  void bfs(graph_t& graph, const char** const labels);
  void dfs(graph_t& graph, const char** const labels);
}

#endif