#include <stdio.h>
#include <stdlib.h>

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
    int numeroPlantillas;
    plantilla *plantillas;
}usuario;

int numeroEquipos;
int numeroJugadores;
configuracion config;
equipo *equipos;
jugador *jugadores;
FILE *EQUIPOS;
FILE *FUTBOLISTAS;
FILE *CONFIGURACION;

void cargarEquipos();
void cargarJugadores ();
void cargarConfiguracion();
void vaciar (char *);
int contadorLineas(FILE *);

#endif