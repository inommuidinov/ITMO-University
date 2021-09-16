#pragma once
#include "map"
#include "unordered_map"
#include "vector"

class Digraph
{
private:
    std::unordered_map<int, std::vector<int>> graph;

public:
    void setHyp(const std::map<int, std::vector<int>> & hyp)
    {
        for (const auto & [i, parents] : hyp) {
            for (const auto & j : parents) {
                graph[i].push_back(j);
            }
        }
    }

    const std::vector<int> & get(const int id)
    {
        return graph[id];
    }
};