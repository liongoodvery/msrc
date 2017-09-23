//
// Created by lion on 17-7-24.
//
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <vector>

using namespace std;
extern char *optarg;

vector<string> split(const string &s, const string &seperator) {
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != s.size()) {
        //找到字符串中首个不等于分隔符的字母；
        int flag = 0;
        while (i != s.size() && flag == 0) {
            flag = 1;
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[i] == seperator[x]) {
                    ++i;
                    flag = 0;
                    break;
                }
        }

        //找到又一个分隔符，将两个分隔符之间的字符串取出；
        flag = 0;
        string_size j = i;
        while (j != s.size() && flag == 0) {
            for (string_size x = 0; x < seperator.size(); ++x)
                if (s[j] == seperator[x]) {
                    flag = 1;
                    break;
                }
            if (flag == 0)
                ++j;
        }
        if (i != j) {
            result.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    string base_dir = ".";
    int ch;

    string name;

    while ((ch = getopt(argc, argv, "b:n:h")) != -1) {
        switch (ch) {
            case 'b':
                base_dir = string(optarg);
                break;
            case 'n':
                name = string(optarg);
                break;
            case 'h':
                cout << "addActivity -b baseDir -n name -h" << endl;
                break;
            case '?':
                exit(EXIT_FAILURE);
        }
        const vector<string> &nameParts = split(name, "_");

    }


    cout << base_dir << "\t" << name;
}