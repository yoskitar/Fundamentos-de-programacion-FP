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
         Problema número 13:
           Introducir una secuencia y eliminar los espacios en blancos 
           dejando uno solo entre valores de la secuencia.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Declaración de la clase de la secuencia.
class SecuenciaLetras{
	
	//Miembros privados de la clase.
	private:
			
		static const int MAX = 50;
		
		string secuencia[MAX];
		
		int total_utilizados;
		
		string cadena_derecho = "";
		
		string cadena_reves = "";
	
	//Datos publicos de la clase.	
	public:
		
		//Constructor sin argumentos de la clase.
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

      
      //Función para mostrar el total de utilizados.
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
		

		//Función para eliminar los valores repetidos de la secuencia.
		void sin_repetidos(){
			
			string sin_repetidos[MAX];
			
			int utilizados_repetidos = 1;
			int principio = 0;
			
			for(int i=0 ; i < total_utilizados ; i++){
				
				string valor_sec = secuencia[i];
				bool introducir = true;
				
				for(int o = 0 ; o < utilizados_repetidos ; o++){
					
					string valor_rep = sin_repetidos[o];
				   
				   if(valor_sec == valor_rep){
				   	
				   	introducir = false;
						
					}
				}
				   
				if ( introducir ){
            	
            	sin_repetidos[principio] = valor_sec;
            	utilizados_repetidos++;
				   principio++;
			   }
			}
			
			total_utilizados = utilizados_repetidos - 1;
			cout << endl << "Sin repetidos: \n";
			
			for(int a = 0; a < total_utilizados ; a++){
				
				string change = sin_repetidos[a];
				secuencia[a] = change;
				cout << secuencia[a];
				
			}
		}
		
		
//No me funciona: Función para eliminar los espacios en blancos excedentes
//de uno.
		void EliminaExcesoBlancos(){
			
			int a = 0;
			int principio = 0;
		
		
			
			for (int i=0 ; i < total_utilizados ; i++){
				
				string indice = secuencia[i];

				if (indice == " " ){
					
					secuencia[principio] = indice;
					principio++;
					
					for ( a = i+1; indice == " " ; a++){
						
						indice = secuencia[a];
						
						
						if (indice == " "){
							
						   total_utilizados--;
						   
						   
					   }
					   
					}
					
					i = a -1;
					
				}
				else{
				
				    secuencia[principio] = indice; 
				    principio++;

				}
	
			}
			
			
	      cout << "\nEliminando exceso de blancos: \n" << total_utilizados;
			for(int o = 0; o < total_utilizados ; o++){
				
			   cout << secuencia[o];
				
			}
			
		}
					
};

int main(){ // Programa Principal.


   //Declaración de datos.
   const int MAXIMO = 50;
   
   SecuenciaLetras secuencia;
   
   string cadena;
   
   int component_1, component_2, total_utilizados;
   
   bool correcto;
  
	
	//Entrada de datos, cálculos y resultados.
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
		
		cout << "\nLa secuecnia es un palindromo.";
		
	}
	else{
		
		cout << "\nLa secuecnia no es un palindromo.";
		
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
	
	
	secuencia.EliminaExcesoBlancos();
	secuencia.sin_repetidos();
	
	
	return (0);
	
}
