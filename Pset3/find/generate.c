/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    /*if user does not give the correct amount of
    vars in the console */
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        //error
        return 1;
    }

    //This is number of rdm numbers wanted by the user.
    int n = atoi(argv[1]);

    /*if argc is 3 then the user provided a seed.
    Else generate numbers without the seed. 
    Srand48 will then procede to see drand48 with numbers*/
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /*each number in drand48 is multiplied by the
    constant and is converted to an int*/
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}