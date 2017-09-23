#include "utils.hpp"
using namespace std;

int main(int argc, char *argv[]) {
	vector<int> vec{1,2,3,4};
	print(vec);
	for(auto& i : vec){
		i *=  3;
	}
	printElements(vec);
    return 0;
}