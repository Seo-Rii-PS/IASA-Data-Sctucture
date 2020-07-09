#include <stdio.h>
#include <assert.h>

typedef int element;
const int SIZE = 10005;

struct heap {
    int n;
    element arr[SIZE];

    void insert(element el) {
        arr[++n] = el;
        int p = n;
        while (p > 1) {
            if (arr[p] <= arr[p >> 1]) return;
            int t = arr[p];
            arr[p] = arr[p >> 1];
            arr[p >> 1] = t;
            p >>= 1;
        }
    }

    element remove() {
        assert(n > 0);
        int t = arr[1];
        arr[1] = arr[n];
        arr[n] = t;
        --n;
        int p = 1;
        while (p <= n) {
            if (p * 2 + 1 > n) {
                if (p * 2 > n) return arr[n + 1];
                if (arr[p] < arr[p * 2]) {
                    t = arr[p];
                    arr[p] = arr[p * 2];
                    arr[p * 2] = t;
                    p = p * 2;
                } else return arr[n + 1];
            } else {
                if (arr[p * 2] > arr[p * 2 + 1]) {
                    if (arr[p] < arr[p * 2]) {
                        t = arr[p];
                        arr[p] = arr[p * 2];
                        arr[p * 2] = t;
                        p = p * 2;
                    } else return arr[n + 1];
                } else {
                    if (arr[p] < arr[p * 2 + 1]) {
                        t = arr[p];
                        arr[p] = arr[p * 2 + 1];
                        arr[p * 2 + 1] = t;
                        p = p * 2 + 1;
                    } else return arr[n + 1];
                }
            }
        }
        return arr[n + 1];
    }

    void print() {
        int i;
        for (i = 1; i <= n; ++i) printf("%d ", arr[i]);
        printf("\n");
    }
};

int main() {
    heap t;
    t.insert(69);
    t.insert(10);
    t.insert(30);
    t.insert(2);
    t.insert(16);
    t.insert(8);
    t.insert(31);
    t.insert(22);
    t.print();
    while (t.n) {
        printf("%d ", t.remove());
    }
    printf("\n");
    printf("%d ", t.remove());
}