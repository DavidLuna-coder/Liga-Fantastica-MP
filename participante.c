#include <stdio.h>
#include <stdlib.h>
#include "Cronista.h"

void participante(){
    int selec;
    do{
        printf("1-crear plantillas\n");
        printf("2-eliminar plantillas\n");
        printf("3-listado de las plantillas\n");
        printf("4-listado de los jugadores de una plantilla\n");
        printf("5-salir de la sesion\n");
        scanf("%i",&selec);
        switch (selec)
        {
        case 1:
           Cplantilla();
            break;
        
        case 2:
            /* code */
            break;

        case 3:
            /* code */
            break;

        case 4:
            /* code */
            break;

        case 5:
         printf("saliendo de la sesión...\n");
            break;
        
        default:
            printf("introduce un numero valido [1,2,3,4 ó 5]: \n");
            break;
        }




    }while(selec!=5);



   return 0; 
}


void Cplantilla(){
int i,j,found,IDt,selec;
do
{
    
 printf("\nintroduce ID para la nueva plantilla: ");
 scanf("%i",&IDt);
 found =0;
 for(i=0;i<numeroPlantillas||found==1 ;i++){
     if(IDt==plantilla[i].ID)
        {
         printf("esta ID ya la tiene otra plantilla\n porfavor introduzca otra ID");
         found =1;
        }
}
} while (found==1);

printf("\nintroduce nombre para la plantilla: ");
scanf("%s",&plantilla[i].nombre);

do
{
    printf("\npresupuesto disponible: %i $",plantilla[i].presupuestoDisponible);
    printf("\n que desea hacer?");
    printf("\n 1-listar los jugadores disponibles");
    printf("\n 2-añadir jugador");
    printf("\n 3-eliminar jugador");
    printf("\n 4-salir de la plantilla");

    scanf("%i",&selec);

    switch (selec)
    {
    case 1:
        lista();
        break;
    case 2:
        addJug(i);
        break;
    
    case 3:
        /* code */
        break;

    case 4:
        printf("saliendo de la plantilla...\n");
        break;

    default:
        break;
    }
} while (selec=!1);


}


void addJug(int *i){
    int IDt,jugPlant,j,found,pres;
do
{
    
 printf("\nintroduce la ID del jugador a añadir: ");
 scanf("%i",&IDt);
 pres=0;
 found =0;
 for(jugPlant=0;j<numeroJugadores||found==1 ;jugPlant++){
     if(IDt==plantilla[i].jugador[jugPlant].id)
        {
         printf("este jugador ya esta en la plantilla");
         found =1;
        }
 }

found=0;
 for(j=0;j<numeroJugadores||found==1 ;j++){
     if(IDt==jugador[j].id)
        {
         found =1;
        }
}

    if(plantilla[i].presupuestoDisponible<jugador[j].precio){
    printf("\nimposible añadir al jugador, el presupuesto no alcanza");
    pres=1;
    }
}while(found==1 && pres==1);

printf("\nAñadiendo al jugador...");

}
