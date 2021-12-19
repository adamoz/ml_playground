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


std::vector<size_t> sort_indexes(std::vector<int> &v){
		std::vector<size_t> i(v.size());
		std::iota(i.begin(), i.end(), 0);

		std::stable_sort(i.begin(), i.end(), [&v](size_t i1, size_t i2){return v[i1]<v[i2];});
		return i;
}


int get_element_position(std::vector<int> &v, int element, size_t start=0){
		size_t end = v.size() - 1;
		size_t middle;

		while(true){
				middle = (size_t) std::round((start + end) / 2);
				if(v[middle] == element) return middle;
				if(v[middle] < element) start = middle+1;
				else end = middle -1;
				
				if(start > end) return -1;
		}
}


std::vector<int> get_2sum_v2(std::vector<int> &v, int sum){
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


int main() {
		std::vector<int> v = {1, 6, 3, 2, 10, 11, 0};
		int sum = 1;

		// Hashed O(n) approach.
		std::vector<int> result = get_2sum_v2(v, sum);
		if(result.size() == 2) std::cout<<result[0]<<" "<<result[1]<<" ";

		// Binary search O(nlog(n)) in sorted array.
		int e2 = 0;
		int p1 = 0;
		int p2 = 0;
		std::vector<size_t> original_positions = sort_indexes(v);
		std::sort(v.begin(), v.end());
		for(auto e1: v){
				e2 = sum - e1;
				if(e2 < e1) break;
				p2 = get_element_position(v, e2, p1+1);
				if(p2 != -1) break;
				p1++;
		}
		if(p2 != -1) std::cout<<original_positions[p1]<<" "<<original_positions[p2]<<" ";

		return 0;
}
	
