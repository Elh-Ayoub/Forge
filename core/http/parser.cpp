#include <string>
#include <vector>
using namespace std;

vector<string> parse(string buffer){
    vector<string> lines;
    string line;

    for (char ch : buffer) {
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
