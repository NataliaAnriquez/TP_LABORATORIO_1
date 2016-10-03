#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>

int main()
{
    char seguir = 's';
    ePersona personas[cantidad];
    Inicializar(personas);

    do
    {
        switch(Menu())
        {
            case 1:
                {
                    Alta(personas);
                    system("pause");
                    break;
                }
            case 2:
                {
                    Baja(personas);
                    system("pause");
                    break;
                }
            case 3:
                {
                    Ordenar(personas);
                    ImprimirRegistro(personas);
                    system("pause");
                    break;
                }
            case 4:
                {
                    Grafico(personas);
                    system("pause");
                    break;
                }
            case 5:
                {
                    seguir = 'n';
                    break;
                }
        }
    }while(seguir == 's');

    return 0;
}
