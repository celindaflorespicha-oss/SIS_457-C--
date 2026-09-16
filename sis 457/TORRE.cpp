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
        if (row == newRow && column != newCol)
        {
            return true;
        }

        if (column == newCol && row != newRow)
        {
            return true;
        }

        return false;
    }

public:

    Torre(bool color, int filaInicial, int columnaInicial)
    {
        isBlack = color;
        row = filaInicial;
        column = columnaInicial;
    }

    void move(int newRow, int newCol)
    {
        if (newRow < 1 || newRow > 8 ||
            newCol < 1 || newCol > 8)
        {
            cout << "Error: la posicion debe estar dentro del tablero." << endl;
            cout << "Las filas y columnas deben estar entre 1 y 8." << endl;
            return;
        }

        if (validateMovement(newRow, newCol))
        {
            row = newRow;
            column = newCol;

            cout << "Movimiento realizado correctamente." << endl;
        }
        else
        {
            cout << "Movimiento invalido." << endl;
            cout << "La Torre solamente puede moverse en horizontal o vertical." << endl;
        }
    }

    const char* draw()
    {
        if (isBlack)
        {
            return "[##]";
        }
        else
        {
            return "[TT]";
        }
    }

    void printState()
    {
        char letraColumna;

        letraColumna = 'A' + column - 1;

        cout << draw() << " ";

        if (isBlack)
        {
            cout << "Torre Negra";
        }
        else
        {
            cout << "Torre Blanca";
        }

        cout << " en Fila: " << row;
        cout << ", Columna: " << letraColumna << endl;
    }
};

int main()
{
    return 0;
}