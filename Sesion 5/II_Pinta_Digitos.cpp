/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-05.
         Problema número 17:
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
   
   	int num_1;                //Número introducido.
      int num_de_digitos;       //Contador de digitos.
      int num_1_original;       //Valor de num_1.
      int digito;               //Dígito a pintar.
      int num_1_restos;         //Restos del valor num_1.
      int potencia_diez;        //10 elevado al número d dígitos.
      
   //Entrada de datos.
   
	cout << "\nIntroduzca un numero entero: ";
	cin >> num_1;
  
		
	//Cálculos.
	   
	   //Guardamos el valor del entero para no perderlo.
	   num_1_original = num_1;
	   //Ponemos en cero el contador de dígitos.
	   num_de_digitos = 0;
	   
      /*
		Mientras el número pueda ser dividido entre 10
      sin dar cero como resultados, el contador se 
      incrementará en uno. Realmente no se 
      corresponde con el número de cifras del 
      dígito, sino con uno menos, para poder hallar
      el número dividiendolo por potencias de diez
      en función del valor obtenido en este primer bucle.
      */
      
		while((num_1/10) != 0){
			
			num_de_digitos = num_de_digitos + 1;
			num_1 = (num_1/10);
			
	      }
		
		num_1_restos = num_1_original;
		
		/*
		El bucle se repetirá mientras el contador de dígitos
		sea como mínimo cero. Dentro del bucle, se calcula
		una potencia de die en función del número de 
		dígitos y se divide el número entre dicha potencia,
		a la vez que decrece en una unidad el contador de
		dígitos, y el valor del múmero intoducido pasa a ser
		el resultado del resto de dicho número entre la potencia
		de diez; se imprime por pantalla el resultado de la divisón 
		del valor de la división entre la potencia.
		*/
		
		cout << "\nEl numero " << num_1_original <<" esta formado por "
		<< "los digitos:" << "\n\n";
		
		while( num_de_digitos >= 0 ){
			
		  potencia_diez = pow(10, num_de_digitos);	
		  digito = num_1_restos / potencia_diez;
		  num_de_digitos = num_de_digitos -1;
	     num_1_restos = num_1_restos % potencia_diez;

	    cout << "   " <<digito;
	     
	  }
	    
		cout << "\n\n";
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
