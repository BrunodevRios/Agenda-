#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

int code, decision, vr=0; //vr = validador; 
float phone_number;
char name[20], respuesta; 
FILE * C;

void bienvenida(FILE * A){
 A = fopen("contactos.txt", "r+"); // el simbolo + es para que pododamos agregar cosas al archivo txt
    if(A == NULL){
        printf("\n ERROR PARA ABRIR ARCHIVO \n");
        exit(0);
    }
    //feof = terminar de leer archivo
   while(!feof(A)){
        fscanf(A, "%d", &code); 
        fscanf(A, "%s", &name);
        fscanf(A, "%f", &phone_number);
        printf("%d     %s    %.0f\n", code, name, phone_number);
    }
}

int mContactos(int decision){

    if(decision==1){
        printf("%cSeguro que desea agregar mas contactos a su agenda?\n", 168);
        printf("(S)i o (N)o?\n");
        printf(">");
        scanf("%s", &respuesta);

        while(respuesta=='s' || respuesta=='S'){
            printf("Codigo:");
            scanf("%d", &code); 
            printf("Nombre:");
            scanf("%s", &name);
            printf("Numero de telefono:");
            scanf("%f", &phone_number);
            fprintf(C,"\n%d     %s    %.0f", code, name, phone_number);
            printf("\nDatos guardados con exito!!\n");
            printf("%cDesea agregar otro contacto a su agenda?\n", 168);
            printf("(S)i o (N)o?\n");
            printf(">");
            scanf("%s", &respuesta);
            vr = 1;
        }

        if(vr == 1){
        
            system("cls"); // Borrar lo impreso anteriormente
            rewind(C); //volver a leer el archivo
            printf("Agenda actualizada correctamente!!\n");
            while(!feof(C)){
                fscanf(C, "%d", &code); 
                fscanf(C, "%s", &name);
                fscanf(C, "%f", &phone_number);
                printf("%d     %s    %.0f\n", code, name, phone_number);
            }
        }
    }
}

int eContactos(int decision){
        if(decision==2){
            printf("%cSeguro que desea eliminar un contacto? \n", 168);
            printf("(S)i o (N)o?\n");
            printf(">");
            scanf("%s", &respuesta);
            while(respuesta=='s' || respuesta=='S'){

            }

        }
}

int main(){
    
    C = fopen("contactos.txt", "r+"); // el simbolo + es para que pododamos agregar cosas al archivo txt
    if(C == NULL){
        printf("\n ERROR PARA ABRIR ARCHIVO \n");
        exit(0);
    }
    //feof = terminar de leer archivo
   while(!feof(C)){
        fscanf(C, "%d", &code); 
        fscanf(C, "%s", &name);
        fscanf(C, "%f", &phone_number);
    }

    bienvenida(C);
    
    printf("\nSi desea agregar un contacto presione 1 \n");
    printf("Si desea eliminar un contacto presione 2 \n");
    printf("Si desea editar un contacto presione 3 \n");
    printf(">");
    scanf("%d", &decision);
    
    mContactos(decision);
    eContactos(decision);
    

    fclose(C);
    printf("Fin del programa\n");
    system("pause");

    return 0;
 }
