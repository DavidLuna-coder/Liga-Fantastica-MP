#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"
#include "_Usuarios.h"
#include "Cronista.h"
#include "admin.h"
#include "participante.h"
void users(){

int elec;

do{
    printf("1-Registro\n");
    printf("2-Acceso al Sistema\n");
    printf("3-Salir del Sistema\n");
    scanf("%i\n",&elec);
    switch(elec){

    case 1:
    registro();
    break;

    case 2:
    acceso();
    break;

    case 3:
    printf("saliendo del porgrama...\n");
    break;

    default:
    printf("introduce un numero valido[1,2 o 3]:\n");
    break;

    }



}while(elec!=3);
}



void acceso(){  // Inicio de sesi�n
    int comprobador1=0;
    int comprobador2=0;
    int id=0;
    char adm[]="administrador";
    char part[]="participante";
    char cron[]="cronista";
    char pasword[8];
    char user[20];
do{
    printf("Insertar nombre de usuario \n");
    fgets(user,20,stdin);
    printf("Insertar nombre contrasena \n");
    fflush(stdin);
    fgets(pasword,8,stdin);
    for(int i=0; i<numeroUsuarios;i++){
        if(strcmp(user,usuarios[i].nombre)==0){
            comprobador1=1;
        }
    }
    for(int i=0; i<numeroUsuarios;i++){
        if(strcmp(pasword,usuarios[i].contrasena)==0){
            comprobador2=1;
            if(comprobador1==1 && comprobador2==1){
                id=usuarios[i].id;
            }
        }
    }
if(comprobador1==1 && comprobador2==1){
    printf("Ha iniciado sesion correctamente\n");
if(strcmp(cron, usuarios[id].tipoPerfil)==0){
cronista();
}
if(strcmp(adm, usuarios[id].tipoPerfil)==0){
menuAdmin();
}
if(strcmp(part, usuarios[id].tipoPerfil)==0){
participante();
}
}
else{
   printf("inicio de sesion incorrecto, vuelva a intentarlo\n");
}




}while(comprobador1==0 || comprobador2==0);
}



void registro(){  //Registrarse

    int comprobador1=0;
    int comprobador2=0;
    int elec2=0;

    char admin[]="administrador";
    char parti[]="participante";
    char cronista[]="cronista";
    
    char paswordR[8];
    char userR[20];
    char useraccessR[5];
   do{
    printf("Insertar nombre de usuario \n");
    fgets(userR,20,stdin);
    printf("Insertar contrasena \n");
    fflush(stdin);
    fgets(paswordR,8,stdin);
    printf("%s",paswordR);
    printf("Insertar nombre de usuario de acceso \n");
    fflush(stdin);
    fgets(useraccessR,5,stdin);

    for(int i=0; i<numeroUsuarios;i++){
        if(strcmp(userR,usuarios[i].nombre)==0){
            comprobador1=1;
        }
    }

    for (int i=0; i<numeroUsuarios;i++){
        if(strcmp(useraccessR,usuarios[i].perfil)==0){
            comprobador2=1;
        }
    }



    if(comprobador1==1 || comprobador2==1){
    printf("Ya existe una sesion con el mismo nombre, o identificador, vuelva a intentarlo \n");
     vaciar (paswordR);
     vaciar (userR);
     vaciar (useraccessR);
    }
else{
   printf("Perfil en creacion...\n");
    numeroUsuarios=numeroUsuarios+1;

    printf("Que tipo de usuario va a ser: \n 1-Participante\n 2-Cronista \n 3-Administrador\n");
    usuarios=(usuario*)realloc(usuarios,numeroUsuarios*sizeof(usuario));
        if(usuarios==NULL){
            printf("Ha habido un error al reservar un espacio de memoria ");
        }
        else{
           for(int j=0;j<numeroUsuarios;j++){
            if(j==numeroUsuarios-1){
                do{
                fflush(stdin);
                scanf("%i", &elec2);
                switch(elec2){
                    case 1:
                        for(int k=0;k<14;k++){
                            usuarios[j].tipoPerfil[k]=parti[k];
                        }
                        
                        break;
                    case 2:
                    for(int k=0;k<14;k++){
                            usuarios[j].tipoPerfil[k]=cronista[k];
                        }
                        
                        break;
                    case 3:
                    for(int k=0;k<14;k++){
                            usuarios[j].tipoPerfil[k]=admin[k];
                        }
                        
                        break;
                    default:
                    printf("introduce un numero valido[1,2 o 3]:\n");
                    break;

                }
            
                }while(elec2!=1 && elec2!=2 && elec2!=3);
                vaciar (usuarios[j].contrasena);
                usuarios[j].id=j;
                
                for(int v=0;v<9;v++){
                   usuarios[j].contrasena[v]= paswordR[v];
                }
                 for(int v=0;v<6;v++){
                   usuarios[j].perfil[v]= useraccessR[v];
                }
                 for(int v=0;v<21;v++){
                    usuarios[j].nombre[v]= userR[v];
                }
                

            }
           }
        }
    }
     }while(comprobador1==1 || comprobador2==1);



}


