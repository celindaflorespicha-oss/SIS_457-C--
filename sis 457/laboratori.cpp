#include <iostream>
using namespace std;

class Torre
{
private:
    int row;
    int column;
    bool isBlack;

    bool validateMovement(int newRow, int newCol)
    {
        if (newRow == row || newCol == column)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:

    Torre(bool color, int fila, int columna)
    {
        isBlack = color;
        row = fila;
        column = columna;
    }

    void move(int newRow, int newCol)
    {
        if (newRow < 1 || newRow > 8 || newCol < 1 || newCol > 8)
        {
            cout << "Error: posicion fuera del tablero." << endl;
            return;
        }

        if (validateMovement(newRow, newCol))
        {
            row = newRow;
            column = newCol;

            cout << "Movimiento de la Torre realizado correctamente." << endl;
        }
        else
        {
            cout << "Error: la Torre no puede realizar ese movimiento." << endl;
        }
    }
};
