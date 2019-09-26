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
         Problema número 14:
           Programa para contar número de apariciones de cada mayuscula.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.
#include <cctype>     //Inclusion de recursos de caracteres.

using namespace std; 

//Función que recibe un mensage string y devuelve un caracter.
char Filtro (string msg){
	
	char iden;
	
	cout << msg;
	iden = cin.get();

   return iden;
	
}

//struct para cada sucursal con el identificador y el número de unidades
//vendidas.
struct Secuencia{
	
	char identificador;
	int apariciones;
	
};


//Declaración de la clase letras.
class Letra{
	
	//datos privados de la clase.
	private:
		
		static const int MAX = 100;
		Secuencia letras[MAX];
		int total_letras;
		int inicio = 0;
		
	//datos públicos de la clase.
	public:
		
		//declaración del constructor sin argumentos.
		Letra(){
			
			letras[0].identificador = 0;
			letras[0].apariciones = 0;
			total_letras = 0;
			
			
			
		}
		
		//método para devolver el total de sucursales.
		int NumeroSucursales(){
			
			return total_letras;
		
		}
		
		//método para añadir el identficador de una sucursal y su
		//numero de ventas. entrada: identificador y ventas.
		void Aniade(char id_letra ){
			
			bool nueva_letra = true;
			
			if (total_letras < MAX){
				
				for (int a = 0; a<=total_letras ; a++){
					
					if (letras[a].identificador == id_letra){
						
						letras[a].apariciones = letras[a].apariciones + 1;
						nueva_letra = false;
						
				   }
				
				}
		      
		      if (nueva_letra){
		      	
               letras[total_letras].apariciones = 
					letras[total_letras].apariciones + 1;
               letras[total_letras].identificador = id_letra;
			      total_letras++;
			   
				}
	      
			}
			
		}
		
		
		//Método para mostrar el total de apariciones de cada caracter.
		void Total_Apariciones(){
			
			bool mayuscula;
			
			//cout << endl << endl << "Total de apariciones de cada mayuscula...\n";
			
			for(int a=0; a < total_letras; a++){
				
				char ident = letras[a].identificador;
			   mayuscula = ( ident >= 65 && ident <= 90 );
				
				if(mayuscula){
				   
					cout << "Letra: " << letras[a].identificador 
				   << " ------> Apariciones: " << letras[a].apariciones << endl;
			   }
				
			}
	
		}
		
	};


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   const int MAX_LETRAS = 100;
   Letra una_secuencia;
   char identificador;
   const char TERMINADOR = '.';
   
  
  
	//Cálculos.
	
	
   		for ( int i = 0 ; i < MAX_LETRAS ; i++){  
	
	         identificador = Filtro("");
		
		      if (identificador == TERMINADOR ){
			
			      i = MAX_LETRAS + 1;
			
		      }
		      else{
		      	
		      	una_secuencia.Aniade(identificador);
		      	
            }
         }
         
   //Resultados.
   
         una_secuencia.Total_Apariciones();
  

	return (0);
	
}
