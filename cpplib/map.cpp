#include <map>
#include <string>
#include "utils.hpp"
using namespace std;
typedef std::map<string,int> Map;
int main(int argc, char *argv[]) {
	Map m{{"1",1},{"2",2},{"1",3}};
	m.insert({"3",3});
	m.insert({"2",22});
	for(const auto &p : m){
		cout << "{" << p.first << "," << p.second << "}" << endl;
	}
    return 0;
}