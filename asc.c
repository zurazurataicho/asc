#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

#define ishexalpha(c)   ((c) >= 'A' && (c) <= 'F')
#define is_hexchar(c)   (isdigit(c) || ishexalpha(c))
#define to_dec(c)       (isdigit(c) ? (c)-'0' : (c)-'A'+10)

void show_list()
{
    printf("   0 1 2 3 4 5 6 7 8 9 A B C D E F\n");
    for (int i = 32; i < 128; i += 16) {
        printf("%X  ", i / 16);
        for (int j = i; j < i + 16; j++) {
            printf("%c ", j);
        }
        putchar('\n');
    }
}

void show_list_inline()
{
    for (int i = 32; i < 128; i += 16) {
        for (int j = i; j < i + 16; j++) {
            putchar(j);
        }
    }
    putchar('\n');
}

int hex_to_dec(char* hex)
{
    char nibu, nibl;
    nibu = toupper(*hex);
    nibl = toupper(*(hex+1));
    if (!is_hexchar(nibu) && !is_hexchar(nibl)) {
        fprintf(stderr, "Error: 0x%s is in illegal hex character.\n", hex);
        exit(EXIT_FAILURE);
    }
    return to_dec(nibu) * 16 + to_dec(nibl);
}

char code_to_char(char* code)
{
    if (*code == '0' && *(code+1) == 'x') {
        return (char)hex_to_dec(code+2);
    }
    for (int i = 0; *(code+i) != '\0'; i++) {
        if (!isdigit(*(code+i))) {
            fprintf(stderr, "Error: %s is in not a digit character.\n", code);
            exit(EXIT_FAILURE);
        }
    }
    return (char)atoi(code);
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        show_list();
        exit(EXIT_SUCCESS);
    }

    int opt;
    int rev = 0;
    int line = 0;
    while ((opt = getopt(argc, argv, "xl")) != -1) {
        switch (opt) {
        case 'l':
            line = 1;
            break;
        case 'x':
            rev = 1;
            break;
        default:
            fprintf(stderr, "Usage: %s [-xl] [char ...]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (line && optind == argc) {
        show_list_inline();
        exit(EXIT_SUCCESS);
    }

    char ch;
    for (int i = optind; i < argc; i++) {
        if (rev) {
            ch = code_to_char(argv[i]);
        } else {
            ch = *argv[i];
        }
        if (line) {
            putchar(ch);
            continue;
        }
        printf("%c: hex=0x%02x, dec=%d\n", ch, ch, ch);
    }
    if (line) {
        putchar('\n');
    }

    return 0;
}
