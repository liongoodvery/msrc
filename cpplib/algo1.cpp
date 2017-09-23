#include <cassert>
#include <algorithm>
#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	vector<int> vec{4,5,3,1,2};
	auto min = min_element(vec.begin(),vec.end());
	assert(*min == 1);
	auto max = max_element(vec.begin(),vec.end());
	assert(*max == 5);

	sort(vec.begin(),vec.end());
	assert(vec[0] == 1);
	assert(vec[4] == 5);
	auto pos = find(vec.begin(),vec.end(),3);
	assert(*pos == 3);
	reverse(pos,vec.end());
	assert(vec[4] == 3);
	assert(vec[3] == 4);
	assert(vec[2] == 5);

    return 0;
}