/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
       Sesión 01-04.
       Problema número 6:
           Modificar el problema para que muestre por pantalla
           un mensaje cuando los valores introducidos no se 
           correspondan con las características especificadas
           y finalizar entonces la ejecución del programa.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main()                    //Programa principal.
{                        
	                   
	// Declara variables para guardar.   
	               
	double capital;                   //Declaración de variables.
	double interes;                  //El capital ingresado,
	double total;                   //interés aplicado y capital total al año.
	bool cond;                   //Expresión lógica en caso de querer
	                            //calcular un nuevo total.
	
	
	
	//Entrada de datos 1.
	
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital;
	cout << "Introduzca el interes de su plazo fijo anual: ";              
	cin >> interes;
	
	//Cálculos 1.
	
	if((capital > 0) and (interes>=0 and interes<=100)){
   	
	total =  capital+capital*(interes/100); 
	cond = 1; 
	
	//Resultados 1.
	
	cout << "\nEl capital total a los 12 meses sera de: " 
	<< total << " €" "\n"; 
	
	
	//Nueva orden.
	
	cout << "\n¿Desea calcular el nuevo total," 
	<< " prolongando el plazo fijo otros 12 meses?"
	<< "\n(1:YES 0:NO)" "\n";
	
	//Entrada de datos 2.
	
	cin >> cond;
	
	//Calculos y resultados 2.
	
	   if(cond){
		
	     capital = total;
	     total =  capital+capital*(interes/100); 
	
	     cout << "\nEl nuevo capital total al año sera: " << total << " €" "\n";
	
      } 
  }
  
  else{
  	
  		cout << "\nLos valores introducidos no son correctos." "\n";
  	
  }
	
	
	cout << "\nFin del programa." "\n";
	
	
	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
