#include <iostream>
#include <vector>
using namespace std;

// Function to generate Jacobsthal sequence up to size n
vector<int> generateJacobsthal(int n) {
    vector<int> jacobsthal(n);
    if (n > 0) jacobsthal[0] = 0;
    if (n > 1) jacobsthal[1] = 1;
    for (int i = 2; i < n; ++i) {
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    }
    return jacobsthal;
}

// Binary search to find the correct insertion position for the key
int binarySearch(const vector<pair<int, int>> &arr, int low, int high, pair<int, int> key, const vector<int> &jacobsthal) {
    while (low <= high) {
        int mid = (low + high) / 2;
        // Compare right-side values of pairs with Jacobsthal sequence
        if (arr[mid].second < key.second)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // Low is the insertion position
}

// Insertion sort for pairs using Jacobsthal sequence and binary search
void insertionSortPairs(vector<pair<int, int>> &arr, int low, int high, const vector<int> &jacobsthal) {
    for (int i = low + 1; i <= high; ++i) {
        pair<int, int> key = arr[i];
        // Find the correct position for the key using binary search
        int pos = binarySearch(arr, low, i - 1, key, jacobsthal);
        // Shift elements to make space for the key
        for (int j = i; j > pos; --j) {
            arr[j] = arr[j - 1];
        }
        arr[pos] = key;
    }
}

// Merge two sorted halves of the array
void mergePairs(vector<pair<int, int>> &arr, int low, int mid, int high, const vector<int> &jacobsthal) {
    vector<pair<int, int>> left(arr.begin() + low, arr.begin() + mid + 1);
    vector<pair<int, int>> right(arr.begin() + mid + 1, arr.begin() + high + 1);

    int i = 0, j = 0, k = low;
    while (i < left.size() && j < right.size()) {
        // Compare based on the Jacobsthal sequence
        if (left[i].second <= right[j].second) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy remaining elements
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

// Merge-Insertion Sort
void mergeInsertionSortPairs(vector<pair<int, int>> &arr, int low, int high, const vector<int> &jacobsthal, int threshold = 4) {
    if (high - low + 1 <= threshold) {
        // Use insertion sort for small subarrays
        insertionSortPairs(arr, low, high, jacobsthal);
    } else {
        int mid = (low + high) / 2;
        // Recursively sort each half
        mergeInsertionSortPairs(arr, low, mid, jacobsthal, threshold);
        mergeInsertionSortPairs(arr, mid + 1, high, jacobsthal, threshold);
        // Merge the sorted halves
        mergePairs(arr, low, mid, high, jacobsthal);
    }
}

// Driver function
int main() {
    vector<pair<int, int>> pairs = {{4, 9}, {3, 7}, {6, 1}, {8, 5}, {2, 8}};

    cout << "Original pairs: ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    cout << endl;

    // Generate Jacobsthal sequence
    vector<int> jacobsthal = generateJacobsthal(pairs.size());
    
    // Sort pairs using Merge-Insertion Sort
    mergeInsertionSortPairs(pairs, 0, pairs.size() - 1, jacobsthal);

    cout << "Sorted pairs: ";
    for (size_t i = 0; i < pairs.size(); ++i) {
        cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
    }
    cout << endl;

    return 0;
}
