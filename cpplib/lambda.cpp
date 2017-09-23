#include <functional>
#include "utils.hpp"
using namespace std;
function<int(int,int)> addFunc(){
	return [](int a , int b) -> int{
		return a + b;
	};
}

template <typename T1 , typename T2>
auto func(T1 x, T2 y) ->decltype(x+y){
	return x+y;
}

int main(int argc, char *argv[]) {
    cout << addFunc()(1,2) << endl;
    cout << func(1,2) << endl;
    return 0;
}

