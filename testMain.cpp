#include <iostream>
#include "test.cpp"
#include <vector>

using namespace std;

int main()
{
	Solution obj;
	int n = 10;
	int m = 20;
	std::vector< vector<int>> walls {{2,3}, {4,5}, {0,1}};
	std::vector< vector<int>> guards {{1,9}, {0,6}, {3,2}};
	int ans = obj.countUnguarded(m, n, guards, walls);
	cout << "ans is " << ans << endl;
}
