#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "guardar.h"

//Cabecera: void guardarConfiguracion
//Preocondicion: 
//Postcondicion: 
void guardarConfiguracion(){ //Guarda todos los datos de la configuración en su fichero correspondiente.
    CONFIGURACION = fopen("Configuracion.txt","w"); 
    if(CONFIGURACION == NULL){
        printf("Error al abrir el fichero de configuracion");
        exit(1);
    }

    fprintf(CONFIGURACION,"nº_maximo_plantillas-%i\nPresupuesto_defecto-%i\nNº_maximo_jugadores_equipo-%i",config.maxPlantillas,config.presupuesto,config.maxJugadores);

    fclose(CONFIGURACION);
}

//Cabecera: void guardarEquipos
//Preocondicion:
//Postcondicion:
void guardarEquipos(){
    int i;
    EQUIPOS = fopen("Equipos.txt","w");
    if(EQUIPOS == NULL){
        printf("Error al guardar los equipos\n");
        exit(1);
    }
    for (i=0;i<numeroEquipos;i++){  // Recorre todos los equipos e imprime en los ficheros los datos de las estructuras de equipos
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

//Cabecera: guardarFutbolistas
//Preocondicion:
//Postcondicion:
void guardarFutbolistas(){
    int i;
    FUTBOLISTAS = fopen("Futbolistas.txt","w");
    if(FUTBOLISTAS == NULL){
        printf("Error al guardar los futbolistas\n");
        exit(1);
    }
    for (i=0;i<numeroJugadores;i++){ //Recorre todas las estructuras de futbolistas y las umprime en el fichero futbolistas.txt
        if(jugadores[i].id<10&&i!=numeroJugadores-1){
            if(jugadores[i].equipo<10){
                fprintf(FUTBOLISTAS,"0%i-0%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            }else{
                fprintf(FUTBOLISTAS,"0%i-%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            }
    }   else if(i==numeroJugadores-1){
        fprintf(FUTBOLISTAS,"%i-%i-%s-%i-%i",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
    }   else if(jugadores[i].equipo<10){
                fprintf(FUTBOLISTAS,"%i-0%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
            } else{
        fprintf(FUTBOLISTAS,"%i-%i-%s-%i-%i\n",jugadores[i].id,jugadores[i].equipo,jugadores[i].nombre,jugadores[i].precio,jugadores[i].valoracion);
    }
}

    fclose(FUTBOLISTAS);
}

//Cabecera: void guardarUsuarios()
//Preocondicion:
//Postcondicion:
//Guarda los datos de la estructura Usuarios
void guardarUsuarios(){
    int i;
    USUARIOS = fopen("Usuarios.txt","w");
    if(USUARIOS == NULL){
        printf("Error al guardar los usuarios");
        exit(1);
    }
    for (i=0;i<numeroUsuarios;i++){ //Almacena los datos de la estructua usuarios por cada uno de ellos.
        if(usuarios[i].id<10){
            fprintf(USUARIOS,"0");
        }
        fprintf(USUARIOS,"%i-%s-%s-%s-%s",usuarios[i].id,usuarios[i].nombre,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
        if(i!=numeroUsuarios-1)
        fprintf(USUARIOS,"\n");
    }

    fclose(USUARIOS);

}

//Cabecera: guardarPlantillas()
//Preocondicion:
//Postcondicion:
//Guarda los datos de la estructura plantillas en el fichero Plantillas.txt
void guardarPlantillas(){
    int i,j,usuarioLimite;
    PLANTILLAS = fopen("Plantillas.txt","w");
    if(PLANTILLAS == NULL){
        printf("Error al guardar las plantillas\n");
        exit(1);
    }
    for(i=0;i<numeroUsuarios;i++){
            if(usuarios[i].numeroPlantillas != 0) //Encuentra cuál es el último usuarios con plantillas.
            usuarioLimite = i;
    }

    for(i =0 ; i<=usuarioLimite;i++){ // Imprime los datos de la estructura plantilla en el fichero
        if(usuarios[i].numeroPlantillas!=0){
        for(j=0;j<usuarios[i].numeroPlantillas;j++){
            if(usuarios[i].plantillas[j].idUsuario<10)
            fprintf(PLANTILLAS,"0");
            fprintf(PLANTILLAS,"%i-",usuarios[i].plantillas[j].idUsuario);
            if(usuarios[i].plantillas[j].idPlantilla<100)
            fprintf(PLANTILLAS,"0");
            if(usuarios[i].plantillas[j].idPlantilla<10)
            fprintf(PLANTILLAS,"0");
            fprintf(PLANTILLAS,"%i-",usuarios[i].plantillas[j].idPlantilla);
            fprintf(PLANTILLAS,"%s-%i-%i",usuarios[i].plantillas[j].nombre,usuarios[i].plantillas[j].presupuestoDisponible,usuarios[i].plantillas[j].puntuacion);
            if(i!=usuarioLimite)
            fprintf(PLANTILLAS,"\n");
            else if(i==usuarioLimite && j!=usuarios[i].numeroPlantillas-1)
            fprintf(PLANTILLAS,"\n");
        }
        }

    }
   fclose(PLANTILLAS);
}
//Cabecera: guardarJugadorPlantilla()
//Preocondicion:
//Postcondicion: 
//Guarda los datos de la estructura JugadorPlantilla en el fichero Jugadores_Plantillas.txt
void guardarJugadorPlantilla(){
    int i;
    JUGADORESPLANTILLAS = fopen("Jugadores_Plantillas.txt","w");


    for(i=0; i<numeroJugadoresPlantillas;i++){ //Recorre todo el vector de estructuras de JugadoresPlantillas y se imprimen los datos en el fichero.
        if(jugadoresPlantillas[i].idJugador<10)
        fprintf(JUGADORESPLANTILLAS,"0");
        fprintf(JUGADORESPLANTILLAS,"%i-",jugadoresPlantillas[i].idJugador);
        if(jugadoresPlantillas[i].idPlantilla<100)
        fprintf(JUGADORESPLANTILLAS,"0");
        if(jugadoresPlantillas[i].idPlantilla<10)
        fprintf(JUGADORESPLANTILLAS,"0");
        fprintf(JUGADORESPLANTILLAS,"%i",jugadoresPlantillas[i].idPlantilla);
        if(i!=numeroJugadoresPlantillas-1)
        fprintf(JUGADORESPLANTILLAS,"\n");
    }

    fclose(JUGADORESPLANTILLAS);
}
