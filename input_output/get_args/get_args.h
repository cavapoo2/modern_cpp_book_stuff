#pragma once
#include<vector>
#include<iostream>
#include<sstream>
template<typename Container>
void show(const Container& cont) {
	for(auto &r: cont) {
		std::cout << r << std::endl;
	}
}
template<typename T>
std::vector<T> getCommandLineArgs(int argc,char*argv[]) {
	std::vector<std::string> arguments(argv + 1, argv + argc);
	std::vector<T> res;
	for(auto& v: arguments){
		std::stringstream conv(v);
		T r;
		conv >> r;
		res.push_back(r);
	}

	return res;

}

