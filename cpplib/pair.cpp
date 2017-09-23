#include <utility>
#include <functional>
#include <cassert>
#include "utils.hpp"
using namespace std;
template<typename T1 , typename T2>
std::ostream& operator<< (ostream& out , const pair<T1,T2> p ){
	return out << "[" << p.first << "," << p.second << "]" ;
}
int main(int argc, char *argv[]) {

	int x = 2; 
	auto p= make_pair(ref(x),ref(x));
	++p.first;
	++p.second;
	assert(x == 4);

	int x2;
	tie(ignore,x2) = p;
	assert(x2 == 4);
    return 0;
} 