#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int menuDeOpciones()
{
    int devolver;
    printf("1- Alta Del cliente\n\n");
    printf("2- Modificacion del cliente\n\n");
    printf("3- Eliminar cliente\n\n");
    printf("4- Listar cliente\n\n");
    printf("5- Cargar sectores\n\n");
    printf("6- Relacionar estructuras\n\n");
    printf("7- Salir del menu\n\n");
    scanf("%d",&devolver);
    return devolver;
}
int MenuDeModificacion()
{
    int devolver;
    printf("1- Modificar descripcion\n");
    printf("2- Modificar idParticular\n");
    printf("3- Modificar importe\n");
    printf("4- Modificar Cantidad\n");
    printf("5- Salir del menu \n");
    scanf("%d",&devolver);
    return devolver;
}
void InicializarEstadoProducto(eProducto productito[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        productito[i].estado = 0;
    }
}
void InicializarEstadoDeProvedor(eProvedor prov[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        prov[i].estado = 0;
    }
}
int BuscarIdProducto(eProducto producto[],int idaBuscar,int tam)
{
    int i;
    int dato = -1;
    for(i=0; i<tam; i++)
    {
        if(idaBuscar == producto[i].idParcitularProducto && producto[i].estado == 1)
        {
            dato = i;
            break;
        }
    }
    return dato;
}
int BuscarEspacioLibreProducto(eProducto productito[],int tam)
{
    int i;
    int dato = -1;
    for(i=0; i<tam; i++)
    {
        if(productito[i].estado == 0)
        {
            dato = i;
            break;
        }
    }
    return dato;
}
int BuscarEspacioLibreProvedor(eProvedor prov[],int tam)
{
    int i;
    int dato = -1;
    for(i=0; i<tam; i++)
    {
        if(prov[i].estado == 0)
        {
            dato = i;
            break;
        }
    }
    return dato;
}

void MostrarCliente(eProducto producto)
{
    printf("Descrip:%s\tImporte:%f\tCantidad:%d\tIdParticular",producto.DescripcionProd,producto.importe,producto.cantidad,producto.idParcitularProducto);
}
void MostrarClientes(eProducto personita[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(personita[i].estado == 1)
        {
            MostrarCliente(personita[i]);
        }

    }
}
void AltaCliente(eProducto producto[],eProvedor provedor[],int tamprov,int tam)
{
    int auxlegajo;
    int espacio;
    int i;
    espacio = BuscarEspacioLibreProducto(producto,tam);
    if(espacio == -1)
    {
        printf("Error, No hay espacio disponible en el sistema");
    }
    else
    {
        fflush(stdin);
        printf("Ingrese su idParticular");
        scanf("%d",&producto[espacio].idParcitularProducto);
        fflush(stdin);
        auxlegajo = BuscarIdProducto(producto,producto[espacio].idParcitularProducto,tam);
        if(auxlegajo != -1)
        {
            printf("Error, ese id ya existe y es de otro usuario\n");
        }
        else
        {
            printf("Los provedores a seleccionar son \n");
            for(i=0;i<tamprov;i++)
            {
                if(provedor[i].estado == 1)
                {
                    printf("%d\t%s\n",i,provedor[i].Descripcion);
                }
            }
            printf("Ingrese el id a relacionar");
            fflush(stdin);
            scanf("%d",&producto[espacio].idRelacional);
            printf("Igrese su descipcion del producto");
            fflush(stdin);
            gets(producto[espacio].DescripcionProd);
            fflush(stdin);
            printf("Ingrese su cantidad");
            fflush(stdin);
            scanf("%d",&producto[espacio].cantidad);
            fflush(stdin);
            printf("Ingrese su importe");
            scanf("%f",&producto[espacio].importe);
            producto[espacio].estado = 1;
            fflush(stdin);
        }

    }
}
void BorrarCliente(eProducto producto[],int tam)
{
    int auxpersona;
    int aux;
    char eliminar;
    printf("Ingrese el id Partucular el producto a eliminar");
    scanf("%d",&aux);
    aux = BuscarIdProducto(producto,aux,tam);
    if(aux != -1)
    {
        MostrarCliente(producto[aux]);
        printf("\nEstas seguro que deseas eliminarlo?s/n");
        fflush(stdin);
        scanf("%c",&eliminar);
        if(eliminar=='s')
        {
            producto[aux].estado = 0;
            printf("Se elimino correctamente!\n");
        }
        else
        {
            printf("Accion calcelada\n");
        }
    }
    else
    {
        printf("Error ese id no existe.");
    }

}
void ModificarCliente(eProducto producto[],int tam)
{
    int salir = 1;
    int auxLegajo;
    int aux;
    char eliminar;
    printf("Ingrese el id particular del producto a modificar");
    scanf("%d",&auxLegajo);
    aux = BuscarIdProducto(producto,auxLegajo,tam);
    if(aux != -1)
    {
        printf("Estas seguro que deseas Modificarlo?");
        fflush(stdin);
        scanf("%c",&eliminar);
        if(eliminar != 's')
        {
            printf("Accion cancelada\n");
        }
        else
        {
            do

            {
                switch(MenuDeModificacion())
                {
                case 1:
                    fflush(stdin);
                    printf("\nIngrese su nuevo nombre");
                    gets(producto[aux].DescripcionProd);
                    break;
                case 2:
                    printf("Ingrese su Numero particular del producto");
                    fflush(stdin);
                    scanf("%c",&producto[aux].idParcitularProducto);
                    break;
                case 3:
                    printf("Ingrese su importe nuevo");
                    fflush(stdin);
                    scanf("%f",&producto[aux].importe);
                    break;
                case 4:
                     printf("Ingrese su cantidad nueva");
                     fflush(stdin);
                     scanf("%d",&producto[aux].cantidad);
                    break;
                case 5:
                    printf("Salir");
                    salir = 2;
                }

            }
            while(salir == 1);

        }

    }
    else
    {
        printf("Error id no encontrado\n");
    }
}
void HarcodearProvedor(eProvedor provedor[])
{
    provedor[0].idVerificador = 1;
    strcpy(provedor[0].Descripcion, "pepitos");
    provedor[0].estado = 1;

    provedor[1].idVerificador = 2;
    strcpy(provedor[1].Descripcion, "moztaza");
    provedor[1].estado = 1;
}
/*void RelacionarSectorConId(ePersona personita[],eSector sector[],int TAM)
{
    int i;
    int j;

    for(i=0;i<TAM;i++)
    {
        if(personita[i].estado == 1)
        {
            for(j=0;j<TAM;j++)
            {
                if(sector[j].estado == 1)
                {
                    if(personita[i].idSector == sector[j].idVerificar)
                    {
                        printf("El id %d corresponde a %s que tiene el sector y el dia es %d",personita[i].idSector,personita[i].nombre,personita[i].fechaIngreso.dia);

                        printf(" %s\n\n",sector[j].descripcion);
                    }
                }
            }
        }
    }
}
*/
void HarcodearClientes(eProducto producto[])
{
    producto[0].idParcitularProducto = 6;
    strcpy(producto[0].DescripcionProd,"lechuga");
    producto[0].idRelacional = 1;
    producto[0].cantidad = 3;
    producto[0].importe = 5.5;
    producto[0].estado = 1;

}
int validarLetra(char opcion[])
{
    int flag = 0,cant,i;

    cant = strlen(opcion);

    for(i=0; i<cant; i++)
    {
        if(!isdigit(opcion[i]))
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
float SacarAcumuladorYPromedio(eProducto producto[],int TAM)
{
    int i;
    float acumulador = 0;


    for(i=0;i<TAM;i++)
    {
        acumulador = acumulador + producto[i].importe;
    }
    printf("%f\n",acumulador);
    return acumulador;
}
