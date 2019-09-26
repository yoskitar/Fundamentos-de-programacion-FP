/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-11.
         Problema número 9:
           Intercambiar dos posiciones del vector y en caso de no poderse,
           invertir el orden de la secuencia.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Declaración de la clase de la secuencia.
class SecuenciaLetras{
		
		//Dtos privados de la clase.
	private:
			
		static const int MAX = 50;
		
		string secuencia[MAX];
		
		int total_utilizados;
		
		string cadena_derecho = "";
		
		string cadena_reves = "";
	
	
	//Dtos publicos de la clase.	
	public:
		
		
		//Constructor sin argumentos.
		SecuenciaLetras(){
			
			total_utilizados = 0;
		
		}
		
		
		//Función para añadir un nuevo valor a la secuencia.
		void Aniade(string letra){
			
			if (total_utilizados < MAX){
				
				secuencia[total_utilizados] = letra;
			   total_utilizados++;
			   
			}
		}

      
      //Función para mostrar el total utilizados.
		int TotalUtilizados(){
			
			return total_utilizados;
			
		}

      
      //Funciones para mostrar una cadena de texto del derecho y del revés
      //y decir si se trata de un palindromo o no.
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
		
		
		bool EsPalindromo(void){
			
			return (cadena_derecho == cadena_reves);
			
		}
		
		
		//Funciones para invertir el vector en caso de que el valor de la
		//posición a intrcambiar no sea correcto.Entrada:dos enteros
		//con ls posiciones a intercambiar.
		void IntercambiaComponentes(int component_1, int component_2){
			
			const int CHANGE = 2;
			string vector_intercambio[CHANGE];
			string var_interc, var_interc_2;

				
			var_interc = secuencia[(component_1 - 1)];
			var_interc_2 = secuencia[(component_2 - 1)];
			secuencia[(component_1 - 1)] = var_interc_2;
			secuencia[(component_2 - 1)]= var_interc;
			   
			cout << "\nIntercambiando posiciones...\n";
			   
			for( int i=0 ; i < total_utilizados ; i++){
					
				cout << secuencia[i];
			}
			
		}
		
		
		//Función para invertir el vector en caso de no poder intercambiarse 
		//las posiciones.
		void Invierte(){
			
			string vector_intercambio[MAX];
			string var_inter;
			   
			for(int i=0 ; i < total_utilizados ; i++){
				
				var_inter = secuencia[i];
				vector_intercambio[i] = var_inter;
		
			}
			
			int inicio = 0;
			
			for (int o = total_utilizados - 1 ; o >=0 ; o--){
				
				var_inter = vector_intercambio[o];
				secuencia[inicio] = var_inter;
				
				inicio++;
	
			}
			
			for(int a=0 ; a < total_utilizados ; a++){
					
				cout << secuencia[a]  ;
						
				}

		}
					
};


int main(){ // Programa Principal.


   //Declaración de variables.
   const int MAXIMO = 50;
   
   SecuenciaLetras secuencia;
   
   string cadena;
   
   int component_1, component_2, total_utilizados;
   
   bool correcto;
  
	
	//Entrada de datos, calculos y resultados.
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
	
	if (secuencia.EsPalindromo()){
		
		cout << "\nLa secuencia es un palindromo.";
		
	}
	else{
		
		cout << "\nLa secuencia no es un palindromo.";
		
	}
	
	
	cout << "\nIndique que posiciones desea intercambiar: ";
	cin >> component_1 >> component_2;
	
	
	total_utilizados = secuencia.TotalUtilizados();
	correcto = ( component_1 - 1 >=0 && component_1 - 1 < total_utilizados ) &&
	( component_2 - 1 >=0 && component_2 - 1 < total_utilizados );
	
	
	if (correcto){
		
		secuencia.IntercambiaComponentes(component_1, component_2);

	}
	else{
		
		cout << "\nNo es posible realizar el intercambio. "
		<< "Invirtiendo vector..." << endl;
		secuencia.Invierte();
		
	}
	
	
	return (0);
	
}
