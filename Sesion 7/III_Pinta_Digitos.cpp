/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-07.
         Problema n�mero 3:
            Escribid en pantalla los d�gitos de cualquier entero 
            introducido mediante la utilizaci�n de funciones.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Primera funci�n para ir transformando los d�gitos en cadena de texto.

string ToString(int digito, string cadena){
	
	string texto;
	
	texto = to_string(digito) + ", ";
   texto = cadena + texto;
   
  return texto;

}


//Funci�n para hallar el n�mero de d�gitos al que elevar
//la potencia de diez. Mientras al ir dividiendo el n�mero
//entre diez, el cociente es distinto de cero, aumenta en
//uno el n�mero de d�gitos.

int Digitos(long long numero){
	
	int num_de_digitos;
	
	
	num_de_digitos = 0;
	
	while((numero/10) != 0){
			
		num_de_digitos++;
		numero = (numero/10);
			
	}
	
	return num_de_digitos;

}


//Funci�n para conseguir la secuencia de los d�gitos que forman el
//n�mero introducido. Va descomponiendo el n�mero de izqda a derecha
//y transformando y guardando el valor en una variable tipo string,
//que se va actualizando con las repeticiones del ciclo while mientras
//nel n�mero de d�gitos no sea cero.

string Entero2String(long long numero, int digitos){
	
	long long potencia_diez;
	long long digito;
	string cadena;
	string secuencia;
	
	cadena = "";
	
		while( digitos >= 0 ){
			
		  potencia_diez = pow(10, digitos);	
		  digito = numero / potencia_diez;
		  digitos--;
	     numero = numero % potencia_diez;

	     secuencia = ToString(digito, cadena);
		  cadena = secuencia;
	     
	   }
	   
	   return secuencia;

}





int main(){ // Programa Principal.

   //Declaraci�n de variables.
   
   long long num_1;           //N�mero introducido.
   long long num_1_original;  //Variable para guardar el Valor anterior.
   int digitos;               //N�mero de d�gitos.
   string secuencia_digitos;  //Cadena de texto con la secuencia de d�gitos.
   
      
   //Entrada de datos.
   
	cout << "\nIntroduzca un numero entero: ";
	cin >> num_1;
  
		
	// C�lculos.
	
   // Guardamos el valor del entero para no perderlo.
  
   num_1_original = num_1;
   
   // Calculamos el n�mero de d�gitos mediante la funci�n para elevar 
   // la potencia de diez.

   digitos = Digitos(num_1);
   
   // Calculamos la secuencia de d�gitos mediante la anterior funci�n
   //definida.
   
   secuencia_digitos = Entero2String(num_1_original, digitos);
   
   // Resultados.  

	cout << "\nEl numero " << num_1_original <<" esta formado por "
	<< "los digitos: \n\n\t" << secuencia_digitos << "\n\n";
		
   
	return (0);
}
