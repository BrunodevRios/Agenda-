#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>


int main(){
    
    int code, vr=0; //vr = validador; 
    float phone_number;
    char name[20], answer; 

    FILE *A;
    A = fopen("contactos.txt", "r+"); // el simbolo + es para que pododamos agregar cosas al archivo txt
    if(A == NULL){
        printf("\n ERROR PARA ABRIR ARCHIVO \n");
        exit(0);
    }else{
        printf("\n      ARCHIVO ABIERTO CORRECTAMENTE!! \n");
    }
   

    //feof = terminar de leer archivo
    while(!feof(A)){
        fscanf(A, "%i", &code); //fscanf = lee dentro del archivo, utiliza el puntero y el tipo de dato que queremos leer y donde se debe guardar
        fscanf(A, "%s", &name);
        fscanf(A, "%f", &phone_number);
        printf("\n%i     %s    %.0f\n", code, name, phone_number);
    }

    printf("Desea agregar mas contactos a su agenda?\n");
        printf("(S)i o (N)o?\n");
        printf(">");
        scanf("%s", &answer);

    while(answer=='s' || answer=='S'){
        printf("Codigo:");
        scanf("%i", &code); 
        printf("Nombre:");
        scanf("%s", &name);
        printf("Numero de telefono:");
        scanf("%f", &phone_number);
        fprintf(A,"\n%i     %s    %.0f", code, name, phone_number);
        printf("\nDatos guardados con exito!!\n");
        printf("Desea agregar otro contacto a su agenda?\n");
        printf("(S)i o (N)o?\n");
        printf(">");
        scanf("%s", &answer);
        vr = 1;
    }

    if(vr == 1){
    system("cls"); // Borrar lo impreso anteriormente
    rewind(A); //volver a leer el archivo
    printf("Agenda actualizada correctamente!!\n");
    while(!feof(A)){
        fscanf(A, "%i", &code); 
        fscanf(A, "%s", &name);
        fscanf(A, "%f", &phone_number);
        printf("%i     %s    %.0f\n", code, name, phone_number);
    }


    }

    fclose(A);
    printf("Fin del programa\n");
    system("pause");

    return 0;
 }

