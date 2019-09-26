/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
// 
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
// 
// 
/* 
         Sesi�n 01-08.
         Problema n�mero 16:
         Programa para calcular un n�mero dado es o no narcisita
         mediante la implementaci�n de funciones.
*/        
/*********************************************************************/

#include <iostream>      // Inclusi�n de los recursos de E/S.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <string>     //Inclusi�n de recursos de tipo string.
#include <cmath>    //Inclusi�n de recursos matem�ticos.

using namespace std; 

//Funci�n para filtrar que el valor introducido sea un entero positivo.
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
Funci�n que halla el n�mero de d�gitos que componen un entero mediante
un ciclo for que se repetir� mientras el n�mero dividido entre 10 de 
distinto de cero como cociente.En verdad no da el n�mero de d�gitos
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
Funci�n que halla la suma de las potencias de los d�gitos
que componen un n�mero. Mediante un ciclo for va descomponiendo
el entero dado y elevandolo al n�mero de d�gitos del entero.
A su vez, va sumando el resultado de cada una de esas operaciones,
dando como resultado la suma de todas las potencias de los d�gitos
del entero dado.
*/
int SumaPotencias(int num_digitos, int num_1_restos){
	
	//Declaraci�n de variables.
	int num_digitos_original;    //Valor original del n�mero de d�gitos.
	int potencia_diez;
	int suma;
	int digito;
	
	
	//C�lculos.
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
Funci�n para saber si un n�mero es o no narcisita mediante
la utilizaci�n de funciones anteriormente definidas, y de un 
condicional para comprobar si se cumple la condici�n que
hace a un n�mero narcisita, dando como resultado el mensaje correspondiente.
*/
string Narcisita(int num){
	
	//Declaraci�n de variables.
	int suma;                    //Sumatorio de las potencias n-�simas.
   int num_digitos;             //N�mero de d�gitos -1 del valor dado.  
   
	string narcisita;            //Mensaje devuelto.
	
	//C�lculos.	
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

   int num_1;                   //N�mero introducido.
   string narcisita;            //Resultado.

	//Entrada de datos.
   
   num_1 = Filtro("Introduzca un numero entero positivo: ");		
		
	
	//C�lculos mediante funci�n anteriormente definida.
	
	narcisita = Narcisita(num_1);
	
	
	//Resultados.
	
	cout << narcisita;
	  
	  
	return (0);
}
