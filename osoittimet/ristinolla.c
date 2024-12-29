#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define GRID_LEN 5

int8_t tictactoe_check(int8_t *gameboard, int win_len);
bool check_right(int8_t *gameboard, int i, int win_len, int target);
bool check_down(int8_t *gameboard, int i, int win_len, int target);

int main()
{
    int8_t gameboard[25] = {2, 1, 1, 1, 0, 2, 2, 0, 2, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 1, 0, 1};
    int8_t winner = tictactoe_check(gameboard, 4);
}

bool check_right(int8_t *gameboard, int i, int win_len, int target)
{
    int counter = 0;
    for (int j = i; j < i + GRID_LEN; j++)
    {
        if (gameboard[j] == target)
        {
            counter += 1;
        }
        else
        {
            break;
        }

        // end of row
        if (i > 0 && i % GRID_LEN == 0)
        {
            break;
        }
    }

    if (counter >= win_len)
    {
        return true;
    }

    return false;
}

bool check_down(int8_t *gameboard, int i, int win_len, int target)
{
    int counter = 0;
    for (int j = i; j < GRID_LEN * GRID_LEN; j += GRID_LEN)
    {
        if (gameboard[j] == target)
        {
            counter += 1;
        }
        else
        {
            break;
        }
    }

    if (counter >= win_len)
    {
        return true;
    }

    return false;
}

// bool check_down_right

// bool check_down_left

int8_t tictactoe_check(int8_t *gameboard, int win_len)
{
    bool found_1 = false;
    bool found_2 = false;

    for (int i = 0; i < GRID_LEN * GRID_LEN; i += 1)
    {
        // check right
        if (found_1 == false)
        {
            found_1 = check_right(gameboard, i, win_len, 1);
        }
        if (found_2 == false)
        {
            found_2 = check_right(gameboard, i, win_len, 2);
        }

        // check down
        if (found_1 == false)
        {
            found_1 = check_down(gameboard, i, win_len, 1);
        }
        if (found_2 == false)
        {
            found_2 = check_down(gameboard, i, win_len, 2);
        }

        // check down right
        if (found_1 == false)
        {
            // check found_1
        }
        if (found_2 == false)
        {
            // check found_2
        }

        // check down left
        if (found_1 == false)
        {
            // check found_1
        }
        if (found_2 == false)
        {
            // check found_2
        }
    }

    if (found_1 && found_2)
    {
        printf("draw!");
        return 0;
    }

    if (found_1)
    {
        printf("1 winning!");
        return 1;
    }

    if (found_2)
    {
        printf("2 winning!");
        return 2;
    }

    return 0;
}