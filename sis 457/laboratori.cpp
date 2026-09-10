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

    string draw()
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
        if (isBlack)
        {
            cout << "[##] Black at Row: " << row
                 << ", Col: " << column << endl;
        }
        else
        {
            cout << "[TT] White at Row: " << row
                 << ", Col: " << column << endl;
        }
    }
};

int main()
{
    Torre torreBlanca(false, 1, 1);
    Torre torreNegra(true, 8, 8);

    cout << "ESTADO INICIAL" << endl;

    torreBlanca.printState();
    torreNegra.printState();

    int nuevaFila;
    int nuevaColumna;

    cout << endl;
    cout << "TORRE BLANCA" << endl;

    cout << "Ingrese nueva fila: ";
    cin >> nuevaFila;

    cout << "Ingrese nueva columna: ";
    cin >> nuevaColumna;

    torreBlanca.move(nuevaFila, nuevaColumna);

    torreBlanca.printState();

    cout << endl;
    cout << "TORRE NEGRA" << endl;

    cout << "Ingrese nueva fila: ";
    cin >> nuevaFila;

    cout << "Ingrese nueva columna: ";
    cin >> nuevaColumna;

    torreNegra.move(nuevaFila, nuevaColumna);

    torreNegra.printState();

    return 0;
}