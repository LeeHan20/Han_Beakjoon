#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    vector<int> hights(9);
    for (int i = 0; i<9; ++i) {
        cin>>hights[i];
    }
    //vector<int> hights = {20,7,23,19,10,15,25,8,13};
    //vector<int> hights = {40,40,10,10,10,10,10,10,10};
    
    int sum_of_hights = accumulate(hights.begin(), hights.end(), 0);
    
    for (int i = 0; i<9; ++i) {
        long int nega_one = count(hights.begin(), hights.end(), -1);
        if (nega_one == 2){
            break;
        }
        for (int j = i+1; j < 10; ++j) {
            int checker = sum_of_hights - hights[i] - hights[j];
            if (checker == 100) {
                hights[i] = -1;
                hights[j] = -1;
        
                }}}
    
    vector<int> result;
    for (int i : hights) {
        if (i != -1) {
            result.push_back(i);
        }}
    
    sort(result.begin(), result.end());
    for (int i : result){
        cout<< i << endl;
    }
    return 0;
}
