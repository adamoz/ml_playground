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
using namespace std;


vector<int> sort_indexes(vector<int> &v){
		vector<int> i(v.size());
		iota(i.begin(), i.end(), 0);

		stable_sort(i.begin(), i.end(), [&v](int i1, int i2){return v[i1]<v[i2];});
		return i;
}


int get_element_position(vector<int> &v, int element, int start=0){
		int end = v.size() - 1;
		int middle;

		while(true){
				middle = (int) round((start + end) / 2);
				if(v[middle] == element) return middle;
				if(v[middle] < element) start = middle+1;
				else end = middle -1;
				
				if(start > end) return -1;
		}
}


vector<int> get_2sum(vector<int> &v, int sum){
		unordered_map<int, int> residual_search;
		vector<int> result;
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


tuple<string,bool, bool, int> step_regexp(string& regexp, int current_position){
		int reg_size = regexp.size();
		string regexp_letter;
		bool plus = false;
		bool star = false;

		if(current_position >= reg_size) return make_tuple("", false, false, -1);
		regexp_letter = regexp[current_position];
		
		if((current_position+1 < reg_size) && (regexp[current_position+1] == '+')){plus = true; current_position += 2;}
		else if((current_position+1 < reg_size) && (regexp[current_position+1] == '*')){star = true; current_position += 2;}
		else current_position += 1;
		return make_tuple(regexp_letter, star, plus, current_position);
}

bool is_regexp_ok(string& text, string& regexp, int spos, int rpos, int ssize, int rsize){
		if((spos>=ssize) && (rpos>=rsize)) return true;
		if((spos<ssize)  && (rpos>=rsize)) return false;
		if((spos>ssize)  && (rpos<rsize)) return false;


		bool ok = false;
		string string_letter;
		auto [symbol, star, plus, next_rpos] = step_regexp(regexp, rpos);
		cout<<symbol<<star<<plus<<" spos: "<<spos<<" rpos: "<<rpos<<" next rpos: "<<next_rpos<<endl;


		if(star || plus){
			if(star){
				ok = is_regexp_ok(text, regexp, spos, next_rpos, ssize, rsize);
				if(ok) return ok;
			}
			while(spos<ssize){
					if(symbol!="."){
							string_letter = text[spos];
							if(symbol!=string_letter) return false;
					}
					spos++;
					ok = is_regexp_ok(text, regexp, spos, next_rpos, ssize, rsize);
					if(ok) return ok;
			}
			return false;
		}
		else if(spos<ssize){
			string_letter = text[spos];
			if(symbol == "."){
				spos++;
				return is_regexp_ok(text, regexp, spos, next_rpos, ssize, rsize);
			}
			else if(symbol==string_letter){
				spos++;
				return is_regexp_ok(text, regexp, spos, next_rpos, ssize, rsize);
			}
			else return false;
		}
		else return false;
}


int main() {
		string regexp = ".*.a*";
		string text = "a";

		//string regexp = "ab*.*.*c+.*.*";
		//string text = "abc";

		cout<<"->"<<is_regexp_ok(text, regexp, 0, 0, text.size(), regexp.size())<<"<-";

		return 0;
}
	
