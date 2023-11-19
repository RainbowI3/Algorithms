#include <iostream>
#include <vector>
using namespace std;
vector<int> prices = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
vector<int> results(11, -1);
class Solution {
public:
    int cut(int n) {
        results[0] = 0;
        
        for (int j = 1; j <= n; j++) {
            int res = 0;
            for(int i = 1; i <= j; i++){
                res = max(res, prices[i - 1] + results[j - i]);
            }
            results[j] = res;
        }
        return results[n];
    }
};

int main() {
    Solution solution;
    int n = 5;
    int result = solution.cut(n);
    cout << "result = "<< result << endl;

    return 0;
}
