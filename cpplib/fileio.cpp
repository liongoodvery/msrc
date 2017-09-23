#include <fstream>
#include <iostream>
#include "utils.hpp"
using namespace std;
int main(int argc, char *argv[]) {
	ifstream fin("/home/lion/tmp/1.xml");
	string s;
	while(fin >> s){
		cout << s << endl;
	}
    cout << "hello world!" << endl;
    return 0;
}