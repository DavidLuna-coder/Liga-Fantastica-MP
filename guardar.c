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