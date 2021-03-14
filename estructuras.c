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
void vaciar (char *);
void copiar (char*, int t);

int main(){
	int pruebazo;
    equipo equipos[20];
    cargarEquipos (equipos);
    return 0;
}

void cargarEquipos(equipo equipos[]){
    FILE *f;
    char temporal[50];
    char aux;
    int cont = 0;
    f = fopen("equipos.txt","r");
    if(f == NULL){
    printf ("Ha ocurrido un error en la carga de equipos\n");
    exit(1);
    } 
    
    while (!feof(f))
    {
        fgets(temporal,50,f);
        cont++;
    }

    rewind(f);
   
   /* equipos = (equipo *)malloc(cont*sizeof(equipos));
    if (equipos == NULL){
        printf("Error en la reserva de memoria en la carga de equipos\n");
        exit(1);
    }*/
    
   for(int i=0; !feof(f) ;i++){
       vaciar(temporal);
        aux = '0';
        for (int j = 0; aux!= '-';j++){
            aux = fgetc(f);
            if(aux!='-'){
                temporal[j]= aux;
            }
        }
        equipos[i].id = atoi(temporal);
        vaciar(temporal);
        aux = '0';
        for (int k=0; aux !='\n'&&!feof(f); k++){
            aux = fgetc(f);
            if(aux != '\n'){
                temporal[k] = aux;
            }
        }
        strcpy (equipos[i].nombre,temporal);
        printf ("%i, %s\n",equipos[i].id, equipos[i].nombre);
    }

    fclose(f);
}


void vaciar (char temp[]){
    for ( int i = 0; i < 50; i++)
    {
        temp[i]='\0';
    }

}
