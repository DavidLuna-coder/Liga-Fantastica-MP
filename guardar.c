#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "guardar.h"

void guardarConfiguracion(){
    CONFIGURACION = fopen("Configuracion.txt","w");
    if(CONFIGURACION == NULL){
        printf("Error al abrir el fichero de configuracion");
        exit(1);
    }

    fprintf(CONFIGURACION,"nº_maximo_plantillas-%i\nPresupuesto_defecto-%i\nNº_maximo_jugadores_equipo-%i",config.maxPlantillas,config.presupuesto,config.maxJugadores);

    fclose(CONFIGURACION);
}

void guardarEquipos(){
    int i;
    EQUIPOS = fopen("Equipos.txt","w");
    if(EQUIPOS == NULL){
        printf("Error al guardar los equipos\n");
        exit(1);
    }
    for (i=0;i<numeroEquipos;i++){
        if(equipos[i].id<10&&i!=numeroEquipos-1){
        fprintf(EQUIPOS,"0%i-%s\n",equipos[i].id,equipos[i].nombre);
        }
        else if (i==numeroEquipos-1){
        fprintf(EQUIPOS,"%i-%s\0",equipos[i].id,equipos[i].nombre);
        }else
        fprintf(EQUIPOS,"%i-%s\n",equipos[i].id,equipos[i].nombre);
    }

    fclose(EQUIPOS);
}

void guardarFutbolistas(){
    int i;
    FUTBOLISTAS = fopen("Futbolistas.txt","w");
    if(FUTBOLISTAS == NULL){
        printf("Error al guardar los futbolistas\n");
        exit(1);
    }
    for (i=0;i<numeroJugadores;i++){
        if(jugadores[i].id<10&&i!=numeroJugadores-1){
            if(jugadores[i].equipo<10){
                fprintf(FUTBOLISTAS,"0%i-0%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            }else{
                fprintf(FUTBOLISTAS,"0%i-%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            }
    }   else if(i==numeroJugadores-1){
        fprintf(FUTBOLISTAS,"0%i-%i-%s-%i-%i",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
    }   else if(jugadores[i].equipo<10){
                fprintf(FUTBOLISTAS,"%i-0%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            } else{
        fprintf(FUTBOLISTAS,"%i-%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
    }
}

    fclose(FUTBOLISTAS);
}

void guardarUsuarios(){
    int i;
    USUARIOS = fopen("Usuarios.txt","w");
    if(USUARIOS == NULL){
        printf("Error al guardar los usuarios");
        exit(1);
    }
    for (i=0;i<numeroUsuarios;i++){
        if(usuarios[i].id>=10&&i!=numeroUsuarios-1){
            fprintf(USUARIOS,"%i-%s-%s-%s-%s\n",usuarios[i].id,usuarios[i].nombre,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
        }else if(usuarios[i].id<10&&i!=numeroUsuarios-1){
            fprintf(USUARIOS,"0%i-%s-%s-%s-%s\n",usuarios[i].id,usuarios[i].nombre,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
        }else{
            fprintf(USUARIOS,"0%i-%s-%s-%s-%s",usuarios[i].id,usuarios[i].nombre,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
    }
    }

    fclose(USUARIOS);
}

void guardarPlantillas(){
    int i,j;
    PLANTILLAS = fopen("Plantillas.txt","w");
    if(PLANTILLAS == NULL){
        printf("Error al guardar las plantillas\n");
        exit(1);
    }
    for(int i=0;i<numeroUsuarios;i++){
       for(int j = 0; j<usuarios[i].numeroPlantillas;j++){
            if(usuarios[i].plantillas[j].idUsuario<10)
            fprintf (PLANTILLAS,"0");
            fprintf(PLANTILLAS,"%i-",usuarios[i].plantillas[j].idUsuario,usuarios[i].plantillas[j].idPlantilla,usuarios[i].plantillas[j].nombre,usuarios[i].plantillas[j].presupuestoDisponible,usuarios[i].plantillas[j].puntuacion);

            if(usuarios[i].plantillas[j].idPlantilla<100)
            fprintf(PLANTILLAS,"0");
            if(usuarios[i].plantillas[j].idPlantilla<10)
            fprintf(PLANTILLAS,"0");
            if(j == numeroPlantillas - 1)
            fprintf(PLANTILLAS,"%i-%s-%i-%i",usuarios[i].plantillas[j].idPlantilla,usuarios[i].plantillas[j].nombre,usuarios[i].plantillas[j].presupuestoDisponible,usuarios[i].plantillas[j].puntuacion);
            else
            fprintf(PLANTILLAS,"%i-%s-%i-%i\n",usuarios[i].plantillas[j].idPlantilla,usuarios[i].plantillas[j].nombre,usuarios[i].plantillas[j].presupuestoDisponible,usuarios[i].plantillas[j].puntuacion);
        }
   }
}
