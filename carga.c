#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carga.h"

int contadorLineas(FILE *FICHERO);
void cargarEquipos();
void cargarJugadores();
void cargarConfiguracion();
void cargarUsuarios();
void cargarPlantillas();
void cargarJugadorPlantilla();
//Carga los datos del fichero equipos.txt en la estructura equipo
//Cabecera: void cargarEquipos()
//Precondición: Existe fichero Jugadores.txt
//Postcondición: Carga los jugadores en la estructura jugadores
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
            if(aux != '\n'&& !feof(EQUIPOS)){
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

//Cabecera: void cargarJugadores()
//Precondición: Existe fichero Jugadores.txt
//Postcondición: Carga los jugadores en la estructura jugadores

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
            if(aux != '\n'&&!feof(FUTBOLISTAS)){
                temporal[j] = aux;
            }
        }
        jugadores[i].valoracion = atoi(temporal);
        vaciar (temporal);

    }
    fclose(FUTBOLISTAS);
}

//Cabecera: void cargarConfiguración()
//Precondición: Existe fichero Configuracion.txt
//Postcondición: Carga la configuración en la estructura config

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

//Cabecera: void cargarUsuarios()
//Precondición: Existe fichero Usuarios.txt
//Postcondición: Carga la configuración en la estructura usuarios

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
            if(aux != '\n'&&!feof(USUARIOS)){
                temp[j]=aux;
            }
        }
        strcpy(usuarios[i].contrasena,temp);
        vaciar (temp);  
    }

    fclose(USUARIOS);
}

//Cabecera: void cargarPlantillas()
//Precondición: Existe fichero Plantillas.txt
//Postcondición: Carga la configuración en la estructura plantillas dentro de la estructura usuarios

void cargarPlantillas(){
    char temp[50];
    char aux;
    int i,j,k,l,id;

    PLANTILLAS = fopen("Plantillas.txt","r");

    if(PLANTILLAS == NULL){
        printf ("Error al cargar las plantillas\n");
        exit(1);
    }
    numeroPlantillas = contadorLineas(PLANTILLAS);
    rewind(PLANTILLAS);
    printf("%iNUNM",numeroPlantillas);
    
    for(i=0; i<numeroUsuarios;i++){
        usuarios[i].numeroPlantillas = 0;
        usuarios[i].plantillas = (plantilla*)malloc(1*sizeof(plantilla));
        if(usuarios[i].plantillas==NULL){
            printf("ERROR\n");
        }
	}
    if(numeroPlantillas!=0){
    for(j=0;!feof(PLANTILLAS);j++){
        vaciar(temp);
        aux = '0';
        for ( k = 0; aux != '-' && !feof(PLANTILLAS); k++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[k]=aux;
            }
        }
	id=atoi(temp);
        usuarios[id].plantillas[j].idUsuario = atoi(temp);
        vaciar(temp);
        aux = '0';

        for ( k = 0; aux != '-' && !feof(PLANTILLAS); k++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[k]=aux;
            }
        }
        usuarios[id].plantillas[j].idPlantilla = atoi(temp);
        vaciar(temp);
        aux = '0';
        
        for ( k = 0; aux != '-' && !feof(PLANTILLAS); k++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[k]=aux;
            }
        }
        strcpy(usuarios[id].plantillas[j].nombre,temp);
        vaciar(temp);
        aux = '0';

        for ( k = 0; aux != '-' && !feof(PLANTILLAS); k++){
            aux = fgetc(PLANTILLAS);
            if(aux!='-'){
                temp[k]=aux;
            }
        }
        usuarios[id].plantillas[j].presupuestoDisponible = atoi(temp);
        vaciar(temp);
        aux = '0';

        for ( k = 0; aux != '\n' && !feof(PLANTILLAS); k++){
            aux = fgetc(PLANTILLAS);
            if(aux!='\n'&& !feof(PLANTILLAS)){
                temp[k]=aux;
            }
        }
        usuarios[id].plantillas[j].puntuacion = atoi(temp);
        vaciar(temp);
        aux = '0';
        usuarios[id].numeroPlantillas++;
        usuarios[id].plantillas = (plantilla*)realloc(usuarios[id].plantillas,(usuarios[id].numeroPlantillas+1)*sizeof(plantilla));
        
        }
}
    fclose(PLANTILLAS);
    
  
    for ( i = 0; i < numeroUsuarios; i++){
        for(j=0;j<usuarios[i].numeroPlantillas;j++){
        
        usuarios[i].plantillas[j].numJugadores = 0;
        
        usuarios[i].plantillas[j].jugadores = (jugador*)malloc(1*sizeof(jugador));
        if(usuarios[i].plantillas[j].jugadores==NULL){
             printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
            }
        
        for ( k = 0; k < numeroJugadoresPlantillas; k++){
            
            if(jugadoresPlantillas[k].idPlantilla == usuarios[i].plantillas[j].idPlantilla){
                for ( l = 0; l < numeroJugadores; l++)
                {
                    if(jugadoresPlantillas[k].idJugador == jugadores[l].id){
    
                        usuarios[i].plantillas[j].jugadores[usuarios[i].plantillas[j].numJugadores].id = jugadores[l].id;
                        usuarios[i].plantillas[j].jugadores[usuarios[i].plantillas[j].numJugadores].equipo = jugadores[l].equipo;
                        usuarios[i].plantillas[j].jugadores[usuarios[i].plantillas[j].numJugadores].precio = jugadores[l].precio;
                        usuarios[i].plantillas[j].jugadores[usuarios[i].plantillas[j].numJugadores].valoracion = jugadores[l].valoracion;
                        strcpy(usuarios[i].plantillas[j].jugadores[usuarios[i].plantillas[j].numJugadores].nombre,jugadores[l].nombre);
                        usuarios[i].plantillas[j].numJugadores ++;
                        usuarios[i].plantillas[j].jugadores = (jugador*)realloc(usuarios[i].plantillas[j].jugadores,(usuarios[i].plantillas[j].numJugadores + 1)*sizeof(jugador));
                        if(usuarios[i].plantillas[j].jugadores==NULL){
                        printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
                        }
                    }    
                }
            }
        }
        }
    }
}

//Cabecera: void cargarJugadorPlantilla()
//Precondición: Existe fichero Jugadores_Plantilals.txt
//Postcondición: Carga la configuración en la estructura jugadorPlantillas

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
            if(aux != '\n'&&!feof(JUGADORESPLANTILLAS)){
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

//Cabecera: void vaciar(char *)
//Precondición: char[N] && N<=50
//Postcondición: Carga la configuración en la estructura usuarios

void vaciar (char temp[]){
    for ( int i = 0; i < 50; i++)
    {
        temp[i]='\0'; //Recorre la cadena y la vacia
    }

}

//Cabecera: int contadorLineas(FILE *)
//Precondición: Existe un fichero
//Postcondición: Cuentas las lineas del fichero, devuelve contador

int contadorLineas(FILE *FICHERO){
	int contador=0;
	char temp[50],c;
    rewind(FICHERO);
    	c=fgetc(FICHERO);
	while(!feof(FICHERO)){
		fgets(temp,50,FICHERO);
		contador++;
    		c=fgetc(FICHERO);

	}
	return contador;
}


//Cabecera: void cargar()
//Precondicion:
//Postcondicion: Carga todos los ficheros en estructuras
void cargar(){
    cargarConfiguracion();
    cargarJugadores();
    cargarEquipos();
    cargarJugadorPlantilla();
    cargarUsuarios();
    cargarPlantillas();
}