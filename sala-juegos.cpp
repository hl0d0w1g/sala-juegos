//2015
//Luis Cambero Piqueras 

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


#define MAX 5
#define encadena 2

void menu1(void);
void menu2(void);
void introduce_jugador(struct jugador [], int);
void palabras_encadenadas(struct jugador [], int);
int caracter_valido(char [], int); 
void num_curioso(struct jugador [], int);
int comprueba(int, long);
long potencia(int, int);
void intercambia(int*, int*);
void elemento_siguiente(struct jugador [], int);
void handicap(struct jugador [], int, float);
void clasificacion(struct jugador [], int);
void grabar_datos(struct jugador [], int);


struct jugador  //Se crea el struct jugdor
{        
	char nombre[20];         
	char apellido[30];        
	float puntuacion;        
	int handicap;        
};

main()
{
	struct jugador jugadores [MAX];
	int n, control1=0;
	char op_menu1, op_menu2, respuesta1;
	printf("****************************************\n");
	printf("*             Entregable 4             *\n"); //Titulo de presentacion del programa
	printf("*            SALA DE JUEGOS            *\n");
	printf("****************************************\n");
	do //Bucle que repite el menú de seleccion siempre y cuando la opcion escogida no sea la quinta
	{
		menu1(); //Llama a la funcion menu1
	    printf("  Opci%cn: ",162);
	    scanf("%c",&op_menu1);  //Se recoge la opcion seleccionada
	    fflush(stdin);
	    switch(op_menu1) //Bucle de analisis de la respuesta del usuario
	    {
		    case '1':{ //Opción 1: Introducir jugadores
		    	do  //Bucle de introduccion de datos que se repite tantas veces como jugadores existan
				{
					
		    		if(control1<MAX) 
					{
						control1++;
						introduce_jugador(jugadores, control1);		
	        		}
					if(control1>=MAX) //Cuando se alcance el maximo dejugadores no se podran introducir mas
					{
						printf("\n*Ya se han introducido el maximo n%cmero de jugadores*\n\n",163);
		    			break;
					}
					do
					{
						printf("\nDesea introducir otro jugador? (SI: s / NO: n):"); //Se vuelve a preguntar, en caso de ser s continuara el bucle
            			scanf("%c",&respuesta1);
	        			fflush(stdin);
					}while((respuesta1!='s')&&(respuesta1!='n'));
				}while(respuesta1=='s');
		    	break;
			}
		    case '2':{  //Opción 2: Juegos
		    	if(control1<2) //Se controla que se han introducido un minimo de 2 jugadores
		    	{
		    	 	printf("\n*Introduzca al menos dos jugadores*\n");
		    	 	break;
				}
				do //Bucle que repite el menú de seleccion siempre y cuando la opcion escogida no sea la d
				{
					menu2(); //Llama a la funcion menu2
	    			printf("  Opci%cn: ",162);
	    			scanf("%c",&op_menu2);  //Se recoge la opcion seleccionada
	    			fflush(stdin);
	    			switch(op_menu2) //Analisis de la respuesta del usuario
	    			{
		    			case 'a':{ //Opción 1: Palabras encadenadas
		    				palabras_encadenadas(jugadores, control1);
		    				break;
						}
		    			case 'b':{  //Opción 2: Numeros curiosos
							num_curioso(jugadores, control1);
							break;
						}
						case 'c':{ //Opción 4: elemento siguiente
							elemento_siguiente(jugadores, control1);
		    	 			break;
						}
						case 'd':{ //Opcion d: volver al menu anterior
							break;
						}
		    			default:{  //Si se introduce un caracter no valido, se muestra el error y se pregunta de nuevo
		    				printf("\n*Opci%cn no valida*\n\n",162); 
							break;
						}
					}
    			} while(op_menu2!='d'); //Solo si la respuesta es d, saldra del bucle do_while
				break;
			}
			case '3':{ //Opción 3: Clasificacion
		    	if(control1<2) //Se controla que se han introducido un minimo de 2 jugadores
		    	{
		    	 	printf("\n*Introduzca al menos dos jugadores*\n");
		    	 	break;
				}
				clasificacion(jugadores, control1);
		    	break;
			}
			case '4':{ //Opción 4: Grabar datos
		    	if(control1<2) //Se controla que se han introducido un minimo de 2 jugadores
		    	{
		    	 	printf("\n*Introduzca al menos dos jugadores*\n");
		    	 	break;
				}
				grabar_datos(jugadores, control1);
		    	break;
			}
			case '5':{ //Opcion 5: Salir del programa
				printf("\nFin del programa. Gracias por jugar con nosotros ;)\n\n"); //Muestra el mensaje y sale del switch y del do_while
				break;
			}
		    default:{  //Si se introduce un caracter no valido, se muestra el error y se pregunta de nuevo
		    	printf("\n*Opci%cn no valida*\n\n",162);
				break;
			}
		} 
    } while(op_menu1!='5'); //Solo si la respuesta es 5, saldra del bucle do_while y esperara una tecla para finalizar definitivamente
	printf("Pulsa una tecla para cerrar la ventana . . .");
	getch();	
}

void menu1(void) //Sirve solamente para mostrar el menú 1 del programa
{
	printf("\nPor favor seleccione una de las siguientes opciones:\n");
	printf("------------------------------------------------------\n");
	printf("  1. Introducir jugadores (Maximo %i)\n", MAX);
	printf("  2. Juegos\n");
	printf("  3. Clasificaci%cn\n", 162);
	printf("  4. Grabar datos\n");
	printf("  5. Salir del programa\n\n");
}

void menu2(void) //Sirve solamente para mostrar el menú 2 del programa
{
	printf("\nPor favor seleccione uno de los siguientes juegos:\n");
	printf("-----------------------------------------------------\n");
	printf("  a. Palabras encadenadas (2 jugadores)\n");
	printf("  b. N%cmeros curiosos (2 jugadores)\n", 163);
	printf("  c. %cSiguiente elemento? (1 jugador)\n", 168);
	printf("  d. Volver al men%c anterior\n\n", 163);
}

void introduce_jugador(struct jugador jugadores [MAX], int n)
 {
	printf("\nIntroduzca los datos del jugador %i\n",(n));
	do  //Bucle que se repite hasta introducir una cadena de tamaño correcto
	{
		printf("\nNombre: ");
		gets(jugadores[n-1].nombre);
		fflush(stdin);
	}while((strlen(jugadores[n-1].nombre)<1)||(strlen(jugadores[n-1].nombre)>20));
	do //Bucle que se repite hasta introducir una cadena de tamaño correcto
	{
		printf("Apellido: ");
		gets(jugadores[n-1].apellido);
		fflush(stdin);
	}while((strlen(jugadores[n-1].apellido)<1)||(strlen(jugadores[n-1].apellido)>30));
	do  //Bucle que se repite hasta introducir un valor correcto
	{
		printf("Handicap (entre 0 y 5): ");
		scanf("%i",&jugadores[n-1].handicap);
		fflush(stdin);
	}while((jugadores[n-1].handicap<0)||(jugadores[n-1].handicap>5));
	jugadores[n-1].puntuacion=0; //Se inicia la puntuacion en 0
 }
 
 void palabras_encadenadas (struct jugador jugadores [MAX], int control1)
 {
 	int i, jugadora, jugadorb, puntuaciona=0, puntuacionb=0, cont1=0, cont2=0, n=2;
	char palabra1 [41];  //Arrays para guardar las palabras
	char palabra2 [41];
	char comprueba1 [encadena+1];  //Arrays de comprobacion de encadenacion
	char comprueba2 [encadena+1];
	printf("****************************************\n"); //Titulo de presentacion del programa
	printf("*        PALABRAS   ENCADENADAS        *\n");
	printf("****************************************\n");
	printf("\nCaracteres a encadenar: %i\n", encadena);
	do
	{
		printf("\nIntroduce el n%cmero del jugador A: ", 163);
		scanf("%i",&jugadora);
		fflush(stdin);
		if((jugadora<1)||(jugadora>control1))
			puts("Jugador no valido");
	}while((jugadora<1)||(jugadora>control1));
	do
	{
		printf("\nIntroduce el n%cmero del jugador B: ", 163);
		scanf("%i",&jugadorb);
		fflush(stdin);
		if((jugadorb<1)||(jugadorb>control1)||(jugadorb==jugadora))
			puts("Jugador no valido");
	}while((jugadorb<1)||(jugadorb>control1)||(jugadorb==jugadora));
	do  //Bucle que se repite siempre y cuando la palabra no tenga la extension correcta o tenga caracteres invalidos
	{
		printf("\nJugador %i - Introduce la palabra inicial (entre %i y 40 caracteres): ", jugadora, (encadena+2));
		scanf("%s",palabra1);
		fflush(stdin);
		cont1=strlen(palabra1); //Se cuenta el numero de letras que tiene la palabra1
	}while((cont1<(encadena+2))||(encadena>40)||((caracter_valido(palabra1, cont1))==1));
	do  //Bucle que se repite siempre y cuando las palabras esten bien encadenadas
	{
		if(n>2)  
		{/*Si se ha superado la palabra inicial, se introduce la palabra2 en la palabra 1 para 
		   volver a usar la variable palabra2 y no perder la palabra contenida en palabra2*/
			for(i=0;i<=40;i++)
			{
				palabra1 [i]=palabra2 [i];
			}
		}
		do
		{  //Bucle que se repite siempre y cuando la palabra no tenga la extension correcta o tenga caracteres invalidos
			printf("\nJugador %i - Introduce la %i%c palabra encadenada (entre %i y 40 caracteres): ", jugadorb, n, 167, (encadena+2));
			scanf("%s",palabra2);
			fflush(stdin);
			cont2=strlen(palabra2); //Se cuenta el numero de letras que tiene la palabra2
		}while((cont2<(encadena+2))||(encadena>40)||((caracter_valido(palabra2, cont2))==1));
		n++; //Se aumenta el valor de n para la siguiente palabra
		for(i=0;i<encadena;i++)
		{
			comprueba1 [i]=palabra1 [(cont1-encadena)+i]; //Se introduce en el array comprueba1 las ultimas letras de palabra1 (el numero depende de la variable encadena)
			comprueba2 [i]=palabra2 [i];                  //Se introduce en el array comprueba2 las primeras letras de palabra2
		}
		comprueba1 [i]='\0'; //Se introduce el caracter de finalizacion en el array comprueba1 y comprueba2
		comprueba2 [i]='\0';
		if(strcmp(comprueba1,comprueba2)==0)
		{   //Si el cadenamiento es correcto se suman tatos puntos como letras tenga la palabra
			puntuacionb=((puntuacionb)+cont2); 
			printf("**%i puntos m%cs para el jugador %i, puntos totales obtenidos = %i**\n", cont2, 160, jugadorb, puntuacionb);
			intercambia (&jugadorb, &jugadora);        //Los jugadores intercambian los papeles
			intercambia (&puntuacionb, &puntuaciona);
			cont1=cont2;
		}
	}while((strcmp(comprueba1,comprueba2)==0));
	puntuaciona=((puntuaciona)+20);
	printf("Error del jugador %i, 20 puntos extra para el jugador %i\n", jugadorb, jugadora);
	puts("\nFin del juego");
	printf("\nPuntuaci%cn final del jugador %i = %i; ", 162, jugadora, puntuaciona); //Se muestra la puntuacion sin corregir y corregida por le handicap de cada jugador
	handicap(jugadores, jugadora, puntuaciona);
	printf("\nPuntuaci%cn final del jugador %i = %i; ", 162, jugadorb, puntuacionb);
	handicap(jugadores, jugadorb, puntuacionb);
	puts("\n\nPulsa un tecla para volver . . .");
	getch();
 }
 
 int caracter_valido(char palabra [41], int j)  //Funcion que comprueba que los caracteres introducidos estan entre la a minuscula a la z incluyendo la ñ
{
	int i, cont=0;
	for(i=0;i<j;i++)
		{
			if ((palabra[i]<97)||(palabra[i]>122))
			{
				if ((palabra[i])!=164)
					cont++;
			}	
		}
	if (cont==0)
	   return 0;
	else
	{
		printf("\nCaracteres no validos\n");
		return 1;
	}   
}

void num_curioso(struct jugador jugadores [MAX], int control1) //Comprueba la condicion de número curioso
{
	int ord, num, temp, x, y, z, rep, cont=0, jugadora, jugadorb, puntuaciona=0, puntuacionb=0; 
	char respuesta;
	printf("****************************************\n"); //Titulo de presentacion del juego
	printf("*          NUMEROS   CURIOSOS          *\n");
	printf("****************************************\n");
	do
	{
		printf("\nIntroduce el n%cmero del jugador A: ", 163);
		scanf("%i",&jugadora);
		fflush(stdin);
		if((jugadora<1)||(jugadora>control1))
			puts("Jugador no valido");
	}while((jugadora<1)||(jugadora>control1));
	do
	{
		printf("\nIntroduce el n%cmero del jugador B: ", 163);
		scanf("%i",&jugadorb);
		fflush(stdin);
		if((jugadorb<1)||(jugadorb>control1)||(jugadorb==jugadora))
			puts("Jugador no valido");
	}while((jugadorb<1)||(jugadorb>control1)||(jugadorb==jugadora));
	for(rep=0;rep<2;rep++)
	{
		do  //El bucle se repite hasta introducir un termino valido
		{
			printf("\nJugador %i - Introduzca el numero (entre 1 y 1000000): ", jugadora);
			scanf("%i",&num);
			fflush(stdin);
		} while((num<1)||(num>1000000)); 
		do
		{
			printf("\nJugador %i - %cEs el %i un n%cmero curioso? (SI: s / NO: n): ", jugadorb, 168, num, 163);
			scanf("%c",&respuesta);
			fflush(stdin);
		}while((respuesta!='s')&&(respuesta!='n'));
		if(respuesta=='s') //Si la respuesta es si se pregunta por el orden
		{
             do  //El bucle se repite hasta introducir un termino valido
		     { 
			     printf("\nIntroduzca el orden (entre 1 y 6): ");
			     scanf("%i",&ord);
			     fflush(stdin);
		     } while((ord<1)||(ord>6));
             if((comprueba(ord, num))==1)  //La funcion devuelve un uno si se cumple
             {
                  printf("\nCORRECTO - El %i cumple la condicion de n%cmero curioso para el orden %i\n\n", num, 163, ord);
                  puntuacionb=(puntuacionb+20);
             }else
             	printf("\nERROR - El %i NO cumple la condicion de n%cmero curioso para el orden %i\n\n", num, 163, ord);
        }else  //Si la respuesta es no, se comprueba para todos los oredenes del 1 al 6
        {
             for(ord=1;ord<=6;ord++)
             {
                 if((comprueba(ord, num))==1)
                     printf("\nERROR - El %i cumple la condicion de n%cmero curioso para el orden %i\n\n", num, 163, ord);
                 else
                     cont++;        
             }
             if(cont==6)
             {
             	puntuacionb=(puntuacionb+20);  
             	printf("\nCORRECTO - El %i no cumple la condicion de n%cmero curioso para ningun orden\n\n", num, 163);
			 }
                 
        } 
		intercambia (&jugadorb, &jugadora);         //Los jugadores intercambian los papeles
		intercambia (&puntuacionb, &puntuaciona);
	}
	puts("\nFin del juego");
	printf("\nPuntuaci%cn final del jugador %i = %i; ", 162, jugadora, puntuaciona); //Se muestra la puntuacion sin corregir y corregida por le handicap de cada jugador
	handicap(jugadores, jugadora, puntuaciona);
	printf("\nPuntuaci%cn final del jugador %i = %i; ", 162, jugadorb, puntuacionb);
	handicap(jugadores, jugadorb, puntuacionb);
	puts("\n\nPulsa un tecla para volver . . .");
	getch();   
}

int comprueba(int ord, long num) //Comprueba la condicion de número curioso
{
	int x=1000000, suma=0, temp, y, z;
	temp=num;  //Se copia el valor del numero a una variable temporal que se ira modificando
	for(;x>=1;)  
	{
	   y=(temp/x);
	   z=potencia(y, ord); //Se llama a la funcion potencia para que devuelva el siguiente termino a sumar
	   if (y!=0)  
	   {
	   	 temp=(temp-(x*y));
	   	 /*Si el resultado de la division del numero introducido entre el valor de x, es distinto de 0,
		   cosa que pasara solo cuando el resultado tenga una parte entera (ya que la variable es int y
		   no tomara los decimales), el valor de temp se reajustara eliminando el dijito ya extraido.
		   Ej: si num=153, cuando x=100, y=1, temp se reajustara restandole 100*1 (x*y), quedando solo
		   dos digitos 53, y se repite el proceso.*/
	   }
	   suma=(suma+z); //Se van sumando los valores devueltos por la funcion potencia
	   x=(x/10);  //Se reduce en uno el "tamaño" de x
    } 
    
    if (suma==num) //Si la suma de los terminos del numero elevados al exponente introducido es igual al numero en si, se cumple la condicion
       return 1;
    else
       return 0;
}

long potencia(int bas,int exp) //Devuelve la potencia del primero termino elevado al segundo 
{
	int resultado=1; //Inicializamos la variable resultado, que sera la que devuelva esta funcion
	for (int i=0;i<exp;i++)
    {
       resultado=resultado*bas;
       //Bucle que multiplicara el numero por si mismo tantas veces como indique el exponente
    }
	return resultado;
}

void intercambia (int *a, int *b) //Introduce el valor de a en b y viceversa
{
	int temp;
	temp=*b;
	*b=*a;
	*a=temp;
}

void elemento_siguiente (struct jugador jugadores [MAX], int control1)
{
	int x1=0, x2=1, cont, x, n, jugador, punt=0, elemento;
	printf("****************************************\n"); //Titulo de presentacion del juego
	printf("*          ELEMENTO  SIGUIENTE         *\n");
	printf("****************************************\n");
	do
	{
		printf("\nIntroduce tu n%cmero de jugador: ", 163);
		scanf("%i",&jugador);
		fflush(stdin);
		if((jugador<1)||(jugador>control1))
			puts("Jugador no valido");
	}while((jugador<1)||(jugador>control1));
	n=((rand()%11)+10);   // Genera un numero aleatorio entre 10 y 20
	for (cont=1;cont<n;cont++)
	{
		x=(x1+x2); //Se llama a la funcion elemento_siguiente para que de el valor actual de la sucesion que se va a mostrar
	    x1=x2; //Se reasigna el valor de cada variable con los actuales dos numeros anteriores
	    x2=x;
	}
	printf("\n%cCual es el elemeto siguiete al %i de la serie de Fibonacci?  ", 168, x);
	scanf("%i",&elemento);
	fflush(stdin);
	if(elemento==(x1+x2)) //Si el numero introducido es la suma de los dos anteriores, la respuesta es correcta
		punt=(punt+10);
	else
		punt=(punt-10);
	puts("\nFin del juego");
	printf("\nPuntuaci%cn final del jugador %i = %i; ", 162, jugador, punt); //Se muestra la puntuacion sin corregir y corregida por le handicap del jugador
	handicap(jugadores, jugador, punt);
	puts("\n\nPulsa un tecla para volver . . .");
	getch();
}

void handicap(struct jugador jugadores [MAX], int jug, float punt) //Corregira la puntuacion de cada jugador en funcion de su handicap
{
	if(jugadores[jug-1].handicap!=0) //Si el handicap es 0 no hace falta correccion de la puntuacion
	{
		punt=(punt+((punt*(jugadores[jug-1].handicap))/10)); //Se suma el porcentaje de su puntuacion de acuerdo al handicap
	}
	jugadores[jug-1].puntuacion=(jugadores[jug-1].puntuacion+punt);
	printf("Corregida por el handicap del jugador %i es: %.2f", jug, punt);
}

void clasificacion(struct jugador jugadores [MAX], int control1)
{
	float orden [control1];
	int imprimir [control1];
	int i, j, x, z, temp, temp2, temp3, cont, n=0;
	for(i=0;i<control1;i++) //Se copian las puntuaciones de los jugadores en el array orden
	{
		orden[i]=(jugadores[i].puntuacion);
	}
	for(i=0;i<control1;i++) //Se ordenan los valores dentro del array de mayor a menor
    {
    	for(j=0;j<(control1-1);j++)
    	{
    		if(orden[j]<orden[j+1]) 
			{
				temp=orden[j]; 
                orden[j]=orden[j+1]; 
                orden[j+1]=temp;
			} /*Si un numero es menor que el siguiente, se intercambian. Repitiendo el proceso se consigue que el mayor llegue a 
		        la primera posicion del array, el segundo mayor a la segunda, etc*/
		}           
	}      
	printf("\n\nCLASIFICACION:\n\n");
	printf("NOMBRE\t\tAPELLIDO\t\tNUMERO\t\tHANDICAP\tPUNTUACION\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	for(i=0;i<control1;i++) //Se introducen en el array imprimir los numeros posibles de jugador
	{
		imprimir[i]=i;
	}
	for(cont=0;cont<control1;cont++)  //Bucle de impresion de datos
	{
 		for(n=0;n<control1;n++)
    	{
    		if(imprimir[n]>=0) //Solo se comprobara sobre los jugadores que queden por imprimir
			{
    			if(orden[cont]==(jugadores[imprimir[n]].puntuacion)) 
    			{
					break;
				} /*Se comprueban las puncuaciones del struct, cuando lluege a la que coincide con la primera posicion del array orden (es decir la mayor
			    	puntuacion) sale del bucle y se usa el valor con el que se ha quedado n para imprimir los datos del jugador que tiene la mayor puntuacion*/
			}
		}
		printf("%s\t\t", jugadores[imprimir[n]].nombre);
		printf("%s\t\t\t", jugadores[imprimir[n]].apellido);
		printf("%i\t\t", (imprimir[n]+1));
		printf("%i\t\t", jugadores[imprimir[n]].handicap);
		printf("%.2f\n", jugadores[imprimir[n]].puntuacion);
		for(j=0;j<control1;j++)
		{
			if(imprimir[n]==imprimir[j]) 
			{//Se sustituye en el array imprimir el jugador que ya se impreso por un numero negativo, de tal forma que sabemos que jugadores quedan por imprimir
				imprimir[j]=(-1);
			}
		}	 
	}
	printf("-----------------------------------------------------------------------------------------------\n");
	puts("Pulsa un tecla para volver . . ."); 
	printf("\n\n\n");              
}

void grabar_datos(struct jugador jugadores [MAX], int x)
{
	FILE *fichero;
	int n, i, cont=0, cont1=0;
	char nombre [20];
	char extension [5]=".txt";
	printf("\nIntroduce el nombre del fichero: ");
	gets(nombre);
	cont1=strlen(nombre); //Se cuenta el numero de letras que tiene la palabra
	for(i=0;i<4;i++) //Se comprueba que la extension introducida es correcta
		{
			if(extension [i]!=nombre [(cont1-4)+i])
				cont++;                
		}
	if(cont!=0)  //Si la extension no es correcta se añade automaticamente la extension correcta
	{
		strcat (nombre, extension);
	}
	fichero=fopen(nombre, "w+"); //Se crea el archivo con el nombre indicado
	if(fichero==NULL)
		puts("El archivo no se ha podido abrir correctamente");
	else
	{
		for(n=0;n<x;n++)  //Bucle de impresion de datos
		{
			fprintf(fichero, "%s; ", jugadores[n].nombre);
			fprintf(fichero, "%s; ", jugadores[n].apellido);
			fprintf(fichero, "%i; ", jugadores[n].handicap);
			fprintf(fichero, "%.2f;\n", jugadores[n].puntuacion);
		}	
	}
	if(fclose(fichero)==0) //Si se cierra correctamente el archivo se muestra un mensaje informando, sino se muestra el error
		printf("\nLos datos se han grabado correctamente en el archivo '%s'\n\n", nombre);
	else
		printf("\nHa ocurrido un error al grabar los datos en el archivo '%s'\n\n", nombre);
}
