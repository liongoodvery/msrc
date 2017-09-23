//
// Created by lion on 17-7-20.
//
#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::cout;
using std::cin;
using std::endl;
int main() {
    string a = "a";
    assert(a == "a");
    string b=R"-(aaaaa
    \n    bbbbbbbbbbb)-";
    cout<<b<<endl;
}