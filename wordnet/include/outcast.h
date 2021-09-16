#pragma once
#include "wordnet.h"

#include <numeric>

class Outcast
{
private:
    WordNet & wordnet;

public:
    Outcast(WordNet & wordnet)
        : wordnet(wordnet)
    {
    }

    // returns outcast word
    std::string outcast(const std::vector<std::string> & nouns)
    {
        std::string result;
        std::map<std::string, int> distances;
        if (nouns.size() > 2) {
            for (const auto & noun : nouns) {
                distances[noun] = std::accumulate(nouns.begin(), nouns.end(), 0, [&](int sum, const std::string & x) {
                    return sum + wordnet.distance(noun, x);
                });
            }

            auto max_pair = std::max_element(distances.begin(), distances.end(), [](const std::pair<std::string, int> & a, const std::pair<std::string, int> & b) -> bool {
                return a.second < b.second;
            });

            auto second = std::find_if(std::next(max_pair), distances.end(), [&](const auto & x) {
                return max_pair->first != x.first && max_pair->second == x.second;
            });

            if (max_pair != second && second != distances.end()) {
                return "";
            }
            return max_pair->first;
        }
        return result;
    }
};