#include <iostream>
#include <algorithm>

int maximum(int arr[], int size);

int main()
{
    int test_array[] = {2, 5, 3, 106, 99, 78, 100, 54, 8};

    int size = sizeof(test_array) / sizeof(test_array[0]);
    std::cout << "Maximum: " << maximum(test_array, size) << std::endl;
    return 0;
}

int maximum(int arr[], int size)
{
    if (size == 0) return arr[0];

    return std::max(maximum(arr, size - 1),arr[size - 1]);
}