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


bool isMatch(string s, string p) {
		bool DP[15][15] = {false};	
		bool match;
		int s_len = s.length();
		int p_len = p.length();



		//initialization 
		DP[s_len][p_len] = true;
		
		// buttom up
		for (int i = s_len ; i >=0 ; i--){
				for (int j = p_len - 1 ; j >=0 ; j--){
						match = (i < s_len && (p[j] == '.' || p[j] == s[i]));
						if (j+1 < p_len && p[j+1] == '*')
								DP[i][j] = DP[i][j+2] || (DP[i+1][j] && match) || (DP[i+1][j+2] && match);
						else if (j+1 < p_len && p[j+1] == '+')
								DP[i][j] = (DP[i+1][j] && match) || (DP[i+1][j+2] && match);
						else
								DP[i][j] = DP[i+1][j+1] && match;
				}
		}
		
		return DP[0][0];
}


int main() {
		string regexp = ".*.a*";
		string text = "a";

		//string regexp = "ab*.*.*c+.*.*";
		//string text = "abc";

		cout<<"->"<<isMatch(text, regexp)<<"<-";

		return 0;
}
