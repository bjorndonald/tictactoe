#include <ostream>
using namespace std;

class Board
{
private:
    int count = 0;
    int space = 3;
    char **entries = new char *[3];

public:
    Board() = default;
    explicit Board(const int &space);
    ~Board();
    char **getEntries() const;
    void show_board_line() const;
    void populate_entries();
    void show_board() const;
    int getSpace() const;
    bool getWinner() const;
    void setSpace(int &count);
    int getCount() const;
    bool addEntry(char &entry, short &index);
    void setCount(int &count);
};

ostream &operator<<(ostream &stream, const Board &board);