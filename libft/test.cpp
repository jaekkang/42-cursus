#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target, int& comparisons) {
  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    comparisons++;  // Counting the comparison

    if (arr[mid] == target) {
      return mid;  // Element found
    } else if (arr[mid] < target) {
      low = mid + 1;  // Discard left half
    } else {
      high = mid - 1;  // Discard right half
    }
  }

  return -1;  // Element not found
}

int main() {
  // Arrays to search
  std::vector<int> arr4;
  arr4.push_back(1);
  arr4.push_back(2);
  arr4.push_back(3);
  arr4.push_back(4);

  std::vector<int> arr5;
  arr5.push_back(1);
  arr5.push_back(2);
  arr5.push_back(3);
  arr5.push_back(4);
  arr5.push_back(5);

  std::vector<int> arr6;
  arr6.push_back(1);
  arr6.push_back(2);
  arr6.push_back(3);
  arr6.push_back(4);
  arr6.push_back(5);
  arr6.push_back(6);

  std::vector<int> arr7;
  arr7.push_back(1);
  arr7.push_back(2);
  arr7.push_back(3);
  arr7.push_back(4);
  arr7.push_back(5);
  arr7.push_back(6);
  arr7.push_back(7);

  // Target element to search for
  int target = 4;

  // Variables to store the number of comparisons
  int comparisons4 = 0, comparisons5 = 0, comparisons6 = 0, comparisons7 = 0;

  // Perform binary search on each array
  binarySearch(arr4, target, comparisons4);
  binarySearch(arr5, target, comparisons5);
  binarySearch(arr6, target, comparisons6);
  binarySearch(arr7, target, comparisons7);
  // Output the number of comparisons for each array
  std::cout << "Comparisons for array with 4 elements: " << comparisons4
            << std::endl;
  std::cout << "Comparisons for array with 5 elements: " << comparisons5
            << std::endl;
  std::cout << "Comparisons for array with 6 elements: " << comparisons6
            << std::endl;
  std::cout << "Comparisons for array with 7 elements: " << comparisons7
            << std::endl;

  return 0;
}
