#include <iostream>
using namespace std;

class Torre
{
private:
    int row;
    int column;
    bool isBlack;

public:

    Torre(bool color, int fila, int columna)
    {
        isBlack = color;
        row = fila;
        column = columna;
    }
};

int main()
{
    Torre torreBlanca(false, 1, 1);
    Torre torreNegra(true, 8, 8);

    return 0;
}