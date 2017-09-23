#include <string>
#include <vector>
#include <memory>
#include <cassert>

#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	shared_ptr<string> ps(new string("abc"));
	assert(*ps == "abc");
	assert((*ps)[0]== 'a');
	ps->replace(0,1,"A");
	assert((*ps)[0]== 'A');
	assert(ps.use_count()==1);
	{
		auto a = ps;
		assert(ps.use_count()==2);
	}
	assert(ps.use_count()==1);
	shared_ptr<string> ps1(new string("def"),
		[](string* p){
			cout << "deleting " << *p << endl;
			delete p;
		});
	vector<shared_ptr<string> > vps ;
	vps.push_back(ps);
	vps.push_back(ps1);
	vps.resize(1);
    return 0;
}