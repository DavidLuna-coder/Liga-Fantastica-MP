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
    char nombre[21];
    int id;
    char tipoPerfil[15];
    char perfil [6];
    char contrasena [9];
}usuario;

typedef struct{
    int id;
    char nombre[30];
    int presupuestoDisponible;
    int puntuacion;
    jugadorPlantilla *jugadores;
    usuario usuarios;
}plantilla;




int numeroEquipos;
int numeroJugadores;
int numeroUsuarios;
configuracion config;
equipo *equipos;
jugador *jugadores;
usuario *usuarios;
FILE *EQUIPOS;
FILE *FUTBOLISTAS;
FILE *CONFIGURACION;
FILE *USUARIOS;

void cargarEquipos();
void cargarJugadores ();
void cargarConfiguracion();
void cargarUsuarios();
void vaciar (char *);
int contadorLineas(FILE *);

#endif