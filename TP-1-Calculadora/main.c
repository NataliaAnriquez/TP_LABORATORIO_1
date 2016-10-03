#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

int main()
{
    char continuar = 's';
    char confirma;
    int opcion = 0;
    float a = 0;
    float b = 0;

    while(continuar == 's')
    {
        system("cls");

        printf("[1] Ingresar 1er operando (A=%5.2f)\n", a);
        printf("[2] Ingresar 2do operando (B=%5.2f)\n", b);
        printf("[3] Calcular la suma (A+B)\n");
        printf("[4] Calcular la resta (A-B)\n");
        printf("[5] Calcular la division (A/B)\n");
        printf("[6] Calcular la multiplicacion (A*B)\n");
        printf("[7] Calcular el factorial (A!)\n");
        printf("[8] Calcular todas las operaciones\n");
        printf("[9] Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese primer numero: ");
                scanf("%f", &a);
                break;
            case 2:
                printf("Ingrese segundo numero: ");
                scanf("%f", &b);
                break;
            case 3:
                Suma(a, b);
                system("pause");
                break;
            case 4:
                Resta(a, b);
                system("pause");
                break;
            case 5:
                if(b == 0)
                {
                    printf("Error - No se puede dividir por 0.\n");
                }
                else
                {
                    Dividir(a, b);
                }
                system("pause");
                break;
            case 6:
                Multiplicar(a, b);
                system("pause");
                break;
            case 7:
                if(a < 0 || a == 0)
                {
                    printf("Error - No se puede realizar factorial de 0 ni de un numero negativo.\n");
                }
                else
                {
                    Factorial(a);
                }
                system("pause");
                break;
            case 8:
                if(b == 0)
                {
                    printf("Error - No se puede dividir por 0.\n");
                }
                else
                {
                    if(a < 0)
                    {
                        printf("Error - No se puede realizar factorial de un numero negativo.\n");
                    }
                    else
                    {
                        Suma(a, b);
                        Resta(a, b);
                        Dividir(a, b);
                        Multiplicar(a, b);
                        Factorial(a);
                    }
                }

                system("pause");
                break;
            case 9:
                printf("Salir del programa? [s/n] \n");
                confirma = tolower(getche());
                if(confirma == 's')
                {
                    continuar = 'n';
                }

                break;
        }
    }

    return 0;
}
