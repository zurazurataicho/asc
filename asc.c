#include <stdio.h>
#include <stdlib.h>

void show_list()
{
    int i, j;
    printf("   0 1 2 3 4 5 6 7 8 9 A B C D E F\n");
    for (i = 32; i < 128; i += 16) {
        printf("%X  ", i / 16);
        for (j = i; j < i + 16; j++) {
            printf("%c ", j);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2) {
        show_list();
        exit(0);
    }

    for (i = 1; i < argc; i++) {
        printf("%c: hex=0x%02x, dec=%d\n", *argv[i], *argv[i], *argv[i]);
    }
}
