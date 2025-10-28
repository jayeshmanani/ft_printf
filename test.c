#include <stdio.h>

int main(){
    char a = 'b';
    printf("%p\n", &a);
    int add = &a;

    printf("%d\n", add);
}