#ifndef CPPLIB_LION_UTILS
#define CPPLIB_LION_UTILS

#include <iostream>
#include <vector>
#include <initializer_list>

void print(std::vector<int> v){
	for(const auto &i : v ){
		std::cout << i << '\t';
	}
	std::cout << std::endl;

}

void print(std::initializer_list<int> vals){
	for(auto p=vals.begin(); p!=vals.end(); ++p){
		std::cout << *p << '\t';
	}
	std::cout << std::endl;
}

template <typename T>
void printElements(const T& coll){
	for(const auto &e : coll){
		std::cout << e << '\t';
	}
	std::cout << std::endl;
}
#endif //CPPLIB_LION_UTILS