#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
typedef struct
{
    int idMensaje;
    char mensaje[2000];
    int popularidad;
    int idUsuarioRela;
}Mensajes;
typedef struct
{
    int idUsuario;
    char nick[5000];
    int popularidad;
}Usuarios;
typedef struct
{
    int idMensaje;
    char mensaje[50];
    int popularidadMensaje;
    int idUsuarioRela;
    char nick[50];
    int  popularidadUsuario;
}Todo;

int employee_compare(void* pEmployeeA,void* pEmployeeB);
void employee_print(Mensajes* this);
Mensajes* employee_new(void);
int employee_compareApe(void* pEmployeeA,void* pEmployeeB);
int employee_compareapellido(void* pEmployeeA,void* pEmployeeB);
int menuModificar();
void setIdMensaje(Mensajes *puntero,int idMensaje);
void setmsg(Mensajes* puntero,char msg[]);
void setPoPularidadMensaje(Mensajes* puntero,int popular);
void idUsuarioRelaa(Mensajes* puntero,int usuarioRela);
void setidUsuario(Usuarios *puntero,int id);
void setnick(Usuarios* puntero,char msg[]);
void intPoPuLaridadUsuario (Usuarios *puntero, int dato);
void BajaDeCliente(ArrayList* lista);
void ModificarCliente(ArrayList *lista);
void AltaCliente(ArrayList* lista,int *puntero);
void CargarDatosAlSistema(ArrayList* lista1);
int employee_compareNumero(void* pEmployeeA,void* pEmployeeB);
void idUsuarioRelaa(Mensajes* puntero,int usuarioRela);
void setPoPularidadMensaje(Mensajes* puntero,int popular);
Todo* employee_newPersonaFull(void);
Usuarios* employee_newUsuario(void);
Mensajes* employee_newMensaje();
void employee_printUsuarios(Usuarios *this);
void CargarUsuariosAlSistema(ArrayList* lista1);



#endif // _EMPLOYEE_H
