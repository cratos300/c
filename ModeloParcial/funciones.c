#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"
/*
void OrdenarPorNumero(ArrayList  *lista)
{
    lista->sort(lista,employee_compareNumero,1);
}
*/
void CargarUsuariosAlSistema(ArrayList* lista1)
{
    FILE *archivo;
    Usuarios *puntero;
    char idUsuarioo[100];
    char nickk[100];
    char popularidadd[100];
    int cant;
    int dato;
    archivo = fopen("usuarios.csv","r");
    if(archivo!=NULL)
    {
        cant = fscanf(archivo,"%[^,],%[^,],%[^\n]\n",idUsuarioo,nickk,popularidadd);
        while(!feof(archivo))
        {
            cant = fscanf(archivo,"%[^,],%[^,],%[^\n]\n",idUsuarioo,nickk,popularidadd);
            if(cant!=3)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro");
                }
            }
            puntero = employee_newUsuario();
            setidUsuario(puntero,atoi(idUsuarioo));
            setPoPularidadMensaje(puntero,atoi(popularidadd));
            setnick(puntero,nickk);
            lista1->add(lista1,puntero);
        }

        }
        fclose(archivo);

}


void CargarDatosAlSistema(ArrayList *Lista)
{
    FILE *archivo;
    Mensajes *puntero;
    char idMensajee[50];
    char popularidadaaaa[50];
    char idUsuarioRelaaaa[50];
    char mensaje[2000];
    int cant = 100;
    int dato;

    archivo = fopen("mensajes.csv","r");
    if(archivo != NULL)
    {
        cant = fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idMensajee,idUsuarioRelaaaa,popularidadaaaa,mensaje);
        while(!feof(archivo))
        {
            cant = fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idMensajee,idUsuarioRelaaaa,popularidadaaaa,mensaje);
            if(cant!=4)
            {
                if(feof(archivo))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro");
                }
            }
            puntero = employee_newMensaje();
            setIdMensaje(puntero,atoi(idMensajee));
            idUsuarioRelaa(puntero,atoi(idUsuarioRelaaaa));
            setPoPularidadMensaje(puntero,atoi(popularidadaaaa));
            setmsg(puntero,mensaje);
            Lista->add(Lista,puntero);



        }

    }
    else
    {
        printf("archivo mal");
    }
    fclose(archivo);
}

/*
void AltaCliente(ArrayList* lista,int *puntero)
{
    int numero;
    char nombre[50];
    char apellido[50];
    int devolver;
    Employee* Nuevo_Empleado = employee_new();

    if(Nuevo_Empleado!=NULL)
    {
        fflush(stdin);
        printf("Ingrese su nombre");
        gets(nombre);
        fflush(stdin);
        printf("Ingrese su numero");
        gets(apellido);
        fflush(stdin);
        printf("Ingrese su dni");
        scanf("%li",&dni);
        devolver = RevisarID(lista,dni);
        if(devolver == 0)
        {
            printf("Error ese dni es de otra persona.");
            free(Nuevo_Empleado);
        }
        else
        {
            *puntero = *puntero +1;
            fflush(stdin);
            setNombre(Nuevo_Empleado,nombre);
            setApellido(Nuevo_Empleado,apellido);
            Nuevo_Empleado->dni = dni;
            setId(Nuevo_Empleado,*puntero);
            printf("%d",Nuevo_Empleado->id);
            lista->add(lista,Nuevo_Empleado);
            printf("Exito al dar de alta\n");

        }

    }
}
void ModificarCliente(ArrayList *lista)
{
    long int dni;
    char nombre[50];
    char apellido[50];
    char seguir = 's';
    Employee *auxEmpleado;
    int id;
    int devolver;
    if(lista!=NULL)
    {
        printf("Ingrese su numero de id a modificar");
        scanf("%d",&id);
        devolver = verificarID(lista,id);
        printf("%d",devolver);
        if(devolver == -1)
        {
            printf("Error ese id no existe");
        }
        else
        {
            printf("Que desea modificar?");
            do
            {
                switch(menuModificar())
                {

                case 1:
                    printf("Ingrese su nuevo nombre");
                    fflush(stdin);
                    gets(nombre);
                    auxEmpleado = (Employee*)lista->get(lista,devolver);
                    setNombre(auxEmpleado,nombre);
                    break;
                case 2:
                    printf("Ingrese su nuevo apellido");
                    fflush(stdin);
                    gets(apellido);
                    auxEmpleado = (Employee*)lista->get(lista,devolver);
                    setApellido(auxEmpleado,apellido);
                    system("pause");
                    break;
                case 3:
                    printf("Ingrese su nuevo DNI");
                    fflush(stdin);
                    scanf("%ld",&dni);
                    auxEmpleado = (Employee*)lista->get(lista,devolver);
                    auxEmpleado->dni = dni;
                    system("pause");
                    break;

                case 4:
                    seguir = 'z';
                    printf("Salio del menu");
                    break;

                }
            }
            while(seguir == 's');
        }


    }
}

void BajaDeCliente(ArrayList* lista)
{
    int verificar;
    int id;
    char respuesta;
    printf("Ingrese el numero de id a eliminar");
    scanf("%d",&id);
    verificar = verificarID(lista,id);
    if(verificar == -1)
    {
        printf("ERROR, ESE ID NO EXISTE");
    }
    else
    {
        printf("Estas seguro que deseas eliminar el cliente?S/N");
        fflush(stdin);
        scanf("%c",&respuesta);
        if(respuesta == 's')
        {
            lista->remove(lista,verificar);
            printf("Cliente dado de baja correctamente");
            system("pause");
        }
        else
        {
            printf("Accion cancelada");
        }
    }
}
*/

void ListarClientes(ArrayList* lista)
{
    Mensajes* auxEmpleado;
    int i;
    for(i=0; i<lista->len(lista); i++)
    {
        auxEmpleado = (Mensajes*)lista->get(lista,i);
        employee_print(auxEmpleado);
    }
}
void setIdMensaje(Mensajes *puntero,int idMensaje)
{
    if(puntero!=NULL)
    {
        puntero->idMensaje = idMensaje;
    }
}
void setmsg(Mensajes* puntero,char msg[])
{
    if(puntero!=NULL)
    {
        strcpy(puntero->mensaje,msg);
    }
}

void setPoPularidadMensaje(Mensajes* puntero,int popular)
{
    if(puntero!=NULL)
    {
        puntero->popularidad = popular;
    }
}
void idUsuarioRelaa(Mensajes* puntero,int usuarioRela)
{
    if(puntero!=NULL)
    {
        puntero->idUsuarioRela = usuarioRela;
    }
}
void setidUsuario(Usuarios *puntero,int id)
{
    if(puntero!=NULL)
    {
        puntero->idUsuario = id;
    }
}
void setnick(Usuarios* puntero,char msg[])
{
    if(puntero!=NULL)
    {
        strcpy(puntero->nick,msg);
    }
}
void intPoPuLaridadUsuario (Usuarios *puntero, int dato)
{
    if(puntero!=NULL)
    {
        puntero->popularidad = dato;
    }
}
/*int employee_compareapellido(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {

        Employee* empA = (Employee*) pEmployeeA;
        Employee* empB = (Employee*) pEmployeeB;
        return strcmp(empA->apellido, empB->apellido);
    }
    return 0;
}
*/

void MostrarUsuarios(ArrayList *lista1)
{
    int i;
    Usuarios *auxEmpleado;
    for(i=0; i<lista1->len(lista1); i++)
    {
        auxEmpleado = (Usuarios*)lista1->get(lista1,i);
        employee_printUsuarios(auxEmpleado);
    }
}
void employee_print(Mensajes* this)
{
    if(this != NULL)
    {
        printf("%d\t%s\t%d\t%d\n\n",this->idMensaje,this->mensaje,this->popularidad,this->idUsuarioRela);
    }
}
void employee_printUsuarios(Usuarios *this)
{
    int dato;
    if(this!=NULL)
    {
        dato = strlen(this->nick);
        printf("%d,%s,%d,%d\n",this->idUsuario,this->nick,this->popularidad, dato);
    }
}
Mensajes* employee_newMensaje(void)
{
    Mensajes* returnAux;
    returnAux = (Mensajes*)malloc(sizeof(Mensajes));
    if(returnAux !=NULL)
    {
        returnAux->idMensaje = 0;
        strcpy(returnAux->mensaje,"");
        returnAux->popularidad = 0;
        returnAux->idUsuarioRela = 0;
    }
    return returnAux;

}
Usuarios* employee_newUsuario(void)
{
    Usuarios* returnAux;
    returnAux = (Usuarios*)malloc(sizeof(Usuarios));
    if(returnAux !=NULL)
    {
        returnAux->idUsuario= 0;
        strcpy(returnAux->nick,"");
        returnAux->popularidad = 0;
    }
    return returnAux;
}
Todo* employee_newPersonaFull(void)
{
    Todo* returnAux;
    returnAux = (Todo*)malloc(sizeof(Todo));
    if(returnAux !=NULL)
    {
        returnAux->idMensaje = 0;
        strcpy(returnAux->mensaje,"");
        returnAux->popularidadMensaje = 0;
        returnAux->idUsuarioRela = 0;
        strcpy(returnAux->nick,"");
        returnAux->popularidadUsuario = 0;
    }
    return returnAux;
}
int menuModificar()
{
    int opcion;
    system("cls");
    printf("**Menu de Opciones**\n\n");

    printf("1. MODIFICAR EL NOMBRE\n");
    printf("2. MODIFICAR EL APELLIDO\n");
    printf("3. MODIFICAR EL DNI\n");
    printf("4. SALIR");



    scanf("%d", &opcion);

    return opcion;
}
/*
int employee_compareNumero(void* pEmployeeA,void* pEmployeeB)
{
    int retornar = 0;
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        retornar = -1;
        Employee* empA = (Employee*) pEmployeeA;
        Employee* empB = (Employee*) pEmployeeB;
        if(empA->numero>empB->numero)
        {
            retornar = 1;
        }
    }
    return retornar;
}*/
/*
void funcionCrearArchivo()
{
    FILE* archivo;
    archivo = fopen("archivo.csv","w");
    if(archivo!=NULL)
    {
        system("pause");
    }
}*/

