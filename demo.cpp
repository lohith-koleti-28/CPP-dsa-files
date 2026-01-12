#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};

    cout << "Initial Array: ";
    printArray(arr);
    cout << "\nStarting Bubble Sort...\n\n";

    int n = arr.size();
    int pass = 1;

    for (int i = 0; i < n - 1; i++) {
        cout << "----- Pass " << pass++ << " -----" << endl;
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparing " << arr[j] << " and " << arr[j + 1];

            if (arr[j] > arr[j + 1]) {
                cout << "  --> swap";
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }

            cout << "\nCurrent array: ";
            printArray(arr);
            cout << endl;
        }

        if (!swapped) {
            cout << "No swaps → array already sorted!\n";
            break;
        }
    }

    cout << "Final Sorted Array: ";
    printArray(arr);

    return 0;
}
