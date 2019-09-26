/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN.
// GRADO EN INGENIERÍA INFORMÁTICA.
//
// CURSO 2015-2016
// (C) Óscar Jiménez Fernández
//
// 
/*    
       Sesión 01-06.
       Problema número 31:
         Dados un interés, un capital y un número de años,
         decir el capital obtenido en cada año hasta el introducido,
         y con cada uno de los intereses hasta llegar al introducido.
			      
*/  
/*********************************************************************/


#include <iostream>              //Inclusión de recursos de E/S
#include <cstdlib>              // Inclusión de llamadas al sistema.


using namespace std;

int main(){                    //Programa principal.
           
	                   
	// Declara variables para guardar.   
	               
	double capital_variado;       //Capital acumulado cada año. 
	int interes;                  //Interés introducido.  
	double capital_total;         //Total de capital obtenido.
	double capital_inicial;       //Capital introducido.
	double interes_double;        //Interés intoducido.
	
	int anios;           //Número de años del lazo fijo. 
	int inter_inicio;    //Inicio del primer ciclo for.
	int anio_inicio;     //Inicio del segundo ciclo for.
	            
	bool valores_correctos_capital;    //Condicionales para los
	bool valores_correctos_interes;    //filtros.
	bool valores_correctos_anios;        
	                           
	//Entrada de datos.
	
	
	/*
	Filtro para controlar que los valores del capital e interés
	intoducidos son correctos.
	*/
	
	
	do{
		
	cout << "\nIntroduzca el capital que desea depositar a plazo fijo anual: ";  
	cin >> capital_inicial;
	
	valores_correctos_capital = ( capital_inicial > 0);
	
	}while(!valores_correctos_capital);
	
	do{
		
	cout << "Introduzca el interes de su plazo fijo anual: ";              
	cin >> interes_double;
	
	interes = interes_double;
	
	valores_correctos_interes = ( interes > 0 ) && 
	(interes_double - interes == 0);
	
	}while(!valores_correctos_interes);
	
	do{
		
	cout << "Introduzca el numero de años: ";              
	cin >> anios;
	
	valores_correctos_anios = ( anios>0 );
	
   }while(!valores_correctos_anios);
	
	
	
	//Cálculos y resultados.
	
	/*
	Anidamiento de ciclos for en el que mientras el interes inicio 
	no sea superior al interés máximo introducido, nos dará la
	salida correspondiente del capital a dicho interés, en
	función del segundo ciclo for atendidendo al número de 
	años que se depositará el capital a plazo fijo.
	*/
	
	for( inter_inicio = 1 ; inter_inicio <= interes ; inter_inicio++ ){
		
		cout << "\nCalculos realizados al " << inter_inicio 
		<< " %:" <<"\n";
		
		capital_variado = capital_inicial;
		
	
	   for( anio_inicio = 1 ; anio_inicio <= anios ; anio_inicio++ ){
		
		capital_total = capital_variado + 
	   ( capital_variado * inter_inicio / 100 );
	   cout <<"\tDinero obtenido en el anio numero "
	   <<anio_inicio << " = " << capital_total << "\n";
	   
	   capital_variado = capital_total;
	  
	   }
	
	}
	
	cout << "\n";

	//Pausa del programa.
   
   system("pause");
   
	return (0);
	
}
