#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	//Conector para acceder al servidor de bases de datos 
	MYSQL *conn;
	int err;
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	//inicializar la conexion, indicando nuestras claves de acceso
	// al servidor de bases de datos (user,pass)
	conn = mysql_real_connect (conn, "localhost","root", "mysql", NULL, 0, NULL, 0);
	if (conn==NULL)
	{
		printf ("Error al inicializar la conexion: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	
	// ahora vamos a crear la base de datos, que se llamara personas
	// primero la borramos si es que ya existe (quizas porque hemos
	// hecho pruebas anteriormente
	consulta = "SELECT FROM partidas WHERE fecha = 'fecha' AND id1 OR id2 CONTAINS 'id'"
}
