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

    eProducto* auxEmpleadooooo;
    ArrayList* lista = al_newArrayList();
    ArrayList* producto = al_newArrayList();
    ArrayList* lista3 = al_newArrayList();
    int cont = 0;
    int i;
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
            AltaCliente(lista,&cont);
            system("pause");
            break;
        case 2:
            ModificarCliente(lista);
            system("pause");
            break;
        case 3:
            BajaDeCliente(lista);
            system("pause");
            break;

        case 4:
            system("cls");

            ListarClientes(lista);
            system("pause");
            break;

        case 5:
            CargarDatosAlSistema(lista,&cont);
            system("pause");

            break;

        case 6:
            RealizarUnaVenta(producto,lista);

            break;
        case 7:
            GenerarInformeDeVentaXProducto(producto,lista3);
            ordenar(lista3);
            for(i=0;i<lista3->len(lista3);i++)
            {
                auxEmpleadooooo = (eProducto*)lista3->get(lista3,i);
                employee_printPRODUCTO(auxEmpleadooooo);
            }
            generarArchivo(lista3);
            system("pause");
            break;
        case 8:
            system("pause");
            break;
        case 9:
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

    printf("1. ALTA DEL CLIENTE\n");
    printf("2. MODIFICACION DEL CLIENTE\n");
    printf("3. BAJA DE  CLIENTE\n");
    printf("4. LISTAR CLIENTES\n");
    printf("5. IMPORTAR CLIENTE DESDE CSV\n");
    printf("6. REALIZAR UNA VENTA\n");
    printf("7. GENERAR INFORME DE VENTA POR PRODUCTO\n");
    printf("8. GENERAR INFORME DE VENTA DE FECHA\n");
    printf("9. INFORMAR\n");
    printf("0. SALIR");



    scanf("%d", &opcion);

    return opcion;
}



