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
         Problema n�mero 3:
           Introducir una secuecia de positivos hasta introducir un valor 
           negativo y eliminar los repetidos mostrando la secuencia en el 
           orden de aparici�n.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Declaraci�n de la clase de la secuecnia
//pre:los valores deben ser positivos, excepto para finalizar la secuencia.
class SecuenciaPositivos{
	
	//miembros privados de la clase.
	private:
		
		static const int MAX = 50;
		
		double positivos[MAX];
		
		int total_utilizados;
		
	
	//miembros p�blicos de la clase.	
	public:
		
		//constructor sin argumentos.
		SecuenciaPositivos(){
			
			total_utilizados = 0;
		
		}
		
		//metodo que recibe un double y a�ade un valor al vector.
		void Aniade(double nuevo){
			
			if (total_utilizados < MAX){
				
				positivos[total_utilizados] = nuevo;
			   total_utilizados++;
			   
			}
		}
		
		
		//funci�n para mostrar el total utilizados.
		int TotalUtilizados(){
			
			return total_utilizados;
			
		}
		
		double GetValor(int posicion){
			
			return positivos[posicion];
			
		}
		
		
		//funci�n para eliminar los valores repetidos.	
		void Elimina(){
			
		
			for( int i = 0 ; i < total_utilizados ; i++ ){
				
				for ( int pos = 0 ; pos < total_utilizados ; pos++ ){
					
					int pos_1 = pos;
					bool repetidos;
					
					double i_ = positivos[i];
					double pos_ = positivos[pos];
					repetidos = ( i_ == pos_ ) && ( i != pos );
					
					if (repetidos){
						
						for( int pos_mas = pos + 1 ; pos_mas < total_utilizados 
						; pos_mas++ ){
						
						   positivos[pos_1] = positivos[pos_mas];
						   pos_1 = pos_1 + 1;
						   
					   }
						
						total_utilizados--;
					   pos--;
					}
						
				}
					
			}
		
		}
	
};

int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   int i, pos;
   double valor;
   
   SecuenciaPositivos secuencia;
   
   
   //Entrada de datos.
   
   for ( i = 0 ; i <= secuencia.TotalUtilizados() ; i++){
   	
   	cout << "\nIntroduca un valor positivo (Valor negativo para finalizar): ";
   	cin >> valor;
   	
		if( valor >= 0 ){
			
		   secuencia.Aniade(valor);
   	
      }
      else{
      	
      	i = secuencia.TotalUtilizados() + 1;
      	
      }
   
   }
   
   //C�lculos y resultados.
   
   secuencia.Elimina();
   
	cout << "\nValores de la secuencia: \n";
   
   for ( pos = 0 ; pos < secuencia.TotalUtilizados() ; pos++ ){
   	
   	cout << secuencia.GetValor(pos);
	
   }

	return (0);
	
}
