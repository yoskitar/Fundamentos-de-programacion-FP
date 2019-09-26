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
         Problema número 19:
           Introducir cuatro calificaciones junto con un nombre para cada
           alumno y calcular la nota media aplicados un tanto porciento,
           además de mostrar un listado con todos los alumnos y sus medias,
			  ordenados en orden decreciente.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Struct que contiene el nombre del alumno y cada una de las notas.
struct RegAlumno {
	
	double nota1, nota2, nota3, nota4, media;
	string apellido_nombre;
	
};


//Declaración de la clase GrupoAlumnos.
class GrupoAlumnos{
	
	//Dtos privados de la clase.
	private:
	   
		static const int MAX_ALUMNOS = 100;
	   RegAlumno alumno[MAX_ALUMNOS];
	   int num_alumno;
	   double peso1, peso2, peso3, peso4;
	   

	//Datos publicos de la clase.
	public:
		
		//Constructor de la clase que ecibe el valor de cada uno de los
		//pesos de las calificaciones y las asigna a cada una de sus
		//variables correspondientes.
		GrupoAlumnos (double p1, double p2, double p3, double p4){
			
			num_alumno = 0;
			peso1 = p1;
			peso2 = p2;
			peso3 = p3;
			peso4 = p4;
			
		}
		
		//Función para añadir un nuevo alumno y calcular la media de sus notas.
		//Recibe: nombre del alumno y cada uno de los valores de las notas.
		//Salida:void
		void Aniade(string nombre, int n1, int n2, int n3, int n4){
			
			int media;
			
			
		   media = ( n1 * (peso1/100.0) + 
			n2 * peso2/(100.0)  + 
			n3 * peso3/(100.0) + 
			n4 * peso4/(100.0) );
			
			alumno[num_alumno].apellido_nombre = nombre;
			alumno[num_alumno].nota1 = n1;
			alumno[num_alumno].nota2 = n2;
			alumno[num_alumno].nota3 = n3;
			alumno[num_alumno].nota4 = n4;
			alumno[num_alumno].media = media;
			num_alumno++;
			
		}
		
		//Funicones para devolver el numero de alumnos,
		//el nomre de un alumno concreto, su media.
		int NumAlumnos(){
			
			return num_alumno;
	
		}
		
		string NombreAlumno(int i){
			
			return alumno[i].apellido_nombre;
			
			
		}
		
		double Media(int i){
			
			return alumno[i].media;
			
		}
		
		
		//Función para eliminar un alumno del vector.
		//Entrada: nomre del alumno.
		//Salida:void
		void Elimina(string nombre_alumno){
			
			string nombre;
			
			for (int i = 0; i < num_alumno; i++){
				
				nombre = alumno[i].apellido_nombre;
				
				if(nombre == nombre_alumno){
				
			      for (int a = i; a < num_alumno ; a++){
				
				      alumno[a] = alumno[a+1];

			      }
			   }
			}
			
		   num_alumno--;
			
		}
		
		//Función para ordenar el listado de alumnos en función
		//de sus medias en orden decreciente.
		void Ordenacion(){
			
			int izda, i;
			double a_desplazar;
			RegAlumno vector_aux[MAX_ALUMNOS];
			
			for (izda = 1; izda < num_alumno; izda++){
				
				a_desplazar = alumno[izda].media;
				vector_aux[0] = alumno[izda];
				
				for(i = izda; i > 0 && a_desplazar > alumno[i-1].media; i--){
					
					alumno[i] = alumno[i-1];
					
				}
				
				alumno[i] = vector_aux[0];
				
			}
			
		}
			
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
   

   const int MAX_PORC = 4; 
	const int MAX_ALUMNOS = 100; 
  
   double pesos[MAX_PORC];
   
   bool suma_correcta;
   
   string nombre, nombre_eliminar;
   double nota1, nota2, nota3, nota4;
   
   int alumnos, num_alumnos;
   char opcion;

  
  
  
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
  
   //Cálculos y entradas de datos.
   
   if(suma_correcta){
   	
   	GrupoAlumnos un_alumno(pesos[0], pesos[1], pesos[2], pesos[3]);
   	
   	for ( int i = 0 ; i < MAX_ALUMNOS ; i++){  
	
		   cout << "\nIntroduzca los apellidos y el nombre " 
		   << "del alumno (jimenez_oscar" 
			<< " ó asterisco (*) para terminar).";
		
	      cin >> nombre;
		
		   if (nombre == "*" ){
			
			   i = MAX_ALUMNOS + 1;
			
		   }
		   else{
         
		      nota1 = Filtro("\nNota del primer examen: ");
		      nota2 = Filtro("\nNota del segundo examen: ");
		      nota3 = Filtro("\nNota del tercer examen: ");
		      nota4 = Filtro("\nNota del cuarto examen: ");
		         
		      un_alumno.Aniade(nombre, nota1, nota2, nota3, nota4);
 
         }
      }
      
      
      
      cout << endl << "¿Desea eliminar algun alumno(s/n)?";
		cin >> opcion;
		
		if(opcion == 's'){
		
		   cout << "Introduzca el nombre del alumno a eliminar: ";
			cin >> nombre_eliminar;  
			
			un_alumno.Elimina(nombre_eliminar);
			
		}
		
		num_alumnos = un_alumno.NumAlumnos();
		un_alumno.Ordenacion();
         
  
   //Resultados.
  
      cout << "\nLista de calificaciones: \n";
   
      for ( alumnos = 0 ; alumnos < num_alumnos; alumnos++ ){
   	   
   	   cout << endl;
         cout << un_alumno.NombreAlumno(alumnos);
			cout << "--->" << un_alumno.Media(alumnos);

      }
      
   }
   else{
   	
		cout << "\nValores introducidos incorrectos. Fin del programa.\n";
		
	}
   
 
	return (0);
	
}
