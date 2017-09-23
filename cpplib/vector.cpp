#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	
  	vector<int> vints;
  	for (int i = 0; i < 5; ++i)
  	{
  		vints.push_back(i);
  	}
  	for(int i = 0; i<vints.size(); ++i){
  		cout << vints[i] << '\t';
  	}
  	cout << endl;
  	for(std::vector<int>::iterator p = vints.begin(); p != vints.end(); ++p){
  		cout << *p << '\t';
  	}
  	cout << endl;
    return 0;
}