#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#pragma once

#include <map>
#include <list>

namespace adjacency_list
{
  void print_graph(const std::map<int, std::list<int>>& graph, const char** const labels);
  void bfs(std::map<int, std::list<int>>& graph, const char** const labels);
  void dfs(std::map<int, std::list<int>>& graph, const char** const labels);
}

#endif