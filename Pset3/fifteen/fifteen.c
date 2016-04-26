/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;


// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int empty_x;
int empty_y;
int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    empty_x = d-1;
    empty_y = d-1;
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */

void init(void)
{
    int num = (d*d)-1;
    //define empty space's x and y coords on board.
    for(int x = 0;x < d;x++){
        for(int y = 0;y < d;y++){
            if(num>0){
                board[x][y] = num;
                num-=1;
            }
        }
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    for(int x = 0;x < d;x++){
        for(int y = 0;y < d;y++){
            if(board[x][y] > 0){
                printf("%3d", board[x][y]);
            }
            else{
                printf(" _ ");
            }
        }
        printf("\n\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
void swap(int positions[]);

bool move(int tile)
{
    int tile_x;
    int tile_y;
    //find coords of inputed tile
    for(int x = 0;x < d;x++){
        for(int y = 0;y < d;y++){
            if(board[x][y] == tile){
                tile_y = y;
                tile_x = x;
            }
        }
    }
    
    //shifting to row above, a shift in the x row not y.
    int below_tile = tile_x+1;
    int above_tile = tile_x-1;
    int left_tile =  tile_y-1;
    int right_tile = tile_y+1;
    
    //create an array to later be passed into a function
    int positions[5] = {tile_x,tile_y,empty_x,empty_y,tile};
    
    //check if empty tile is directly below chosen tile.
    if(below_tile == empty_x && tile_y == empty_y){
       swap(positions);
       empty_x-=1;
       return true;
    }
    else if(above_tile == empty_x  && tile_y == empty_y){
       swap(positions);
       empty_x+=1;
       return true;
    }
    else if(left_tile == empty_y && tile_x == empty_x){
       swap(positions);
       empty_y+=1;
       return true;
    }
    else if(right_tile == empty_y && tile_x == empty_x){
       swap(positions);
       empty_y-=1;
       return true;
    }
    return false;
}

void swap(int positions[]){
    board[positions[0]][positions[1]] = 0;
    board[positions[2]][positions[3]] = positions[4];
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */

bool won(void)
{
    //flatten 2d array
    int myArray[d * d-1];
    int i = 0;
    for(int x = 0;x < d;x++){
        for(int y = 0;y < d;y++){
          myArray[i++] = board[x][y];
        }
    }
    int count = 0;
    for(int x = 1,n=(d*d)-1;x < n;x++){
        if(myArray[x] != myArray[x-1]+1){
            //printf("no");
            count+=1;
        }
    }
    if(count > 0){
        return false;
    }
    return true;
}