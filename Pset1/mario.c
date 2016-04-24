#include <stdio.h>
#include <cs50.h>

int main(void){
    int height;
    do{
        printf("height: ");
        height = GetInt();
    }
    while(height < 0 || height > 23);
    for(int i = 1; i < height+1; i++){
        for(int x = 0;x <height-i;x++){
            printf(" ");
        }
        for(int y = 0;y < i+1;y++){
            printf("#");
        }
        printf("\n");
    }
}