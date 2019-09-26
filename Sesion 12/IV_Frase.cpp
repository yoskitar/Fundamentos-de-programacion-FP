/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-12.
         Problema número 18:
         Crear la clase SecuenciaCaracteres y implementar los metodos
			adecuados para eliminar los blancos iniciales y finales, indicar
			laposicion de una palabra, borrar una palabra, devolver la palabra
			de la posicion n-esima. 
*/
/*********************************************************************/




//      !!!!!!!!!!!SIN TERMINAR!!!!!!!!!!!!

//  NO SÉ COMO INICIALIZAR EL CONSTRUCTOR CON UN STRING Y CREAR UN CADENA
//  DE CARACTERES CON DICHO STRING. (PREGUNTAR)





#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Declaración de la clase de la secuencia.
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
		
		//Función para añadir un nuevo valor al vector.
		void Aniade(string letra){
			
			if (total_utilizados < MAX){
				
				secuencia[total_utilizados] = letra;
			   total_utilizados++;
			   
			}
		}

      //Función para mostrar el total de utilizados.
		int TotalUtilizados(){
			
			return total_utilizados;
			
		}
		
		//Función para leer el contenido de la frase.
		void Frase(){
			
			for(int a = 0; a < total_utilizados; a++){
				
				cout << secuencia[a];
				
			}
			
		}
				
};

int main(){ // Programa Principal.

   //Declaración de datos
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
