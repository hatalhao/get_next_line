#include <stdio.h>

int main()
{
    static char *x;

    printf("<%p>\n", x);
}