/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-12.
         Problema n�mero 18:
         Crear la clase SecuenciaCaracteres y implementar los metodos
			adecuados para eliminar los blancos iniciales y finales, indicar
			laposicion de una palabra, borrar una palabra, devolver la palabra
			de la posicion n-esima. 
*/
/*********************************************************************/




//      !!!!!!!!!!!SIN TERMINAR!!!!!!!!!!!!

//  NO S� COMO INICIALIZAR EL CONSTRUCTOR CON UN STRING Y CREAR UN CADENA
//  DE CARACTERES CON DICHO STRING. (PREGUNTAR)





#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Declaraci�n de la clase de la secuencia.
class SecuenciaLetras{
		
	//Datos privados de la clase.
	private:
			
		static const int MAX = 50;
		
		string secuencia[MAX];
		
		int total_utilizados;
		
	
	//Datos publicos de la clase.	
	public:
		
		//Constructor sin argumentos de la clase.
		SecuenciaLetras(string cadena){
			
			total_utilizados = 0;
			if (total_utilizados < MAX){
				
				secuencia[total_utilizados] = cadena;
			   total_utilizados++;
			}
			
		
		}
		
		//Funci�n para a�adir un nuevo valor al vector.
		void Aniade(string letra){
			
			if (total_utilizados < MAX){
				
				secuencia[total_utilizados] = letra;
			   total_utilizados++;
			   
			}
		}

      //Funci�n para mostrar el total de utilizados.
		int TotalUtilizados(){
			
			return total_utilizados;
			
		}
		
		//Funci�n para leer el contenido de la frase.
		void Frase(){
			
			for(int a = 0; a < total_utilizados; a++){
				
				cout << secuencia[a];
				
			}
			
		}
				
};

int main(){ // Programa Principal.

   //Declaraci�n de datos
   const int MAXIMO = 50; 
   string cadena;

  
	
	//Entrada, calculos y resultados.
	for ( int i=0 ; i < MAXIMO ; i++ ){
		
	   
      cadena = cin.get();
      
      if (cadena == "#"){
      	
      	i = MAXIMO;
      	
      }
      else{
      
      SecuenciaLetras frase(cadena);
      
      
      }
		
	}
	
	
	return (0);
	
}
