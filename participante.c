#include <stdio.h>
#include <stdlib.h>
#include "Cronista.h"
#include <string.h>
#include "participante.h"
#include "carga.h"
#include "_Usuarios.h"

void Cplantilla();
void configu();
void addJug();
void remoJug();
void listarPlantillas();
void eliminarPlantillas();
void ranking();
void listaJugadoresplantillas();
void listaJugadoresdisponibles();
//Cabecera: void participantes()
//Precondición: 
//Postcondición:
void participantes(){
    int selec; //Variable que actúa como selector en el menú
    do{
        printf("1-Crear plantillas\n");
        printf("2-Configurar plantilla\n");
        printf("3-Listado de las plantillas\n");
        printf("4-Eliminar plantillas\n");
        printf("5-Ranking \n");
        printf("6-Salir de la sesion\n");

        scanf("%i",&selec);
        fflush(stdin);
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
         printf("Saliendo de la sesion...\n");
            break;
        
        default:
            printf("Introduce un numero valido [1,2,3,4 o 5]: \n");
            break;
        }




    }while(selec!=6);

}

//Cabecera: void Cplantilla()
//Precondicición:
//Postcondición: Nº plantillas + 1, se añade una nueva plantilla
void Cplantilla(){
int i,j,found,selec; //
char plant[30],aux;
if(usuarios[usuarioActual].numeroPlantillas<config.maxPlantillas){ //Comprueba si se ha alcanzado el máximo de plantillas
printf("\nIntroduce nombre para la plantilla: ");

do{
    found =1;
fflush(stdin);
fflush(stdin);
fgets(plant,30,stdin);
plant[strlen(plant)-1]='\0';
for(i=0;i<usuarios[usuarioActual].numeroPlantillas && found!=0;i++){ //Comprueba si el nombre de la plantilla ya existe
    found = strcmp(usuarios[usuarioActual].plantillas[i].nombre,plant);
    printf("%i\n",found);
    if(found==0){
        printf("\nEl nombre de esta plantilla ya existe");
        printf("\nPor favor vuelva a introducir otro nombre: ");
    }
}
}while(found==0);

usuarios[usuarioActual].numeroPlantillas++; // Aumenta el numero de Plantillas en 1
numeroPlantillas++;
usuarios[usuarioActual].plantillas = (plantilla*)realloc(usuarios[usuarioActual].plantillas,(usuarios[usuarioActual].numeroPlantillas)*sizeof(plantilla)); //Se reasigna el tamaño de la estructura dentro de usuarios

    if(usuarios[usuarioActual].plantillas==NULL){
        printf("Error en la reserva de memoria de la plantilla\n");
        }
        else{ //Se introducen todos los datos correspondientes a la nueva estructura
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idPlantilla=numeroPlantillas;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].idUsuario=usuarios[usuarioActual].id;
strcpy(usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].nombre,plant);
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].presupuestoDisponible=config.presupuesto;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].numJugadores=0;
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].puntuacion=0;
  printf("\nPresupuesto disponible: %i $",usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].presupuestoDisponible);
    printf("\n----------------------------------------\n");
usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].jugadores = (jugador*)malloc(1*sizeof(jugador));
                if(usuarios[usuarioActual].plantillas[usuarios[usuarioActual].numeroPlantillas-1].jugadores==NULL){
                    printf("Error en la carga de usuarios al registrarse\n");
                    exit(1);
                }
}
}else 
printf ("Has alcanzado el maximo de plantillas disponibles.\n"); //Imprime esto en caso de superar el numero de plantillas máximas
}
//Cabecera: void configu()
//Precondicion:
//Postcondicion:
//Permite cambiar la configuración de la plantilla
void configu(){

int selec;
do
{
   //Menú de configuración de la plantilla
    printf("\n Que desea hacer?");
    printf("\n 1-Listar los jugadores plantilla");
    printf("\n 2-Listar los jugadores disponibles");
    printf("\n 3-Anadir jugador");
    printf("\n 4-Eliminar jugador");
    printf("\n 5-Salir de la plantilla ");

    scanf("%i",&selec);
    fflush(stdin);
    switch (selec)
    {
    case 1:
        listaJugadoresplantillas();
        break;
    
    case 2:
        listaJugadoresdisponibles();
        break;
    case 3:
        addJug();
        break;
    
    case 4:
        remoJug();
        break;

    case 5:
        printf("Saliendo de la plantilla...\n");
        break;

    default:
        printf("introduce un numero valido [1,2,3 o 4]: \n");
        break;
    }
} while (selec=!1);

}

//cabecera: void addJug()
//precondicion:
//Postcondición: numeroJugadores ++

//Añade un jugadore a la plantilla deseada
void addJug(){
    int i,IDt,jugPlant,j,found, found2,pres; 

do
{
    
    listarPlantillas();
    printf("\nIntroduce el numero de la plantilla: "); 
    fflush(stdin);
    scanf("%i",&i); //Almacena la posicion de memoria de la plantilla
    if(usuarios[usuarioActual].plantillas[i-1].numJugadores<config.maxJugadores){
    
   
    fflush(stdin);
    printf("\nIntroduce la ID del jugador a anadir: ");
    scanf("%i",&IDt); //IDt: id temporal para encontrar al jugador si ya esta en la plantilla,almacena la id del jugador
 pres=0;
 found =0;
 for(jugPlant=0;jugPlant<usuarios[usuarioActual].plantillas[i-1].numJugadores && found==0 ;jugPlant++){ //Comprueba que el jugador no esté en la plantilla
     if(IDt==usuarios[usuarioActual].plantillas[i-1].jugadores[jugPlant].id)
        {
         printf("Este jugador ya esta en la plantilla");
         found =1;
        }
 }
    


found2=0;
 for(j=0;j<numeroJugadores && found2==0 ;j++){ //Comprueba que exista un jugador con dicha id
     if(IDt==jugadores[j].id)
        {
         found2 =1;
        }
}

    j--;
    if(found2!=1){
        printf("No existe jugador con dicha ID");
    }

    if(usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible<jugadores[IDt].precio){ //Comprueba que la plantilla tenga suficiente dinero para el fichaje
    printf("\nImposible añadir al jugador, el presupuesto no alcanza PRECIO %i TIENES %i, eres %i,%i\n",jugadores[IDt].precio,usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible,usuarioActual,i-1);
    
    pres=1;
    }
   
    }
    
}while(pres==1 || found2==0 || found==1 && usuarios[usuarioActual].plantillas[i-1].numJugadores<config.maxJugadores);
if(usuarios[usuarioActual].plantillas[i-1].numJugadores<config.maxJugadores){

printf("\nAnadiendo al jugador...");

    usuarios[usuarioActual].plantillas[i-1].numJugadores ++; //Añade 1 al numero de jugadores total
    usuarios[usuarioActual].plantillas[i-1].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i-1].jugadores,(usuarios[usuarioActual].plantillas[i-1].numJugadores + 1)*sizeof(jugador)); //Aumenta el tamaño de la estructura de jugadores
   
        if(usuarios[usuarioActual].plantillas[i-1].jugadores==NULL){
        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        exit(1);
        }
        else //Almacena los datos de los jugadores correspondientes en las estructuras
        {
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].id = jugadores[IDt].id;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].equipo = jugadores[IDt].equipo;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].precio = jugadores[IDt].precio;
         usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].valoracion = jugadores[IDt].valoracion;
         strcpy(usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].nombre,jugadores[IDt].nombre);
            printf("\nJugador anadido con exito a la plantilla\n");
            printf("%s\n",usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].nombre);
            
        }
 
   
    //Vuelca los datos en la estructura jugadoresPlantillas   
    usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible = usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible - jugadores[j].precio;
    numeroJugadoresPlantillas++;
    jugadoresPlantillas=(jugadorPlantilla*)realloc(jugadoresPlantillas, numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
    if(jugadoresPlantillas==NULL){
        printf("ERROR");
        exit(1);
    }
    jugadoresPlantillas[numeroJugadoresPlantillas-1].idJugador=usuarios[usuarioActual].plantillas[i-1].jugadores[usuarios[usuarioActual].plantillas[i-1].numJugadores-1].id;
    jugadoresPlantillas[numeroJugadoresPlantillas-1].idPlantilla=usuarios[usuarioActual].plantillas[i-1].idPlantilla;
    
    
    } 
    else{
        printf("Numero maximo de jugadores por plantilla alcanzado\n");
    }
    valorarPlantillas();
}

//Cabecera: void remoJug()
//Precondicion: 
//Postcondicion:

//Elimina un jugador de las plantillas
void remoJug(){
    int idt,j,found,found2,k,i,l,m;
    listarPlantillas();
    printf("\nIntroduce el número de la plantilla: ");
    fflush(stdin);
    scanf("%i",&i); //Almacena la posición de memoria de la plantilla
    fflush(stdin);
    printf("\nIntroduce la id del jugador a eliminar: ");
    scanf("%i",&idt);// Almacena la id del jugador que va a ser eliminado
    found =0;
    for(j=0;j<usuarios[usuarioActual].plantillas[i-1].numJugadores && found==0;j++){//Localiza al jugador
        if(idt==usuarios[usuarioActual].plantillas[i-1].jugadores[j].id){
            found=1;
        }
    }
    j--;
    found2=0;
    for(l=0;l<numeroJugadoresPlantillas&&found2==0;l++){ //Localiza la plantilla
        if(usuarios[usuarioActual].plantillas[i-1].idPlantilla == jugadoresPlantillas[l].idPlantilla && usuarios[usuarioActual].plantillas[i-1].jugadores[j].id == jugadoresPlantillas[l].idJugador){
            found2=1;
            for(m=l;m<numeroJugadoresPlantillas;m++){
                jugadoresPlantillas[m].idJugador=jugadoresPlantillas[m+1].idJugador;
                jugadoresPlantillas[m].idPlantilla=jugadoresPlantillas[m+1].idPlantilla;
            }
            numeroJugadoresPlantillas--;
            if(numeroJugadoresPlantillas>0){
                jugadoresPlantillas=(jugadorPlantilla *)realloc(jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadoresPlantilla));
            } else
             jugadoresPlantillas=(jugadorPlantilla *)realloc(jugadoresPlantillas,1*sizeof(jugadoresPlantilla));

            if (jugadoresPlantillas==NULL)
            {
                printf("ERROR en la reasignacion de memoria de jugadoresPlantilla\n");
                exit(1);
            }
            
        }
    }

if(found==1){
    //Se reasignan los datos para poder eliminar a la plantilla.
    usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible = usuarios[usuarioActual].plantillas[i-1].presupuestoDisponible + usuarios[usuarioActual].plantillas[i-1].jugadores[j].precio;

  for(k=j;k<usuarios[usuarioActual].plantillas[i-1].numJugadores;k++){
    usuarios[usuarioActual].plantillas[i-1].jugadores[k].id = usuarios[usuarioActual].plantillas[i-1].jugadores[k+1].id;
    usuarios[usuarioActual].plantillas[i-1].jugadores[k].equipo = usuarios[usuarioActual].plantillas[i-1].jugadores[k+1].equipo;
    usuarios[usuarioActual].plantillas[i-1].jugadores[k].precio = usuarios[usuarioActual].plantillas[i-1].jugadores[k+1].precio;
    usuarios[usuarioActual].plantillas[i-1].jugadores[k].valoracion = usuarios[usuarioActual].plantillas[i-1].jugadores[k+1].valoracion;
    strcpy(usuarios[usuarioActual].plantillas[i-1].jugadores[k].nombre,(usuarios[usuarioActual].plantillas[i-1].jugadores[k+1].nombre));

  }
    //Se reduce el numero de jugadores y se reasigna su espacion de memoria.
    usuarios[usuarioActual].plantillas[i-1].numJugadores --;
    if (usuarios[usuarioActual].plantillas[i-1].numJugadores>0)
    {
        usuarios[usuarioActual].plantillas[i-1].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i-1].jugadores,(usuarios[usuarioActual].plantillas[i-1].numJugadores)*sizeof(jugador));
    }
    else {
    usuarios[usuarioActual].plantillas[i-1].jugadores = (jugador*)realloc(usuarios[usuarioActual].plantillas[i-1].jugadores,(1)*sizeof(jugador));
    }
    
        
        if(usuarios[usuarioActual].plantillas[i-1].jugadores==NULL){
        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
        exit(1);
        }
        else
        {
            printf("\nJugador eliminado con exito a la plantilla\n");
        }
    valorarPlantillas();
}else
    printf("Ese jugador no se encuentra en la plantilla\n");
}

//Cabecera: void listaJugadoresPlantillas
//Precondición: void listaJugadoresplantillas()
//Postcondicion:

//Imprime los jugadores que pertenecen a las plantillas junto a la plantilla correspondiente.
void listaJugadoresplantillas(){
int i, j;
for(i=0;i<usuarios[usuarioActual].numeroPlantillas ;i++){
    printf("%i-%s\n",usuarios[usuarioActual].plantillas[i].idPlantilla,usuarios[usuarioActual].plantillas[i].nombre);
    
    for(j=0;j<usuarios[usuarioActual].plantillas[i].numJugadores ;j++){
        printf("     %i-%s\n",usuarios[usuarioActual].plantillas[i].jugadores[j].id,usuarios[usuarioActual].plantillas[i].jugadores[j].nombre);

    }

}
}

//void listaJugadoresdisponibles
//Precondición:
//Postcondición:

//Lista los jugadores que cumplen los requisitos de presupuesto.
void listaJugadoresdisponibles(){
for(int i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
    printf("%i-%s\n",usuarios[usuarioActual].plantillas[i].idPlantilla,usuarios[usuarioActual].plantillas[i].nombre);
    for(int j=0;j<numeroJugadores;j++){
    if(jugadores[j].precio<=usuarios[usuarioActual].plantillas[i].presupuestoDisponible){
        printf("   %i-%s-%i\n",jugadores[j].id,jugadores[j].nombre,jugadores[j].precio);
    }

}
}
}


//Cabecera: listarPlantillas()
//Precondición:
//Postcondición

//Lista todas lasp las plantillas
void listarPlantillas(){

	int i;
	printf("La lista de plantillas es:\n");
	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		printf("%i-%s-%i-%i\n",i+1,usuarios[usuarioActual].plantillas[i].nombre, usuarios[usuarioActual].plantillas[i].presupuestoDisponible, usuarios[usuarioActual].plantillas[i].puntuacion);
	}

}
//void eliminarPlantillas();
//Precondicion:Debe tener cargado en memoria los datos de plantillas y de jugadores plantillas
//Postcondicion: Elimina una Plantilla

//Elimina una plantilla
void eliminarPlantillas(){
	int i,j,k,select,found=0,plantillaActual;
	listarPlantillas();
	if(usuarios[usuarioActual].numeroPlantillas!=0){
		do{
			printf("Introduzca la id de la plantilla que quiere eliminar\n");
			scanf("%i",&select); //Seleccioa la plantilla a borrar
			for(i=0;i<usuarios[usuarioActual].numeroPlantillas&&found!=1;i++){
				if(select==usuarios[usuarioActual].plantillas[i].idPlantilla){ //Busca la plantilla
					plantillaActual=i;
					found=1;
					select=usuarios[usuarioActual].plantillas[i].idPlantilla;
					}
			}
			if(found==0){
				printf("Plantilla no encontrada\n");
			}
		}while(found==0);
		for(i=0;i<usuarios[usuarioActual].plantillas[plantillaActual].numJugadores;i++){ //Si la encuentra reasigna los valores de las estructuras
			found=0;
			for(j=0;j<numeroJugadoresPlantillas&&found!=1;j++){
				if(usuarios[usuarioActual].plantillas[plantillaActual].jugadores[i].id==jugadoresPlantillas[j].idJugador&&usuarios[usuarioActual].plantillas[plantillaActual].idPlantilla==jugadoresPlantillas[j].idPlantilla){
					found=1;
					for(k=j;k<numeroJugadoresPlantillas;k++){
						jugadoresPlantillas[k].idPlantilla=jugadoresPlantillas[k+1].idPlantilla;
						jugadoresPlantillas[k].idJugador=jugadoresPlantillas[k+1].idJugador;
					}
                //Reduce el número de jugadores Plantillas y reasigna el tamaño del vector de estructuras
				numeroJugadoresPlantillas--;
                if(numeroJugadoresPlantillas>0)
				jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
                else 
				jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
                

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
            //Reasigna los datos de los numero de plantillas del usuario y reasigna su espacio de memoria
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
		printf("No hay plantillas que eliminar\n");
	}
}
//void ranking();
//Precondicion:Debe tener cargado los datos de usuarios, y por lo tanto sus plantillas, en memoria
//Poscondicion: 

//Imprime las 3 mejores plantillas del usuario.
void ranking(){
	int i, aux, aux2, aux3, Pos1,Pos2,Pos3, k=0;
	printf("Las plantillas con mayor puntuacion son:\n");
    aux=usuarios[usuarioActual].plantillas[k].puntuacion;
    Pos1=k;
    //Asigna la posición del vector según la puntuación
	for(i=0;i<usuarios[usuarioActual].numeroPlantillas;i++){
		if (aux<usuarios[usuarioActual].plantillas[i].puntuacion){
            aux=usuarios[usuarioActual].plantillas[i].puntuacion;
            Pos1=i;
        }
        
	}
    if (usuarios[usuarioActual].numeroPlantillas>=2){
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
    if (usuarios[usuarioActual].numeroPlantillas>=3){
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



    printf("1 %i-%s-%i-%i\n",usuarios[usuarioActual].plantillas[Pos1].idPlantilla,usuarios[usuarioActual].plantillas[Pos1].nombre, usuarios[usuarioActual].plantillas[Pos1].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos1].puntuacion);
    printf("2 %i-%s-%i-%i\n",usuarios[usuarioActual].plantillas[Pos2].idPlantilla,usuarios[usuarioActual].plantillas[Pos2].nombre, usuarios[usuarioActual].plantillas[Pos2].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos2].puntuacion);
    printf("3 %i-%s-%i-%i\n\n",usuarios[usuarioActual].plantillas[Pos3].idPlantilla,usuarios[usuarioActual].plantillas[Pos3].nombre, usuarios[usuarioActual].plantillas[Pos3].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos3].puntuacion);
    }else
   {
    printf("1 %i-%s-%i-%i\n",usuarios[usuarioActual].plantillas[Pos1].idPlantilla,usuarios[usuarioActual].plantillas[Pos1].nombre, usuarios[usuarioActual].plantillas[Pos1].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos1].puntuacion);
    printf("2 %i-%s-%i-%i\n\n",usuarios[usuarioActual].plantillas[Pos2].idPlantilla,usuarios[usuarioActual].plantillas[Pos2].nombre, usuarios[usuarioActual].plantillas[Pos2].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos2].puntuacion);
   }
    }
    else{
    printf("1 %i-%s-%i-%i\n\n",usuarios[usuarioActual].plantillas[Pos1].idPlantilla,usuarios[usuarioActual].plantillas[Pos1].nombre, usuarios[usuarioActual].plantillas[Pos1].presupuestoDisponible, usuarios[usuarioActual].plantillas[Pos1].puntuacion); 
    }  
}