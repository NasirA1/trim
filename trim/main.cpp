#include <iostream>
#include "arithmetic.h"
#include "string_helper.h"
#include "adjacency_list.h"

int main(int argc, char* argv[])
{    
    std::cout << "Hello, world!\n";
    std::cout << calc::add(1, 2) << std::endl;
    std::cout << util::replicate("hello", 3) << std::endl;

    // Graph here:  https://en.wikipedia.org/wiki/Depth-first_search
    constexpr const size_t SIZE = 7;
    const char* labels[SIZE]{ "A", "B", "C", "D", "E", "F", "G" };
    adjacency_list::graph_t graph = {
        {0, { 1, 2, 4 }},
        {1, { 3, 5 }},
        {2, { 6 }},
        {3, {}},
        {4, { 5 }},
        {5, { 4 }},
        {6, {}}
    };

    adjacency_list::print_graph(graph, labels);

    std::cout << "BFS: ";
    adjacency_list::bfs(graph, labels);

    std::cout << "DFS: ";
    adjacency_list::dfs(graph, labels);

    return EXIT_SUCCESS;
}