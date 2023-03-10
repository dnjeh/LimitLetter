#include <stdio.h>
int main() {
    char a[50];
    scanf("%s", a);
    printf(a);
    for(int i=0;a[i]!='\n'&&a[i]!='\0';i++) printf("%d (%c)", a[i], a[i]);
}