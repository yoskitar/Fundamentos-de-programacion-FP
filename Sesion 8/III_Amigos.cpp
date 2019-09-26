/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
// 
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
// 
// 
/* 
         Sesión 01-08.
         Problema número 14:
         Programa para calcular si dos números dados son amigos mediante
         funciones, y una segunda parte en la que dado un valor,
         busque si en un radio determinado el número introducido tiene
         o no amigos.
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <string>     //Inclusión de recursos de tipo string.
#include <cmath>    //Inclusión de recursos matemáticos.

using namespace std; 

//Función para filtrar que los valores introducidos sean positivos.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero;
	
	valores_correctos = ( numero >= 0 );
	
	}while(!valores_correctos);
	
	return numero;
	
}


/*
Función para hallar los divisores de un número, mediante un ciclo
while que se repite hasta que el divisor sea menor que 2. Si al dividir
el numero por el divisor, el resto es cero, dicho divisor se va añadiendo
a una suma de todos los divisores del número dado. Finalmente devielve el 
resultado de la suma.
*/
int Divisores(int dividendo){
	
	int divisor;
	bool divide;
	int suma;
	
	divisor = dividendo;
	divisor--;
	suma = 0;
	
	while(divisor>1){
		
		divide = ( (dividendo % divisor) == 0 ) ;
   	
      if (divide){
   	
	   suma = suma + divisor;
		
	   }
		
	   divisor--; 
   
	}
   
	return suma;    
}

/*
Función que empleando las anteriores funciones, duvuelve si dos número son
o no amigos. Si la suma de los diviores del primero mas 1 es igual al segundo 
número dado y viceversa, los números se consideran amigos.
*/
string Amigos(int num_1, int num_2){
	
	int suma_1;
	int suma_2;
	
	bool amigos;
	bool amigo_1;
	bool amigo_2;
	
	string son_amigos;
	string no_son_amigos;
	string respuesta;
	
	
	suma_1 = Divisores(num_1);
	suma_2 = Divisores(num_2);
	
	amigo_1 = ( (suma_1 + 1 ) == num_2 );
	amigo_2  = ( (suma_2 + 1 ) == num_1);
	amigos = (amigo_1 && amigo_2 );
	
	son_amigos =( "\nLos numeros " + to_string(num_1) + " y "
	+ to_string(num_2) + " son amigos." ); 
		
	no_son_amigos = ( "\nLos numeros " + to_string(num_1) + " y "
	+ to_string(num_2) + " no son amigos." ); 
	
	
	respuesta = (amigos)? son_amigos:no_son_amigos;
	
   return respuesta;
}

/*
Función que recorre un intervalo dado comprobando si un número tiene
algun amigo en dicho intervalo. La función va recorriendo todos los
valores del intervalo mediante un ciclo while, y en caso de 
encontrar algún amigo del número dado, suma a una cadena string
el mensaje correspondiente. Cuando evalúa todos los valores del intervalo,
devuelve la cadena con todos los amigos del número, o con el mensaje
correspondiente en caso de no tener ninguno en dicho intervalo. 
*/
string AmigoCercano(int num_3){
	
	const double RADIO = 1.0/3.0;
	int max;
	int min;
	int diferencia;
	string son_amigos;
	string amigo;
	string friendfound;
	string no_encontrados;
	string inicio;
	
	diferencia = num_3 * RADIO;
	max = num_3 + diferencia;
	min = num_3 - diferencia;
	friendfound = "\nNo se han encontrado amigos.";
	inicio =  "" ;
	
	while(max > min){
	
	   amigo = Amigos(num_3, max);
	
	   son_amigos = ( "\nLos numeros " + to_string(num_3) + " y "
	   + to_string(max) + " son amigos." ); 
	   no_encontrados = ( "\nNo se han encontrado amigos en dicho radio." );
   
   	if(amigo == son_amigos) {
   	
		  friendfound = inicio + son_amigos;	
   	  inicio = friendfound;
   	  
		}
		
		max--;
	}
   
   return friendfound;
   
}


int main(){  //Programa principal.
	
	//Declaración de variables.

	int num_1;
	int num_2;
	int num_3;
	string amigos;
	string amigo_cercano;
	
	//Entrada de datos 1.
	
	num_1 = Filtro( "\nIntroduzca un primer entero positivo: " );
	num_2 = Filtro( "\nIntroduzca un segundo entero positivo: " );
	
   
   //Cálculos 1.
   
   amigos = Amigos(num_1, num_2);
   
   
   //Resultados 1.
   
   cout << amigos;

   
   //Entrada de datos 2.
   
   num_3 = Filtro( "\n\nIntroduzca un entero positivo para comprobar si"
	" tiene algun amigo en un radio de cercania a 1/3 de él: " );


   //Cálculos 2.
   
   amigo_cercano = AmigoCercano(num_3);
 
 
   //Resultados2.
   
   
   cout << "\nCalculo de amigos en un radio de 1/3 de " << num_3
	<< ": \n" << amigo_cercano;
   
   
	return(0);
}
