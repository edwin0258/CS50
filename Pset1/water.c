#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("minutes: ");
    int length = GetInt();
    printf("bottles: %i\n", length*12);
}