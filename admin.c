#include "carga.h"
#include "administrador.h"
#include <stdio.h>
#include <string.h>

void menuAdmin(){
	int select;
	do{
		printf("Que opcion quieres?\n1-Listar equipos\n2-Listar Usuarios\n3-Modificar Usuario\n4-Crear Usuario\n5-Eliminar Usuario\n6-Crear Equipo\n7-Modificar presupuestos\n8-Limite de Plantillas\n9-Borrar Equipo\n10-Salir");
		scanf("%i",&select);
		switch(select){
			case 1:
				listarEquipos();
			break;
			case 2:
				listarUsuarios();
			break;
			case 3:
				modificarUsuarios();
			break;
			case 4:
				anadirUsuario();
			break;
			case 5:
				eliminarUsuario();
			break;
			case 6:
				anadirEquipo();
			break;
			case 7:
				modificarPresupuestos();
			break;
			case 8:
				limitePlantillas();
			break;
			case 9:
				borrarEquipo();
			break;
			default:
				printf("Opcion no disponible\n");
			break;
		}
	}while(select!=10);
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
	
void modificarPresupuestos(){
	int dineroGastado,nuevoPresupuesto,i,j,k,l;
	printf("Introduzca el nuevo presupuesto");
	scanf("%i",&nuevoPresupuesto);
	for(j=0;j<numeroUsuarios;j++){
		printf("%i",usuarios[j].numeroPlantillas);
		for(i=0;i<usuarios[j].numeroPlantillas;i++){
			dineroGastado=0;
			for(k=0;k<usuarios[j].plantillas[i].numJugadores;k++){
				dineroGastado=dineroGastado + usuarios[j].plantillas[i].jugadores[k].precio;
			}
			if(dineroGastado>nuevoPresupuesto){
				printf("U:%i-P:%i\n",j,i);
				usuarios[j].plantillas[i].numJugadores--;
				usuarios[j].plantillas[i].presupuestoDisponible=nuevoPresupuesto;
				for(l=0;l<usuarios[j].plantillas[i].numJugadores;l++){
					usuarios[j].plantillas[i].presupuestoDisponible=usuarios[j].plantillas[i].presupuestoDisponible-usuarios[j].plantillas[i].jugadores[j].precio;
				}
				usuarios[j].plantillas[i].jugadores = (jugador*) realloc (usuarios[j].plantillas[i].jugadores,usuarios[j].plantillas[i].numJugadores*sizeof(jugador));
				i--;
			}
			printf("a");
		}
	}
	config.presupuesto=nuevoPresupuesto;
	printf("Presupuesto cambiado exitosamente\n");
}

void limitePlantillas(){
	int maxPlantillas,k;
	printf("Cual sera el nuevo limite de plantillas?");
	scanf("%i",&config.maxPlantillas);
	for(k=0;k<numeroUsuarios;k++){
		if(usuarios[k].numeroPlantillas>config.maxPlantillas){
			usuarios[k].numeroPlantillas=config.maxPlantillas;
		}
		usuarios[k].plantillas = (plantilla*) realloc (usuarios[k].plantillas,config.maxPlantillas*sizeof(plantilla));
		printf("%i",k);
	}
	printf("Limite cambiado exitosamente\n");
}
	
void borrarEquipo(){
	int selectDelete,found,i,j,k,l;
	do{
		listarEquipos();
		printf("Introduzca la id del equipo que desea borrar\n");
		scanf("%i",&selectDelete);
		for(i=0;i<numeroEquipos&&found==0;i++){
			if(selectDelete==equipos[i].id){
				found=1;
				printf("Equipo encontrado\n");
			}
		}
	}while(found==0);
	found=0;
	for(i=0;i<numeroEquipos&&found==0;i++){
		if(selectDelete==equipos[i].id){
			found=1;
			for(k=i;k<numeroEquipos;k++){
				equipos[k].id=equipos[k+1].id;
				strcpy(equipos[k].nombre,equipos[k+1].nombre);
				for(l=0;l<5;l++){
					equipos[k].jugadores[l].id=equipos[k+1].jugadores[l].id;
					equipos[k].jugadores[l].precio=equipos[k+1].jugadores[l].precio;
					equipos[k].jugadores[l].equipo=equipos[k+1].jugadores[l].equipo;
					equipos[k].jugadores[l].valoracion=equipos[k+1].jugadores[l].valoracion;
				}
			}
			numeroEquipos--;
			equipos= (equipo*) realloc (equipos,numeroEquipos*sizeof(equipo));
		}
	}
	for(i=0;i<numeroUsuarios;i++){
		for(j=0;j<usuarios[i].numeroPlantillas;j++){
			for(k=0;k<usuarios[i].plantillas[j].numJugadores;k++){
				printf("%i",k);
				if(selectDelete==usuarios[i].plantillas[j].jugadores[k].equipo){
					if(usuarios[i].plantillas[j].numJugadores>1){
						usuarios[i].plantillas[j].presupuestoDisponible=usuarios[i].plantillas[j].presupuestoDisponible + usuarios[i].plantillas[j].jugadores[k].precio;
						usuarios[i].plantillas[j].numJugadores--;
						for(l=k;l<usuarios[i].plantillas[j].numJugadores;l++){
							strcpy(usuarios[i].plantillas[j].jugadores[l].nombre, usuarios[i].plantillas[j].jugadores[l+1].nombre);
							usuarios[i].plantillas[j].jugadores[l].id=usuarios[i].plantillas[j].jugadores[l+1].id;
							usuarios[i].plantillas[j].jugadores[l].equipo=usuarios[i].plantillas[j].jugadores[l+1].equipo;
							usuarios[i].plantillas[j].jugadores[l].valoracion=usuarios[i].plantillas[j].jugadores[l+1].valoracion;
							usuarios[i].plantillas[j].jugadores[l].precio=usuarios[i].plantillas[j].jugadores[l+1].precio;
						}	

						usuarios[i].plantillas[j].jugadores= (jugador*) realloc (usuarios[i].plantillas[j].jugadores,usuarios[i].plantillas[j].numJugadores*sizeof(jugador));
						k=-1;
					}
					else{
						usuarios[i].plantillas[j].numJugadores=0;
						k=-1;
					}
				}
			}
		}
	}
	for(i=0;i<numeroJugadores;i++){
		if(selectDelete==jugadores[i].equipo){
			for(k=i;k<numeroJugadores;k++){
				jugadores[k].equipo=jugadores[k+1].equipo;
				jugadores[k].precio=jugadores[k+1].precio;
				jugadores[k].valoracion=jugadores[k+1].valoracion;
				strcpy(jugadores[k].nombre,jugadores[k+1].nombre);
			}
			numeroJugadores--;
			jugadores=(jugador*) realloc (jugadores,numeroJugadores*sizeof(jugador));
		}
	}
}
				






				























		
