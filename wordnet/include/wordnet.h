#pragma once

#include <algorithm>
#include <digraph.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <shortest_common_ancestor.h>
#include <sstream>
#include <string>
#include <vector>

class WordNet
{

public:
    WordNet(const std::string & synsets_fn, const std::string & hypernyms_fn)
    {
        read_input(synsets_fn, input::synsets);
        read_input(hypernyms_fn, input::hypernyms);
    }

    using iterator = std::set<std::string>::iterator;

    // get iterator to list all nouns stored in WordNet
    auto nouns()
    {
        return dictionary.begin();
    }

    auto end()
    {
        return dictionary.end();
    }

    auto begin()
    {
        return dictionary.begin();
    }

    // returns 'true' if 'word' is stored in WordNet
    bool is_noun(const std::string & word) const
    {
        return std::find(dictionary.begin(), dictionary.end(), word) != dictionary.end();
    }

    // returns gloss of "shortest common shortestCommonAncestor" of noun1 and noun2
    std::string sca(const std::string & a, const std::string & b)
    {
        return gloss[shortestCommonAncestor.ancestor_subset(wordLinks[a], wordLinks[b])];
    }

    // calculates distance between noun1 and noun2
    int distance(const std::string & a, const std::string & b)
    {
        return shortestCommonAncestor.length_subset(wordLinks[a], wordLinks[b]);
    }

private:
    std::set<std::string> dictionary;
    std::map<int, std::string> gloss;
    ShortestCommonAncestor shortestCommonAncestor;
    std::map<std::string, std::set<int>> wordLinks;

    enum input
    {
        synsets,
        hypernyms
    };

    std::vector<std::string> split(const std::string & str, char delimeter)
    {
        std::vector<std::string> result;
        std::stringstream ss(str);
        std::string item;

        while (getline(ss, item, delimeter)) {
            result.push_back(item);
        }

        return result;
    }

    void read_input(const std::string & str, const input in)
    {
        std::fstream fin(str);
        if (fin.fail()) {
            throw std::runtime_error("Can't open file " + str);
        }

        std::string tmp;
        std::map<int, std::vector<int>> hyp;
        while (std::getline(fin, tmp)) {
            auto nouns = split(tmp, ',');
            switch (in) {
            case synsets: {
                auto id = std::atoi(nouns[0].c_str());
                gloss[id] = nouns[nouns.size() - 1];
                auto words = split(nouns[1], ' ');
                for (const auto & i : words) {
                    dictionary.insert(i);
                    wordLinks[i].insert(id);
                }
                break;
            }
            case hypernyms: {
                int id = -1;
                for (const auto & i : nouns) {
                    if (id == -1) {
                        id = std::atoi(i.c_str());
                    }
                    else {
                        hyp[id].push_back(std::atoi(i.c_str()));
                    }
                }
                break;
            }
            }
        }
        if (in == input::hypernyms) {
            shortestCommonAncestor.setHyp(hyp);
        }
    }
};

#include "outcast.h"