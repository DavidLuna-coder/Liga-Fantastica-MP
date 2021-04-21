#include "carga.h"
#include "administrador.h"
#include <stdio.h>
#include <string.h>
//void menuAdmin();
//Precondicion:Debe tener los datos en memoria principal cargados;
//Postcondicion:Redirecciona a la funcion respectiva que pida el usuario
void menuAdmin(){
	int select;//Variable que marcara en el switch a cual de la funciones se redirecciona
	char aux;
	do{
		printf("Que opcion quieres?\n1-Listar equipos\n2-Listar Usuarios\n3-Modificar Usuario\n4-Crear Usuario\n5-Eliminar Usuario\n6-Crear Equipo\n7-Modificar presupuestos\n8-Limite de Plantillas\n9-Borrar Equipo\n10-Cambiar limite de jugadores por plantilla\n11-Borrar jugador\n12-Crear Jugador\n13-Salir\n");
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
			case 10:
				jugadoresPlantilla();
			break;
			case 11:
				disponibilidadJugadores();
			break;
			case 12:
				disponibilidadJugadores2();
			break;
			case 13:
				printf("Saliendo...\n");
			break;
			default:
				printf("Opcion no disponible\n");
			break;
		}
	}while(select!=13);
}
//void listarEquipos();
//Precondicion:Debe tener cargado en memoria los datos de los equipos;
//Postcondicion:Lista todos los equipos disponibles;
void listarEquipos(){
	int i;
	printf("La lista de equipos es:\n");
	for(i=0;i<numeroEquipos;i++){
		printf("-%i-%s-\n",equipos[i].id,equipos[i].nombre);
	}
}
//void listarUsuarios();
//Precondicion:Debe tener cargado en memoria los datos de los usuarios
//Postcondicion:Lista todos los equipos disponibles
void listarUsuarios(){
	int i;
	printf("La lista de usuarios es:\n");
	for(i=0;i<numeroUsuarios;i++){
		printf("-%s-%i-%s-%s-%s\n",usuarios[i].nombre,usuarios[i].id,usuarios[i].tipoPerfil,usuarios[i].perfil,usuarios[i].contrasena);
	}
}
//void modificarUsuarios();
//Precondicion:Debe tener cargado en memoria los datos de los usuarios;
//Postcondicion:Permite al administrador modificar los distintos parametros de un usuario;
void modificarUsuarios(){
	int select,select_2,n_id,error,user,i;
	char temporal[20];
	char seguir,aux;
	printf("Dame la ID del usuario que quieras modificar\n");
	scanf("%i",&user);
	//Comprobador de que que el usuario introduzca la ID de un usuario valido
	if(user>numeroUsuarios||user<0){
		printf("Usuario no existe");
	}
	else{
		do{
		printf("Que quieres modificar?:\n1-Nombre de usuario\n2-La ID\n3-Tipo de perfil\n4-Contrasena\n5-Salir\n");
		error=0;
		scanf("%i",&select);
		//Switch que permite seleccionar que es lo que se quiere cambiar
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
					//Switch que permite cambiar el tipo de perfil del usuarios seleccionado
			       		switch(select_2){
				       			case 1:
						       		strcpy(usuarios[user-1].tipoPerfil,"participante");
								printf("Usuario cambiado correctamente");
							break;
					       		case 2:
								strcpy(usuarios[user-1].tipoPerfil,"cronista");
								printf("Usuario cambiado correctamente");
							break;
					       		case 3:
								strcpy(usuarios[user-1].tipoPerfil,"administrador");
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
//void anadirUsuario();
//Precondicion:Debe tener cargado en memoria los datos de los usuarios;
//Postcondicion:Permite crear un nuevo usuario con sus respectivos datos;
void anadirUsuario(){
	int error,i,select;
	char temporal[20];//Cadena que permite guardar parte de los datos
	char temporal2[20];
	//A la variable global de numero de usuarios se le suma uno (ya que se esta creando uno nuevo) y crea un nuevo espacio de memoria donde se almacenaran los datos de este usuario;
	usuarios = (usuario*) realloc (usuarios,numeroUsuarios*sizeof(usuario));
	printf("Que nombre le quieres dar a el usuario?");
	//Bucle que se encarga de revisar que el nombre de usuario este disponible
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
	do{
		error=1;
		fgets(temporal2,20,stdin);
		temporal[strlen(temporal)-1]='\0';
		for(i=0;i<numeroUsuarios&&error==1;i++){
			error=strcmp(temporal2,usuarios[i].perfil);
			if(error==0){
				printf("Nombre de usuario no disponible");
			}
		}
	}while(error==0);
	numeroUsuarios++;
	strcpy(usuarios[numeroUsuarios-1].nombre,temporal);
	strcpy(usuarios[numeroUsuarios-1].perfil,temporal2);
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
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);

		break;
		case 2:
			strcpy(usuarios[numeroUsuarios-1].tipoPerfil,"cronista");
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);
		break;
		case 3:
			strcpy(usuarios[numeroUsuarios-1].tipoPerfil,"participante");
			printf("El usuario sera %s",usuarios[numeroUsuarios-1].tipoPerfil);
		break;
		default:
			printf("Opcion no disponible");
	}
}
//void eliminarUsuario();
//Precondicion: Debe tener cargado en memoria los datos de los usuarios
//Postcondicion: Permite eliminar un usurario
void eliminarUsuario(){
	int i,j,k,l,m,user,found;
	char seguir;
	printf("Que usuario quieres eliminar?\n");
	scanf("%i",&user);
	if(user>numeroUsuarios||user<0){
		printf("Usuario no existe\n");
	}
	else{
		if(usuarios[user].numeroPlantillas!=0){
			for(i=0;i<usuarios[user].numeroPlantillas;i++){
				for(j=0;j<usuarios[user].plantillas[i].numJugadores;j++){
					found=0;
					for(k=0;k<numeroJugadoresPlantillas&&found!=1;k++){
						printf("%i-%i\n",jugadoresPlantillas[k].idPlantilla,jugadoresPlantillas[k].idJugador);
						if(usuarios[user].plantillas[i].jugadores[j].id==jugadoresPlantillas[k].idJugador&&usuarios[user].plantillas[i].idPlantilla==jugadoresPlantillas[k].idPlantilla){
							found=1;
							for(l=k;l<numeroJugadoresPlantillas;l++){
								jugadoresPlantillas[l].idPlantilla=jugadoresPlantillas[l+1].idPlantilla;
								jugadoresPlantillas[l].idJugador=jugadoresPlantillas[l+1].idJugador;
							}
							k--;
							numeroJugadoresPlantillas--;
							if(numeroJugadoresPlantillas>0){
								jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
								if(jugadoresPlantillas==NULL){
									printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
								}
							}
							else{
								jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
								if(jugadoresPlantillas==NULL){
									printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
								}
							}
							printf("DELETE!!!\n");
						}
					}
				}
				if(found==1){
					for(j=0;j<numeroJugadoresPlantillas;j++){
						if(usuarios[user].plantillas[i].idPlantilla<jugadoresPlantillas[j].idPlantilla){
							jugadoresPlantillas[j].idPlantilla--;
						}
					}
					for(m=i+1;m<usuarios[user].numeroPlantillas;m++){
						usuarios[user].plantillas[m].idPlantilla--;
					}
				}
			}
		}
			usuarios[user].numeroPlantillas=0;
	}

		for(i=user;i<numeroUsuarios;i++){
			strcpy(usuarios[i-1].nombre,usuarios[i].nombre);
			strcpy(usuarios[i-1].contrasena,usuarios[i].contrasena);
			strcpy(usuarios[i-1].tipoPerfil,usuarios[i].tipoPerfil);
			strcpy(usuarios[i-1].perfil,usuarios[i].perfil);
		}
		numeroUsuarios--;
		usuarios = (usuario*) realloc (usuarios,numeroUsuarios*sizeof(usuario));
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
//void modificarPresupuestos();
//Precondicion: Debe tener en cargado en memoria los datos de la configuracion
//Postcondicion: Permite modificar el presupuesto con el que contaran los participantes
void modificarPresupuestos(){
	int dineroGastado,nuevoPresupuesto,found,i,j,k,l,m;
	printf("Introduzca el nuevo presupuesto");
	scanf("%i",&nuevoPresupuesto);
	for(j=0;j<numeroUsuarios;j++){
		printf("%i",usuarios[j].numeroPlantillas);
		for(i=0;i<usuarios[j].numeroPlantillas;i++){
			dineroGastado=0;//Variable que tiene en cuanta cuanto dinero ha gastado cada usuario en cada plantilla
			for(k=0;k<usuarios[j].plantillas[i].numJugadores;k++){
				dineroGastado=dineroGastado + usuarios[j].plantillas[i].jugadores[k].precio;
			}
			if(dineroGastado>nuevoPresupuesto){
				found=0;
				usuarios[j].plantillas[i].numJugadores--;
				usuarios[j].plantillas[i].presupuestoDisponible=nuevoPresupuesto;
				for(k=0;k<numeroJugadoresPlantillas&&found!=1;k++){
					if(usuarios[j].plantillas[i].jugadores[usuarios[j].plantillas[j].numJugadores].id==jugadoresPlantillas[k].idJugador&&usuarios[j].plantillas[j].idPlantilla==jugadoresPlantillas[k].idPlantilla){
						found=1;
						for(m=k;m<numeroJugadoresPlantillas;m++){
							jugadoresPlantillas[m].idJugador=jugadoresPlantillas[m+1].idJugador;
							jugadoresPlantillas[m].idPlantilla=jugadoresPlantillas[m+1].idPlantilla;
						}
						k--;
						numeroJugadoresPlantillas--;
						if(numeroJugadoresPlantillas>0){
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}
						}
						else{	
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}
						}
					}
				}
				for(l=0;l<usuarios[j].plantillas[i].numJugadores;l++){
					usuarios[j].plantillas[i].presupuestoDisponible=usuarios[j].plantillas[i].presupuestoDisponible-usuarios[j].plantillas[i].jugadores[j].precio;
				}
				usuarios[j].plantillas[i].jugadores = (jugador*) realloc (usuarios[j].plantillas[i].jugadores,usuarios[j].plantillas[i].numJugadores*sizeof(jugador));
				i--;
			}
		}//Bucle que comprueba que el dinero gastado de cada plantilla no sobrepase el nuevo presupuesto asigando y de ser asi eliminar el ultimo jugador de la plantilla y reajustando el dinero que tiene el susodicho usuario 
	}
	config.presupuesto=nuevoPresupuesto;
	printf("Presupuesto cambiado exitosamente\n");
}
//void limitePlantillas();
//Precondicion: Debe tener cargado en memoria los datos de la configuracion
//Postcondicion: Permite modificar el limite de plantillas por usuario
void limitePlantillas(){
	int maxPlantillas,found,k,j,i,l;
	printf("Cual sera el nuevo limite de plantillas?");
	scanf("%i",&config.maxPlantillas);
	for(k=0;k<numeroUsuarios;k++){
		if(usuarios[k].numeroPlantillas>config.maxPlantillas){
			for(i=config.maxPlantillas;i<usuarios[k].numeroPlantillas;i++){
				for(j=0;j<numeroJugadoresPlantillas;j++){
					if(usuarios[k].plantillas[i].idPlantilla==jugadoresPlantillas[j].idPlantilla){
						for(l=j;l<numeroJugadoresPlantillas;l++){
							jugadoresPlantillas[l].idPlantilla=jugadoresPlantillas[l+1].idPlantilla;
							jugadoresPlantillas[l].idJugador=jugadoresPlantillas[l+1].idJugador;
						}
						j--;
						numeroJugadoresPlantillas--;
						if(numeroJugadoresPlantillas>0){
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}
						}
						else{	
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}		
						}
						j=0;
					}
				}
			}
			usuarios[k].numeroPlantillas=config.maxPlantillas;
		}
		usuarios[k].plantillas = (plantilla*) realloc (usuarios[k].plantillas,config.maxPlantillas*sizeof(plantilla));
	}//Bucle que revisa si el numero de plantillas de un usuario supera el numero nuevo de plantillas y de ser asi lo reajusta al nuevo limite eliminando la ultima de las plantillas
	printf("Limite cambiado exitosamente\n");
}
//void borrarEquipo();
//Precondicion: Debe tener cargado en memoria la informacion de: Usuarios,Plantillas,Equipos,Jugadores;
//Postcondicion: Perminte borrar un equipo arrastrando consigo los jugadores, los borra de las plantillas en los que este y devuelve el presupuesto de los jugadores ya mencionados
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
	for(i=0;i<numeroEquipos&&found!=1;i++){
		if(equipos[i].id==selectDelete){
			found=1;
			for(j=0;j<5;j++){
				for(k=0;k<numeroJugadoresPlantillas;k++){
					if(equipos[i].jugadores[j].id==jugadoresPlantillas[k].idJugador){
						for(l=k;l<numeroJugadoresPlantillas;l++){
							jugadoresPlantillas[l].idPlantilla=jugadoresPlantillas[l+1].idPlantilla;
							jugadoresPlantillas[l].idJugador=jugadoresPlantillas[l+1].idJugador;
						}
						numeroJugadoresPlantillas--;
						k--;
						if(numeroJugadoresPlantillas>0){
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}
						}
						else{
							jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
							if(jugadoresPlantillas==NULL){
								printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
							}
						}
					}
				}
			}
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
							usuarios[i].plantillas[j].jugadores[l].id=usuarios[i].plantillas[j].jugadores[l+1].id-1;
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
	for(i=0;i<numeroEquipos&&found==0;i++){
		if(selectDelete==equipos[i].id){
			found=1;
			for(k=i;k<numeroEquipos;k++){
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
}
//void jugadoresPlantilla();
//Precondicion: Debe tener caragado en memoria la informacion de la configuracionl
//Postcondicion: Permite modficar el limite de jugadores por plantilla
void jugadoresPlantilla(){
	int nuevoLimite,i,j,k,l,m,found;
	do{
		printf("Cual sera el nuevo limite de jugadores por plantilla?\n");
		scanf("%i",&nuevoLimite);
		if(nuevoLimite<1){
			printf("Solo numemro naturales mayores a 0\n");
		}
	}while(nuevoLimite<1);
	config.maxJugadores=nuevoLimite;
	for(i=0;i<numeroUsuarios;i++){
		for(j=0;j<usuarios[i].numeroPlantillas;j++){
			if(nuevoLimite<usuarios[i].plantillas[j].numJugadores){
				for(m=nuevoLimite;m<usuarios[i].plantillas[j].numJugadores;m++){
					found=0;
					for(k=0;k<numeroJugadoresPlantillas&&found!=1;k++){
						if(usuarios[i].plantillas[j].idPlantilla==jugadoresPlantillas[k].idPlantilla&&usuarios[i].plantillas[j].jugadores[m].id==jugadoresPlantillas[k].idJugador){
							found=1;
							for(l=k;l<numeroJugadoresPlantillas;l++){
								jugadoresPlantillas[l].idPlantilla=jugadoresPlantillas[l+1].idPlantilla;
								jugadoresPlantillas[l].idJugador=jugadoresPlantillas[l+1].idJugador;
							}
							numeroJugadoresPlantillas--;
							if(numeroJugadoresPlantillas>0){
								jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
								if(jugadoresPlantillas==NULL){
									printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
								}
							}
							else{
								jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
								if(jugadoresPlantillas==NULL){
									printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
								}
							}
						}	
					}
				}
				usuarios[i].plantillas[j].jugadores=(jugador*) realloc (usuarios[i].plantillas[j].jugadores,nuevoLimite*sizeof(jugador));
				usuarios[i].plantillas[j].numJugadores=nuevoLimite;
			}
		}
	}//Bucle que comprueba si una plantilla supera el nuevo 
}
//void disponibilidadJugadores();
//Precondicion: Debe estar toda la informacion cargada en memoria
//Postcondicion: permite eliminar un jugador con lo que ello implica
void disponibilidadJugadores(){
	int selectDelete,found,i,j,k,l;
	for(i=0;i<numeroJugadores;i++){
		printf("-%i-%s-\n",jugadores[i].id,jugadores[i].nombre);
	}
	printf("Selecciona la id del jugador que quieres eliminar");
	scanf("%i",&selectDelete);
	for(i=0;i<numeroJugadoresPlantillas;i++){
		if(selectDelete==jugadoresPlantillas[i].idJugador){
			printf("Test Delete %i\n",jugadoresPlantillas[i].idPlantilla);
			for(l=i;l<numeroJugadoresPlantillas;l++){
				jugadoresPlantillas[l].idPlantilla=jugadoresPlantillas[l+1].idPlantilla;
				jugadoresPlantillas[l].idJugador=jugadoresPlantillas[l+1].idJugador;
			}
			i--;
			numeroJugadoresPlantillas--;
			if(numeroJugadoresPlantillas>0){
				jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,numeroJugadoresPlantillas*sizeof(jugadorPlantilla));
				if(jugadoresPlantillas==NULL){
					printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
				}
			}
			else{
				jugadoresPlantillas= (jugadorPlantilla*) realloc (jugadoresPlantillas,1*sizeof(jugadorPlantilla));
				if(jugadoresPlantillas==NULL){
					printf("Error en la reserva de memoria de los jugadores de la plantilla\n");
				}
			}
		}
	}
	for(i=0;i<numeroUsuarios;i++){
		for(j=0;j<usuarios[i].numeroPlantillas;j++){
			found=0;
			for(k=0;k<usuarios[i].plantillas[j].numJugadores&&found==0;k++){
				if(usuarios[i].plantillas[j].jugadores[k].id==selectDelete){
					found=1;
					usuarios[i].plantillas[j].presupuestoDisponible=usuarios[i].plantillas[j].presupuestoDisponible+usuarios[i].plantillas[j].jugadores[k].precio;
					usuarios[i].plantillas[j].numJugadores--;
					for(l=k;l<usuarios[i].plantillas[j].numJugadores;l++){
						usuarios[i].plantillas[j].jugadores[l].id= usuarios[i].plantillas[j].jugadores[l+1].id;
						usuarios[i].plantillas[j].jugadores[l].equipo= usuarios[i].plantillas[j].jugadores[l+1].equipo;
						usuarios[i].plantillas[j].jugadores[l].precio=usuarios[i].plantillas[j].jugadores[l+1].precio;
						usuarios[i].plantillas[j].jugadores[l].valoracion=usuarios[i].plantillas[j].jugadores[l+1].valoracion;
						strcpy(usuarios[i].plantillas[j].jugadores[l].nombre,usuarios[i].plantillas[j].jugadores[l+1].nombre);
					}
				}
			}
		}
	}
}
//void disponibilidadJugadores2();
//Precondicion: Debe tener los jugadores cargados en memoria
//Postcondicion: Permite crear jugadores
void disponibilidadJugadores2(){
	char temp[21],aux;
	int i,j,error,id;
	if(numeroJugadores==100){
		printf("No hay espacio para mas jugadores, por favor elimine alguno de los ya existentes\n");
	}
	else{
		do{
			scanf("%c",&aux);
			error=1;
			printf("Introduza el nombre del jugador que quiere crear\n");
			fgets(temp,20,stdin);
			temp[strlen(temp)-1]='\0';
			for(i=0;i<numeroJugadores&&error!=0;i++){
				error=strcmp(temp,jugadores[i].nombre);
			}
			if(error==0){
				printf("Jugador ya existe\n");
			}
			else{
				numeroJugadores++;
				jugadores=(jugador*) realloc (jugadores,numeroJugadores*sizeof(jugador));
				strcpy(jugadores[numeroJugadores-1].nombre,temp);
				printf("Jugador creado correctamente\n");
				listarEquipos();
				do{
					error=0;
					printf("Introduzca la id del equipo al que pertenece\n");
					scanf("%i",&jugadores[numeroJugadores-1].equipo);
					for(i=0;i<numeroEquipos&&error!=1;i++){
						if(jugadores[numeroJugadores-1].equipo==equipos[i].id){
							error=1;
						}
					}
					if(error==0){
						printf("Equipo no existe\n");
					}
				}while(error==0);
				do{
					error=1;
					do{
						printf("Introduzca la id del jugador\n");
						scanf("%i",&jugadores[numeroJugadores-1].id);
					}while(jugadores[numeroJugadores-1].id>99);
					for(i=0;i<numeroJugadores-1&&error!=0;i++){
						if(jugadores[i].id==jugadores[numeroJugadores-1].id){
							printf("Id ya en uso, coja otra\n");
							error=0;
						}
					}
				}while(error==0);
				printf("Introduzca el precio del jugador\n");
				scanf("%i",&jugadores[numeroJugadores-1].precio);
				jugadores[numeroJugadores-1].valoracion=0;
				}
		}while(error==0);
	}
}	
