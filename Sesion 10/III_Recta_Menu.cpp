/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/* 
         Sesión 01-010.
         Problema número 27:
            Programa para crear dos menus, uno para terminar o introducir 
            coeficientes de una recta, y otro para en caso de introducir
            los coeficientes, dar la pendiente, la ordenada, o la abscisa
            además de poder volver al menu principal.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Declaración de la clase MenuPrincipal.
//PRE: Las opciones deben ser las especificadas para cada acción.
class MenuPrincipal{
	
	//Datos miembros privados de la clase.
	private:
		
   char opcion;
   double A, B, C;
		
	//Miemro públicos y constructor de la clase.
	public:
		
		MenuPrincipal(char la_opcion): opcion(la_opcion){}
	
	
	//Función que devuelve un valor lógico en función de si desea continuar
	//o no.
	bool Opcion(){
		
	   bool continu = false;
		
		if (opcion == 'R'){
		
			continu = true;
			
		}
		else{
			
			continu = false;
			
		}
		
		return continu;

	}
		
		
	//Función para darle valores a los coeficientes de la recta.
	void Coeficientes(){
	
		double a, b, c;
		
		
		if (opcion == 'R'){
			
			cout << "\nIntroduzca los coeficientes de la recta (A,B,C): ";
			cin >> a; cin >> b ; cin >> c;
		
			A = a;
			B = b;
			C = c;
			
		}
		else{
			
			cout <<"\nEl programa va a finalizar su ejecucion.";
			
		}

	}
	
	
	//Funciones para conseguir los valores de los coeficientes.
	double GetA(){
		
		return A;
		
	}
	
	double GetB(){
		
		return B;
		
	}
	
	double GetC(){
		
		return C;
		
	}
		
		
};


//Declaración de la clase MenuPrincipal.
//PRE: Las opciones deben ser las especificadas para cada acción.
class MenuOperaciones{
	
	//Datos miembros privados de la clase.
	private:
		
		char opc_operacion;
		
	
	//Datos miembros publicos y constructor de la clase.
	public:
		
		MenuOperaciones(char la_operacion): opc_operacion(la_operacion){}
		
	
	//Función para realizar una opción u otra en función de la opción escogida.	
	void OpcOpercion(double a, double b, double c){
		
		bool pendiente = (opc_operacion == 'P');
		bool abscisa = (opc_operacion == 'A');
		bool ordenada = (opc_operacion == 'O');		
		bool volver = (opc_operacion == 'V');
		double orde, abscis;
		
		if (pendiente){
			
			cout << "\nLa pendiente de la recta es: " << Pendiente(a, b);
			
		}
		else{
			
			if(abscisa){
				
				cout << "\nIntroduzca el valor de la ordenada: ";
				cin >> orde;
				cout << "\nEl valor de la abscisa es: " << Abscisa(orde, a, b, c);
				
			}
			else{
				
				if(ordenada){

				cout << "\nIntroduzca el valor de la abscisa: "; 
				cin >> abscis;
				cout << "\nEl valor de la ordenada es: "
				<< Ordenada(abscis, a, b, c);					
					
				}
				else{
					
					if(volver){
						
					   cout << "\nVolviendo al menu principal...";
					
				   }
				}
				
			}
			
		}
		
	}
	
	
	//Funciones para calcular cada una de las acciones que ofrece el menú.
	double Pendiente(double a, double b){
			
		return  (-1.0* a / b);
	
	}
	
	double Ordenada(double x, double a, double b, double c){
		
		return ( -c - (a * x ) ) / b; 
			
	}
	
	double Abscisa(double y, double a, double b, double c){
		
		return ( -c - ( b * y ) )  / a; 
			
	}
	
};


	
		


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   char eleccion;
   bool finalizar;
   char elecc_oper;

  
  //Cálculos entradas y resultados mediante la clase y las funciones
  //decladas.
   
   finalizar = false;
   
   while(!finalizar){
   
	   do{
		
		   cout << "\n\nIntroduzca la opcion del menu que desee realizar "
			<< "(R: Introducir valores de recta; T: Terminar ejecucion).";
	      cin >> eleccion;
	   
	      eleccion = toupper(eleccion);
		
	   }while( eleccion != 'T' && eleccion != 'R' );


   	//Cálculos.
	
	   MenuPrincipal una_opcion(eleccion); //Uso del constructor.
	
	   if(una_opcion.Opcion()){
	   	
	   	una_opcion.Coeficientes();
	   	
	   	do{
	   	   cout << "\nSeleccione la operacion que desee realizar "
	   	   << "(P:Hallar pendiente; O:Hallar ordenada;"
				<< "A:Hallar abscisa): ";
	         cin >> elecc_oper;
	   
	         elecc_oper = toupper(elecc_oper);
		
	      }while( elecc_oper != 'P' && elecc_oper != 'A' && elecc_oper != 'O'
			&& elecc_oper != 'V' );
	      
	   	MenuOperaciones operacion_recta(elecc_oper);
	   	operacion_recta.OpcOpercion(una_opcion.GetA(), una_opcion.GetB(),
			una_opcion.GetC());
			
			finalizar = false;
		
	   }
	   else{
		
		   finalizar = true;
	   }
	
   }		
	
	//Resultados.
	

	return (0);
	
}
