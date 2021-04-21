#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "Cronista.h"
//void cronista(jugador *);

    //cabecera: void cronista();
    //precondicion: tener cargados los usuarios y los jugadores
    //postcondicion: permite ejecutar todas las funciones de el cronista
void cronista(){
int elec;   //elec: variable para selecionar una opcion en el switch
    
do{      //menu de selecion de las funciones del cronista
 printf("1-mostrar lista de jugadores y sus valoraciones\n");
printf("2-valorar un jugador\n");
printf("3-Salir de la sesion\n");
    scanf("%i",&elec);
    fflush(stdin);
switch(elec){
    case 1: 
    lista();
    break;

    case 2: 
    valorar();
    break;

    case 3:
    printf("saliendo de la sesion...\n");
    break;

    default:
    printf("introduce un numero valido [1,2 o 3]: \n");
    break;
}   
    
}while(elec!=3);
system("pause");
}

    //cabecera: void lista();
    //precondicion: debe tener cargado los jugadores 
    //postcondicion: muestra una lista de todos los jugadores
void lista(){
int i;
for(i=0;i<numeroJugadores;i++){
    printf("%i-%i-%s-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].valoracion);
}
}


    //cabecera: void valorar();
    //precondicion: debe tener cargado los jugadores 
    //postcondicion: otorga una valoracion a un jugador elegido por su ID
void valorar (){
    int id,i,val,find=0;    //id: id temporar que sirve para compararla con la id real que buscamos
                            //val: valor que regula el valor maximo y minimo que un jugador puede tomar [0-10]
                            //find: variable que marca si el jugador ha sido encontrado
    printf("introduce la id del jugador a valorar: ");
    scanf("%i",&id);

    for(i=0;i<numeroJugadores || find==0;i++){
        if(jugadores[i].id==id){
            printf("\n introduzca una valoracion entre 0-10 para %s: ",jugadores[i].nombre);
            scanf("%i",&val);
            while(val<0 || val>10){
                printf("introduce un valor entre 0-10\n");
                scanf("%i",&val);
            }
            jugadores[i].valoracion=val;
            valorarPlantillas();
            find=1;
        }
    }
    
}