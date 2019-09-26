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
         Problema número 16:
         Programa para calcular un número dado es o no narcisita
         mediante la implementación de funciones.
*/        
/*********************************************************************/

#include <iostream>      // Inclusión de los recursos de E/S.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <string>     //Inclusión de recursos de tipo string.
#include <cmath>    //Inclusión de recursos matemáticos.

using namespace std; 

//Función para filtrar que el valor introducido sea un entero positivo.
double Filtro(string mensaje){
	
	bool valores_correctos;
	double numero_d;
	int num_1;
	
	do{
		
	cout << mensaje;            
	cin >> numero_d;
	
	num_1 = numero_d;
	
	valores_correctos = ( num_1 > 0 ) && 
	(numero_d - num_1 == 0);
	
	}while(!valores_correctos);
	
	return num_1;
	
}

/*
Función que halla el número de dígitos que componen un entero mediante
un ciclo for que se repetirá mientras el número dividido entre 10 de 
distinto de cero como cociente.En verdad no da el número de dígitos
total, sino uno menos.
*/
int Digitos(int num_1){
	
	int num_digitos;
	
	
	for( num_digitos = 0 ; (num_1/10) != 0; num_digitos++){
		   
			num_1 = (num_1/10);

	}
	
	return num_digitos;	
}


/*
Función que halla la suma de las potencias de los dígitos
que componen un número. Mediante un ciclo for va descomponiendo
el entero dado y elevandolo al número de dígitos del entero.
A su vez, va sumando el resultado de cada una de esas operaciones,
dando como resultado la suma de todas las potencias de los dígitos
del entero dado.
*/
int SumaPotencias(int num_digitos, int num_1_restos){
	
	//Declaración de variables.
	int num_digitos_original;    //Valor original del número de dígitos.
	int potencia_diez;
	int suma;
	int digito;
	
	
	//Cálculos.
	num_digitos_original = num_digitos + 1;
	suma = 0;
		
	for(; num_digitos >= 0 ; num_digitos--){
	
	   potencia_diez = pow(10*1.0, num_digitos);	
		digito = num_1_restos / potencia_diez;
	   num_1_restos = num_1_restos % potencia_diez;
	     
	   suma = suma + pow(digito*1.0, num_digitos_original);
		 
	}
   
	return suma;	
}

/*
Función para saber si un número es o no narcisita mediante
la utilización de funciones anteriormente definidas, y de un 
condicional para comprobar si se cumple la condición que
hace a un número narcisita, dando como resultado el mensaje correspondiente.
*/
string Narcisita(int num){
	
	//Declaración de variables.
	int suma;                    //Sumatorio de las potencias n-ésimas.
   int num_digitos;             //Número de dígitos -1 del valor dado.  
   
	string narcisita;            //Mensaje devuelto.
	
	//Cálculos.	
	num_digitos = Digitos(num);
	suma = SumaPotencias(num_digitos, num);
		
	if (suma == num){
			
		narcisita = ( "\nEl numero introducido " + to_string(num)
		+ " es narcisista.");
		
	}
	
	else{
			
		narcisita = ( "\nEl numero introducido " + to_string(num)
		+ " no es narcisista." );
		
	}
	
	//Salida.	
	return narcisita;

}


int main(){ // Programa Principal.
                      
   // Declara variables para guardar.

   int num_1;                   //Número introducido.
   string narcisita;            //Resultado.

	//Entrada de datos.
   
   num_1 = Filtro("Introduzca un numero entero positivo: ");		
		
	
	//Cálculos mediante función anteriormente definida.
	
	narcisita = Narcisita(num_1);
	
	
	//Resultados.
	
	cout << narcisita;
	  
	  
	return (0);
}
