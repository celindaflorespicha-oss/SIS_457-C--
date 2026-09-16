#include <iostream>
using namespace std;
class Torre{
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
};