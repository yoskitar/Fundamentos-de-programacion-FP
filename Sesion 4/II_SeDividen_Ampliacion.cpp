/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesion 01-04.
         Problema n�mero 12:
            Leer dos valores enteros y decir qui�n divide a qui�n.
            En caso de alguno de ellos ser cero, mostrar por pantalla
            que ninguno divide al otro.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>    // Inclusi�n de llamadas al sistema.

using namespace std; 

//Clase para separar c�lculos de resultados.
enum class Divisibles {no_divisibles, divisible_1, divisible_2};


int main(){ // Programa Principal.
         
            
   // Declara variables para guardar.

	Divisibles divide;     //Clase declarada.
	
	int num_1;            //Valores a comparar 
   int num_2;           //si se dividen o no.
   
 
   //Entrada de datos.
	
	cout << "\nIntroduzca el primer numero: ";
	cin >> num_1;
	
	cout << "\nIntroduzca el segundo numero: ";
	cin >> num_2;
	
		

	//C�lculos.
	
	/*
	Estructura condicional donde en caso de alguno de los valores
	ser cero, muestra en resultados dicho caso con su respectivo
	mensaje.
	Si los valores son distintos a cero, comprueba si el primer valor
	divide al segundo y viceversa, mostrandose en resultdos el
	mensaje correspondiente a cada caso.
	*/
	
	if ( num_1 == 0 || num_2 == 0 ){
   	
   	divide = Divisibles::no_divisibles;
   		
	}
	
	else{
	
    	if ( (num_1 % num_2) == 0) {
    		
    		divide = Divisibles::divisible_1;
		
   	}
	
   	if ( (num_2 % num_1) == 0) {
   		
   		divide = Divisibles::divisible_2;
		
   	}
   	
   }
  	 
  	
  	//Resultados.
  	
  	/*
  	El primer caso se corresponde al primer condicional, donde alguno
  	de los valores introducidos es cero. El segundo y el tercer caso
  	muestra cuando uno de los valores es divisible por el otro.
  	*/
  	
  	switch (divide){
  		case Divisibles::no_divisibles:
  			cout<< "\nNo son divisibles." << "\n";
  			break;
  		
		case Divisibles::divisible_1:
		   cout<< "\nEl numero " << num_1 << " es divisible por " 
	   	<< num_2;
			break;
			
	   case Divisibles::divisible_2:
	      cout<< "\nEl numero " << num_2 << " es divisible por " 
		   << num_1;
		   
  	}
  	
  	
	cout << "\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
