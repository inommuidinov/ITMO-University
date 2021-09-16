#pragma once

#include "limits"
#include "map"
#include "unordered_map"
#include "vector"

class ShortestCommonAncestor
{
public:
    void setHyp(const std::map<int, std::vector<int>> & hyp)
    {
        digraph.setHyp(hyp);
    }

    // calculates length of shortest common shortestCommonAncestor path from node with id 'u' to node with id 'v'
    int length(int v, int w)
    {
        const auto & min = min_elem(v, w);
        return min.second.depth_sum();
    }

    // returns node id of shortest common shortestCommonAncestor of nodes u and v
    int ancestor(int v, int w)
    {
        return min_elem(v, w).first;
    }

    // calculates length of shortest common shortestCommonAncestor path from node subset 'subset_a' to node subset 'subset_b'
    int length_subset(const std::set<int> & a, const std::set<int> & b)
    {
        int len = INF;
        for (const auto & i : a) {
            for (const auto & j : b) {
                len = std::min(len, length(i, j));
            }
        }
        return len;
    }

    // returns node id of shortest common shortestCommonAncestor of node subset 'a' and node subset 'b'
    int ancestor_subset(const std::set<int> & a, const std::set<int> & b)
    {
        int len = INF;
        int id = INF;
        for (const auto & i : a) {
            for (const auto & j : b) {
                int curLen = length(i, j);
                if (curLen < len) {
                    len = curLen;
                    id = ancestor(i, j);
                }
            }
        }
        return id;
    }

private:
    Digraph digraph;

    const static int INF = std::numeric_limits<int>::max();

    enum path
    {
        u,
        v
    };

    struct Node
    {
        int depth_u = INF >> 1;
        int depth_v = INF >> 1;
        int depth_sum() const
        {
            return depth_u + depth_v;
        }
    };

    std::pair<int, Node> min_elem(int v, int w)
    {
        std::map<int, Node> path;
        buildPath(v, path::u, path, 0);
        buildPath(w, path::v, path, 0);

        return *std::min_element(path.begin(), path.end(), [](const std::pair<int, Node> & a, const std::pair<int, Node> & b) {
            return a.second.depth_sum() < b.second.depth_sum();
        });
    }

    void buildPath(int id, const path flag, std::map<int, Node> & Path, int depth)
    {
        auto & depth_ref = flag == path::u ? Path[id].depth_u : Path[id].depth_v;
        depth_ref = std::min(depth_ref, depth);

        for (const auto & i : digraph.get(id)) {
            buildPath(i, flag, Path, (++depth)--);
        }
    }
};