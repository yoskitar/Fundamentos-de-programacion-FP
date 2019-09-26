/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01 - 03
         Problema número 7:
            Pasar una letra mayúscula a minúscula sin usar toupper
            ni tolower.
*/
/*********************************************************************/


#include <iostream>     // Inclusión de los recursos de E/S.
#include <cstdlib>    // Inclusión de llamadas al sistema.

using namespace std; 


int main() // Programa Principal.
{              
            
            system ("chcp 1252");        //Caracteres latinos.
            
   // Declara variables para guardar.

   char letra_original;
   char letra_convertida;
   char diferencia;
   
	//Entrada de datos.
	
	cout << "\nIntroduzca la letra: ";
	cin >> letra_original;
	
	
	//Cálculos.
	
	/*
	Si la letra introducida esta dentro de los valores en la tabla ASCII
	de las mayúsculas, restamos la diferencia hasta las minúsculas
	y mostramos un mensaje con la respectiva minúscula.
	*/
	
	diferencia = 'A' - 'a';
	
	if (letra_original >= 'A' and letra_original <= 'Z'){
		
		letra_convertida = letra_original - diferencia;
		
	   cout << "\nLa minúscula de " << letra_original << " sería: "
	   << letra_convertida << "\n";
	   
	}
	
	/*Si la letra se encuentra entre los valores de las minúsculas,
	se muestra un mensaje diciendo que ya era minúscula.
	*/
	
	if (letra_original >= 'a' and letra_original <= 'z') {
		
		letra_convertida = letra_original;
		
		 cout << "\nLa letra introducida ya es minúscula: "
		 << letra_convertida << "\n";
		 
	}

	//Pausa del programa.
   
   system("pause");
   
	return (0);
}
