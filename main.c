#include <stdio.h>
#include <stdlib.h>
#include <string.h>




#define C 3



void mostrarClientes(int[], char[][30], int[], int[], int);


int main()
{
    //legajo, nombre  edad


    int legajos[C]= {6,5,1}, edades[C]= {5,6,7}, estados[C]= {1,1,1}, flag;
    char nombres[C][30]= {"Maria", "Juan", "Maria"};


    char seguir='s', respuesta, auxString[100];
    int opcion;
    int i, j;
    int auxInt;

    do
    {
        printf("1.Alta\n2. Bajas\n3. Modificaciones\n4. Ordenar\n5. Mostrar\n6. Salir\nElija una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            flag=0;
            for(i=0; i<C; i++)
            {
                if(estados[i]==0)
                {
                    printf("Ingrese legajo: ");
                    scanf("%d", &legajos[i]);
                    printf("Ingrese edad: ");
                    scanf("%d", &edades[i]);
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(nombres[i]);

                    estados[i] = 1;
                    flag=1;
                    break;

                }
            }

            if(flag==0)
            {
                printf("No hay espacio!");
            }
            break;

        case 2:
            flag =0;
            printf("Ingrese legajo a eliminar: ");
            scanf("%d", &auxInt);

            for(i=0; i<C; i++)
            {
                if(estados[i]==1 && auxInt == legajos[i])
                {
                    printf("%d--%s--%d\n", legajos[i], nombres[i], edades[i]);

                    printf("Esta seguro de eliminar el cliente? s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        estados[i] = 0;
                    }
                    else
                    {
                        printf("Accion cancelada!");
                    }
                    flag=1;
                    break;

                }
            }



            if(flag==0)
            {
                printf("legajo inexistente");
            }


            break;

        case 3:
            flag =0;
            printf("Ingrese legajo a modificar: ");
            scanf("%d", &auxInt);

            for(i=0; i<C; i++)
            {
                if(estados[i]==1 && auxInt == legajos[i])
                {
                    printf("%d--%s--%d\n", legajos[i], nombres[i], edades[i]);
                    printf("Ingrese la nueva edad: ");
                    scanf("%d", &auxInt);
                    printf("Esta seguro de realizar la modificacion? s/n: ");
                    respuesta = getche();
                    if(respuesta=='s')
                    {
                        edades[i] = auxInt;
                    }
                    else
                    {
                        printf("Accion cancelada!");
                    }
                    flag=1;
                    break;

                }
            }



            if(flag==0)
            {
                printf("legajo inexistente");
            }


            break;
        case 4:

            for(i=0; i<C-1; i++)
            {
                for(j=i+1; j<C; j++)
                {
                    if(estados[i]==1 && estados[j]==1)
                    {
                        if(strcmp(nombres[i],nombres[j])>0)
                        {
                            strcpy(auxString, nombres[i]);
                            strcpy(nombres[i], nombres[j]);
                            strcpy(nombres[j],auxString);

                            auxInt = legajos[i];
                            legajos[i] = legajos[j];
                            legajos[j] = auxInt;

                            auxInt = edades[i];
                            edades[i] = edades[j];
                            edades[j] = auxInt;

                            auxInt = estados[i];
                            estados[i] = estados[j];
                            estados[j] = auxInt;

                        }
                        else
                        {
                            if(strcmp(nombres[i],nombres[j])==0)
                            {
                                if(legajos[i]>legajos[j])
                                {
                                    auxInt = legajos[i];
                                    legajos[i] = legajos[j];
                                    legajos[j] = auxInt;

                                    auxInt = edades[i];
                                    edades[i] = edades[j];
                                    edades[j] = auxInt;

                                    auxInt = estados[i];
                                    estados[i] = estados[j];
                                    estados[j] = auxInt;
                                }
                            }
                        }
                    }
                }
            }


            break;
        case 5:
            mostrarClientes(legajos, nombres, edades, estados, C);
            break;

        case 6:
            seguir = 'n';
            break;
        }

    }
    while(seguir=='s');

}


void mostrarClientes(int leg[], char nom[][30], int edad[], int est[], int tam)
{
    int i;
    for(i=0; i<C; i++)
    {
        if(est[i]!=0)
        {
            printf("%d--%s--%d\n", leg[i], nom[i], edad[i]);
        }

    }

}

