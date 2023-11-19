#include <iostream>
#include <vector>
#include<math.h>
#include<iomanip>
#include <algorithm>
#include <string>
#include<unordered_map>
#include <fstream>
using namespace std;
int get_max_value(vector<int>& a) {
    int n = a.size();
    vector<vector<int>>d(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        d[i][i] = a[i];
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j){
            for(int k = i;k < j; ++k){
                d[i][j] = max({
                       d[i][j],
                       d[i][k] + d[k + 1][j],
                       d[i][k] * d[k + 1][j]
                    });
            }
        }     
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<setw(3) << d[i][j] << " ";
        }
        cout << endl;
    }
    return d[0][n - 1];
}
int main() {
    vector<int>input { 1,2,3,4,5 };
    cout << get_max_value(input) ;
    return 0;
}