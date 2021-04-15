#include <stdio.h>
#include <stdlib.h>

#ifndef _Carga
#define _Carga

typedef struct {
    int id;
    int equipo;
    char nombre [21];
    int precio;
    int valoracion;
}jugador;


typedef struct equipo {
    int id;
    char nombre[21];
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
    int idUsuario;
    int idPlantilla;
    char nombre[30];
    int presupuestoDisponible;
    int puntuacion;
    int numJugadores;
    jugador *jugadores;
}plantilla;

typedef struct{
    char nombre[21];
    int id;
    char tipoPerfil[15];
    char perfil [6];
    char contrasena [9];
    int numeroPlantillas;
    plantilla *plantillas;
}usuario;


int numeroEquipos;
int numeroJugadores;
int numeroUsuarios;
int numeroPlantillas;
int numeroJugadoresPlantillas;

configuracion config;
equipo *equipos;
jugador *jugadores;
usuario *usuarios;
jugadorPlantilla *jugadoresPlantillas;

FILE *EQUIPOS;
FILE *FUTBOLISTAS;
FILE *CONFIGURACION;
FILE *USUARIOS;
FILE *PLANTILLAS;
FILE *JUGADORESPLANTILLAS;

void cargarEquipos();
void cargarJugadores();
void cargarConfiguracion();
void cargarUsuarios();
void cargarPlantillas();
void cargarJugadorPlantilla();
void vaciar (char *);

#endif