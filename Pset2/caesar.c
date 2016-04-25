#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void getEncryption(string text,int num);
int main(int argc, string argv[]){
    /*argc is the amount of arguments given by user
    including name, so we are confirming that user
    gave a number with program name.*/
    if(argc == 2 && argv[1] != NULL){
        string k = argv[1];
        int num = atoi(k);
        
        string text = GetString();
        getEncryption(text, num);
        printf("\n");
        return 0;
    }
    else{
        printf("Did not recieve neccessary variables\n");
        return 1;
    }
}

void getEncryption(string text,int num){
    if(text != NULL){
        for(int x = 0, n = strlen(text);x < n;x++){
            //check if text[x] is a letter
            if(isalpha(text[x])){
                int position = text[x]+num;
                while(position > 122 && isupper(text[x]) == false){
                    position = (position - 122)+96;
                }
                while(position > 90 && isupper(text[x])){
                    position = (position - 90)+64;
                }
                printf("%c", position);
            }
            else{
                printf("%c", text[x]);
            }
        }
    }
}