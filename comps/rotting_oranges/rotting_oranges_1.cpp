#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>


std::pair<bool, bool> orange_iteration(std::vector<std::vector<int> >& grid1, std::vector<std::vector<int> >& grid2){
		bool changed = false;
		bool finished = true;
		for(int x=0; x<grid1.size(); x++){
				for(int y=0; y<grid1[x].size(); y++){
						if(grid1[x][y]==2 || grid1[x][y]==0){
								grid2[x][y] = grid1[x][y];
								continue;
						}
						if((grid1[std::max(x-1, 0)][y]==2) || 
							 (grid1[std::min<int>(x+1, grid1.size()-1)][y]==2) ||
						   (grid1[x][std::max(y-1, 0)]==2) ||
						   (grid1[x][std::min<int>(y+1, grid1[x].size()-1)]==2)){

								grid2[x][y] = 2;
								changed = true;
						}
						else{
								finished = false;
						}
				}
		}
		return std::make_pair(changed, finished);
}


void print_matrix(std::vector<std::vector<int> > matrix){
		for(auto row: matrix){
    		for(auto col: row){
      			std::cout<<col<<" ";
      	}
      	std::cout<<std::endl;
  	}
		std::cout<<std::endl;
}


void empty_flag(std::vector<std::vector<int> >& flag){
		// Initialize flags
		for(int x=0; x<flag.size(); x++){
  			std::fill(flag[x].begin(), flag[x].end(), 0);
		}
}


int main() {
		std::vector<std::vector<int> > grid1 = {{2,1,1}, {0,0,0}, {0,1,1}};
		std::vector<std::vector<int> > grid2 = grid1;
		std::pair<bool, bool> result;
		int steps = 0;
		bool changed = true;
		
		print_matrix(grid1);
		while(changed){
				if(steps%2==0){
						result = orange_iteration(grid1, grid2);
						print_matrix(grid2);
				}
				else{
						result = orange_iteration(grid2, grid1);
						print_matrix(grid1);
				}
				steps += 1;
				changed = result.first;
		}

		std::cout<<steps-1<<" "<<result.second<<std::endl;
		return 0;
}

