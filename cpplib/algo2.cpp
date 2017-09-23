#include <list>
#include <algorithm>
#include <cassert>
using namespace std;
int main(int argc, char *argv[]) {
	list<int> li;
	for (int i = 0; i < 20; ++i){
		li.push_back(i);
	}
	auto pos = find(li.begin(),li.end(),25);
	assert(pos == li.end());
	pos = find(li.begin(),li.end(),5);
	assert(*pos == 5);

	pos = find_if(li.begin(), li.end() ,[](int i){return i == 15;});
	assert(*pos == 15);

    return 0;
}