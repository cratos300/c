#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define TAM 2
#define TAMPROV 3

int main()
{

    int salir = 1;
    eProducto Persona[TAM];
    eProvedor sector[TAM];
    InicializarEstadoProducto(Persona,TAM);
    InicializarEstadoProducto(sector,TAM);
    HarcodearClientes(Persona);
    HarcodearProvedor(sector);
    float acum = 0;

    do

    {
        switch(menuDeOpciones())
        {
        case 1:
            AltaCliente(Persona,sector,TAMPROV,TAM);
            break;
        case 2:
            ModificarCliente(Persona,TAM);
            break;
        case 3:BorrarCliente(Persona,TAM);
            break;
        case 4:
            MostrarClientes(Persona,TAM);
            break;
        case 5:
            break;
        case 6:
            acum = SacarAcumuladorYPromedio(Persona,TAM);
            printf("%f",acum);
            getch();
            break;
        case 7: salir = 2;
                break;
        }

    }
    while(salir == 1);
    return 0;
    }
