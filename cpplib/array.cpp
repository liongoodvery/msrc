#include <array>
#include <cassert>
#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	array<int,5> arr ={{1,2}};
	assert(arr[0] == 1);
	assert(arr[1] == 2);
	assert(arr[3] == 0);
	assert(arr[4] == 0);


    return 0;
}