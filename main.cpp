int main() {
    constexpr int SIZE = 12;
    int arr[SIZE];
    int arr2[SIZE] = {5, 10, 26, 34, 40, 46, 50, 61, 69, 76, 88, 91};
    cout << "Random numbers:" << endl;
    generate(SIZE, arr);
    display(SIZE, arr);
    cout << endl << "Bubble sort" << endl;
    bubble_sort(arr, SIZE);
    display(SIZE, arr);
    cout << endl << "Quick sort" << endl;
    quick_sort(arr, 0, SIZE - 1);
    display(SIZE, arr);
    cout << endl << "Insertion sort" << endl;
    insertion_sort(arr, SIZE);
    display(SIZE, arr);
    cout << endl << "Merge sort" << endl;
    merge_sort(arr, 0, SIZE - 1);
    display(SIZE, arr);
    cout << endl << "Shaker sort" << endl;
    shaker_sort(arr, SIZE);
    display(SIZE, arr);
    int number;
    cout << endl << endl << "Enter a number to search for: ";
    cin >> number;
    cout << endl << "Linear search with sentinel" << endl;
    linear_search_sentinel(arr2, SIZE, number);
    cout << endl << "Linear search" << endl;
    cout << "Your number is at position " << linear_search(arr2, SIZE, number) << endl;
    cout << endl << endl << "Jump search" << endl;
    cout << "Your number is at position " << jump_search(arr2, SIZE, number) << endl;
    cout << endl << "Interpolation search" << endl;
    cout << "Your number is at position " << interpolation_search(arr2, 0, SIZE - 1, number) << endl;
    cout << endl << "Binary search" << endl;
    cout << "Your number is at position " << binary_search(arr2, 0, SIZE - 1, number) << endl;
    
    return 0;
}

