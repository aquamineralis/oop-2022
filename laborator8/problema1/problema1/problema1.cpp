#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

std::ifstream fin("text.txt");

class Compare {
  public:
    bool operator()(std::pair<std::string, int> p1, std::pair<std::string, int> p2) {
        if (p1.second < p2.second)
            return true;
        if (p1.second == p2.second) {
            if (p1.first > p2.first)
                return true;
            else
                return false;
        }
        return false;
    }
};

int main() {
    std::string phrase;
    std::string separators = " ,!?.";
    std::getline(fin, phrase);

    std::transform(phrase.begin(), phrase.end(), phrase.begin(), [](char c) { return std::tolower(c); });

    std::map<std::string, int> words;
    std::string word = "";
    for (int i = 0; phrase[i]; i++) {
        if (separators.find(phrase[i]) != -1) {
            if (i > 0 && separators.find(phrase[i - 1]) == -1) {
                if (words.find(word) == words.end()) {
                    words.insert({ word, 1 });
                } else {
                    words[word]++;
                }
                word = "";
            }
        } else {
            word += phrase[i];
        }
    }
    if (word != "") {
        if (words.find(word) == words.end()) {
            words.insert({ word, 1 });
        } else {
            words[word]++;
        }
    }

    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> words_queue;

    std::map<std::string, int>::iterator it = words.begin();
    while (it != words.end()) {
        std::pair<std::string, int> pair;
        pair.first  = it->first;
        pair.second = it->second;
        words_queue.push(pair);
        it++;
    }

    while (!words_queue.empty()) {
        std::cout << words_queue.top().first << " => " << words_queue.top().second << '\n';
        words_queue.pop();
    }
    return 0;
}
