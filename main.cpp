#include <iostream>
#include <iomanip>
#include <cctype>
#include <stdlib.h>
#include <unistd.h>
#include "Board.hpp"
using namespace std;

void clear()
{
#if defined _WIN32
    system("cls");
    // clrscr(); // including header file : conio.h
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    // std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined(__APPLE__)
    system("clear");
#endif
}

int main(int argc, char **argv)
{
    char input;
    Board board = Board(3);
    bool is_o = true;

    while (true)
    {

        clear();

        cout << board;
        char player = is_o ? 'O' : 'X';
        cout << player << " player: Please input number of placement: ";
        cin >> input;
        short index = input - '0';
        if (input == 'X' || input == 'x')
        {
            break;
        }

        if (index > 9)
        {
            cout << "Wrong input!" << endl;
            sleep(2);
            continue;
        }
        if (!board.addEntry(player, index))
        {
            sleep(2);
            continue;
        }
        if (board.getWinner())
            break;

        is_o = !is_o;
    }

    cout << "Thank you for playing";

    return 0;
}