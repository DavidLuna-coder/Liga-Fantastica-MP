#include "carga.h"
#include "administrador.h"
#include <stdio.h>
#include <string.h>

void menuAdmin(){
	int exit;
}


void listarEquipos(){
	int i;
	printf("La lista de equipos es:\n");
	for(i=0;i<numeroEquipos;i++){
		printf("-%i-%s-\n",equipos[i].id,equipos[i].nombre);
	}
}

void listarUsuarios(){
	int i;
	printf("La lista de usuarios es:\n");
	for(i=0;i<numeroUsuarios;i++){
		printf("-%s-%i-%s-%s-%s\n",usuarios[i].nombre,usuarios[i].id,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
	}
}
void modificarUsuarios(){
	int select,select_2,n_id,error,user,i;
	char temporal[20];
	char seguir,aux;
	printf("Dame la ID del usuario que quieras modificar\n");
	scanf("%i",&user);
	if(user>numeroUsuarios||select<0){
		printf("Usuario no existe");
	}
	else{
		do{
		printf("Que quieres modificar?:\n1-Nombre de usuario\n2-La ID\n3-Tipo de perfil\n4-Contrasena\n5-Salir\n");
		error=0;
		scanf("%i",&select);
		switch(select){
			case 1: 
				printf("Que nuevo nombre de usuario quieres?");
				scanf("%c",&aux);
		       		fgets(temporal,20,stdin);
				temporal[strlen(temporal)-1]='\0';
		       		strcpy(usuarios[user-1].nombre,temporal);
				printf("Nombre de usuario camiado correctamente");
				break;
			case 2:
				printf("Que ID quieres asignarle?\n");
				scanf("%i",&n_id);
				for(i=0;i<numeroUsuarios&&error==0;i++){
			       		if(usuarios[i].id==n_id){
				       		error=1;
					};
			       	};
			       	if(error==1){
				       	printf("ID ya en uso");
		       		}
			       	else{
			       		usuarios[user-1].id=n_id;
			       		printf("ID cambiada correctamente");
		       		}
			       break;
				case 3:
				do{
					printf("El usuario es un %s\n A cual lo quieres cambiar?\n1-Participante\n2-Cronista\n3-Administrador\n4-Salir\n",usuarios[user].tipoPerfil);
			       
			       		scanf("%i",&select_2);
			       		switch(select_2){
				       			case 1:
						       		strcpy(usuarios[user-1].tipoPerfil,"participante");
					       			strcpy(usuarios[user-1].perfil,"parti");
								printf("Usuario cambiado correctamente");
							break;
					       		case 2:
								strcpy(usuarios[user-1].tipoPerfil,"cronista");
								strcpy(usuarios[user-1].perfil,"croni");
								printf("Usuario cambiado correctamente");
							break;
					       		case 3:
								strcpy(usuarios[user-1].tipoPerfil,"administrador");
								strcpy(usuarios[user-1].perfil,"admin");
								printf("Usuario cambiado correctamente");
							break;
							case 4:
								printf("Saliendo del menu...");
							break;
				    	   		default:
								printf("Opcion no disponible");
							break;}
					}while(select_2!=4);
			break;
			case 4:
				printf("La contrasena actual es %s\nA cual la quieres cambiar?\n", usuarios[user-1].contrasena);
				scanf("%c",&aux);
				fgets(temporal,8,stdin);
				temporal[strlen(temporal)-1]='\0';
				strcpy(usuarios[user-1].contrasena,temporal);
				printf("La contrasena nueva es %s",usuarios[user-1].contrasena);
				break;
			case 5:
				printf("Saliendo del menu...");
			break;
			default:
				printf("Opcion no disponible");
			break;}
		}while(select!=5);
		}
	}

void anadirUsuario(){
	int error,i,select;
	char temporal[20];
	numeroUsuarios++;
	usuarios = (usuario*) realloc (usuarios,numeroUsuarios*sizeof(usuario));
	printf("Que nombre le quieres dar a el usuario?");
	do{
		error=1;
		fgets(temporal,20,stdin);
		temporal[strlen(temporal)-1]='\0';
		for(i=0;i<numeroUsuarios&&error==1;i++){
			error=strcmp(temporal,usuarios[i].nombre);
			if(error==0){
				printf("Nombre de usuario no disponible");
			}
		}
	}while(error==0);
	strcpy(usuarios[numeroUsuarios-1].nombre,temporal);
	printf("Su usuario es %s",usuarios[numeroUsuarios-1].nombre);
	printf("Que contrasena quieres?");
	fgets(temporal,8,stdin);
	strcpy(usuarios[numeroUsuarios-1].contrasena,temporal);
	printf("Su contrasena es %s", usuarios[numeroUsuarios-1].contrasena);
	usuarios[numeroUsuarios-1].id=numeroUsuarios;
	printf("Su ID es %i",numeroUsuarios);
	printf("Que tipo de usuario sera?\n1-Administrador\n2-Cronista\n3-Participante");
	scanf("%i",&select);
	switch(select){
		case 1:
			strcpy(usuarios[numeroUsuarios-1].tipoPerfil,"administrador");
			strcpy(usuarios[numeroUsuarios-1].perfil,"admin");
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);

		break;
		case 2:
			strcpy(usuarios[numeroUsuarios-1].tipoPerfil,"cronista");
			strcpy(usuarios[numeroUsuarios-1].perfil,"croni");
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);
		break;
		case 3:
			strcpy(usuarios[numeroUsuarios-1].tipoPerfil,"participante");
			strcpy(usuarios[numeroUsuarios-1].perfil,"parti");
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);
		break;
		default:
			printf("Opcion no disponible");
	}
}

void eliminarUsuario(){
	int i,user;
	char seguir;
	printf("Que usuario quieres eliminar?\n");
	scanf("%i",&user);
	if(user>numeroUsuarios||user<0){
		printf("Usuario no existe\n");
	}
	else{
		for(i=user;i<numeroUsuarios;i++){
			strcpy(usuarios[i-1].nombre,usuarios[i].nombre);
			strcpy(usuarios[i-1].contrasena,usuarios[i].contrasena);
			strcpy(usuarios[i-1].tipoPerfil,usuarios[i].tipoPerfil);
			strcpy(usuarios[i-1].perfil,usuarios[i].perfil);
		}
		numeroUsuarios--;
		usuarios = (usuario*) realloc (usuarios,numeroUsuarios*sizeof(usuario));
	}
}

void anadirEquipo(){
	char temporal[21];
	if (numeroEquipos==20){
		printf("Espacio infusiciente para mas equipos, por favor, borre alguno de los existentes\n");
	}
	else{
		numeroEquipos++;
		equipos = (equipo*) realloc (equipos,numeroEquipos*sizeof(equipo));
		printf("Que nombre quieres para el equipo?\n");
		fgets(temporal,21,stdin);
		temporal[strlen(temporal)-1]='\0';
		strcpy(equipos[numeroEquipos-1].nombre,temporal);
		printf("El nombre del equipo es %s\n",equipos[numeroEquipos-1].nombre);
		printf("La ID del equipo sera %i\n",numeroEquipos);
		equipos[numeroEquipos-1].id=numeroEquipos;
	}
}
	
void modificarPresupuesto(){
	int dineroGastado,nuevoPresupuesto,i;
	printf("Introduzca el nuevo presupuesto");
	scanf("%i",&nuevoPresupuesto);
	for(i=0;i<numeroPlantillas;i++){
		dineroGastado=config.presupuesto-plantillas->presupuestoDisponible;
		if(dineroGastado>nuevoPresupuesto){}
	}
}





				























		
