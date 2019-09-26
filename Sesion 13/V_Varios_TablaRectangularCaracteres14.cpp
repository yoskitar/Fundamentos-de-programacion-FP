/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-13.
         Problema número 14:
           Crear la clase TablaRectangularCaracteres e implementar 
           métodos para comprobar si una matriz es simétrica, primero
           hallando la traspuesta y comprobando que ambas matrices son iguales
           y segundo, comprobando si los elementos de las filas de la matriz
           se corresponden con los de las columnas de la simétrica 
           directamanete, sin hallar la traspuesta.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 


//Declaración de la clase SecuecniaCaracteres.
class SecuenciaCaracteres {
	
	
	//Datos privados de la clase.
	private:
		
		int numero_caracteres;
		static const int MAX = 50;
		char vector_secuencia[MAX]={0};
	
	
	//Datos publicos de la clase.	
	public:
		
		
		//Constructos sin argumentos de la clase.
		SecuenciaCaracteres(){
			
			numero_caracteres = 0;
			
		}
		
		
		//Función para añadir un nuevo caracter a la secuencia.
		//Entrada: Un nuevo caracter.
		void Aniade(char un_caracter){
			
			vector_secuencia[numero_caracteres] = un_caracter;
			numero_caracteres++;
			
		}
		
		
		//Función para devolver un carcacter de la secuencia.
		//Entrada: Posicion a devolver.
		//Salida: Caracter contenido en la posición dada del vector.
		char ElementoDelVector(int a){
			
			return vector_secuencia[a];
			
		}
		
		
		//Función para devolver el total de caracteres de la secuencia.
		//Salida: Total de caracteres de la secuencia.
		int TotalCaracteres(){
			
			return numero_caracteres;

		}
		
		
		//Función para borrar la secuencia.
		void BorraSecuencia(){
			
			numero_caracteres = 0;
			
		}

};


//Declaración de la clase TablaRectangularCaracteres.
class TablaRectangularCaracteres {
	
	//Dtos privados de la clase.
	private:
		
		static const int MAX = 50;
		int TablaCaracteres[MAX][MAX];
		int total_filas;
		int total_columnas;
		
	   

	   

	//Datos publicos de la clase.	    
	public:
		
		TablaRectangularCaracteres(){
			
			total_filas = 0;
			total_columnas = 0;
			
		}
		
		
		//Función para añadir una nueva fila a la tabla.
		//Recibe: Fila de secuencia de caracteres.
		//Salida:void		
		void Aniade(SecuenciaCaracteres fila_nueva){
			
			total_columnas = fila_nueva.TotalCaracteres();
			
			for(int a=0; a < total_columnas ; a++){
				
				TablaCaracteres[total_filas][a] = fila_nueva.ElementoDelVector(a);
				
			}
			
			total_filas++;
			
		}
		
		
		//Función para borrar la tabla.
		void EliminaTodos(){
			
			total_filas = 0;
			total_columnas = 0;
		
		}
		
		
		//Función para comprobar si na tabla está o no vacía.
		void EstaVacia(){
			
			bool vacia = ( (total_filas == 0) && (total_columnas == 0) );
			
			if (vacia){
				
				cout << "\n\tLa tabla esta vacia." << endl;
		   }
		   else{
		   	
		   	cout << "\n\tLa tabla no esta vacia." << endl;
		   	
		   }
		   
		}
		
		
		//Función para hallar la traspuesta de una matriz.
		//En una nueva tabla va introduciendo las filas de la
		//tabla dada en las columnas de una tabla nueva creada.
		//Una vez hallada la traspuesta, se comprueba si ambas
		//coinciden. En dicho caso, la matriz será simétrica y mostrará
		//el mensaje correspondiente.
		void SimetricaTraspuesta(){
			
			bool simetrica;
			
			char tabla_aux[MAX][MAX];
			
			
			simetrica = true;
			
			for (int f = 0 ; f < total_filas ; f++){
				
				for (int c = 0 ; c < total_columnas ; c++){
					
					tabla_aux[c][f] = TablaCaracteres[f][c];
				
				}
				
				
			}
			
			for (int f = 0 ; f < total_filas ; f++){
				
				for (int c = 0 ; c < total_columnas ; c++){
					
					if(tabla_aux[f][c] != TablaCaracteres[f][c]){
						
						c = total_columnas;
						f = total_filas;
						simetrica = false;
						
					}
				
				}
				
			}
			
			if(simetrica){
				
				cout << "\n\tLa matriz es simetrica.";
				
			}
			else{
				
				cout << "\n\tLa matriz no es simetrica.";
				
			}
			
		}
		
		
		
      //Función para comprobar si los elementos de las filas de una tabla
      //se corresponden con los elementos de las columnas de la misma tabla.
		void SimetricaDirecta(){
			
			bool simetrica = true;
			
			
	      for (int f = 0 ; f < total_filas ; f++){
				
				for (int c = 0 ; c < total_columnas ; c++){
					
					if(TablaCaracteres[c][f] != TablaCaracteres[f][c]){
						
						c = total_columnas;
						f = total_filas;
						simetrica = false;
						
					}
				
				}
				
			}
			
			if(simetrica){
				
				cout << "\n\tLa matriz es simetrica." << endl;
				
			}
			else{
				
				cout << "\n\tLa matriz no es simetrica." << endl;
				
			}
			
		}
		
	
};


int main(){ // Programa Principal.


	//Declaración de datos.
	SecuenciaCaracteres una_secuencia;
	
	TablaRectangularCaracteres una_tabla;
	
	char caracter, respuesta;
	bool sigue, nueva_secuencia;
	
	sigue = true;
	nueva_secuencia = true;
	
	una_tabla.EstaVacia();
	
	//Entrada de datos.
	while(nueva_secuencia){
		
			while(sigue){
		
			cout << "\nIntroduzca un caracter (* para terminar): ";
			cin >> caracter;
		
			if(caracter != '*'){
			
				una_secuencia.Aniade(caracter);
			
			}
			else{
			
				sigue = false;
			
			}

		}
		
		una_tabla.Aniade(una_secuencia);
		una_secuencia.BorraSecuencia();
	
		cout << "\n\t¿Desea intoducir una nueva secuencia (s=si)?";
		cin >> respuesta;
	
		if(respuesta != 's'){ 
	
			nueva_secuencia = false;
		
		}else{
			
			sigue = true;
			
		}
	
   }
   
   //Cálculos y resultados mediate la llamada a las funciones de la clase.
   una_tabla.EstaVacia();
   una_tabla.SimetricaTraspuesta();
   una_tabla.SimetricaDirecta();


              
              
	return (0);
	
}
