/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-11.
         Problema n�mero 7:
        introducir una secuencia de letras y decir si se trata de un 
        palindromo o no.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 

//declaraci�n de la clase secuecnialetras.
class SecuenciaLetras{
		
	//datos privados de la clase.
	private:
			
		static const int MAX = 50;
		
		string secuencia[MAX];
		
		int total_utilizados;
		
		string cadena_derecho = "";
		
		string cadena_reves = "";
	
	
	//Datos publicos de la clase.	
	public:
		
		
		//Constructor sin argumentos.
		SecuenciaLetras(){
			
			total_utilizados = 0;
		
		}
		
		
		//Funci�npara a�adir un nuevo valor al vector de la secuecnia.
		void Aniade(string letra){
			
			if (total_utilizados < MAX){
				
				secuencia[total_utilizados] = letra;
			   total_utilizados++;
			   
			}
		}

      
      //Funci�n para mostrar el total utilizados.
		int TotalUtilizados(){
			
			return total_utilizados;
			
		}

      
      
      //Funci�nes para mostar la secuecnia. Salida:string con la secuecnia.
		string ToStringDerecho(){
			
			for (int i = 0; i < total_utilizados ; i++){
			
			   cadena_derecho = cadena_derecho + secuencia[i];
		   
			}
			
			return cadena_derecho;	
		}
		
		
		string ToStringReves(){
			
			for (int o = total_utilizados - 1 ; o >= 0 ; o--){
			
			   cadena_reves = cadena_reves + secuencia[o];
		   
			}
			
			return cadena_reves;	
		}
		
		
		//Funci�n que devuelve un valor l�gico para saber si la secuencia
		//es un palindromo.
		bool EsPalindromo(void){
			
			return (cadena_derecho == cadena_reves);
			
		}
				
};

int main(){ // Programa Principal.


   //Declaraci�n de variables.
   
   const int MAXIMO = 50;
   SecuenciaLetras secuencia;
   string cadena;
	
	
	//C�lculos y entrada de datos.
	for ( int i=0 ; i < MAXIMO ; i++ ){
		
	   
      cadena = cin.get();
      
      if (cadena == "#"){
      	
      	i = MAXIMO;
      	
      }
      else{
      
      secuencia.Aniade(cadena);
      
      }
		
	}
	
	secuencia.ToStringDerecho();
	secuencia.ToStringReves();
	cout << secuencia.TotalUtilizados();
	
	
	//Salida de resultados.
	if (secuencia.EsPalindromo()){
		
		cout << "\nLa secuecnia es un palindromo.";
		
	}
	else{
		
		cout << "\nLa secuecnia no es un palindromo.";
		
	}


	return (0);
	
}
