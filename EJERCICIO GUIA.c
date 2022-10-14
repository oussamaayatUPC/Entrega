#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int es_palindromo(char nombre[20]) {
	int palindromo = 1;
	int i = 0;
	for(i = 0; i<strlen(nombre);i++){
		if (nombre[i]!=nombre[strlen(nombre)-1 - i]) {
			palindromo = 0;
		}
	}
	return palindromo;
	
}
void nombre_mayuscula(char nombre[20], char nombre1[20]) {
	strcpy(nombre1,"");
	int i = 0;
	for(i = 0; i<strlen(nombre);i++){
		strcat(nombre, toupper(nombre[i]));
	}
}

int main(int argc, char *argv[]) {
	char peticion[100];
	char resultado[100];
	
	strcpy(peticion, "Miguel/47/Juan/12/Maria/22/Marcos/19");
	
	char nombre[20];
	int edad;
	char *p = strtok (peticion, "/");
	
	while (p!=NULL)
	{
		strcpy(nombre,p)
		p = strtok (NULL);
		edad = atoi (p);
		if (edad > 18)
			sprintf (respuesta, "%s%s*%d-", respuesta, nombre, edad);
		
		p = strtok(NULL, "/");
	}
	respuesta [strlen(respuesta) - 1] = '\0';
	printf("Resultado: %s\n", respuesta);
	
}