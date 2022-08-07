#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


int main(){
    
    int code, decision, vr=0; //vr = validador; 
    float phone_number;
    char name[20], respuesta; 
    FILE *A;

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
    
    
    printf("\n\nSi desea agregar un contacto presione 1 \n");
    printf("Si desea eliminar un contacto presione 2 \n");
    printf("Si desea editar un contacto presione 3 \n");
    printf(">");
    scanf("%d", &decision);
    
    if(decision==1){
    printf("Seguro que desea agregar mas contactos a su agenda?\n");
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
        fprintf(A,"\n%d     %s    %.0f", code, name, phone_number);
        printf("\nDatos guardados con exito!!\n");
        printf("Desea agregar otro contacto a su agenda?\n");
        printf("(S)i o (N)o?\n");
        printf(">");
        scanf("%s", &respuesta);
        vr = 1;
    }

    if(vr == 1){
    system("cls"); // Borrar lo impreso anteriormente
    rewind(A); //volver a leer el archivo
    printf("Agenda actualizada correctamente!!\n");
    while(!feof(A)){
        fscanf(A, "%d", &code); 
        fscanf(A, "%s", &name);
        fscanf(A, "%f", &phone_number);
        printf("%d     %s    %.0f\n", code, name, phone_number);
    }
    }

    }else if(decision==2){
            printf("hola\n");
    }

    fclose(A);
    printf("Fin del programa\n");
    system("pause");

    return 0;
 }

