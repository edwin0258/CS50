#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    int coins = 0;
    int amount;
    do{
      printf("Amount owed: ");
      amount = roundf(GetFloat()*10000)/100;
    }
    while(amount < 1);
    while(amount > 0){
        if(amount >= 25){coins+=1;amount-=25;}
        else{
          if(amount >= 10){coins+=1;amount-=10;}
          else{
            if(amount >= 5){coins+=1;amount-=5;}
            else{
              if(amount >= 1){coins+=1;amount-=1;}
            }
          }
        }
    }
    printf("%i\n", coins);
}