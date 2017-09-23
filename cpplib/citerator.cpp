#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "utils.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    vector<string> ve;
    ifstream fin(__FILE__);
    copy(istream_iterator<string>(fin),
         istream_iterator<string>(),
         back_inserter(ve));
    copy(ve.begin(), ve.end(), ostream_iterator<string>(cout,"\n"));
    return 0;
}