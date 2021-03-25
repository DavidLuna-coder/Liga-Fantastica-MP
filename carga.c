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
    char aux;
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

void cargarUsuarios(){
    char aux = '0';
    int i,j;
    char temp[50];

    USUARIOS = fopen("Usuarios.txt","r");
    if(USUARIOS == NULL){
        printf("Ha ocurrido un error en la carga de usuarios\n");
        exit(1);
    }
    
    numeroUsuarios = contadorLineas(USUARIOS);
    usuarios = (usuario *)malloc(numeroUsuarios*sizeof(usuario));
    if(usuarios == NULL){
        printf("Error en la reserva de memoria de usuarios\n");
        exit(1);
    }
    rewind(USUARIOS);

    for(i=0;!feof(USUARIOS);i++){
        vaciar(temp);

        for ( j = 0; aux != '-'&&!feof(USUARIOS); j++)
        {
            aux = fgetc(USUARIOS);
            if(aux != '-'){
                temp[j]=aux;
            }
        }
        usuarios[i].id = atoi(temp);
        aux = '0';
        vaciar(temp);
        for ( j = 0; aux != '-'&&!feof(USUARIOS); j++)
        {
            aux = fgetc(USUARIOS);
            if(aux != '-'){
                temp[j]=aux;
            }
        }
        strcpy(usuarios[i].nombre,temp);
        aux = '0';
        vaciar (temp);

        for ( j = 0; aux != '-'&&!feof(USUARIOS); j++)
        {
            aux = fgetc(USUARIOS);
            if(aux != '-'){
                temp[j]=aux;
            }
        }
        strcpy(usuarios[i].tipoPerfil,temp);
        aux = '0';
        vaciar (temp);

        for ( j = 0; aux != '-'&&!feof(USUARIOS); j++)
        {
            aux = fgetc(USUARIOS);
            if(aux != '-'){
                temp[j]=aux;
            }
        }
        strcpy(usuarios[i].perfil,temp);
        aux = '0';
        vaciar (temp);

        for ( j = 0; aux != '\n'&&!feof(USUARIOS); j++)
        {
            aux = fgetc(USUARIOS);
            if(aux != '\n'){
                temp[j]=aux;
            }
        }
        strcpy(usuarios[i].contrasena,temp);
        vaciar (temp);  
    }

    fclose(USUARIOS);
}

void cargarPlantillas(){
    char temp[50];
    char aux;
    int i,j,contador;

    PLANTILLAS = fopen("Plantillas.txt","r");

    if(PLANTILLAS == NULL){
        printf ("Error al cargar las plantillas\n");
        exit(1);
    }
    numeroPlantillas = contadorLineas(PLANTILLAS);

    plantillas = (plantilla *)malloc(numeroPlantillas * sizeof(plantillas)); 

    if(plantillas == NULL){
        printf ("Error en la reserva de memoria de plantillas\n");
        exit(1);
    }

    rewind(PLANTILLAS);

    for(i=0;!feof(PLANTILLAS);i++){
        vaciar(temp);
        aux = '0';

        for ( j = 0; aux != '-' && !feof(PLANTILLAS); j++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        plantillas[i].idUsuario = atoi(temp);
        vaciar(temp);
        aux = '0';

        for ( j = 0; aux != '-' && !feof(PLANTILLAS); j++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        plantillas[i].idPlantilla = atoi(temp);
        vaciar(temp);
        aux = '0';

        for ( j = 0; aux != '-' && !feof(PLANTILLAS); j++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        strcpy(plantillas[i].nombre,temp);
        vaciar(temp);
        aux = '0';

        for ( j = 0; aux != '-' && !feof(PLANTILLAS); j++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[j]=aux;
            }
        }
        plantillas[i].presupuestoDisponible = atoi(temp);
        vaciar(temp);
        aux = '0';

        for ( j = 0; aux != '\n' && !feof(PLANTILLAS); j++){
            aux = fgetc(PLANTILLAS);
            if(aux!='\n'){
                temp[j]=aux;
            }
        }
        plantillas[i].puntuacion = atoi(temp);
        vaciar(temp);
        aux = '0';
    }
    fclose(PLANTILLAS);

    
    for ( i = 0; i < numeroPlantillas; i++){
        plantillas[i].numJugadores = 0;
        plantillas[i].jugadores = (jugador*)malloc(1*sizeof(jugador));
        if(plantillas[i].jugadores==NULL){
             printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
            }
        for ( j = 0; j < numeroJugadoresPlantillas; j++){

            if(jugadoresPlantillas[j].idPlantilla == plantillas[i].idPlantilla){
                for (int k = 0; k < numeroJugadores; k++)
                {
                    if(jugadoresPlantillas[j].idJugador == jugadores[k].id){
    
                        plantillas[i].jugadores[plantillas[i].numJugadores].id = jugadores[k].id;
                        plantillas[i].jugadores[plantillas[i].numJugadores].equipo = jugadores[k].equipo;
                        plantillas[i].jugadores[plantillas[i].numJugadores].precio = jugadores[k].precio;
                        plantillas[i].jugadores[plantillas[i].numJugadores].valoracion = jugadores[k].valoracion;
                        strcpy(plantillas[i].jugadores[plantillas[i].numJugadores].nombre,jugadores[k].nombre);
                        plantillas[i].numJugadores ++;
                        plantillas[i].jugadores = (jugador*)realloc(plantillas[i].jugadores,(plantillas[i].numJugadores + 1)*sizeof(jugador));
                        if(plantillas[i].jugadores==NULL){
                        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
                        }
                    }    
                }
            }
        }
    }
}


void cargarJugadorPlantilla(){
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int i,j;

    JUGADORESPLANTILLAS = fopen("Jugadores_Plantillas.txt","r");

    if (JUGADORESPLANTILLAS==NULL){
        printf("Error al abrir el fichero de Jugadores_Plantillas.txt\n");
        exit (1);
    }
    numeroJugadoresPlantillas = contadorLineas(JUGADORESPLANTILLAS);

    jugadoresPlantillas = (jugadorPlantilla*)malloc(numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
    if(jugadoresPlantillas == NULL){
        printf("Error en la reserva de memoria\n");
    }

    rewind(JUGADORESPLANTILLAS);

    for (i=0; !feof(JUGADORESPLANTILLAS);i++){
        aux = '0';
        for(j=0; aux != '-' && !feof(JUGADORESPLANTILLAS); j++){
            aux = fgetc(JUGADORESPLANTILLAS);
            if(aux != '-'){
                temporal[j] = aux;
            }
        }
        jugadoresPlantillas[i].idJugador = atoi(temporal);
        aux = '0';
        vaciar(temporal);
        for(j=0; aux != '\n'&& !feof(JUGADORESPLANTILLAS); j++){
            aux = fgetc(JUGADORESPLANTILLAS);
            if(aux != '\n'){
                temporal[j] = aux;
            }
        }
        jugadoresPlantillas[i].idPlantilla = atoi(temporal);
        aux = '0';
        vaciar(temporal);
    }
    
    fclose(JUGADORESPLANTILLAS);

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
    rewind(FICHERO);
	while(!feof(FICHERO)){
		fgets(temp,50,FICHERO);
		contador++;

	}
	return contador;
}