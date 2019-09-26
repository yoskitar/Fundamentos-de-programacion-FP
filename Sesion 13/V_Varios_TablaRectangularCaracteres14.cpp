/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-13.
         Problema n�mero 14:
           Crear la clase TablaRectangularCaracteres e implementar 
           m�todos para comprobar si una matriz es sim�trica, primero
           hallando la traspuesta y comprobando que ambas matrices son iguales
           y segundo, comprobando si los elementos de las filas de la matriz
           se corresponden con los de las columnas de la sim�trica 
           directamanete, sin hallar la traspuesta.
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 


//Declaraci�n de la clase SecuecniaCaracteres.
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
		
		
		//Funci�n para a�adir un nuevo caracter a la secuencia.
		//Entrada: Un nuevo caracter.
		void Aniade(char un_caracter){
			
			vector_secuencia[numero_caracteres] = un_caracter;
			numero_caracteres++;
			
		}
		
		
		//Funci�n para devolver un carcacter de la secuencia.
		//Entrada: Posicion a devolver.
		//Salida: Caracter contenido en la posici�n dada del vector.
		char ElementoDelVector(int a){
			
			return vector_secuencia[a];
			
		}
		
		
		//Funci�n para devolver el total de caracteres de la secuencia.
		//Salida: Total de caracteres de la secuencia.
		int TotalCaracteres(){
			
			return numero_caracteres;

		}
		
		
		//Funci�n para borrar la secuencia.
		void BorraSecuencia(){
			
			numero_caracteres = 0;
			
		}

};


//Declaraci�n de la clase TablaRectangularCaracteres.
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
		
		
		//Funci�n para a�adir una nueva fila a la tabla.
		//Recibe: Fila de secuencia de caracteres.
		//Salida:void		
		void Aniade(SecuenciaCaracteres fila_nueva){
			
			total_columnas = fila_nueva.TotalCaracteres();
			
			for(int a=0; a < total_columnas ; a++){
				
				TablaCaracteres[total_filas][a] = fila_nueva.ElementoDelVector(a);
				
			}
			
			total_filas++;
			
		}
		
		
		//Funci�n para borrar la tabla.
		void EliminaTodos(){
			
			total_filas = 0;
			total_columnas = 0;
		
		}
		
		
		//Funci�n para comprobar si na tabla est� o no vac�a.
		void EstaVacia(){
			
			bool vacia = ( (total_filas == 0) && (total_columnas == 0) );
			
			if (vacia){
				
				cout << "\n\tLa tabla esta vacia." << endl;
		   }
		   else{
		   	
		   	cout << "\n\tLa tabla no esta vacia." << endl;
		   	
		   }
		   
		}
		
		
		//Funci�n para hallar la traspuesta de una matriz.
		//En una nueva tabla va introduciendo las filas de la
		//tabla dada en las columnas de una tabla nueva creada.
		//Una vez hallada la traspuesta, se comprueba si ambas
		//coinciden. En dicho caso, la matriz ser� sim�trica y mostrar�
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
		
		
		
      //Funci�n para comprobar si los elementos de las filas de una tabla
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


	//Declaraci�n de datos.
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
	
		cout << "\n\t�Desea intoducir una nueva secuencia (s=si)?";
		cin >> respuesta;
	
		if(respuesta != 's'){ 
	
			nueva_secuencia = false;
		
		}else{
			
			sigue = true;
			
		}
	
   }
   
   //C�lculos y resultados mediate la llamada a las funciones de la clase.
   una_tabla.EstaVacia();
   una_tabla.SimetricaTraspuesta();
   una_tabla.SimetricaDirecta();


              
              
	return (0);
	
}
