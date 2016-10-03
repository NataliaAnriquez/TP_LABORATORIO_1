#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float resultado;

void Suma(float a, float b)
{
    resultado = a + b;
    printf("Resultado de la SUMA: %.2f\n", resultado);
}

void Resta(float a, float b)
{
    resultado = a - b;
    printf("Resultado de la RESTA: %.2f\n", resultado);
}

void Dividir(float a, float b)
{
    resultado = a / b;
    printf("Resultado de la DIVISION: %.2f\n", resultado);
}

void Multiplicar(float a, float b)
{
    resultado = a * b;
    printf("Resultado de la MULTIPLICACION: %.2f\n", resultado);
}

void Factorial(float a)
{
    int i;
    resultado = a;
    for(i=a-1; i > 1; i--)
    {
        resultado = resultado * i;
    }

    printf("Resultado de FACTORIAL: %.2f\n", resultado);
}
