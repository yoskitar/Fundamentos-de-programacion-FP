/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-05.
         Problema n�mero 17:
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
   
   	int num_1;                //N�mero introducido.
      int num_de_digitos;       //Contador de digitos.
      int num_1_original;       //Valor de num_1.
      int digito;               //D�gito a pintar.
      int num_1_restos;         //Restos del valor num_1.
      int potencia_diez;        //10 elevado al n�mero d d�gitos.
      
   //Entrada de datos.
   
	cout << "\nIntroduzca un numero entero: ";
	cin >> num_1;
  
		
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
		El bucle se repetir� mientras el contador de d�gitos
		sea como m�nimo cero. Dentro del bucle, se calcula
		una potencia de die en funci�n del n�mero de 
		d�gitos y se divide el n�mero entre dicha potencia,
		a la vez que decrece en una unidad el contador de
		d�gitos, y el valor del m�mero intoducido pasa a ser
		el resultado del resto de dicho n�mero entre la potencia
		de diez; se imprime por pantalla el resultado de la divis�n 
		del valor de la divisi�n entre la potencia.
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
