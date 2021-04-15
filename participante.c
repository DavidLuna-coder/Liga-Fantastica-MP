#include <stdio.h>
#include <stdlib.h>
#include "Cronista.h"
#include <string.h>
#include "participante.h"
#include "carga.h"
#include "_Usuarios.h"

void participantes(){
    int selec;
    do{
        printf("1-crear plantillas\n");
        printf("2-configurar plantilla\n");
        printf("3-listado de las plantillas\n");
        printf("4-eliminar plantillas\n");
        printf("5-ranking \n");
        printf("6-salir de la sesion\n");

        scanf("%i",&selec);
        switch (selec)
        {
        case 1:
           Cplantilla();
            break;
        
        case 2:
            configu();
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;
        case 5:
            /* code */
            break;
        case 6:
         printf("saliendo de la sesión...\n");
            break;
        
        default:
            printf("introduce un numero valido [1,2,3,4 ó 5]: \n");
            break;
        }




    }while(selec!=6);

}


void Cplantilla(){
int i,j,found,IDt,selec;
char plant[30];
printf("\nintroduce nombre para la plantilla: ");
do{
    found =1;
    fflush(stdin);
fgets(plant,30,stdin);
for(i=0;i<usuarios[usuarioActual].numeroPlantillas || found ==0;i++){
    found = strcmp(usuarios[usuarioActual].plantillas[i].nombre,plant);

    if(found==0){
        printf("\nel nombre de esta plantilla ya existe");
        printf("\npor favor vuelva a introducir otro nombre: ");
    }
}
}while(found==0);

usuarios[usuarioActual].numeroPlantillas++;
usuarios[usuarioActual].plantillas = (plantilla*)realloc(usuarios[usuarioActual].plantillas,(usuarios[usuarioActual].numeroPlantillas)*sizeof(plantilla)); //no revisado(75-80)
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idPlantilla=usuarios[usuarioActual].numeroPlantillas;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idUsuario=usuarios[usuarioActual].id;
strcpy(usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].nombre,plant);
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].presupuestoDisponible=config.presupuesto;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].numJugadores=0;
  printf("\npresupuesto disponible: %i $",usuarios[usuarioActual].plantillas[i].presupuestoDisponible);
    printf("\n\n----------------------------------------\n");
}
void configu(){

int selec;
do
{
  
    printf("\n que desea hacer?");
    printf("\n 1-listar los jugadores plantilla");
    printf("\n 2-listar los jugadores disponibles");
    printf("\n 3-añadir jugador");
    printf("\n 4-eliminar jugador");
    printf("\n 5-salir de la plantilla");

    scanf("%i",&selec);

    switch (selec)
    {
    case 1:
        lista();
        break;
    
    case 2:
    
    
        break;
    case 3:
        addJug();
        break;
    
    case 4:
        remoJug();
        break;

    case 5:
        printf("saliendo de la plantilla...\n");
        break;

    default:
        printf("introduce un numero valido [1,2,3 ó 4]: \n");
        break;
    }
} while (selec=!1);

}


void addJug(){
    int i,IDt,jugPlant,j,found,pres;
do
{
printf("\nintroduce el número de la plantilla: ");
    fflush(stdin);
    scanf("%i",&i);
 printf("\nintroduce la ID del jugador a añadir: ");
 scanf("%i",&IDt); //IDt: id temporar para encontrar al jugador si ya esta en la plantilla
 pres=0;
 found =0;
 for(jugPlant=0;j<numeroJugadores && found==0 ;jugPlant++){
     if(IDt==usuarios[usuarioActual].plantillas[i].jugadores[jugPlant].id)
        {
         printf("este jugador ya esta en la plantilla");
         found =1;
        }
 }

found=0;
 for(j=0;j<numeroJugadores && found==0 ;j++){
     if(IDt==jugadores[j].id)
        {
         found =1;
        }
}

    if(usuarios[usuarioActual].plantillas[i].presupuestoDisponible<jugadores[j].precio){
    printf("\nimposible añadir al jugador, el presupuesto no alcanza");
    pres=1;
    }
}while(found==1 && pres==1);

printf("\nAñadiendo al jugador...");

    usuarios[usuarioActual].plantillas[i].jugadores[usuarios[usuarioActual].plantillas[i].numJugadores].id = jugadores[j].id;
    usuarios[usuarioActual].plantillas[i].jugadores[usuarios[usuarioActual].plantillas[i].numJugadores].equipo = jugadores[j].equipo;
    usuarios[usuarioActual].plantillas[i].jugadores[usuarios[usuarioActual].plantillas[i].numJugadores].precio = jugadores[j].precio;
    usuarios[usuarioActual].plantillas[i].jugadores[usuarios[usuarioActual].plantillas[i].numJugadores].valoracion = jugadores[j].valoracion;
    strcpy(usuarios[usuarioActual].plantillas[i].jugadores[usuarios[usuarioActual].plantillas[i].numJugadores].nombre,jugadores[j].nombre);
    usuarios[usuarioActual].plantillas[i].numJugadores ++;
    usuarios[usuarioActual].plantillas[i].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i].jugadores,(usuarios[usuarioActual].plantillas[i].numJugadores + 1)*sizeof(jugador));
        
        if(usuarios[usuarioActual].plantillas[i].jugadores==NULL){
        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        }
        else
        {
            printf("\njugador añadido con exito a la plantilla\n");
        }
    usuarios[usuarioActual].plantillas[i].presupuestoDisponible = usuarios[usuarioActual].plantillas[i].presupuestoDisponible - jugadores[j].precio;
}


void remoJug(){
    int idt,j,found,k,i;
    printf("\nintroduce el número de la plantilla: ");
    fflush(stdin);
    scanf("%i",&i);
    printf("\nintroduce la id del jugador a eliminar: ");
    scanf("%i",&idt);
    found =0;
    for(j=0;j<usuarios[usuarioActual].plantillas[i].numJugadores || found==0;j++){
        if(idt==usuarios[usuarioActual].plantillas[i].jugadores[j].id){
            found=1;
        }
    }

    usuarios[usuarioActual].plantillas[i].presupuestoDisponible = usuarios[usuarioActual].plantillas[i].presupuestoDisponible - usuarios[usuarioActual].plantillas[i].jugadores[j].precio;

  for(k=j;k<usuarios[usuarioActual].plantillas[i].numJugadores;k++){
      usuarios[usuarioActual].plantillas[i].jugadores[k].id = usuarios[usuarioActual].plantillas[i].jugadores[k+1].id;
    usuarios[usuarioActual].plantillas[i].jugadores[k].equipo = usuarios[usuarioActual].plantillas[i].jugadores[k+1].equipo;
    usuarios[usuarioActual].plantillas[i].jugadores[k].precio = usuarios[usuarioActual].plantillas[i].jugadores[k+1].precio;
    usuarios[usuarioActual].plantillas[i].jugadores[k].valoracion = usuarios[usuarioActual].plantillas[i].jugadores[k+1].valoracion;
    strcpy(usuarios[usuarioActual].plantillas[i].jugadores[k].nombre,(usuarios[usuarioActual].plantillas[i].jugadores[k+1].nombre));

  }
    usuarios[usuarioActual].plantillas[i].numJugadores --;
    usuarios[usuarioActual].plantillas[i].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i].jugadores,(usuarios[usuarioActual].plantillas[i].numJugadores - 1)*sizeof(jugador));
        
        if(usuarios[usuarioActual].plantillas[i].jugadores==NULL){
        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        }
        else
        {
            printf("\njugador eliminado con exito a la plantilla\n");
        }

}


