#include "strlib.h"

int str_length(const char *s) {
    const char *p = s;
    while (*p != '\0') p++;
    return (int)(p - s);
}

void str_copy(char *dst, const char *src, int dst_size) {
    if (dst_size <= 0) return;
    int i = 0;
    while (i < dst_size - 1 && *(src + i) != '\0') {
        *(dst + i) = *(src + i);
        i++;
    }
    *(dst + i) = '\0';
}

int str_compare(const char *a, const char *b) {
    while (*a != '\0' && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)(*a) - (unsigned char)(*b);
}

void str_reverse(char *s) {
    int len = str_length(s);
    if (len <= 1) return;
    char *start = s;
    char *end = s + len - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int str_count_char(const char *s, char c) {
    int count = 0;
    while (*s != '\0') {
        if (*s == c) count++;
        s++;
    }
    return count;
}

void str_to_upper(char *s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z') *s -= 32;
        s++;
    }
}

void array_stats(const int arr[], int len, int *out_min, int *out_max, double *out_avg) {
    if (len <= 0) { *out_min = *out_max = 0; *out_avg = 0.0; return; }
    int min = *arr, max = *arr;
    long sum = 0;
    for (int i = 0; i < len; i++) {
        int val = *(arr + i);
        if (val < min) min = val;
        if (val > max) max = val;
        sum += val;
    }
    *out_min = min; *out_max = max; *out_avg = (double)sum / len;
}

int array_find(const int arr[], int len, int target) {
    for (int i = 0; i < len; i++) {
        if (*(arr + i) == target) return i;
    }
    return -1;
}