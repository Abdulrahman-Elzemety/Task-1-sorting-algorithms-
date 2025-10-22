#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;



void bubbleSort(int arr[], int n) {
    int comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "Number of comparisons: " << comparisons << endl;
}



void insertionSort(int arr[], int n) {
    int comparisons = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;


        while (j >= 0 && (++comparisons && arr[j] > key)) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Number of comparisons: " << comparisons << endl;
}




void selectionSort(int arr[], int n) {
    int comparisons = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }

    cout << "Number of comparisons: " << comparisons << endl;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



void test_comparisons() {

    int randomBase[30] = {
        12, 5, 19, 2, 30, 8, 14, 3, 22, 9,
        27, 1, 6, 18, 25, 10, 16, 7, 20, 4,
        29, 11, 28, 15, 13, 21, 26, 17, 24, 23
    };

    int sortedBase[30] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30
    };

    int inverseBase[30] = {
        30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
        20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };



    cout << "Bubble Sort:- " << endl;

    for (int type = 0; type < 3; type++) {
        int* baseArray;
        if (type == 0) {
            cout << "\nRandom Arrays:\n";
            baseArray = randomBase;
        }
        else if (type == 1) {
            cout << "\nSorted Arrays:\n";
            baseArray = sortedBase;
        }
        else {
            cout << "\nInverse Sorted Arrays:\n";
            baseArray = inverseBase;
        }

        for (int size = 1; size <= 30; size++) {
            int arr[30];
            for (int i = 0; i < size; i++) arr[i] = baseArray[i];

            cout << "--- Size " << size << " ---" << endl;
            cout << "Original array: ";
            printArray(arr, size);

            auto start = high_resolution_clock::now();
            bubbleSort(arr, size);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;


            cout << "Sorted array:   ";
            printArray(arr, size);
            cout << endl;
        }
    }


    cout << "Insertion Sort:- " << endl;

    for (int type = 0; type < 3; type++) {
        int* baseArray;
        if (type == 0) {
            cout << "\nRandom Arrays:\n";
            baseArray = randomBase;
        }
        else if (type == 1) {
            cout << "\nSorted Arrays:\n";
            baseArray = sortedBase;
        }
        else {
            cout << "\nInverse Sorted Arrays:\n";
            baseArray = inverseBase;
        }

        for (int size = 1; size <= 30; size++) {
            int arr[30];
            for (int i = 0; i < size; i++) arr[i] = baseArray[i];

            cout << "--- Size " << size << " ---" << endl;
            cout << "Original array: ";
            printArray(arr, size);

            auto start = high_resolution_clock::now();
            insertionSort(arr, size);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;


            cout << "Sorted array:   ";
            printArray(arr, size);
            cout << endl;
        }
    }


    cout << "Selection Sort:- " << endl;

    for (int type = 0; type < 3; type++) {
        int* baseArray;
        if (type == 0) {
            cout << "\nRandom Arrays:\n";
            baseArray = randomBase;
        }
        else if (type == 1) {
            cout << "\nSorted Arrays:\n";
            baseArray = sortedBase;
        }
        else {
            cout << "\nInverse Sorted Arrays:\n";
            baseArray = inverseBase;
        }

        for (int size = 1; size <= 30; size++) {
            int arr[30];
            for (int i = 0; i < size; i++) arr[i] = baseArray[i];

            cout << "--- Size " << size << " ---" << endl;
            cout << "Original array: ";
            printArray(arr, size);

            auto start = high_resolution_clock::now();
            selectionSort(arr, size);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Execution time: " << duration.count() << " microseconds" << endl;


            cout << "Sorted array:   ";
            printArray(arr, size);
            cout << endl;
        }
    }
}


int main() {
    test_comparisons();
}