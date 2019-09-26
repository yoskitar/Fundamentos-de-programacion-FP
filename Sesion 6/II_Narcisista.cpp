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
         Problema n�mero 34:
            Escribid en pantalla los d�gitos de cualquier entero 
            introducido.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.

using namespace std; 


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   	int num_1;                   //N�mero introducido.
      int num_digitos;             //Contador de digitos.
      int num_1_original;          //Valor de num_1.
      int digito;                  //D�gito a pintar.
      int num_1_restos;            //Restos del valor num_1.
      int potencia_diez;           //10 elevado al n�mero d d�gitos.
      int suma;                    //Sumatorio de las potencias n-�simas.
      int num_digitos_original;    //Valor oriinal del n�mero de d�gitos.
      
      double num_1_double;       //N�mero introducido double.
      
      bool valores_correctos_numero;   //Condici�n para el filtro.
      
   //Entrada de datos.
   
   
   //Filtro para controlar que los valores introducidos sean correctos.
	do{
		
	cout << "Introduzca un numero entero positivo: ";              
	cin >> num_1_double;
	
	num_1 = num_1_double;
	
	valores_correctos_numero = ( num_1 > 0 ) && 
	(num_1_double - num_1 == 0);
	
	}while(!valores_correctos_numero);
  
		
		
	//C�lculos.
	
	   
	   //Guardamos el valor del entero para no perderlo.
	   num_1_original = num_1;
	   //Ponemos en cero el contador de d�gitos.
	   num_digitos = 0;
	   
      /*
		Mientras el n�mero pueda ser dividido entre 10
      sin dar cero como resultados, el contador se 
      incrementar� en uno. Realmente no se 
      corresponde con el n�mero de cifras del 
      d�gito, sino con uno menos, para poder hallar
      el n�mero dividiendolo por potencias de diez
      en funci�n del valor obtenido en este primer bucle.
      */
      
		for( num_digitos = 0 ; (num_1/10) != 0; num_digitos++){
		   
			num_1 = (num_1/10);

		}
		
		num_1_restos = num_1_original;
		
		/*
		Ciclo for que se repetira hasta que el contador sea
		inferior cero. Dentro observamos una estructura condicional,
		para filtrar la salida de datos donde si la suma de los
		valores de las potencias se corresponde con el valor
		del n�mero introducido dar� la salida correspondiente.
	
		*/
		
		suma = 0;
		num_digitos_original = num_digitos + 1;
		
		for(; num_digitos >= 0 ; num_digitos--){
		   
		  potencia_diez = pow(10*1.0, num_digitos);	
		  digito = num_1_restos / potencia_diez;
	     num_1_restos = num_1_restos % potencia_diez;
	     
	     suma = suma + pow(digito*1.0, num_digitos_original);
		 
		}
		
		if (suma == num_1_original){
			
			cout << "\nEl numero introducido " <<num_1_original
			<< " es narcisista.";
		
		}
		else{
			
			cout << "\nEl numero introducido " <<num_1_original
			<< " no es narcisista.";
		
		}

	    
		cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
