#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotate90Clockwise(vector<vector<int>> a) 
{ 
  	int N = a.size();
    for (int i = 0; i < N / 2; i++) { 
        for (int j = i; j < N - i - 1; j++) { 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 
    return a;
}

vector<vector<int>> rotateMatrix90Anti(vector<vector<int>> mat) 
{ 
	int N = mat.size();
    for (int x = 0; x < N / 2; x++) { 
        for (int y = x; y < N - x - 1; y++) { 
            int temp = mat[x][y]; 
  
            mat[x][y] = mat[y][N - 1 - x]; 
  
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            mat[N - 1 - y][x] = temp; 
        } 
    } 
    return mat;
} 

void sort_(vector<vector<int>>& v){
	for(auto &x : v){
		sort(x.begin(), x.end());
	}
}
  
void print_(vector<vector<int>>& v){
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}




int largest_square_(vector<vector<int>> v){
	int n = v.size();
	int m = v[0].size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	int max_ = -1;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(i == 0 || j == 0){
				dp[i][j] = v[i][j];
			}
			else{
				if(v[i][j] == 0){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
				}
			}

			max_ = max(max_ , dp[i][j]);
		}
	}

	return max_;
}

int melt(vector<vector<int>> v){
	
	auto temp = rotate90Clockwise(v);
	sort_(temp);
	v = rotateMatrix90Anti(temp);
	print_(v);

	return largest_square_(v);
}

int main(){

	int n; cin>>n;

	vector<vector<int>> v(n, vector<int>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			char temp; cin>>temp;
			if(temp == 'C')
				v[i][j] = 0;
			else
				v[i][j] = 1;
		}
	}


	auto first = v;
	auto second = rotateMatrix90Anti(first);
	auto third = rotateMatrix90Anti(second);
	auto fourth = rotateMatrix90Anti(third);


	//print_(first);
	int first_ = melt(first);
	
	//print_(second);
	int second_ = melt(second);
	
	//print_(third);
	int third_ = melt(third);
	
	//print_(fourth);
	int fourth_ = melt(fourth);

	
	
	
	
	

	int res = max(first_, max(second_, max(third_, fourth_)));

	cout << res << endl;

	// rotate90Clockwise(v);
	// sort_(v);
	// cout << endl;

	// print_(v);

	// rotateMatrix90Anti(v);

	// cout << endl;
	// print_(v);


	// cout << endl;
	// cout << largest_square_(v);

	return 0;
}