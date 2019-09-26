/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-06.
         Problema n�mero 30:
            Programa para codificar secuencia de valores, como
            el mecanismo de compresi�n de datos 'zip', es decir,
            el valor y el n�mero de veces que se repite dicho valor.
            
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.

using namespace std; 


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   	int num_1;                //N�mero introducido.
      int num_de_digitos;       //Contador de digitos.
      int num_1_original;       //Valor de num_1.
      int digito;               //D�gito a pintar.
      int num_1_restos;         //Restos del valor num_1.
      int potencia_diez;        //10 elevado al n�mero d d�gitos.
      int valor;                //Valor num�rico del digito.
      int repeticiones;     //Valor inicial de repeticiones.
      
      double num_1_double;      //Valor real para el filtro.
      
      bool valores_correctos_numero;   //Condici�n del filtro.
      
   //Entrada de datos.
   
   //Filtro para introducir valores enteros naturales.
   
   do{
		
	cout << "Introduzca una secuencia de enteros: ";              
	cin >> num_1_double;
	
	num_1 = num_1_double;
	
	valores_correctos_numero = (num_1_double - num_1 == 0);
	
	}while(!valores_correctos_numero);
  
		
	//C�lculos.
	   
	   //Guardamos el valor del entero para no perderlo.
	   num_1_original = num_1;
	   //Ponemos en cero el contador de d�gitos.
	   num_de_digitos = 0;
	   
      /*
		Mientras el n�mero pueda ser dividido entre 10
      sin dar cero como resultados, el contador se 
      incrementar� en uno. Realmente no se 
      corresponde con el n�mero de cifras del 
      d�gito, sino con uno menos, para poder hallar
      el n�mero dividiendolo por potencias de diez
      en funci�n del valor obtenido en este primer bucle.
      */
      
		while((num_1/10) != 0){
			
			num_de_digitos = num_de_digitos + 1;
			num_1 = (num_1/10);
			
	   }
		
		num_1_restos = num_1_original;
		
		/*
		Primero se calcula el valor del primer digito de la secuencia;
		mientras el n�mero de digitos no sea inferior a cero, se repetir�
		el ciclo while.
		Dentro encontramos varios condicionales para los diferentes
		casos a encontrar.
		Si al dividir el n�mero entre la potencia de diez correspondiente
		el valor es diferente, ej: 3355, como el 3 es distinto del 5,
		el programa pintar� el valor 3 con el valor del contador de 
		repeticiones, 2 en este caso, quedando '23'.
		Cuando el n�mero de d�gitos sea inferior a cero, es decir,
		la ultima ejecuci�n del ciclo while, entraremos en el primer
		condicionante, donde se repetir� la salida de datos correspondiente
		como en el caso anterior.
		En resumen, el programa va comparando los d�gitos de la secuencia
		y cuando detecta que el valor cambia nos muestra la salida.
	
		*/
		
		cout << "\nEl numero " << num_1_original <<" comprimido ser�a: "
		<< "\n\n" <<"\t";
		
		potencia_diez = pow(10, num_de_digitos);	 
		digito = num_1_restos / potencia_diez;
		valor = digito;
		repeticiones = 0;
		
		while( num_de_digitos >= 0 ){
			
		  potencia_diez = pow(10, num_de_digitos);	 
		  digito = num_1_restos / potencia_diez;
		  num_de_digitos = num_de_digitos -1;
	     num_1_restos = num_1_restos % potencia_diez;
	     
	     if(num_de_digitos == -1){
	     	
			repeticiones++;
		   cout << repeticiones << digito ;
		  
		  }
	     
	   
		
	     if (valor != digito ){

	      cout << repeticiones << valor;
	      repeticiones = 0;
	    
	     }
	    
	     
	     repeticiones = repeticiones + 1;
	     valor = digito;
	     
	  }
	    
		cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
