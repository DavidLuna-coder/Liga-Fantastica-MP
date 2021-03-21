#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carga.h"

//Carga los datos del fichero equipos.txt en la estructura equipo
void cargarEquipos(){
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int i,j,k;
    EQUIPOS = fopen("Equipos.txt","r");
    if(EQUIPOS == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 
    numeroEquipos = contadorLineas(EQUIPOS);
    rewind (EQUIPOS);
    equipos = (equipo*)malloc(numeroEquipos*(sizeof(equipo)));
   for(i=0; !feof(EQUIPOS) ;i++){
       vaciar(temporal);
        aux = '0';
        for ( j = 0; aux!= '-'&& !feof(EQUIPOS);j++){ //Cuando encuentra un guión  almacena el texto previo de la linea en temporal
            aux = fgetc(EQUIPOS);
            if(aux!='-'){
                temporal[j]= aux;
            }
        }
         equipos[i].id = atoi(temporal);//Copiamos en la id de equipo la cadena guardada
        vaciar(temporal);
        aux = '0';

        //Cada vez que encuentra un salto de línea copia el texto anterior en temporal
        for ( j=0; aux !='\n'&&!feof(EQUIPOS); j++){
            aux = fgetc(EQUIPOS);
            if(aux != '\n'){
                temporal[j] = aux;
            }
        }
        //Copia el nombre en la estructura
        strcpy (equipos[i].nombre,temporal);

        
    }
    

    for(i = 0; i<=numeroEquipos;i++){
        k = 0;
        
        for (j=0; j<= numeroJugadores && k<5;j++){
            if(equipos[i].id == jugadores[j].equipo){
                equipos[i].jugadores[k].id = jugadores[j].id;
                strcpy(equipos[i].jugadores[k].nombre,jugadores[j].nombre);
                k++;
            }
            
        }

    }
    fclose(EQUIPOS);
    

}
//Carga los datos del fichero futbolista en la estructura jugadores.

void cargarJugadores (){
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int i,j;

    FUTBOLISTAS = fopen("Futbolistas.txt","r");
    if(FUTBOLISTAS == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 

    numeroJugadores = contadorLineas(FUTBOLISTAS);
    jugadores = (jugador *)malloc(numeroJugadores*sizeof(jugador));
    rewind (FUTBOLISTAS);
    for(i=0;!feof(FUTBOLISTAS);i++){
        vaciar(temporal);
        aux = '0';
        for (j = 0; aux!= '-'&& !feof(FUTBOLISTAS);j++){ //Cuando encuentra un guión  almacena el texto previo de la linea en temporal
            aux = fgetc(FUTBOLISTAS);
            if(aux!='-'){
                temporal[j]= aux;
            }
        }
        jugadores[i].id = atoi(temporal);//Copiamos en la id de equipo la cadena guardada
        vaciar(temporal);
        aux = '0';
        
        //Cada vez que encuentra un salto de línea copia el texto anterior en temporal
        for (j=0; aux !='-'&&!feof(FUTBOLISTAS); j++){
            aux = fgetc(FUTBOLISTAS);
            if(aux != '-'){
                temporal[j] = aux;
            }
        }
        jugadores[i].equipo = atoi(temporal);

        vaciar(temporal);
        aux = '0';

        for(j=0;aux!='-'&& !feof(FUTBOLISTAS);j++){
            aux = fgetc(FUTBOLISTAS);

            if (aux!= '-'){
                temporal[j]=aux;
            }
        }
        strcpy (jugadores[i].nombre,temporal);
        vaciar (temporal);
        aux = '0';

        for (j=0;aux!='-' && !feof(FUTBOLISTAS);j++){
            aux = fgetc(FUTBOLISTAS);
            if (aux!= '-'){
                temporal[j]=aux;
            }
        }

        jugadores[i].precio = atoi(temporal);
        vaciar(temporal);
        
        aux = '0';
        for(j=0; aux != '\n' && !feof(FUTBOLISTAS);j++){
            aux = fgetc(FUTBOLISTAS);
            if(aux != '\n'){
                temporal[j] = aux;
            }
        }
        jugadores[i].valoracion = atoi(temporal);
        vaciar (temporal);

    }
    fclose(FUTBOLISTAS);
}

void cargarConfiguracion(){
    char temp[50];
    int i;
    int j;
    int aux;
    CONFIGURACION = fopen("Configuracion.txt", "r");
    if (CONFIGURACION == NULL){
        printf("Error al cargar la configuración.\n");
        exit(1);
    }

    for (i=0; !feof(CONFIGURACION);i++){
        vaciar(temp);
        for (j=0;aux != '-'&& !feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
        };

        for (j=0;aux != '\n'&&!feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
            if (aux!='\n')
            temp[j]=aux;
        }
        config.maxPlantillas= atoi(temp);
        vaciar(temp);

        for (j=0;aux != '-'&& !feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
        };

        for (j=0;aux != '\n'&&!feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
            if (aux!='\n')
            temp[j]=aux;
        }
        config.presupuesto= atoi(temp);
        vaciar(temp);

        for (j=0;aux != '-'&& !feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
        };

        for (j=0;aux != '\n'&&!feof(CONFIGURACION);j++){
            aux = fgetc(CONFIGURACION);
            if (aux!='\n')
            temp[j]=aux;
        }
        config.maxJugadores= atoi(temp);
        vaciar(temp);
    }
    fclose(CONFIGURACION);
}
// Vacia la cadena de caracteres donde se almacenaremos los datos antes te volcarlos en la estructura
void vaciar (char temp[]){
    for ( int i = 0; i < 50; i++)
    {
        temp[i]='\0';
    }

}

int contadorLineas(FILE *FICHERO){
	int contador=0;
	char temp[50];
	while(!feof(FICHERO)){
		fgets(temp,50,FICHERO);
		contador++;
	}
	return contador;
}