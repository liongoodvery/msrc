#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iterator>
#include <algorithm>
#include <cassert>
#include "utils.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    list<int> li;
    for (int i = 0; i < 5; ++i) {
        li.push_back(i);
    }

    vector<int> ve;
    copy(li.begin(), li.end(), back_inserter(ve));

    deque<int> de;
    copy(li.begin(), li.end(), back_inserter(de));
    copy(li.begin(), li.end(), front_inserter(de));
    copy(li.begin(), li.end(), inserter(de, de.begin()));

    set<int> se;
    copy(li.begin(), li.end(), inserter(se, se.begin()));

    printElements(se);
    return 0;
}