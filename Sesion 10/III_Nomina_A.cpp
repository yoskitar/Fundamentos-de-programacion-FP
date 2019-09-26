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
         Problema número 28:
            Introducir una cantidad como la cantidad total de ingresos
            de una empresa y dar como resultado el total porcentual que
            recibe cada uno de los integantes de la empresa. Todo ello 
            mediante la implementación de clases.
           
*/
/*********************************************************************/


#include <iostream>      // Inclusión de los recursos de E/S.os.
#include <cstdlib>      // Inclusión de llamadas al sistema.
#include <cmath>       // Inclusión de recursos matemáticos.
#include <string>     //Inclusión de recursos de tipo string.

using namespace std; 

//Declaración de la clase Dinero.
//PRE: los valores recibidos por la clase deben ser como mínimo cero,
//ya que no puedes obtener unas ganancias negativas. En todo caso serían
//deudas.
class Nomina{
	
	//Datos miembros privados de la clase.
	private:
		
		//Constantes para indicar el porcentaje que obtienen de las ganancias
		//cada uno de los integrantes de la empresa.
		const double DESIGNER;
		const double FABRICANTE;
		
		double ingresos;
		double salar_desig;
		double salar_fabr;
		
	
	
	//Métodos y constructor públicos de la clase.	
	public:
		
		Nomina(double total_ingresos)
		:DESIGNER (2.0/5),
		FABRICANTE (1.0/5)
		{
			
			ingresos = total_ingresos;
			salar_desig = Salario(DESIGNER);
			salar_fabr = Salario(FABRICANTE);
			
		}		
		

	//Función para hallar el salario bruto de cada una de las partes en función
	//de los ingresos totales de la empresa y de la parte que le corrresponde 
	//a cada uno de los miembros de la empresa.
	//Entrada: Parte del total de los ingresos de la empresa 
	//que le corresponden.
	//Salida: Salario bruto de trabajador.		
	double Salario(double Parte){
		
		double salario;
		
		salario = Parte * ingresos;
		
		return salario;
	
   }
		
	
	
	
   //Funciones para leer las ganancias de cada uno de los integranes 
   //de la empresa, en función de la parte que le corresponde a cada uno, 
   //y las ganancias totales de la empresa.
   
	double GetDesigner(){
		
		return salar_desig;
		
	}
	
	double GetFabricante(){
		
		return salar_fabr;
		
	}
	
	double GetIngresos(){
		
		return ingresos;
		
	}

};


//Filtro para introducir una valor positivo.
//Entrada:Mensaje a mostrar.
//Salida:Valor pedido.
double Filtro(string mensaje){
	
	bool valores_correctos;
	
	double numero;

	
	do{
		
	cout << mensaje;            
	cin >> numero;
	

	
	valores_correctos = ( numero >= 0 );
	
	}while(!valores_correctos);
	
	return numero;
	
}


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   double ingresos_empresa;
  
   //Entrada de datos mediante filtros definidos en las funiones.
   
   ingresos_empresa = Filtro("Introduzca los ingresos totales"
	" obtenidos por la empresa: ");


	//Cálculos.
	
	Nomina una_empresa(ingresos_empresa); //Uso del constructor.
	
	//Resultados.
	
	cout << "\nLos ingresos totales obtenidos por la empresa son: " 
	<< una_empresa.GetIngresos();
	cout << "\nLos ingresos brutos obtenidos por el diseñador seran: " 
	<< una_empresa.GetDesigner();
   cout << "\nLos ingresos brutos obtenidos por cada uno de"
	<< " los fabricantes seran: " << una_empresa.GetFabricante();
	
 
	return (0);
	
}
