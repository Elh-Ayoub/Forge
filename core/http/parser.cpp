#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> stringTo2DArray(const string& input);

vector<string> parse(string buffer){
    
    // char *lines[12];
    vector<string> lines = stringTo2DArray(buffer);

    // for (const auto& row : lines) {
    //     cout << row << endl;
    // }

    // Request tmp;
    // return tmp;
    return lines;
}

vector<string> stringTo2DArray(const string& input) {
    vector<string> lines;
    string line;

    for (char ch : input) {
        if (ch == '\n') {
            lines.push_back(line);
            line.clear();
        } else {
            line += ch;
        }
    }

    // Push the last line into lines vector (if any)
    if (!line.empty()) {
        lines.push_back(line);
    }

    return lines;
}
