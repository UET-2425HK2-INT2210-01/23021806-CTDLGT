#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers(5);
    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    int min_val = *min_element(numbers.begin(), numbers.end());
    int max_val = *max_element(numbers.begin(), numbers.end());

    cout << min_val + max_val << endl;
    return 0;
}