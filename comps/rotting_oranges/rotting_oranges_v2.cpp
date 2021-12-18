#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <queue>
#include <algorithm>

void print_matrix(std::vector<std::vector<int> > matrix){
		for(auto row: matrix){
    		for(auto col: row){
      			std::cout<<col<<" ";
      	}
      	std::cout<<std::endl;
  	}
		std::cout<<std::endl;
}



int main() {
		std::vector<std::pair<int, int> > nbhd = {{-1, 0}, {1, 0}, {0,1}, {0, -1}};
		std::vector<std::vector<int> > grid = {{2,1,1}, {0,0,0}, {0,1,1}};
		std::queue<std::pair<int, int> > rotten;
	
		int m = grid.size();
		int n = grid[0].size();
		int fresh = 0;
		int top = 0;
		int time = 0;

    for(int i = 0; i < m; i++) {
    		for(int j = 0; j < n; j++) {
        		if(grid[i][j] == 1) fresh++;
            else if(grid[i][j] == 2) rotten.push({i, j});
        }
    }


		while(!rotten.empty()){
				top = rotten.size();
				while(top>0){
						auto cur = rotten.front();
            rotten.pop();
            for(auto dir: nbhd) {
            		int x = cur.first + dir.first;
        	        int y = cur.second + dir.second;
                if(x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1) {
                		grid[x][y] = 2;
                    rotten.push({x, y});
                    fresh--;
                }
            }
						top--;
        }
				print_matrix(grid);
        time++;	
		}
		std::cout<<time<<std::endl;
		return 0;
}

