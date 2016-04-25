#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    string name = GetString();
    if(name != NULL){
        printf("%c",toupper(name[0]));
        for(int x = 0, n = strlen(name);x < n;x++){
            if(name[x] == ' '){
                printf("%c",toupper(name[x+1]));
            }
        }
        printf("\n");
    }
}