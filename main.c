#include <stdio.h>
#include <stdlib.h>
#include "carga.h"
#include "administrador.h"
#include "Cronista.h"
#include "_Usuarios.h"
#include "guardar.h"



int main(){

	//orden de carga:
	//jugadores>equipos>configuracion>jugadorPlantilla>plantilla>usuarios

	cargar();
	valorarPlantillas();
	printf("	                    ___x \n");
	printf("	 o__         o__   |   |x \n");
	printf("	/|          /|     |   |Xx\n");
	printf("	/ > o       <|     |   |XXx \n");
	printf(	"---BIENVENIDO A LIGA FANTASTICA!---\n");

	users();	//users() lleva al usuario al menu de inicio de sesion/ registro
	guardarConfiguracion();
	guardarEquipos();
	guardarFutbolistas();
	guardarUsuarios();
	guardarPlantillas();
	guardarJugadorPlantilla();

return 0;
}