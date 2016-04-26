/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
const int min = 0;
bool search(int value, int values[],int min,int max)
{
    if(min <= max){
        int mid = (max+min)/2;
        if(values[mid] < value){
            return search(value, values, mid+1,max);
        }
        else if(values[mid] > value){
            return search(value, values,min,mid-1);
        }
        else{
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n)
{
    int count = 0;
    for(int x = 1;x < n;x++){
        if(values[x] < values[x-1]){
            int placeholder = values[x-1];
            values[x - 1] = values[x];
            values[x] = placeholder;
            count+=1;
        }
    }
    if(count != 0){
        sort(values, n);
    }
    else{
    // TODO: implement an O(n^2) sorting algorithm
        return;
    }
}