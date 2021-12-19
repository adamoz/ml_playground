#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <queue>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <unordered_map>


std::vector<int> sort_indexes(std::vector<int> &v){
		std::vector<int> i(v.size());
		std::iota(i.begin(), i.end(), 0);

		std::stable_sort(i.begin(), i.end(), [&v](int i1, int i2){return v[i1]<v[i2];});
		return i;
}


int get_element_position(std::vector<int> &v, int element, int start=0){
		int end = v.size() - 1;
		int middle;

		while(true){
				middle = (int) std::round((start + end) / 2);
				if(v[middle] == element) return middle;
				if(v[middle] < element) start = middle+1;
				else end = middle -1;
				
				if(start > end) return -1;
		}
}


std::vector<int> get_2sum(std::vector<int> &v, int sum){
		std::unordered_map<int, int> residual_search;
		std::vector<int> result;
		int residual;

		for(int i=0; i<v.size(); i++){
				residual = sum - v[i];
				if(residual_search.find(residual) == residual_search.end()){
					residual_search.insert({v[i], i});
				}
				else{
					result.push_back(i);
					result.push_back(residual_search[residual]);
					return result;
				}
		}
		return result;
}


std::tuple<std::string, int> step_regexp(std::string& regepx, int current_position){
		return std::make_tuple("a", current_position+1);
}



int main() {
		std::string regexp = "abcd.*xxx";
		auto [symbol, next_position] = step_regexp(regexp, 3);
		std::cout<<symbol<<" "<<next_position;
		return 0;
}
	
