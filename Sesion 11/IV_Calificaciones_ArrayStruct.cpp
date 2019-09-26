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
         Problema número 2:
           Introducir cuatro calificaciones junto con un nombre para cada
           alumno y calcular la nota media aplicados un tanto porciento,
           además de mostrar un listado con todos los alumnos y sus medias.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Struct que contiene el nombre del alumno y cada una de las notas.
struct RegAlumno {
	
	double nota1, nota2, nota3, nota4;
	string apellido_nombre;
	
};

//Función que recibe un mensaje y deuelve un valor comprendido entre cero 
//y diez.
double Filtro (string msg){
	
	double valor;
	
	do{
		
	cout << msg;
	cin >> valor;
	
   }while( valor < 0 || valor > 10);
   
   return valor;
	
}


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   const int MAX_ALUMNOS = 100;
   const int MAX_PORC = 4;  
   RegAlumno notas[MAX_ALUMNOS];
   double pesos[MAX_PORC];
   double calificacion_media[MAX_ALUMNOS];
   int num_alumnos, alumnos, i;
   
   bool suma_correcta;
   
   RegAlumno alumno;
  
  
  
	//Entrada de datos.
	
	cout << "\nIntroduzca los porcentajes de los examenes:";
	cout << "\nEjemplo: 22.5 30.5 29.5 17.5";
	cout << "\nPrimer examen: ";
	cin >> pesos[0];
	cout << "\nSegundo examen: ";
	cin >> pesos[1];
	cout << "\nTercer examen: ";
	cin >> pesos[2];
	cout << "\nCuarto examen: ";
	cin >> pesos[3];
	   
	suma_correcta = ( pesos[0] + pesos[1] + pesos[2] + pesos[3] ) == 100.0;
	
   num_alumnos = 0;
   
   
   
   //Cálculos y entradas de datos.
   
   if(suma_correcta){
   	
   		for ( i = 0 ; i < MAX_ALUMNOS ; i++){  
	
		      cout << "\nIntroduzca los apellidos y el nombre " 
		      << "del alumno (jimenez_oscar" 
				<< " ó asterisco (*) para terminar).";
		
	         cin >> alumno.apellido_nombre;
		
		      if (alumno.apellido_nombre == "*" ){
			
			      i = MAX_ALUMNOS + 1;
			
		      }
		      else{
         
		         alumno.nota1 = Filtro("\nNota del primer examen: ");
		         alumno.nota2 = Filtro("\nNota del segundo examen: ");
		         alumno.nota3 = Filtro("\nNota del tercer examen: ");
		         alumno.nota4 = Filtro("\nNota del cuarto examen: ");
		   
		         calificacion_media[i] = ( alumno.nota1 * (pesos[0]/100.0) + 
			      alumno.nota2 * pesos[1]/(100.0)  + 
					alumno.nota3 * pesos[2]/(100.0) + 
			      alumno.nota4 * pesos[3]/(100.0) );
			
			      notas[i] = alumno;
               num_alumnos++;
            
            }
         }
         
  
   //Resultados.
  
      cout << "\nLista de calificaciones: \n";
   
      for ( alumnos = 0 ; alumnos < num_alumnos ; alumnos++ ){
   	
   	   cout << notas[alumnos].apellido_nombre << " -----> " 
		   << calificacion_media[alumnos] << endl;

      }
      
   }
   else{
   	
		cout << "\nValores introducidos incorrectos. Fin del programa.\n";
		
	}
   
 
	return (0);
	
}
