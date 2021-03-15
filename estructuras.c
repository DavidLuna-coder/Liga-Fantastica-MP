#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    int equipo;
    char nombre [20];
    int precio;
    int valoracion;
}jugador;


typedef struct {
    int id;
    char nombre[20];
    jugador jugadores[5];
}equipo;

typedef struct{
    int presupuesto;
    int maxPlantillas;
    int maxJugadores;
}configuracion;

typedef struct{
    int idJugador;
    int idPlantilla;
}jugadorPlantilla;

typedef struct{
    int id;
    char nombre[30];
    int presupuestoDisponible;
    int puntuacion;
    jugadorPlantilla *jugadores;
}plantilla;



typedef struct{
    char nombre[20];
    int id;
    char tipoPerfil[10];
    char perfil [5];
    char contrasena [8]; 
    plantilla *plantillas;
}usuario;


void cargarEquipos(equipo *);
void cargarJugadores(jugador *);
void vaciar (char *);
void copiar (char*, int t);
int recorrerFichero (FILE *,char*);

int main(){
    equipo *equipos;
    jugador *jugadores;
    cargarEquipos (equipos);
    printf ("CARGADO EQUIPOS \n");
    cargarJugadores (jugadores);
    printf ("JUGADORES CARGADOS \n");
    return 0;
}



//Carga los datos del fichero equipos.txt en la estructura equipo
void cargarEquipos(equipo *equipos){
    FILE *f;
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int cont = 0;
    f = fopen("equipos.txt","r");
    if(f == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 

    while (!feof(f)) //Cuenta las líneas del fichero
    {
        fgets(temporal,50,f);
        cont++;
    }
    rewind(f); //Rebobina el fichero
   // Reservamos memoria del vector de estructuras en funcion de las filas
    equipos = (equipo *)malloc(cont*sizeof(equipo));
    if (equipos == NULL){
        printf("Error en la reserva de memoria en la carga de equipos\n");
        exit(1);
    }
    
    //Recorre todo el fichero
   for(int i=0; !feof(f) ;i++){
       vaciar(temporal);
        aux = '0';
        for (int j = 0; aux!= '-'&& !feof(f);j++){ //Cuando encuentra un guión  almacena el texto previo de la linea en temporal
            aux = fgetc(f);
            if(aux!='-'){
                temporal[j]= aux;
            }
        }
         equipos[i].id = atoi(temporal);//Copiamos en la id de equipo la cadena guardada
        vaciar(temporal);
        aux = '0';

        //Cada vez que encuentra un salto de línea copia el texto anterior en temporal
        for (int k=0; aux !='\n'&&!feof(f); k++){
            aux = fgetc(f);
            if(aux != '\n'){
                temporal[k] = aux;
            }
        }
        //Copia el nombre en la estructura
        strcpy (equipos[i].nombre,temporal);
    }

    fclose(f);
}
//Carga los datos del fichero futbolista en la estructura jugadores.

void cargarJugadores (jugador *jugadores){
    FILE *FUTBOLISTAS;
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int cont = 0;
    int i,j;
    FUTBOLISTAS = fopen("Futbolistas.txt","r");
    if(FUTBOLISTAS == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 
    
    
    while (!feof(FUTBOLISTAS)) //Cuenta las líneas del fichero
    {
        fgets(temporal,50,FUTBOLISTAS);
        cont++;
    }
    rewind(FUTBOLISTAS); //Rebobina el fichero

   // Reservamos memoria del vector de estructuras en funcion de las filas
    jugadores = (jugador *)malloc(cont*sizeof(jugador));
    if (jugadores == NULL){
        printf("Error en la reserva de memoria en la carga de jugadores\n");
        exit(1);
    }
    
    //Recorre todo el fichero
   for(i=0;!feof(FUTBOLISTAS) ;i++){
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

// Vacia la cadena de caracteres donde se almacenaremos los datos antes te volcarlos en la estructura
void vaciar (char temp[]){
    for ( int i = 0; i < 50; i++)
    {
        temp[i]='\0';
    }

}


