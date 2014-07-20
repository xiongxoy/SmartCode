#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::string item = "";
    bool in = false;
    for (int i = 0; i < s.length(); i++) {
      if (in) {
        if (' ' != s[i])
          item += s[i];
        else {
          in = false;
          elems.push_back(item);
          item = "";
        }
      } else {
        if (' ' != s[i]) {
          item = "";
          item += s[i];
          in = true;
        }
      }
    }
    if (in) {
      elems.push_back(item);
    }
    return elems;
  }

  public:
  string reverseWords(string &s) {
    vector<string> items;
    split(s, ' ', items);
    string ret = "";
    for(auto it = items.rbegin(); it != items.rend(); ++it) {
      ret += *it;
    }
    return ret;
  }
};

int main(int argc, const char *argv[])
{
  Solution sol;
  string s = "1 2 3";
  cout << sol.reverseWords(s);
  s = " ";
  cout << endl;
  cout << ": ";
  cout << sol.reverseWords(s);
  return 0;
}




