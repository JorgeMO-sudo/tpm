/*
* Jorge Márquez Ortega, 5 Mar 2021
*/
#include <Socket_Servidor.h>
#include <Socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

main (int argc,char** argv)
{
	if(argc < 3){
		printf("Error parametros insuficientes: \n");
		printf("Usage: Servidor servicio puerto[1025-65536] \n");
		exit(-1);
	}

	char* servicio = argv[1];
	char* puerto = argv[2];
	if((atoi(puerto) < 1025)||(atoi(puerto) > 65536)){
		printf("Error puerto fuera de rango: \n");
		printf("Usage: puerto[1025-65536] \n");
		exit(-1);
	}


	/*
	* Descriptores de socket servidor y de socket con el cliente
	*/
	int Socket_Servidor;
	int Socket_Cliente;
	char Cadena[100];

	/*
	* Se abre el socket servidor, con el servicio "cpp_c" si no está dado de
	* alta en /etc/services se actualiza el fichero con el puerto 15557 
	*/
	Socket_Servidor = Abre_Socket_Inet (servicio,puerto);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket servidor\n");
		exit (-1);
	}

	/*
	* Se espera un cliente que quiera conectarse
	*/
	Socket_Cliente = Acepta_Conexion_Cliente (Socket_Servidor);
	if (Socket_Servidor == -1)
	{
		printf ("No se puede abrir socket de cliente\n");
		exit (-1);
	}

	/*
	* Se lee la informacion del cliente, suponiendo que va a enviar 
	* 5 caracteres.
	*/
	Lee_Socket (Socket_Cliente, Cadena, 5);

	/*
	* Se escribe en pantalla la informacion que se ha recibido del
	* cliente
	*/
	printf ("Soy Servior, he recibido : %s\n", Cadena);

	/*
	* Se prepara una cadena de texto para enviar al cliente. La longitud
	* de la cadena es 5 letras + \0 al final de la cadena = 6 caracteres
	*/
	strcpy (Cadena, "Adios");
	Escribe_Socket (Socket_Cliente, Cadena, 6);

	/*
	* Se cierran los sockets
	*/
	close (Socket_Cliente);
	close (Socket_Servidor);
}
