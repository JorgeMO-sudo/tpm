#include <stdio.h>
#include <Socket_Cliente.h>
#include <Socket.h>
#include <string.h>
#include <stdlib.h>

main (int argc,char** argv)
{
	if(argc < 4){
		printf("Error parametros insuficientes \n");
		printf("Usage: Cliente host ip servicio\n");
	}

	char* host_name = argv[1];
	char* ip = argv[2];
	char* servicio = argv[3];
	/*
	* Descriptor del socket y buffer para datos
	*/
	int Socket_Con_Servidor;
	char Cadena[100];

	/*
	* Se abre la conexion con el servidor, pasando el nombre del ordenador
	*/
	Socket_Con_Servidor = Abre_Conexion_Inet (host_name,ip,servicio);
	if (Socket_Con_Servidor == 1)
	{
		printf ("No puedo establecer conexion con el servidor\n");
		exit (-1);
	}

	/*
	* Se prepara una cadena con 5 caracteres y se envia, 4 letras mas
	* el \0 que indica fin de cadena en C
	*/
	strcpy (Cadena, "Hola");
	Escribe_Socket (Socket_Con_Servidor, Cadena, 5);

	/*
	* Se lee la informacion enviada por el servidor, que se supone es
	* una cadena de 6 caracteres.
	*/
	Lee_Socket (Socket_Con_Servidor, Cadena, 6);

	/*
	* Se escribe en pantalla la informacion recibida del servidor
	*/
	printf ("Soy cliente, He recibido : %s\n", Cadena);

	/*
	* Se cierra el socket con el servidor
	*/
	close (Socket_Con_Servidor);
}
