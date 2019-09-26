/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-07.
         Problema número 3:
            Escribid en pantalla los dígitos de cualquier entero 
            introducido mediante la utilización de funciones.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Primera función para ir transformando los dígitos en cadena de texto.

string ToString(int digito, string cadena){
	
	string texto;
	
	texto = to_string(digito) + ", ";
   texto = cadena + texto;
   
  return texto;

}


//Función para hallar el número de dígitos al que elevar
//la potencia de diez. Mientras al ir dividiendo el número
//entre diez, el cociente es distinto de cero, aumenta en
//uno el número de dígitos.

int Digitos(long long numero){
	
	int num_de_digitos;
	
	
	num_de_digitos = 0;
	
	while((numero/10) != 0){
			
		num_de_digitos++;
		numero = (numero/10);
			
	}
	
	return num_de_digitos;

}


//Función para conseguir la secuencia de los dígitos que forman el
//número introducido. Va descomponiendo el número de izqda a derecha
//y transformando y guardando el valor en una variable tipo string,
//que se va actualizando con las repeticiones del ciclo while mientras
//nel número de dígitos no sea cero.

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

   //Declaración de variables.
   
   long long num_1;           //Número introducido.
   long long num_1_original;  //Variable para guardar el Valor anterior.
   int digitos;               //Número de dígitos.
   string secuencia_digitos;  //Cadena de texto con la secuencia de dígitos.
   
      
   //Entrada de datos.
   
	cout << "\nIntroduzca un numero entero: ";
	cin >> num_1;
  
		
	// Cálculos.
	
   // Guardamos el valor del entero para no perderlo.
  
   num_1_original = num_1;
   
   // Calculamos el número de dígitos mediante la función para elevar 
   // la potencia de diez.

   digitos = Digitos(num_1);
   
   // Calculamos la secuencia de dígitos mediante la anterior función
   //definida.
   
   secuencia_digitos = Entero2String(num_1_original, digitos);
   
   // Resultados.  

	cout << "\nEl numero " << num_1_original <<" esta formado por "
	<< "los digitos: \n\n\t" << secuencia_digitos << "\n\n";
		
   
	return (0);
}
