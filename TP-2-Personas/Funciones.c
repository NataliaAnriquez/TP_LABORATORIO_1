#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int cantidad = 50;

int Menu()
{
    int opcion;
    system("cls");

    printf("[1] Dar de Alta una persona.\n");
    printf("[2] Dar de Baja una persona.\n");
    printf("[3] Imprimir lista por Nombre.\n");
    printf("[4] Imprimir grafico de edades.\n");
    printf("[5] Salir\n");
    printf("\nSeleccione una opcion: ");

    scanf("%d", &opcion);

    while(opcion > 5 || opcion < 1)
    {
        printf("\nError, opcion no valida. Reingrese: ");
        scanf("%d", &opcion);
    }

    return opcion;
}

void Inicializar(ePersona personas[])
{
    int i;
    for(i = 0; i < cantidad; i++)
    {
       personas[i].estado = 0;
    }
}

void Alta(ePersona persona[])
{
    int dni;
    int indice;

    indice = PosicionLibre(persona);

    if(indice != -1)
    {
        printf("\nIngrese DNI: ");
        scanf("%d", &dni);

        if(Existe(persona, dni))
        {
            printf("\nLa persona ya se encuentra en el registro de datos.\n");
        }
        else
        {
            persona[indice].estado = 1;

            persona[indice].dni = dni;

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(persona[indice].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &persona[indice].edad);

            printf("\nEl alta fue procesada exitosamente.\n\n");
        }
    }
    else
    {
        printf("\nNo hay cupo disponible para el alta.\n");
    }
}

void Baja(ePersona personas[])
{
     int dni;
     int indice;
     char respuesta;

     printf("\nIngrese DNI: ");
     scanf("%d", &dni);

     indice = Existe(personas, dni);

     if(indice == -1)
     {
         printf("\nDNI [%d] no encontrado en el registro del sistema\n\n", dni);
     }
     else
     {
        printf("\nDatos de la persona\n\n");

        printf("\n ------------------------------------------------\n");
        printf("|DNI \t\t EDAD \t NOMBRE \t\t | \n");
        printf("|%d \t %d \t %s \t | \n", personas[indice].dni, personas[indice].edad, personas[indice].nombre);
        printf(" ------------------------------------------------\n");

        printf("\n\nConfirma la eliminacion del registro? [s/n] ");
        fflush(stdin);
        scanf("%c", &respuesta);

        if(respuesta == 's')
        {
            personas[indice].estado = 2;
            printf("\nBaja efectuada exitosamente\n");
        }
        else
        {
            printf("\n\nLa baja fue cancelada...\n\n");
        }
    }
}

void Ordenar(ePersona personas[])
{
    ePersona auxPersona;
    int i;
    int j;

    for (i = 0; i < cantidad - 1; i++)
    {
        for (j = i+1; j < cantidad; j++)
        {
            if (strcmp(personas[i].nombre, personas[j].nombre)>0)
            {
                auxPersona = personas[i];
                personas[i] = personas[j];
                personas[j] = auxPersona;
            }
        }
    }
}

void ImprimirRegistro(ePersona personas[])
{
    int i;

    printf("\n ------------------------------------------------\n");
    printf("|DNI \t\t EDAD \t NOMBRE \t\t | \n");

    for(i = 0; i < cantidad; i++)
    {
        if(personas[i].estado == 1)
        {
            printf("|%d \t %d \t %s \t | \n", personas[i].dni, personas[i].edad, personas[i].nombre);
        }
    }
    printf(" ------------------------------------------------\n");
    printf("\n\n");
}

void Grafico(ePersona personas[])
{
    int i;
    int cont18 = 0;
    int cont19a35 = 0;
    int cont35 = 0;
    int flag=0;
    int mayor;

    for(i=0; i < cantidad; i++)
    {
        if(personas[i].estado == 1)
        {
            if(personas[i].edad < 19)
            {
                cont18++;
            }
            else
            {
                if(personas[i].edad > 18 && personas[i].edad < 36)
                {
                    cont19a35++;
                }
                else
                {
                    cont35++;
                }
            }
        }
    }

    if(cont18 >= cont19a35 && cont18 >= cont35)
    {
        mayor = cont18;
    }
    else
    {
        if(cont19a35 >= cont18 && cont19a35 >= cont35)
        {
            mayor = cont19a35;
        }
        else
        {
            mayor = cont35;
        }
    }

    printf("\n\n--+------------------\n");
    for(i=mayor; i>0; i--)
    {
        printf("%02d|",i);

        if(i <= cont18)
        {
            printf("*");
        }

        if(i <= cont19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= cont35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }

        printf("\n");
    }
    printf("--+------------------\n");

    printf("  |<18\t19-35\t>35\n");
    printf("   %d\t%d\t%d\n\n", cont18, cont19a35, cont35);

}

int PosicionLibre(ePersona personas[])
{
    int indice = -1;
    int i;

    for(i = 0; i < cantidad; i++)
    {
        if(personas[i].estado == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int Existe(ePersona personas[], int dni)
{
    int i;
    for(i = 0; i < cantidad; i++)
    {
        if(personas[i].dni == dni)
        {
            return 1;
        }
    }
    return 0;
}
