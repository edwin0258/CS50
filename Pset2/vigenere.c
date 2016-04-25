#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void convertToCypher(int k, char p);
int checkWord(string word);
int main(int argc, string argv[]){
    if(argc == 2 && argv[1] != NULL){
        //cypher word
        string word = argv[1];
        //check if word is all letters.
        if(checkWord(word) == 1){
            printf("Invalid Input\n");
            return 1;
        }
        string text = GetString();
        
        int word_len = strlen(word);
        //printf("%s\n", argv[1]);
        //keep track of char position in word.
        int count = 0;
        for(int x=0,n=strlen(text);x<n;x++){
            if(count == word_len){
                count = 0;
            }
            if(isalpha(text[x])){
                convertToCypher(tolower(word[count])-'a', text[x]);
                count+=1;
            }
            else{
                printf("%c",text[x]);
            }
        }
        printf("\n");
        return 0;
    }
    else{
       printf("Did not recieve proper number of arguments\n");
       return 1;
    }
}

void convertToCypher(int k,char p){
    int position = k+p;
    while(position > 122 && isupper(p)==false){
        position = (position-122)+96;
    }
    while(position > 90 && isupper(p)){
        position = (position-90)+64;
    }
    printf("%c", position);
}

int checkWord(string word){
    for(int x=0,n=strlen(word);x < n;x++){
        if(isalpha(word[x]) == false){
            return 1;
            break;
        }
    }
    return 0;
}