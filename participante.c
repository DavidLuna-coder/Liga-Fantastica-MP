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
            listarPlantillas();
            break;

        case 4:
            eliminarPlantillas();
            break;
        case 5:
            ranking();
            break;
        case 6:
         printf("saliendo de la sesion...\n");
            break;
        
        default:
            printf("introduce un numero valido [1,2,3,4 ó 5]: \n");
            break;
        }




    }while(selec!=6);

}


void Cplantilla(){
int i,j,found,IDt,selec;
char plant[30],aux;
printf("\nintroduce nombre para la plantilla: ");
do{
    found =1;
scanf("%c",&aux);
fgets(plant,30,stdin);
plant[strlen(plant)-1]='\0';
for(i=0;i<usuarios[usuarioActual].numeroPlantillas && found!=0;i++){
    found = strcmp(usuarios[usuarioActual].plantillas[i].nombre,plant);
    printf("%i\n",found);
    if(found==0){
        printf("\nel nombre de esta plantilla ya existe");
        printf("\npor favor vuelva a introducir otro nombre: ");
    }
}
}while(found==0);

usuarios[usuarioActual].numeroPlantillas++;
numeroPlantillas++;
usuarios[usuarioActual].plantillas = (plantilla*)realloc(usuarios[usuarioActual].plantillas,(usuarios[usuarioActual].numeroPlantillas)*sizeof(plantilla)); 

    if(usuarios[usuarioActual].plantillas==NULL){
        printf("Error en la reserva de memoria de la plantilla\n");
        }
        else{
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idPlantilla=numeroPlantillas;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idUsuario=usuarios[usuarioActual].id;
strcpy(usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].nombre,plant);
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].presupuestoDisponible=config.presupuesto;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].numJugadores=0;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].puntuacion=0;
  printf("\npresupuesto disponible: %i $",usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].presupuestoDisponible);
    printf("\n\n----------------------------------------\n");
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].jugadores = (jugador*)malloc(1*sizeof(jugador));
                if(usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].jugadores==NULL){
                    printf("error en la carga de usuarios al registrarse\n");
                    exit(1);
                }
}
}
void configu(){

int selec;
do
{
  
    printf("\n que desea hacer?");
    printf("\n 1-listar los jugadores plantilla");
    printf("\n 2-listar los jugadores disponibles");
    printf("\n 3-anadir jugador");
    printf("\n 4-eliminar jugador");
    printf("\n 5-salir de la plantilla ");

    scanf("%i",&selec);

    switch (selec)
    {
    case 1:
        lista();
        break;
    
    case 2:
        /*code*/
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
    do{
printf("\nintroduce el número de la plantilla: ");
    fflush(stdin);
    scanf("%i",&i);
 printf("\nintroduce la ID del jugador a añadir: ");
 scanf("%i",&IDt); //IDt: id temporal para encontrar al jugador si ya esta en la plantilla
 pres=0;
 found =0;
 for(jugPlant=0;j<numeroJugadores && found==0 ;jugPlant++){
     if(IDt==usuarios[usuarioActual].plantillas[i-1].jugadores[jugPlant].id)
        {
         printf("este jugador ya esta en la plantilla");
         found =1;
        }
 }
}while(found==1);
found=0;
 for(j=0;j<numeroJugadores && found==0 ;j++){
     if(IDt==jugadores[j].id)
        {
         found =1;
        }
}
    if(found!=1){
        printf("No existe jugador con dicha ID");
    }

    if(usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible<jugadores[j].precio){
    printf("\nimposible añadir al jugador, el presupuesto no alcanza");
    pres=1;
    }
}while(pres==1 || found==0);

printf("\nAnadiendo al jugador...");

    usuarios[usuarioActual].plantillas[i-1].numJugadores ++;
    usuarios[usuarioActual].plantillas[i-1].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i-1].jugadores,(usuarios[usuarioActual].plantillas[i-1].numJugadores + 1)*sizeof(jugador));
   
        if(usuarios[usuarioActual].plantillas[i-1].jugadores==NULL){
        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        exit(1);
        }
        else
        {
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].id = jugadores[j].id;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].equipo = jugadores[j].equipo;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].precio = jugadores[j].precio;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].valoracion = jugadores[j].valoracion;
         strcpy(usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].nombre,jugadores[j].nombre);
            printf("\njugador anadido con exito a la plantilla\n");
        }
 
   
       
    usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible = usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible - jugadores[j].precio;
    numeroJugadoresPlantillas++;
    jugadoresPlantillas[numeroJugadoresPlantillas].idJugador=usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores].id;
    jugadoresPlantillas[numeroJugadoresPlantillas].idPlantilla=usuarios[usuarioActual].plantillas[i-1].idPlantilla;
    jugadoresPlantillas=(jugadorPlantilla*)realloc(jugadoresPlantillas, numeroJugadoresPlantillas*sizeof(jugadoresPlantillas));
printf("AQUI %i\n", jugadores[j].id);
printf("AQUI %i\n", jugadoresPlantillas[numeroJugadoresPlantillas].idPlantilla);
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

void listarPlantillas(){

	int i;
	printf("La lista de plantillas es:\n");
	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		printf("-%i-%s-%i-%i-\n",usuarios[usuarioActual].plantillas[i].idPlantilla,usuarios[usuarioActual].plantillas[i].nombre, usuarios[usuarioActual].plantillas[i].presupuestoDisponible, usuarios[usuarioActual].plantillas[i].puntuacion);
	}

}
//void eliminarPlantillas();
//Precondicion:Debe tener cargado en memoria los datos de plantillas y de jugadores plantillas
//Pos
void eliminarPlantillas(){
	int i,j,k,select,found=0,plantillaActual;
	listarPlantillas();
	if(usuarios[usuarioActual].numeroPlantillas!=0){
		do{
			printf("Introduzca la id de la plantilla que quiere eliminar\n");
			scanf("%i",&select);
			for(i=0;i<usuarios[usuarioActual].numeroPlantillas&&found!=1;i++){
				if(select==usuarios[usuarioActual].plantillas[i].idPlantilla){
					plantillaActual=i;
					printf("Plantilladortest%i\n",plantillaActual);
					found=1;
					select=usuarios[usuarioActual].plantillas[i].idPlantilla;
					}
			}
			if(found==0){
				printf("Plantilla no encontrada\n");
			}
		}while(found==0);
		for(i=0;i<usuarios[usuarioActual].plantillas[plantillaActual].numJugadores;i++){
			found=0;
			for(j=0;j<numeroJugadoresPlantillas&&found!=1;j++){
				if(usuarios[usuarioActual].plantillas[plantillaActual].jugadores[i].id==jugadoresPlantillas[j].idJugador&&usuarios[usuarioActual].plantillas[plantillaActual].idPlantilla==jugadoresPlantillas[j].idPlantilla){
					found=1;
					for(k=j;k<numeroJugadoresPlantillas;k++){
						jugadoresPlantillas[k].idPlantilla=jugadoresPlantillas[k+1].idPlantilla;
						jugadoresPlantillas[k].idJugador=jugadoresPlantillas[k+1].idJugador;
					}
				numeroJugadoresPlantillas--;
				jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
        			if(jugadoresPlantillas==NULL){
        			printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        			}
				}
			}
		}
			for(k=0;k<numeroJugadoresPlantillas;k++){
				if(select<jugadoresPlantillas[k].idPlantilla){
					jugadoresPlantillas[k].idPlantilla--;
				}
			}
		if(usuarios[usuarioActual].numeroPlantillas>1){
			for(i=plantillaActual;i<usuarios[usuarioActual].numeroPlantillas-1;i++){
				usuarios[usuarioActual].plantillas[i].numJugadores=usuarios[usuarioActual].plantillas[i+1].numJugadores;
				if(usuarios[usuarioActual].plantillas[i].numJugadores!=0){
					usuarios[usuarioActual].plantillas[i].jugadores= (jugador*) realloc (usuarios[usuarioActual].plantillas[i].jugadores,usuarios[usuarioActual].plantillas[i].numJugadores*sizeof(jugador));
        				if(usuarios[usuarioActual].plantillas[plantillaActual].jugadores==NULL){
        				printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        				}
				}
				else{
					usuarios[usuarioActual].plantillas[i].jugadores= (jugador*) realloc (usuarios[usuarioActual].plantillas[i].jugadores,1*sizeof(jugador));
        				if(usuarios[usuarioActual].plantillas[plantillaActual].jugadores==NULL){
        				printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
					}
				}	
				for(k=0;k<usuarios[usuarioActual].plantillas[i].numJugadores;k++){
					usuarios[usuarioActual].plantillas[i].jugadores[k].id=usuarios[usuarioActual].plantillas[i+1].jugadores[k].id;
					usuarios[usuarioActual].plantillas[i].jugadores[k].equipo=usuarios[usuarioActual].plantillas[i+1].jugadores[k].equipo;
					usuarios[usuarioActual].plantillas[i].jugadores[k].precio=usuarios[usuarioActual].plantillas[i+1].jugadores[k].precio;
					usuarios[usuarioActual].plantillas[i].jugadores[k].valoracion=usuarios[usuarioActual].plantillas[i+1].jugadores[k].valoracion;
					strcpy(usuarios[usuarioActual].plantillas[i].jugadores[k].nombre,usuarios[usuarioActual].plantillas[i+1].jugadores[k].nombre);
					}
				usuarios[usuarioActual].plantillas[i].presupuestoDisponible=usuarios[usuarioActual].plantillas[i+1].presupuestoDisponible;
				usuarios[usuarioActual].plantillas[i].puntuacion=usuarios[usuarioActual].plantillas[i+1].puntuacion;
				strcpy(usuarios[usuarioActual].plantillas[i].nombre,usuarios[usuarioActual].plantillas[i+1].nombre);
			}
			usuarios[usuarioActual].numeroPlantillas--;
			numeroPlantillas--;
			usuarios[usuarioActual].plantillas= (plantilla*) realloc (usuarios[usuarioActual].plantillas,usuarios[usuarioActual].numeroPlantillas*sizeof(plantilla));
        		if(usuarios[usuarioActual].plantillas==NULL){
        			printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        		}
		}
		else{
			usuarios[usuarioActual].numeroPlantillas--;
		}
	}
	else{
		printf("No hay plantillas que eliminar");
	}
}
//void ranking();
//Precondicion:Debe tener cargado los datos de usuarios, y por lo tanto sus plantillas, en memoria
//Poscondicion: 

void ranking(){
	int i, aux, aux2, aux3, Pos1,Pos2,Pos3, k=0;
	printf("Las plantillas con mayor puntuacion son:\n");
    aux=usuarios[usuarioActual].plantillas[k].puntuacion;
    Pos1=k;
	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		if (aux<usuarios[usuarioActual].plantillas[i].puntuacion){
            aux=usuarios[usuarioActual].plantillas[i].puntuacion;
            Pos1=i;
        }
        
	}

     aux2=usuarios[usuarioActual].plantillas[k].puntuacion; 
    Pos2=k;
    if(k==Pos1){
        k++;
       aux2=usuarios[usuarioActual].plantillas[k].puntuacion;
        Pos2=k; 
    }
	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		if (aux2<usuarios[usuarioActual].plantillas[i].puntuacion && Pos1!=i){
            aux=usuarios[usuarioActual].plantillas[i].puntuacion;
            Pos2=i;
        }
        
	}
      aux3=usuarios[usuarioActual].plantillas[k].puntuacion; 
    Pos3=k;
     printf("%i\n", Pos3); 
    if(k==Pos2){
       k++;
        printf("%i\n", k); 
       aux3=usuarios[usuarioActual].plantillas[k].puntuacion;
        Pos3=k;
        printf("%i\n", Pos3); 
    }
      if(k==Pos1){
        k++;
        printf("%i\n", k);
       aux3=usuarios[usuarioActual].plantillas[k].puntuacion;
        Pos3=k; 
        printf("%i\n", Pos3);
    }
    	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		if (aux3<usuarios[usuarioActual].plantillas[i].puntuacion && Pos1!=i && Pos2!=i){
            aux3=usuarios[usuarioActual].plantillas[i].puntuacion;
            Pos3=i;
        }
        
	}



    printf("-%i-%s-%i-%i-\n",usuarios[usuarioActual].plantillas[Pos1].idPlantilla,usuarios[usuarioActual].plantillas[Pos1].nombre, usuarios[usuarioActual].plantillas[Pos1].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos1].puntuacion);
    printf("-%i-%s-%i-%i-\n",usuarios[usuarioActual].plantillas[Pos2].idPlantilla,usuarios[usuarioActual].plantillas[Pos2].nombre, usuarios[usuarioActual].plantillas[Pos2].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos2].puntuacion);
    printf("-%i-%s-%i-%i-\n",usuarios[usuarioActual].plantillas[Pos3].idPlantilla,usuarios[usuarioActual].plantillas[Pos3].nombre, usuarios[usuarioActual].plantillas[Pos3].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos3].puntuacion);

}




