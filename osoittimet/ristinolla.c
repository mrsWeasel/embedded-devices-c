#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define GRID_LEN 5

int8_t tictactoe_check(int8_t *gameboard, int win_len);
bool check_right(int8_t *gameboard, int i, int win_len, int target);
bool check_down(int8_t *gameboard, int i, int win_len, int target);
bool check_down_right(int8_t *gameboard, int i, int win_len, int target);
bool check_down_left(int8_t *gameboard, int i, int win_len, int target);

int main()
{
    // TESTIT: ASETA GRID_LEN arvoksi 5 (tehtävän palautus vaatii 10)
    // TESTIT VAAKARIVILLE
    // vasemmalta oikealle 4 peräkkäin - voitto
    int8_t gameboard_1[25] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    // vasemmalta oikealle 4 peräkkäin muttei samassa rivissä - ei voittoa
    int8_t gameboard_2[25] = {0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    // vasemmalta oikealle 4 peräkkäin - tasapeli
    int8_t gameboard_3[25] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 2, 2};

    // TESTIT PYSTYRIVILLE
    // ylhäältä alas 4 peräkkäin ensimmäisessä sarakkeessa - voitto
    int8_t gameboard_4[25] = {1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1};
    // ylhäältä alas 4 peräkkäin toisessa (2) ja kolmannessa (1) sarakkeessa - tasapeli
    int8_t gameboard_5[25] = {0, 2, 1, 0, 0, 0, 2, 1, 0, 0, 0, 2, 1, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 1};

    // TESTIT DIAGONAALILLE - VASEMMALTA OIKEALLE
    // vasemmasta nurkasta alkaen 4 vinottain - voitto
    int8_t gameboard_6[25] = {2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0};
    // 2. rivin 2. sarakkeesta alkaen 4 vinottain - voitto
    int8_t gameboard_7[25] = {0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2};

    // TESTIT DIAGONAALILLE - OIKEALTA VASEMMALLE
    // oikeasta nurkasta alkaen 4 vinottainen - voitto
    int8_t gameboard_8[25] = {0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    // 2. rivin 4. sarakkeesta alkaen 4 vinottain - voitto
    int8_t gameboard_9[25] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0};

    printf("Vaakarivitestit:\n");
    int8_t game_1 = tictactoe_check(gameboard_1, 4);
    int8_t game_2 = tictactoe_check(gameboard_2, 4);
    int8_t game_3 = tictactoe_check(gameboard_3, 4);

    printf("Pystyrivitestit:\n");
    int8_t game_4 = tictactoe_check(gameboard_4, 4);
    int8_t game_5 = tictactoe_check(gameboard_5, 4);

    printf("Vinorivitestit vas. oikealle:\n");
    int8_t game_6 = tictactoe_check(gameboard_6, 4);
    int8_t game_7 = tictactoe_check(gameboard_7, 4);

    printf("Vinorivitestit oik. vasemmalle:\n");
    int8_t game_8 = tictactoe_check(gameboard_8, 4);
    int8_t game_9 = tictactoe_check(gameboard_9, 4);
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
        if (i > 0 && (i + 1) % GRID_LEN == 0)
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

bool check_down_right(int8_t *gameboard, int i, int win_len, int target)
{
    int counter = 0;
    for (int j = i; j < GRID_LEN * GRID_LEN; j += GRID_LEN + 1)
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
        if (j > 0 && (j + 1) % GRID_LEN == 0)
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

bool check_down_left(int8_t *gameboard, int i, int win_len, int target)
{
    int counter = 0;
    for (int j = i; j < GRID_LEN * GRID_LEN; j += GRID_LEN - 1)
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
        if (j % GRID_LEN == 0)
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
            found_1 = check_down_right(gameboard, i, win_len, 1);
        }
        if (found_2 == false)
        {
            found_2 = check_down_right(gameboard, i, win_len, 2);
        }

        // check down left
        if (found_1 == false)
        {
            found_1 = check_down_left(gameboard, i, win_len, 1);
        }
        if (found_2 == false)
        {
            found_2 = check_down_left(gameboard, i, win_len, 2);
        }
    }

    if (found_1 && found_2)
    {
        printf("draw!\n");
        return 0;
    }

    if (found_1)
    {
        printf("1 winning!\n");
        return 1;
    }

    if (found_2)
    {
        printf("2 winning!\n");
        return 2;
    }

    printf("no one winning\n");
    return 0;
}