#include <stdio.h>

int main(void)
{
    int i,x=1;

    printf("Select your spacing: ");
    scanf("%d", &i);
    printf("Spacing is at least %d: |%*d|\n", i, i, x);
    printf("Spacing is at least %d: |%-*d|\n", i, i, x);
    return (0);
}
