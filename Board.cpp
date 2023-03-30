#include "Board.hpp"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
const char HORIZONTAL_STROKE = '-';
const char INTERSECTION = '+';
const char VERTICAL_STROKE = '|';

void Board::show_board_line() const
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << INTERSECTION;
        for (size_t i = 0; i < space; i++)
        {
            std::cout << HORIZONTAL_STROKE;
        }
    }
    std::cout << INTERSECTION << std::endl;
}

void Board::populate_entries()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        entries[i] = new char[3];
        for (int j = 0; j < 3; j++)
        {
            entries[i][j] = '0' + count++;
        }
    }
}

void Board::show_board() const
{
    for (int i = 0; i < 4; i++)
    {
        show_board_line();
        if (i < 3)
        {
            for (size_t j = 0; j < 3; j++)
            {
                std::cout << "| " << entries[i][j] << " ";
            }
            std::cout << "|" << std::endl;
        }
    }
}

int Board::getSpace() const
{
    return space;
}

char checkHorizontal(char **test)
{
    for (short index = 0; index < 9; index++)
    {
        if (index % 3 == 0)
        {
            int j = index % 3;
            int i = (index / 3);
            if (test[i][j] == test[i][j + 1] && test[i][j + 2] == test[i][j + 1])
            {
                return test[i][j];
            }
        }
    }
    return '0';
}

char checkVertical(char **test)
{
    for (short index = 0; index < 3; index++)
    {

        int j = index % 3;
        int i = (index / 3);
        if (test[i][j] == test[i + 1][j] && test[i + 2][j] == test[i + 1][j])
        {
            return test[i][j];
        }
    }
    return '0';
}

char checkDiagonal(char **test)
{
    short index = 2;

    short j = index % 3;
    short i = (index / 3);
    if (test[i][j] == test[i + 1][j - 1] && test[i + 1][j - 1] == test[i + 2][j - 2])
    {
        return test[i][j];
    }
    index = 0;

    j = index % 3;
    i = (index / 3);
    if (test[i][j] == test[i + 1][j + 1] && test[i + 1][j + 1] == test[i + 2][j + 2])
    {
        return test[i][j];
    }

    return '0';
}

bool Board::getWinner() const
{
    char check;
    check = checkHorizontal(entries);
    if (check != '0')
    {
        cout << check << " is the winner!" << endl;
        return true;
    }
    check = checkVertical(entries);
    if (check != '0')
    {
        cout << check << " is the winner!" << endl;
        return true;
    }
    check = checkDiagonal(entries);
    if (check != '0')
    {
        cout << check << " is the winner!" << endl;
        return true;
    }
    return false;
}

void Board::setSpace(int &space)
{
    this->space = space;
}

int Board::getCount() const
{
    return count;
}

void Board::setCount(int &count)
{
    this->count = count;
}

Board::Board(const int &space)
{
    populate_entries();
    this->space = space;
}

Board::~Board()
{
    delete[] entries;
}

char **Board::getEntries() const
{
    return entries;
}

bool Board::addEntry(char &entry, short &index)
{
    int j = index % 3;
    int i = (index / 3);
    if (entries[i][j] != 'X' && entries[i][j] != 'O')
    {
        entries[i][j] = entry;
        count++;

        return true;
    }

    else
    {
        std::cout << "Already occupied!" << endl;
    }
    return false;
}

std::ostream &operator<<(std::ostream &stream, const Board &board)
{
    for (int i = 0; i < 4; i++)
    {
        board.show_board_line();
        if (i < 3)
        {
            for (size_t j = 0; j < 3; j++)
            {
                std::cout << "| " << board.getEntries()[i][j] << " ";
            }
            std::cout << "|" << std::endl;
        }
    }
    return stream;
}
