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

int convertirColumna(char columna)
{
    if (columna == 'A' || columna == 'a')
        return 1;
    else if (columna == 'B' || columna == 'b')
        return 2;
    else if (columna == 'C' || columna == 'c')
        return 3;
    else if (columna == 'D' || columna == 'd')
        return 4;
    else if (columna == 'E' || columna == 'e')
        return 5;
    else if (columna == 'F' || columna == 'f')
        return 6;
    else if (columna == 'G' || columna == 'g')
        return 7;
    else if (columna == 'H' || columna == 'h')
        return 8;

    return -1;
}

int main()
{
    cout << "============================================" << endl;
    cout << "       JUEGO DE LA TORRE DE AJEDREZ        " << endl;
    cout << "============================================" << endl;

    cout << endl;
    cout << "INSTRUCCIONES" << endl;
    cout << "Las columnas se representan con letras de A a H." << endl;
    cout << "Las filas se representan con numeros del 1 al 8." << endl;
    cout << "La Torre solamente puede moverse en horizontal o vertical." << endl;

    Torre torreBlanca(false, 1, 1);
    Torre torreNegra(true, 8, 8);

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "             ESTADO INICIAL                 " << endl;
    cout << "--------------------------------------------" << endl;

    torreBlanca.printState();
    torreNegra.printState();

    char columna;
    int fila;
    int nuevaColumna;

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "        MOVIMIENTO DE LA TORRE BLANCA       " << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Ingrese la nueva columna (A-H): ";
    cin >> columna;

    cout << "Ingrese la nueva fila (1-8): ";
    cin >> fila;

    nuevaColumna = convertirColumna(columna);

    if (nuevaColumna == -1)
    {
        cout << "Error: columna invalida." << endl;
        cout << "Debe ingresar una columna entre A y H." << endl;
    }
    else
    {
        torreBlanca.move(fila, nuevaColumna);
    }

    cout << endl;
    cout << "Estado actual de la Torre Blanca:" << endl;
    torreBlanca.printState();

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << "        MOVIMIENTO DE LA TORRE NEGRA        " << endl;
    cout << "--------------------------------------------" << endl;

    cout << "Ingrese la nueva columna (A-H): ";
    cin >> columna;

    cout << "Ingrese la nueva fila (1-8): ";
    cin >> fila;

    nuevaColumna = convertirColumna(columna);

    if (nuevaColumna == -1)
    {
        cout << "Error: columna invalida." << endl;
        cout << "Debe ingresar una columna entre A y H." << endl;
    }
    else
    {
        torreNegra.move(fila, nuevaColumna);
    }

    cout << endl;
    cout << "Estado actual de la Torre Negra:" << endl;
    torreNegra.printState();

    cout << endl;
    cout << "============================================" << endl;
    cout << "             FIN                              " << endl;
    cout << "============================================" << endl;

    return 0;
}