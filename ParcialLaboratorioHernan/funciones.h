typedef struct
{
    int idVerificador;
    char Descripcion[20];
    int estado;
}eProvedor;
typedef struct
{
    int idParcitularProducto;
    int idRelacional;
    char DescripcionProd[20];
    float importe;
    int cantidad;
    int estado;

}eProducto;
typedef struct
{
    int idVerificar;
    char descripcion[20];
    int estado;
}eSector;
int menuDeOpciones();
void InicializarEstadoProducto(eProducto personita[],int tam);
int BuscarIdProducto(eProducto personita[],int idaBuscar,int tam);
int BuscarEspacioLibreProducto(eProducto personita[],int tam);
void MostrarCliente(eProducto personita);
void MostrarClientes(eProducto personita[],int tam);
void AltaCliente(eProducto producto[],eProvedor provedor[],int tamprov,int tam);
void BorrarCliente(eProducto personita[],int tam);
int MenuDeModificacion();
void ModificarCliente(eProducto personita[],int tam);
void InicializarEstadoDeProvedor(eProvedor prov[],int tam);
void HarcodearProvedor(eProvedor sector[]);
void HarcodearClientes(eProducto personita[]);
//void RelacionarSectorConId(ePersona personita[],eSector sector[],int TAM);


