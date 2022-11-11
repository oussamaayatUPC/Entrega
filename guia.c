void *AtenderCliente (void *socket){
	int sock_conn;
	int *s;
	s = (int *) socket;
	sock_conn = *s;
	char peticion[read_buffer_length];
	char respuesta[write_buffer_length];
	int ret;
	int terminar =0;
	while  (terminar == 0){
		
	
	ret = read(sock_conn,peticion,sizeof(peticion));
	printf("Recibido");
	peticion[ret]='\0';
	
	printf("Peticion: %s\n",peticion);
	
	char *p = strtok (peticion, "/");
	int codigo = atoi(p);
	
	char nombre_usuario[username_max_length];
	
	
	char contrasena[password_max_length];
	char correo[email_max_length];
	char fecha[10];
	char dia1[10];
	char dia2[10];
	MYSQL *conn;
	conn = mysql_init(NULL);
	if (conn == NULL) {
		printf("Error al crear la conexion: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	conn = mysql_real_connect(conn, database_host, database_username, database_password, database_name, 0, NULL, 0);
	
	if (conn == NULL) {
		
		printf("Error conectando: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
		
    
	}
	mysql_close(conn);		
	close(sock_conn);
	
	
	
}

int sock_conn, sock_listen;
	struct sockaddr_in serv_adr;
	if ((sock_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		printf("Error creant socket");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
 	serv_adr.sin_family = AF_INET;
 	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY); 
 	serv_adr.sin_port = htons(port);
	
 	if (bind(sock_listen, (struct sockaddr *) &serv_adr, sizeof(serv_adr)) < 0)
		printf("Error al bind");
	if (listen(sock_listen, 5) < 0)
		printf("Error en el Listen");
	int i;
	int sockets[100];
	i = 0;
	pthread_t thread;
	for(;;){
		printf("Escuchando\n");
		sock_conn = accept(sock_listen, NULL, NULL);
		printf("Conexion recibida\n");
		sockets[i] = sock_conn;
		pthread_create(&thread, NULL, AtenderCliente, &sockets[i]);
		i = i + 1;
		
	}
	return 0;