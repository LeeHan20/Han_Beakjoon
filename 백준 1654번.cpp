#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct structure {
    int possessed_line_number;
    int needed_line_number;
    vector<int> length_of_lines;
};

void make_input(structure &parameters) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> parameters.possessed_line_number >> parameters.needed_line_number;
    parameters.length_of_lines.resize(parameters.possessed_line_number);
    for (int i = 0; i < parameters.possessed_line_number; ++i) {
        cin >> parameters.length_of_lines[i];
    }
    return;
}

bool can_make_lines(const vector<int> &length_of_lines, int needed_line_number, long long cut_length) {
    long long count = 0;
    for (int length : length_of_lines) {
        count += length / cut_length;
    }
    return count >= needed_line_number;
}

long long find_max_length(structure &parameters) {
    long long left = 1;
    long long right = *max_element(parameters.length_of_lines.begin(), parameters.length_of_lines.end());
    long long answer = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (can_make_lines(parameters.length_of_lines, parameters.needed_line_number, mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return answer;
}

int main() {
    structure parameters;
    make_input(parameters);

    long long max_length = find_max_length(parameters);

    cout << max_length << "\n";
    return 0;
}

//사실상 이진 탐색을 모르고 있다면 풀지 못하는 문제

//문제를 더 풀기보다는 알고리즘과 탐색 등 전공공부를 해야겠음
