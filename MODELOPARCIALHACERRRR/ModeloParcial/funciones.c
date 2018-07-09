#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.h"

void generarArchivo(ArrayList* lista3)
{
    eProducto *producto;
    FILE *archivo;
    int i;

    archivo = fopen("informar.csv","w");
    if(archivo!=NULL)
    {
        for(i=0; i<lista3->len(lista3); i++)
        {
            producto = (eProducto*)lista3->get(lista3,i);
            fprintf(archivo,"%d,%s,%f,%d,%d,%d,%d,%f\n",producto->id,producto->CodigoProducto,producto->costoUnitario,producto->cantidad,producto->dia,producto->mes,producto->anio,producto->importe);
        }
    }
    fclose(archivo);
}
void ordenar(ArrayList* lista3)
{
    lista3->sort(lista3,employee_compareImporte,1);
}
void GenerarInformeDeVentaXProducto(ArrayList* lista2,ArrayList* lista3)
{
    char aux[50];
    int auxInt;
    int i;
    eProducto* producto;
    while(lista3->isEmpty(lista3)!=1)
    {
        lista3->remove(lista3,0);
    }
    printf("Ingrese el codigo del producto");
    fflush(stdin);
    gets(aux);
    auxInt = BuscarCodigoParaRevisar(lista2,aux);
    if(auxInt==-1)
    {
        printf("Error ese codigo de producto no existe");
    }
    else
    {
        for(i=0; i<lista2->len(lista2); i++)
        {
            producto = lista2->get(lista2,i);
            if(strcmp(producto->CodigoProducto,aux) == 0)
            {
                producto->importe = producto->cantidad*producto->costoUnitario;
                lista3->add(lista3,producto);
            }
        }
    }
}
int BuscarCodigoParaRevisar(ArrayList* lista2, char dato[])
{
    int i;
    eProducto* puntero;
    int flag = -1;
    if(lista2!=NULL)
    {
        for(i=0; i<lista2->len(lista2); i++)
        {
            puntero = (eProducto*)lista2->get(lista2,i);
            if(strcmp(puntero->CodigoProducto,dato)==0)
            {
                flag = i;
                break;
            }
        }
    }
    return flag;
}
void RealizarUnaVenta(ArrayList* lista2,ArrayList* lista)
{
    eProducto *producto = employee_newPRODUCTO();
    int id;
    char CodigoProducto[50];
    float costoUnitario;
    int cantidad;
    int dia;
    int mes;
    int anio;
    int devolver;

    printf("Ingrese el id del cliente");
    scanf("%d",&id);
    devolver = BuscarPORID(lista,id);
    if(devolver == 0)
    {
        printf("Error ese id del comprador no existe\n");
        system("pause");
    }
    else
    {
        fflush(stdin);
        printf("Ingrese el codigo del producto(ALPHA NUMERICO)");
        gets(CodigoProducto);
        fflush(stdin);
        printf("Ingrese el costo unitario del producto");
        scanf("%f",&costoUnitario);
        fflush(stdin);
        printf("Ingrese la cantidad");
        scanf("%d",&cantidad);
        fflush(stdin);
        printf("Ingrese el dia de la venta");
        scanf("%d",&dia);
        fflush(stdin);
        printf("Ingrese el mes de la venta");
        scanf("%d",&mes);
        fflush(stdin);
        printf("Ingrese el anio de la venta");
        scanf("%d",&anio);
        fflush(stdin);
        setIdproducto(producto,id);
        setcodigoProducto(producto,CodigoProducto);

        setUnitarioproducto(producto,costoUnitario);
        setCantidadproducto(producto,cantidad);
        setDIAproducto(producto,dia);
        setMESproducto(producto,mes);
        setAnioproducto(producto,anio);
        lista2->add(lista2,producto);

    }


}
void CargarDatosAlSistema(ArrayList *lista,int *entero)
{
    FILE *archivo;
    Employee *NuevoEmpleado;
    char dni[50];
    char nombre[50];
    char apellido[50];
    int cant;
    int i;
    char detected[50];
    int flag = 0;
    printf("Ingrese el nombre del archivo");
    fflush(stdin);
    gets(detected);
    fflush(stdin);
    archivo = fopen(detected,"r");
    if(archivo != NULL)
    {
        fscanf(archivo,"%[^,],%[^,],%[^\n]\n",nombre,apellido,dni);
        while(!feof(archivo))
        {
            cant = fscanf(archivo,"%[^,],%[^,],%[^\n]\n",nombre,apellido,dni);
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
            for(i=0; i<lista->len(lista); i++)
            {
                NuevoEmpleado = lista->get(lista,i);
                if(NuevoEmpleado->dni == atol(dni))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
            {
                *entero = *entero+1;
                NuevoEmpleado = employee_new();
                strcpy(NuevoEmpleado->nombre,nombre);
                strcpy(NuevoEmpleado->apellido,apellido);
                NuevoEmpleado->dni = atol(dni);
                NuevoEmpleado->id = *entero;
                lista->add(lista,NuevoEmpleado);
            }
            flag = 0;

        }
    }
    else
    {
        printf("archivo mal");
    }
}

void AltaCliente(ArrayList* lista,int *puntero)
{

    int id;
    long int dni;
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
        printf("Ingrese su apellido");
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
            setDNI(Nuevo_Empleado,dni);
            setId(Nuevo_Empleado,puntero);
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
                    scanf("%d",&dni);
                    auxEmpleado = (Employee*)lista->get(lista,devolver);
                    setDNI(auxEmpleado,dni);
                    system("pause");
                    break;

                case 4:
                    seguir = 'z';
                    break;

                }
            }
            while(seguir == 's');
        }


    }
}

void BajaDeCliente(ArrayList* lista)
{
    Employee *auxEmpleado;
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
void OrdenarClientes(ArrayList* lista)
{
    lista->sort(lista,employee_compareapellido,1);
}
void ListarClientes(ArrayList* lista)
{
    Employee* auxEmpleado;
    int i;
    for(i=0; i<lista->len(lista); i++)
    {
        auxEmpleado = (Employee*)lista->get(lista,i);
        employee_print(auxEmpleado);
    }

}
void setId(Employee *puntero,int *dato)
{
    if(puntero!=NULL)
    {
        puntero->id = *dato;
        printf("%d",puntero->id);
    }
}
void setDNI(Employee* puntero,long int dato)
{
    if(puntero != NULL)
    {
        puntero->dni = dato;
    }
}
void setNombre(Employee* puntero,char nombre[])
{
    if(puntero!=NULL)
    {
        strcpy(puntero->nombre,nombre);
    }
}
void setApellido(Employee* puntero,char apellido[])
{
    if(puntero!=NULL)
    {
        strcpy(puntero->apellido,apellido);
    }
}
int RevisarID(ArrayList* lista,int id)
{
    int devolver = -1;
    int i;
    Employee *auxEmpleado;
    for(i=0; i<lista->len(lista); i++)
    {
        auxEmpleado = (Employee*)lista->get(lista,i);
        if(auxEmpleado->dni == id)
        {
            devolver = 0;
            break;
        }
    }
    return devolver;
}
int BuscarPORID(ArrayList *lista,int id)
{
    printf("%d",id);
    int i;
    Employee *aux;
    int flag = 0;

    for(i=0; i<lista->len(lista); i++)
    {
        aux = (Employee*)lista->get(lista,i);
        if(aux->id == id)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
/*
int CargarListaNegras(FILE *archivito,ArrayList* lista_black,ArrayList* lista)
{
}
/*
/*void DepurarArchivos(ArrayList* lista,ArrayList* listaNegra,ArrayList* depurada)
{

}*/
int employee_compareapellido(void* pEmployeeA,void* pEmployeeB)
{
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {

        Employee* empA = (Employee*) pEmployeeA;
        Employee* empB = (Employee*) pEmployeeB;
        return strcmp(empA->apellido, empB->apellido);
    }
    return 0;
}


int employee_compareImporte(void* pEmployeeA,void* pEmployeeB)
{
    int retornar = 0;
    if(pEmployeeA != NULL && pEmployeeB != NULL)
    {
        retornar = -1;
        eProducto* empA = (eProducto*) pEmployeeA;
        eProducto* empB = (eProducto*) pEmployeeB;
        if(empA->importe>empB->importe)
        {
            retornar = 1;
        }
    }
    return retornar;
}



void employee_print(Employee* this)
{
    if(this != NULL)
    {
        printf("%s\t%s\t%d\t%ld\n", this->nombre,this->apellido,this->id,this->dni);
    }
}


Employee* employee_new(void)
{
    Employee* returnAux;
    returnAux = (Employee*)malloc(sizeof(Employee));
    if(returnAux !=NULL)
    {
        strcpy(returnAux->nombre,"");
        strcpy(returnAux->apellido,"");
        returnAux->dni = 0;
        returnAux->id = 0;
    }
    return returnAux;

}
int  verificarID(ArrayList *lista,int id)
{
    printf("\n\n%dasdadasd",id);
    int i;
    int retorno = -1;
    Employee *auxEmpleado;
    for(i=0; i<lista->len(lista); i++)
    {
        auxEmpleado = (Employee*)lista->get(lista,i);
        if(auxEmpleado->id == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

/*
void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        this->isEmpty = 1;
    }

}
*/
/*
int employee_setId(Employee* this, int dni)
{
 if(this != NULL){
       if(dni > 0 && dni < 99999999){
        this->dni = dni;
        return 0;
       }
    }
    return -1;

}
*/
/*
int employee_getId(Employee* this)
{
    int id = -1;
     if(this != NULL){
            id = this->id;
     }
    return id;

}
*/
void setIdproducto(eProducto *puntero,int dato)
{
    if(puntero!=NULL)
    {
        puntero->id = dato;
    }
}
void setcodigoProducto(eProducto *puntero,char dato[])
{
    if(puntero!=NULL)
    {
        strcpy(puntero->CodigoProducto,dato);
    }
}
void setUnitarioproducto(eProducto *puntero,float dato)
{
    printf("\n\n%f\n",dato);

    if(puntero!=NULL)
    {
        puntero->costoUnitario= dato;
    }
}
void setCantidadproducto(eProducto *puntero,int dato)
{
    if(puntero!=NULL)
    {
        puntero->cantidad = dato;
    }
}
void setDIAproducto(eProducto *puntero,int dato)
{
    if(puntero!=NULL)
    {
        puntero->dia = dato;
    }
}
void setMESproducto(eProducto *puntero,int dato)
{
    if(puntero!=NULL)
    {
        puntero->mes = dato;
    }
}
void setAnioproducto(eProducto *puntero,int dato)
{
    if(puntero!=NULL)
    {
        puntero->anio = dato;
    }
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
eProducto* employee_newPRODUCTO(void)
{
    eProducto* returnAux;
    returnAux = (eProducto*)malloc(sizeof(eProducto));
    if(returnAux !=NULL)
    {
        returnAux->id = 0;
        strcpy(returnAux->CodigoProducto,"");
        returnAux->costoUnitario = 0;
        returnAux->cantidad = 0;
        returnAux->dia = 0;
        returnAux->mes = 0;
        returnAux->anio = 0;
        returnAux->importe = 0;
    }
    return returnAux;
}
void employee_printPRODUCTO(eProducto* this)
{
    if(this != NULL)
    {
        printf("%d\t%s\t%f\t%d\t%d\t%d\t%d\t%f\n", this->id,this->CodigoProducto,this->costoUnitario,this->cantidad,this->dia,this->mes,this->anio,this->importe);
    }
}

