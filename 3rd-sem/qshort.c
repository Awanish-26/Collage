#include<stdio.h>
#include<stdlib.h>

int compare(const void*, const void*);

int main() {
    int num, width;
    int arr[8] = { 34,65,23,4,12,15,33,98 };
    num = sizeof(arr) / sizeof(arr[0]);
    width = sizeof(arr[0]);
    qsort((void*)arr, num, width, compare);

    /*  void qsort(void *base, size_t num, size_t width, int (*compare)(const void *, const void *))     */

    for (int i = 0; i < 8; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
int compare(const void* a, const void* b) {
    if (((int*)a) == ((int*)b)) {
        return 0;
    }
    else if (((int*)a) < ((int*)b)) {
        return -1;
    }
    else
        return 1;

}