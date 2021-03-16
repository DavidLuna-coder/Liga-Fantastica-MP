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


void cargarEquipos(FILE *,equipo *);
void cargarJugadores(FILE *,jugador *);
void vaciar (char *);
void copiar (char*, int t);
int contadorLineas(FILE *);
int recorrerFichero (FILE *,char*);//No se para que coño sirve esta funcion pero yo la dejo por si acaso ;D

int main(){
    int i,cont1,cont2;
    FILE *FUTBOLISTASs;
    FUTBOLISTASs=fopen("Futbolistas.txt","r");
    if(FUTBOLISTASs==NULL){
	    printf("No se pudo abrir");
	    exit (1);
    }
    FILE *ff;
    ff = fopen("equipos.txt","r");
    if(ff == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 
    equipo *equipos;
    jugador *jugadores;
    cont1=contadorLineas(ff);//Cuenta el numero de lineas del fichero equipos.txt
    rewind(ff); //Rebobina el fichero
   // Reservamos memoria del vector de estructuras en funcion de las filas
    equipos = (equipo *)malloc(cont1*sizeof(equipo));
    if (equipos == NULL){
        printf("Error en la reserva de memoria en la carga de equipos\n");
        exit(1);
    }
    cont2=contadorLineas(FUTBOLISTASs);//cuenta el numero de lineas del fichero futbolistas.txt
    jugadores = (jugador *)malloc(cont2*sizeof(jugador));//Reserva memoria para el vector dinamico respectivo a los datos de los jugadores
    rewind(FUTBOLISTASs); //Rebobina el fichero
    cargarEquipos (ff,equipos);
    printf ("CARGADO EQUIPOS \n");
    cargarJugadores (FUTBOLISTASs,jugadores);
    printf ("JUGADORES CARGADOS \n");
    printf("Lista:\n");//PREVIA DEL TEST
    for(i=0;i<cont2;i++){//IMPORTANTE!! Esto no es más que un test para comprobar que los datos estan bien cargados IMPORTANTE!!
	    printf("Jugador:%i-%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
    }
    for(i=0;i<cont1;i++){//IMPORTANTE!! Esto no es más que un test para comprobar que los datos esten bien cargados IMPORTANTE!!
	    printf("Equipos:%i-%s\n",equipos[i].id,equipos[i].nombre);
    }
    fclose(ff);
    fclose(FUTBOLISTASs);
    return 0;
}



//Carga los datos del fichero equipos.txt en la estructura equipo
void cargarEquipos(FILE *f,equipo *equipos){
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int cont = 0;

    
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
}
//Carga los datos del fichero futbolista en la estructura jugadores.

void cargarJugadores (FILE *FUTBOLISTAS,jugador *jugadores){
    char temporal[50]; // Cadena donde almacenaremos los datos que posteriormente copiaremos
    char aux;
    int cont = 0;
    int i,j;
										printf("TestJugadores");

    
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
