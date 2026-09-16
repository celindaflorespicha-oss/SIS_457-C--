#include <iostream>

using namespace std;

class Torre
{
private:
    int row;
    int column;
    bool isBlack;

public:

    Torre(bool color, int filaInicial, int columnaInicial)
    {
        isBlack = color;
        row = filaInicial;
        column = columnaInicial;
    }
};

int main()
{
    return 0;
}