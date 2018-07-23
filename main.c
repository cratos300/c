#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "ArrayList.h"
/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/
int menu();

int main()
{

    ArrayList* lista = al_newArrayList();
    ArrayList* lista1 = al_newArrayList();

    if(lista==NULL)
    {
        printf("Error algun puntero es nulo");
        exit(-1);
    }
    char seguir = 's';

    do
    {
        switch(menu())
        {

        case 1:
            CargarDatosAlSistema(lista);
            ListarClientes(lista);
            system("pause");
            break;
        case 2:
            CargarUsuariosAlSistema(lista1);
            MostrarUsuarios(lista1);
            system("pause");
            break;
        case 3:

            system("pause");
            break;
        case 4:
            system("pause");
            break;
        case 5:
            system("pause");
            break;
        case 6:
            seguir = 'n';
            break;
        }
    }
    while(seguir == 's');


    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. LEER ARCHIVO\n");
    printf("2. COMPLETAR\n");
    printf("3. ORDENAR LISTA\n");
    printf("4. MOSTRAR DATOS QUE SE REPITEN\n");
    printf("5. MOSTRAR DATOS QUE NO SE REPITEN\n");
    printf("6. SALIR \n");



    scanf("%d", &opcion);

    return opcion;
}



