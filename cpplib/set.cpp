#include <set>
#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	multiset<string> ms = {"lion","android"};
	for(const auto &s : ms) {
		cout << s << "\t";
	}
	cout << endl;
	ms.insert({"good", "more", "lion"});
		for(const auto &s : ms) {
		cout << s << "\t";
	}
	cout << endl;
    return 0;
}