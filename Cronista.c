#include <stdio.h>
#include <stdlib.h>
//void cronista(jugador *);
void lista(jugador *);
void valorar (jugador *);


void cronista(jugador *jugadores){
int elec,res;



do{
 printf("1-mostrar lista de jugadores y sus valoraciones\n");
printf("2-valorar un jugador\n");
printf("3-Salir de la sesion\n");
    scanf("%i",&elec);
switch(elec){
    case 1: 
    lista(jugadores);
    break;

    case 2: 
    valorar(jugadores);
    break;

    case 3:
    printf("saliendo de la sesión...\n");
    break;

    default:
    printf("introduce un numero valido [1,2 ó 3]: \n");
    break;
}   
    
}while(elec!=3);
system("pause");
}

void lista(jugador *jugadores){
int i;
for(i=0;i<=100;i++){
    printf("%i-%i-%s-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].valoracion);
}
}

void valorar (jugador *jugadores){
    int id,i,val,find=0;
    printf("introduce la id del jugador a valorar: ");
    scanf("%i",&id);

    for(i=0;i<=100 || find==0;i++){
        if(jugadores[i].id==id){
            printf("/n introduzca una valoracion entre 0-10 para %s: ",jugadores[i].nombre);
            scanf("%i",&val);
            while(val<0 || val>10){
                printf("introduce un valor entre 0-10\n");
                scanf("%i",&val);
            }
            jugadores[i].valoracion=val;
            find=1;
        }
    }
}
