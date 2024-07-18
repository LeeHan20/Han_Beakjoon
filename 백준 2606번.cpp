#include <iostream>
#include <vector>
using namespace std;

int main() {
    int number_of_computer, connection_of_computer;
    cin >> number_of_computer;
    cin >> connection_of_computer;
    vector<int> connection(number_of_computer, 0);
    
    for (int i = 0; i < connection_of_computer; ++i) {
        int com_number1, com_number2;
        cin >> com_number1 >> com_number2;
        com_number1 = com_number1 - 1;
        com_number2 = com_number2 - 1;

        if (connection[com_number1] == 0 && connection[com_number2] == 0) {
            connection[com_number1] = com_number1 + 1;
            connection[com_number2] = com_number1 + 1;
        } else if (connection[com_number1] == 0) {
            connection[com_number1] = connection[com_number2];
        } else if (connection[com_number2] == 0) {
            connection[com_number2] = connection[com_number1];
        } else {
            int old_group = connection[com_number2];
            int new_group = connection[com_number1];
            for (int j = 0; j < number_of_computer; ++j) {
                if (connection[j] == old_group) {
                    connection[j] = new_group;
                }
            }
        }
    }

    int number_of_pollution = 0;
    for (int i = 1; i < number_of_computer; ++i) {
        if (connection[i] == connection[0]) {
            number_of_pollution += 1;
        }
    }
    cout << number_of_pollution << endl;
    return 0;
}
