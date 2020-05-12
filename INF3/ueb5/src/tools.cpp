#include <string>

using namespace std;



void removeTags(string &line, const string tag)
{
    string start = "<"+tag+">";
    string end = "</"+tag+">";

    line.erase(0, line.find(start)+start.size());
    line.erase(line.find(end), end.size());
}
