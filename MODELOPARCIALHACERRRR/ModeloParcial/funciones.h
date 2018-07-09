
#include "ArrayList.h"
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    long long int dni;
    char nombre[50];
    char apellido[50];
}typedef Employee;

typedef struct
{
    int id;
    char CodigoProducto[50];
    float costoUnitario;
    int cantidad;
    int dia;
    int mes;
    int anio;
    float importe;
}eProducto;

int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Employee* this);
Employee* employee_new(void);
void employee_delete(Employee* this);
int employee_setId(Employee* this, int id);
int employee_getId(Employee* this);
int employee_compareApe(void* pEmployeeA,void* pEmployeeB);
int employee_compareapellido(void* pEmployeeA,void* pEmployeeB);
eProducto* employee_newPRODUCTO(void);
void setUnitarioproducto(eProducto *puntero,float dato);
void employee_printPRODUCTO(eProducto* this);
eProducto* employee_newPRODUCTO(void);
int menuModificar();
void setAnioproducto(eProducto *puntero,int dato);
void setMESproducto(eProducto *puntero,int dato);
void setDIAproducto(eProducto *puntero,int dato);
void setCantidadproducto(eProducto *puntero,int dato);
void setUnitarioproducto(eProducto *puntero,float dato);
void setIdproducto(eProducto *puntero,int dato);
int  verificarID(ArrayList *lista,int id);
int employee_compareapellido(void* pEmployeeA,void* pEmployeeB);
int BuscarPORID(ArrayList *lista,int id);
int RevisarID(ArrayList* lista,int id);
void setApellido(Employee* puntero,char apellido[]);
void setNombre(Employee* puntero,char nombre[]);
void setDNI(Employee* puntero,long int dato);
void setId(Employee *puntero,int *dato);
void ListarClientes(ArrayList* lista);
void BajaDeCliente(ArrayList* lista);
void ModificarCliente(ArrayList *lista);
void AltaCliente(ArrayList* lista,int *puntero);
void CargarDatosAlSistema(ArrayList *lista,int *entero);
void RealizarUnaVenta(ArrayList* lista2,ArrayList* lista);
int BuscarCodigoParaRevisar(ArrayList* lista2, char dato[]);
void GenerarInformeDeVentaXProducto(ArrayList* lista2,ArrayList* lista3);
int employee_compareImporte(void* pEmployeeA,void* pEmployeeB);
#endif // _EMPLOYEE_H
