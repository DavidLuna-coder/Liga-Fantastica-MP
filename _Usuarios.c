#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carga.h"
#include "_Usuarios.h"
#include "Cronista.h"
#include "administrador.h"

void users(){

int elec;

do{
    printf("1-Registro\n");
    printf("2-Acceso al Sistema\n");
    printf("3-Salir del Sistema\n");
    scanf("%i",&elec);
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



void acceso(){  // Inicio de sesion
    int comprobador1=0;
    int comprobador2=0;
   
    int len;
    char adm[]="administrador";
    char part[]="participante";
    char cron[]="cronista";
    char pasword[8];
    char user[20];
do{
    printf("Insertar nombre de usuario \n");
    fflush(stdin);
    fgets(user,20,stdin);
    strtok(user, "\n");
    printf("Insertar nombre contrasena \n");
    fflush(stdin);
    fgets(pasword,8,stdin);
    strtok(pasword, "\n");
   
   printf("%s", usuarios[2].nombre);
    len=strlen(usuarios[2].nombre);
    printf("%i\n", len);
    
    
    len=strlen(user);
    printf("%i\n", len);
     
    for(int i=0; i<numeroUsuarios;i++){
        if(strcmp(user,usuarios[i].nombre)==0){
            comprobador1=1;
        
                usuarioActual=usuarios[i].id;
                printf("%i", usuarioActual);
                
        }
    }
   printf("%s\n", usuarios[usuarioActual].tipoPerfil);
    for(int i=0; i<numeroUsuarios;i++){
      
        if(strcmp(pasword,usuarios[i].contrasena)==0 && comprobador1==1){
            comprobador2=1;
            
        }
    }
   
if(comprobador1==1 && comprobador2==1){
    printf("Ha iniciado sesion correctamente\n");
    
if(strcmp(cron, usuarios[usuarioActual].tipoPerfil)==0){
printf("Bienvenido Cronista\n");
cronista();
}
if(strcmp(adm, usuarios[usuarioActual].tipoPerfil)==0){
    printf("Bienvenido Administrador\n");
menuAdmin();
}
if(strcmp(part, usuarios[usuarioActual].tipoPerfil)==0){
printf("participantes proximamente\n");
}
}
else{
   printf("inicio de sesion incorrecto, vuelva a intentarlo\n");
}




}while(comprobador1==0 || comprobador2==0);
}



void registro(){  //Registrarse

    int comprobador1;
    int comprobador2;
    int elec2=0;
    int len=0;
    printf(" %i\n", numeroUsuarios);
    char admin[]="administrador";
    char parti[]="participante";
    char cronista[]="cronista";
    
    char paswordR[8];
    char userR[20];
    char useraccessR[5];
   do{
       comprobador1=0;
       comprobador2=0;
    printf("Insertar nombre de usuario \n");
    fflush(stdin);
    fgets(userR,20,stdin);
    strtok(userR, "\n");
    printf("Insertar contrasena \n");
    fflush(stdin);
    fgets(paswordR,8,stdin);
    strtok(paswordR, "\n");
    printf("Insertar nombre de usuario de acceso \n");
    fflush(stdin);
    fgets(useraccessR,5,stdin);
    strtok(useraccessR, "\n");
    
  
     
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
                        strcpy(usuarios[j].tipoPerfil, "participante");
                        break;
                    case 2:
                    strcpy(usuarios[j].tipoPerfil, "cronista");
                        
                        break;
                    case 3:
                   strcpy(usuarios[j].tipoPerfil, "administrador");
                        
                        break;
                    default:
                    printf("introduce un numero valido[1,2 o 3]:\n");
                    break;

                }
            
                }while(elec2!=1 && elec2!=2 && elec2!=3);
                vaciar (usuarios[j].contrasena);
                usuarios[j].id=j;
                
                
                 strcpy(usuarios[j].contrasena, paswordR);
                 strcpy(usuarios[j].perfil, useraccessR);
                strcpy(usuarios[j].nombre, userR);
                printf("%s",usuarios[j].tipoPerfil );
                printf(" %i", j);
            }
           }
        }
    }
     }while(comprobador1==1 || comprobador2==1);



}


