#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>

int obtenerEspacioLibre(EPersona lista[],int TAM)
{
    int i;
    int dato=-1;
    for(i=0; i<TAM; i++)
    {
        if(lista[i].estado==0)
        {
            dato=i;
            break;
        }
    }

    return dato;
}
int buscarPorDni(EPersona lista[], int DNI, int TAM)
{
    int indice=-1;
    int i;

    for(i=0; i<TAM; i++)
    {
        if(lista[i].dni==DNI && lista[i].estado == 1)
        {
            indice=i;
        }
    }
    return indice;
}
/*
void MostrarNombre(EPersona lista)
{
        printf("%s,%d,%d",lista.nombre,lista.edad,lista.dni);
}

void MostrarAlumnos(EPersona lista[],int TAM)
{
    int i;

    for(i=0;i<TAM;i++)
    {
        MostrarNombre(lista[i]);
    }
}

*/
void altaUsuario(EPersona cliente[],int tam,int grafico[])
{
    int estado;
    int flag;
    int indice;
    indice=obtenerEspacioLibre(cliente,tam);

    if(indice!=-1)
    {
        printf("Ingrese el dni");
        scanf("%d",&cliente[indice].dni);
        estado = buscarPorDni(cliente,cliente[indice].dni,tam);
        if(estado == -1)
        {
            fflush(stdin);
            printf("Ingrese su nombre:");
            gets(cliente[indice].nombre);
            fflush(stdin);
            printf("Ingrese su edad:");
            scanf("%d",&cliente[indice].edad);
            fflush(stdin);
            fflush(stdin);
            cliente[indice].estado=1;

        }
        else
            {
                printf("Error ese dni ya existe\n");
            }
    }
            else
            {
                printf("No hay lugar en el sistema");
            }

             if(cliente[indice].edad>=0 && cliente[indice].edad<18)
            {
                grafico[0] = grafico[0]+1;
            }
                else
                if(cliente[indice].edad>=18&& cliente[indice].edad<35)
                {
                    grafico[1] = grafico[1]+1;

                 }
            else
                {
                    grafico[2] = grafico[2]+1;
                }


    }
    void borrarunCliente(EPersona persona[],int tam)
    {
        char respuesta;
        int indiceDNI;
        int auxDNI;
        printf("Ingrese el dni a eliminar:");
        scanf("%d",&auxDNI);

        indiceDNI=buscarPorDni(persona,auxDNI,tam);
        if(indiceDNI!=-1)
        {
            printf("%s,%d,%d,",persona[indiceDNI].nombre,persona[indiceDNI].edad,persona[indiceDNI].dni);
            printf("Estas seguro que deseas eliminarlo s/n");
            fflush(stdin);
            scanf("%c",&respuesta);
            fflush(stdin);
            if(respuesta =='s')
            {
                persona[indiceDNI].estado=0;
                printf("Baja dada exitosamente");
            }
            else
            {
                printf("Accion cancelada\n");
            }

        }
        else
            printf("\nEse dato no existe\n");
    }
    void ImprimirListaOrdenadaPorNombre(EPersona personita[],int tam)
    {
        int i,j;
        EPersona aux;
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(strcmp(personita[i].nombre,personita[j].nombre)>0)
                {
                    aux = personita[i];
                    personita[i] = personita[j];
                    personita[j] = aux;
                }
            }
        }
        printf("Nombre\tEdad\tDNI\n");
        for(i=0; i<tam; i++)
        {
            if(personita[i].estado==1)
            {
                printf("\n\n%s,%d,%d,",personita[i].nombre,personita[i].edad,personita[i].dni);
            }
        }
    }
    /*
void GraficodeEdades(int grafico[])
{
    int i;
    int aux;
    int flag = 0;
    for(i=0;i<3;i++)
    {
        if(grafico[i] > aux || flag ==0)
        {
            aux = grafico[i];
            flag =1;
        }
    }
    for(i=aux; i>0; i--){
        if(i<= grafico[0]){
            printf("*");
        }
        if(i<= grafico[1]){
            flag=1;
            printf("\t*");
        }
        if(i<= grafico[2]){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("<18\t19-35\t>35");
}
*/
void GraficodeEdades(int grafico[])
{
    int i;
    int aux;
    int flag = 0;
    for(i=0;i<3;i++)
    {
        if(grafico[i] > aux || flag ==0)
        {
            aux = grafico[i];
            flag =1;
        }
    }
    printf("Graf en pos 0 :%d%d%d\n",grafico[0],grafico[1],grafico[2]);
    for(i=0;i<aux;i++)
    {
        if(grafico[0]>=i)
        {
            printf("*d\t\n\n");

        }
        if(grafico[1]>=i)
        {
            printf("*a\n\n");
        }


        if(grafico[2]>=i)
        {
            printf("*b\n");
        }

    }
}


