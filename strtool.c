#include <stdio.h>
#include "strlib.h"

int main() {
    int choice;
    while (1) {
        printf("\n= String & Array Toolkit =\n1. String length\n2. String copy\n3. String compare\n4. Reverse a string\n5. Count a character\n6. Convert to uppercase\n7. Array stats\n8. Find value in array\n9. Quit\nEnter choice (1-9): ");
        if (scanf("%d", &choice) != 1 || choice == 9) break;

        switch(choice) {
            case 1: { char b[100]; printf("Enter string: "); scanf("%s", b); printf("Length: %d\n", str_length(b)); break; }
            case 2: { char s[100], d[8]; printf("Enter string: "); scanf("%s", s); str_copy(d, s, sizeof(d)); printf("Copied: %s\n", d); break; }
            case 3: { char a[100], b[100]; printf("Enter two strings: "); scanf("%s %s", a, b); int r = str_compare(a, b); if(r<0) printf("%s before %s\n", a, b); else if(r>0) printf("%s after %s\n", a, b); else printf("Equal\n"); break; }
            case 4: { char b[100]; printf("Enter string: "); scanf("%s", b); str_reverse(b); printf("Reversed: %s\n", b); break; }
            case 5: { char b[100], c; printf("Enter string and char: "); scanf("%s %c", b, &c); printf("Count: %d\n", str_count_char(b, c)); break; }
            case 6: { char b[100]; printf("Enter string: "); scanf("%s", b); str_to_upper(b); printf("Upper: %s\n", b); break; }
            case 7: { int l, d[100], mn, mx; double avg; printf("Enter count then values: "); scanf("%d", &l); for(int i=0; i<l; i++) scanf("%d", &d[i]); array_stats(d, l, &mn, &mx, &avg); printf("min=%d max=%d avg=%.2f\n", mn, mx, avg); break; }
            case 8: { int l, d[100], t; printf("Enter count then values: "); scanf("%d", &l); for(int i=0; i<l; i++) scanf("%d", &d[i]); printf("Enter target: "); scanf("%d", &t); int i = array_find(d, l, t); if(i!=-1) printf("Found at index %d.\n", i); else printf("Not found.\n"); break; }
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}