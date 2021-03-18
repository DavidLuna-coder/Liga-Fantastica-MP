#ifndef _Carga
#define _Carga

typedef struct {
    int id;
    int equipo;
    char nombre [20];
    int precio;
    int valoracion;
}jugador;


typedef struct equipo {
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

equipo *equipos;
jugador *jugadores;
FILE *EQUIPOS;
FILE *FUTBOLISTAS;

void cargarEquipos(equipo *);
void cargarJugadores(jugador *);
void vaciar (char *);
int contadorLineas(FILE *);

#endif