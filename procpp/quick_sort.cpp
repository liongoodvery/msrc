//
// Created by lion on 17-8-19.
//

#include <iostream>

using namespace std;

static void quick_sort(int *a, int p, int r);

static int partition(int *a, int p, int r);

static int swap(int *a, int ia, int ib);

static void print(int *a, int size);

int main() {
    int a[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int len = sizeof(a) / sizeof(int);
    print(a, len);
    quick_sort(a, 0, len - 1);
    print(a, len);
    return 0;
}

void quick_sort(int *a, int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
}

int partition(int *a, int p, int r) {
    int i = p - 1;

    int key = a[r];
    for (int j = p; j < r ; ++j) {
        if (a[j] <=  key) {
            i++;
            swap(a, i, j);
        }
    }

    swap(a, i + 1, r);
    return i + 1;

}

int swap(int *a, int ia, int ib) {
    int tmp = *(a + ia);
    *(a + ia) = *(a + ib);
    *(a + ib) = tmp;
}

void print(int *a, int size) {
    for (int i = 0; i < size; ++i) {
        cout << *(a + i) << '\t';
    }
    cout << endl;
}