#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array arr);
void Append(struct Array *arr, int x);
void Insert(struct Array *arr, int index, int x);
int Delete(struct Array *arr, int index);
int Get(struct Array arr, int index);
void Set(struct Array *arr, int index, int x);
int Max(struct Array arr);
int Min(struct Array arr);
int Sum(struct Array arr);
void Reverse(struct Array *arr);

int main() {
    struct Array arr;
    
    printf("Enter capacity of the array: ");
    scanf("%d", &arr.size);
    
    arr.A = (int *)malloc(arr.size * sizeof(int));
    arr.length = 0;

    Append(&arr, 10);
    Append(&arr, 20);
    Append(&arr, 30);
    Append(&arr, 40);
    Append(&arr, 50);

    Display(arr);

    Insert(&arr, 2, 25);
    Display(arr);

    Delete(&arr, 4);
    Display(arr);

    printf("%d\n", Get(arr, 3));
    
    Set(&arr, 0, 99);
    Display(arr);

    printf("%d\n", Max(arr));
    printf("%d\n", Min(arr));
    printf("%d\n", Sum(arr));

    Reverse(&arr);
    Display(arr);

    free(arr.A);
    return 0;
}

void Display(struct Array arr) {
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Append(struct Array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x) {
    if (index >= 0 && index <= arr->length && arr->length < arr->size) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        int x = arr->A[index];
        for (int i = index; i < arr->length - 1; i++) {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }
    return -1;
}

int Get(struct Array arr, int index) {
    if (index >= 0 && index < arr.length) {
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x) {
    if (index >= 0 && index < arr.length) {
        arr->A[index] = x;
    }
}

int Max(struct Array arr) {
    if (arr.length == 0) return -1;
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] > max) {
            max = arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr) {
    if (arr.length == 0) return -1;
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < min) {
            min = arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr) {
    int total = 0;
    for (int i = 0; i < arr.length; i++) {
        total += arr.A[i];
    }
    return total;
}

void Reverse(struct Array *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
        i++;
        j--;
    }
}