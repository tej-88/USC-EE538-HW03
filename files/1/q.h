#ifndef FILES_2_Q
#define FILES_2_Q
#include <iostream>
#include <map>
#include <string>
// TODO: Implement the following functions in q.cc.

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
std::map<std::string, int> WordHistogram(std::string &text);


#endif /* FILES_2_Q */
