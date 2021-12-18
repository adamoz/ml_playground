#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>

std::tuple<int, std::string> f(){
	return std::tuple<int, std::string>(123, "test of tuple");
}

template<typename A, typename B> auto ff(A a, B b){
	return a+b;
}


int main() {
	std::string string_array[] = {"a", "b", "c", "d"};	
	std::string &s_ref = string_array[0];
	std::string s_copy = string_array[0];

	std::cout<<"string array "<<string_array<<" "<<string_array[0]<<std::endl;
	std::cout<<"String array reference "<<&s_ref<<" "<<s_ref<<std::endl;
	std::cout<<"String array copy "<<&s_copy<<" "<<s_copy<<std::endl;

	return 0;


}

