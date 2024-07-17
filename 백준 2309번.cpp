#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> heights(9);
    for (int i = 0; i < 9; ++i) {
        cin >> heights[i];
    }
    //vector<int> hights = {20,7,23,19,10,15,25,8,13};
    //vector<int> hights = {40,40,10,10,10,10,10,10,10};

    int sum_of_heights = accumulate(heights.begin(), heights.end(), 0);
    
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            int checker = sum_of_heights - heights[i] - heights[j];
            if (checker == 100) {
                heights[i] = -1;
                heights[j] = -1;
                break;
            }}
        if (heights[i] == -1) {
            break;
        }}

    vector<int> result;
    for (int i : heights) {
        if (i != -1) {
            result.push_back(i);
        }}

    sort(result.begin(), result.end());
    for (int i : result) {
        cout << i << endl;
    }
    
    return 0;
}
