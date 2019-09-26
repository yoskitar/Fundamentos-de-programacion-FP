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
         Problema número 20:
           Introducir cuatro calificaciones junto con un nombre para cada
           alumno y calcular la nota media aplicados un tanto porciento,
           además de mostrar un listado con todos los alumnos y sus medias,
			  ordenados en orden decreciente.Ampliar para poder introducir un 
			  numero indeterminado de notas para cada alumno con un maximo de
			  diez.
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Struct que contiene el nombre del alumno y cada una de las notas.
struct RegAlumno {
	
	static const int MAX_NOTAS = 10;
	double media = 0;
	double notas[MAX_NOTAS];
	string apellido_nombre;
	
};


//Declaración de la clase GrupoAlumnos.
class GrupoAlumnos{
	
	//Dtos privados de la clase.
	private:
	   
	   static const int MAX_NOTAS = 10;
		static const int MAX_ALUMNOS = 100;
	   RegAlumno alumno[MAX_ALUMNOS];
	   int num_alumno;
	   double peso1, peso2, peso3, peso4;
	   int num_notas;
	   double pesos[MAX_NOTAS];
	   int numero_peso = 0;
	   

	//Datos publicos de la clase.
	public:
		
		GrupoAlumnos (){
			
			num_alumno = 0;
			num_notas = 0;
			
		}
		
		
		//Funcion para añadir un nuevo peso al vector.
		//Recibe: valor del peso del examen.
		//Salida:void.
		void Pesos(double peso){
			
			pesos[numero_peso] = peso;
			numero_peso++;
			
		}
		
		//Función para añadir un nuevo alumno y calcular la media de sus notas.
		//Recibe: nombre del alumno y cada uno de los valores de las notas.
		//Salida:void
		void Aniade(string nombre){

			double nota, media;
			media = 0;
			double peso;
			
			for(int i = 0 ; i < num_notas; i++){
				
				cout << "\nIntroduzca la nota del examen " << (i+1) << ": ";
				cin >> nota;
				alumno[num_alumno].notas[i] = nota;
				
				peso = pesos[i];
				media = media + ( nota * ( peso*1.0 /100.0 ) );
					
			}
			
			alumno[num_alumno].media = media;
			alumno[num_alumno].apellido_nombre = nombre;
			num_alumno++;
			
		}
		
		//Funicones para devolver el numero de alumnos,
		//el nomre de un alumno concreto, su media.		
		void GetNumNotas(int numero_notas){
			
			num_notas = numero_notas;
			
		}
		
		
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
   

	const int MAX_ALUMNOS = 100; 
   
   bool suma_correcta;
   
   string nombre, nombre_eliminar;
   double suma;
   
   int alumnos, num_alumnos, num_calificaciones;
   double peso_notas;
   char opcion;
   
   GrupoAlumnos un_alumno;

  
  
  
	//Entrada de datos.
	
	cout << "\nIntroduzca el numero de calificaciones: ";
	cin >> num_calificaciones;
	
	un_alumno.GetNumNotas(num_calificaciones);
	
	cout << "\nIntroduzca los porcentajes de los examenes:";
	cout << "\nEjemplo: 22.5 30.5 29.5 17.5";
   
   for(int i = 0; i < num_calificaciones ; i++){
   	
   	cout << "\nIntroduzca el peso de la nota " << (i+1) << ": ";
   	cin >> peso_notas;
   	un_alumno.Pesos(peso_notas);
   	suma = suma + peso_notas;
   	
   }
   
   suma_correcta = (suma == 100.0);
	
  
   //Cálculos y entradas de datos.
   
   if(suma_correcta){
   	
   	for ( int i = 0 ; i < MAX_ALUMNOS ; i++){  
	
		   cout << "\nIntroduzca los apellidos y el nombre " 
		   << "del alumno (jimenez_oscar" 
			<< " ó asterisco (*) para terminar).";
		
	      cin >> nombre;
		
		   if (nombre == "*" ){
			
			   i = MAX_ALUMNOS + 1;
			
		   }
		   else{
		         
		      un_alumno.Aniade(nombre);
 
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
