#include <stdio.h>
#include <unistd.h> // For getopt
#include <ctype.h>

int main(int argc, char *argv[]) {
    int opt;
    int shout = 0;
    char *name = "World";

    // "n:" means the -n flag requires an argument
    // "s" means the -s flag is a simple toggle
    while ((opt = getopt(argc, argv, "n:s")) != -1) {
        switch (opt) {
            case 'n':
                name = optarg;
                break;
            case 's':
                shout = 1;
                break;
            default:
                fprintf(stderr, "Usage: %s [-n name] [-s]\n", argv[0]);
                return 1;
        }
    }

    printf("Hello, ");
    if (shout) {
        for (int i = 0; name[i]; i++) putchar(toupper(name[i]));
    } else {
        printf("%s", name);
    }
    printf("!\n");

    return 0;
}