#include "q.h"

#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <algorithm>
// Implement each function of `q.h` here.

// Given a string, you are asked to create a histogram of all the words
// that appear in that string.
//
// **Assumption:** The given text only has the following characters:
// - lower case alphabetic characters, i.e. `'a' to 'z'`
// - Dot, comma and space, i.e.: `'.', ',',  ' '`

// There are no other characters in the input
// text, i.e. it does not have any new lines, tab, numbers, etc.
//
// Example 1: Input: "this is a test, and this is another one."
//
// Output:
// { {"a", 1},
//   {"and", 1},
//   {"another", 1},
//   {"is", 2},
//   {"one", 1},
//   {"test", 1},
//   {"this", 2}
// }

// Example 2: Input: " this ,."
//
// Output:
// {
//   {"this", 1}
// }
// Note: the only function from std:: that you can use is std::find.
std::map<std::string, int> WordHistogram(std::string &text) {
    std::map<std::string, int> hist;
    
    if (text.empty()) {
        return hist;
    } 

    std::set<char> special_chars = {'.', ',', ' '};

    std::string tmp_str;

    for (const auto &x : text) {
        auto it = special_chars.find(x);
        if (it == special_chars.end()) {
            tmp_str.push_back(x);
        } 
        else {
            if (!tmp_str.empty()) {
                auto map_it = hist.find(tmp_str);
                if (map_it == hist.end()) {
                    hist[tmp_str] = 1;
                }
                else {
                    hist[tmp_str]++;
                }
                tmp_str.clear();
            }
        }
    }

    if (!tmp_str.empty()) {
        auto map_it = hist.find(tmp_str);
        if (map_it == hist.end()) {
            hist[tmp_str] = 1;
        }
        else {
            hist[tmp_str]++;
        }
    }

    return hist;
}