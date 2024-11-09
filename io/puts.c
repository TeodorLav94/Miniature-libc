#include <unistd.h>
#include <string.h>


int puts(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        char c = str[i];
        write(1, &c, 1);
        i++;
    }
    char new = '\n';
    write(1, &new, 1);
    return i + 1;
}
