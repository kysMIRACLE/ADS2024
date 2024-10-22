#include <iostream>
using namespace std;


void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; 
    int n2 = r - m;     

    
    int L[n1], R[n2];

   
    for (i = 0; i < n1; i++) {
        L[i] = a[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

   
    i = 0;  
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int a[], int N) {
    int size, l, m, r;

    
    for (size = 1; size < N; size = 2 * size) {
        
        for (l = 0; l < N - 1; l += 2 * size) {
            m = l + size - 1;
            r = min(l + 2 * size - 1, N - 1);

            if (m < r) {
                merge(a, l, m, r);
            }
        }
    }
}

void printArray(int a[], int N) {
    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int a[] = {6, 1, 2, 3, 9, 4, 5, 7, 8};
    int N = sizeof(a) / sizeof(a[0]);

    cout << "Original array: " << endl;
    printArray(a, N);

    mergeSort(a, N);

    cout << "Sorted array: " << endl;
    printArray(a, N);

    return 0;
}