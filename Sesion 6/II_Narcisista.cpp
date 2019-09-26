/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-06.
         Problema número 34:
            Escribid en pantalla los dígitos de cualquier entero 
            introducido.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.

using namespace std; 


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   	int num_1;                   //Número introducido.
      int num_digitos;             //Contador de digitos.
      int num_1_original;          //Valor de num_1.
      int digito;                  //Dígito a pintar.
      int num_1_restos;            //Restos del valor num_1.
      int potencia_diez;           //10 elevado al número d dígitos.
      int suma;                    //Sumatorio de las potencias n-ésimas.
      int num_digitos_original;    //Valor oriinal del número de dígitos.
      
      double num_1_double;       //Número introducido double.
      
      bool valores_correctos_numero;   //Condición para el filtro.
      
   //Entrada de datos.
   
   
   //Filtro para controlar que los valores introducidos sean correctos.
	do{
		
	cout << "Introduzca un numero entero positivo: ";              
	cin >> num_1_double;
	
	num_1 = num_1_double;
	
	valores_correctos_numero = ( num_1 > 0 ) && 
	(num_1_double - num_1 == 0);
	
	}while(!valores_correctos_numero);
  
		
		
	//Cálculos.
	
	   
	   //Guardamos el valor del entero para no perderlo.
	   num_1_original = num_1;
	   //Ponemos en cero el contador de dígitos.
	   num_digitos = 0;
	   
      /*
		Mientras el número pueda ser dividido entre 10
      sin dar cero como resultados, el contador se 
      incrementará en uno. Realmente no se 
      corresponde con el número de cifras del 
      dígito, sino con uno menos, para poder hallar
      el número dividiendolo por potencias de diez
      en función del valor obtenido en este primer bucle.
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
		del número introducido dará la salida correspondiente.
	
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
