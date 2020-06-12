#include "helpper.h"
#include <vector>
#include <sstream>
#include  <string>
//#include <specstrings.h>

vector<string> Helpper::split(const string &s, char delim)
{
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}


