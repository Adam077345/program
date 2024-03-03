#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Funkcja generowania liczb losowych
void generate(int SIZE, int excl_numbers[]) {
    srand(static_cast<unsigned>(time(NULL)));
    for (int i = 0; i < SIZE; i++) {
        int random = rand() % 25 + 1;
        excl_numbers[i] = random;
    }
}

// Funkcja wyświetlająca tablice
void display(int SIZE, int excl_numbers[]) {
    for (int i = 0; i < SIZE; i++) {
        cout << excl_numbers[i] << " ";
    }
}

// Algorytm sortowania bąbelkowego
void bubble_sort(int arr[], int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE - i; j++) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

// Algorytm szybkiego sortowania
void quick_sort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int x = arr[(left + right) / 2];

    do {
        while (arr[i] < x) {
            i++;
        }

        while (arr[j] > x) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) quick_sort(arr, left, j);

    if (right > i) quick_sort(arr, i, right);
}

// Algorytm sortowania przez wstawianie
void insertion_sort(int arr[], int SIZE) {
    int i, j, x;

    for (i = 1; i < SIZE; i++) {
        x = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = x;
    }
}
   
// Funkcja scalania dla sortowania przez scalanie
void merge(int arr[], int p, int q, int SIZE) {
    int n1 = q - p + 1;
    int n2 = SIZE - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++) {
        M[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;  
        } else {
            arr[k] = M[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Algorytm sortowania scalającego
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int m = left + (right - left) / 2;
        merge_sort(arr, left, m);
        merge_sort(arr, m + 1, right);
        merge(arr, left, m, right);
    }
}

// Algorytm sortowania przez wstrząsanie
void shaker_sort(int arr[], int SIZE) {
    int left = 0, right = SIZE - 1;
    bool swapped = true;
    while (swapped == true) {
        swapped = false;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right = right - 1;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left = left + 1;
    }
}

// Wyszukiwanie liniowe z wartownikiem
void linear_search_sentinel(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;
    int i = 0;
    while (arr[i] != key) {
        i++;
    }
    arr[n - 1] = last;
    if ((i < n - 1) || (arr[n - 1] == key)) {
        cout << "Your number is at position " << i;
    } else {
        cout << "Number not found";
    }
}

// Liniowy algorytm wyszukiwania
int linear_search(int arr2[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (arr2[i] == number) {
            return i;
        }
    }
    return -1;
}


// Algorytm wyszukiwania skokowego
int jump_search(int arr[], int n, int number) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < number) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }
    while (arr[prev] < number) {
        prev++;
        if (prev == min(step, n)) {
            return -1;
        }
    }
    if (arr[prev] == number) {
        return prev;
    }
    return -1;
}

// Algorytm wyszukiwania interpolacji
int interpolation_search(int arr[], int start, int end, int number) {
    int position;
    if (start <= end && number >= arr[start] && number <= arr[end]) {
        position = start + (((double)(end - start) / (arr[end] - arr[start])) * (number - arr[start]));
        if (arr[position] == number) {
            return position;
        }
        if (arr[position] < number) {
            return interpolation_search(arr, position + 1, end, number);
        }
        if (arr[position] > number) {
            return interpolation_search(arr, start, position - 1, number);
        }
    }
    return -1;
}

// Algorytm wyszukiwania binarnego
int binary_search(int arr[], int low, int high, int number) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == number) {
            return mid;
        }
        if (arr[mid] < number) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

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
