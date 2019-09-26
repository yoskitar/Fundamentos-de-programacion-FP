/*********************************************************************/
// FUNDAMENTOS DE PROGRAMACI�N.
// GRADO EN INGENIER�A INFORM�TICA.
//
// CURSO 2015-2016
// (C) �scar Jim�nez Fern�ndez
//
// 
/* 
         Sesi�n 01-010.
         Problema n�mero 28:
            Introducir una cantidad como la cantidad total de ingresos
            de una empresa y dar como resultado el total porcentual que
            recibe cada uno de los integantes de la empresa. Todo ello 
            mediante la implementaci�n de clases.Adem�s, mostrar el salario
            neto de ada uno de los trabajadores aplicada una retenci�n.a
           
*/
/*********************************************************************/


#include <iostream>      // Inclusi�n de los recursos de E/S.os.
#include <cstdlib>      // Inclusi�n de llamadas al sistema.
#include <cmath>       // Inclusi�n de recursos matem�ticos.
#include <string>     //Inclusi�n de recursos de tipo string.

using namespace std; 

//Declaraci�n de la clase Dinero.
//PRE: los valores recibidos por la clase deben ser como m�nimo cero,
//ya que no puedes obtener unas ganancias negativas. En todo caso ser�an
//deudas.
//PRE:El valor de la retenci�n deber� ser un entero positivo.
class Nomina{
	
	//Datos miembros privados de la clase.
	private:
		
		//Constantes para indicar el porcentaje que obtienen de las ganancias
		//cada uno de los integrantes de la empresa.
		const double DESIGNER;
		const double FABRICANTE;
		
		//Variables para los ingresos de la empresa y las ganacias brutas y 
		//netas de cada uno de los integrantes de la empresa, as� como la
		//retenci�n a aplicar.
		double ingresos;
		double salar_b_desig;
		double salar_b_fabr;
		double salar_n_desig;
		double salar_n_fabr;
		double retencion;
		
	
	
	//M�todos y constructor p�blicos de la clase.	
	public:
		
		Nomina(double total_ingresos, double retencion_fiscal)
		:DESIGNER (2.0/5),
		FABRICANTE (1.0/5)
		{
			
			ingresos = total_ingresos;
			retencion = retencion_fiscal;
			
			salar_b_desig = SalarioB(DESIGNER);
			salar_b_fabr = SalarioB(FABRICANTE);
			
	      salar_n_desig = SalarioN(salar_b_desig);
	      salar_n_fabr = SalarioN(salar_b_fabr);
		 	
		}		
		
		
	//Funci�n para hallar el salario bruto de cada una de las partes en funci�n
	//de los ingresos totales de la empresa y de la parte que le corrresponde 
	//a cada uno de los miembros de la empresa.
	//Entrada: Parte del total de los ingresos de la empresa 
	//que le corresponden.
	//Salida: Salario bruto de trabajador.
	double SalarioB(double Parte){
		
		double salario_b;
		
		salario_b = Parte * ingresos;
		
		return salario_b;
	
   }
   
   //Funci�n para hallar el salario neto de cada una de las partes en funci�n
	//del salario bruto y de la retenci�n a aplicar.
	//Entrada: Salario bruto del trabajador.
	//Salida: Salario neto de trabajador.
   double SalarioN(double bruto){
		
		double salario_n;
		
		salario_n = bruto - (bruto * retencion / 100.0);
		
		return salario_n;
	
   }
		
		
   //Funciones para leer las ganancias de cada uno de los integranes 
   //de la empresa, en funci�n de la parte que le corresponde a cada uno, 
   //y las ganancias totales de la empresa. 
	double GetDesignerB(){
		
		return salar_b_desig;
		
	}
	
	double GetFabricanteB(){
		
		return salar_b_fabr;
		
	}
	
	double GetDesignerN(){
		
		return salar_n_desig;
		
	}
	
	double GetFabricanteN(){
		
		return salar_n_fabr;
		
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
   double retencion_fisc;
  
  
   //Entrada de datos mediante filtros definidos en las funiones.
   
   ingresos_empresa = Filtro("Introduzca los ingresos totales"
	" obtenidos por la empresa: ");
	retencion_fisc = Filtro("Introduzca la retencion fiscal a aplicar: ");


	//C�lculos.
	
	Nomina una_empresa(ingresos_empresa, retencion_fisc); //Uso del constructor.
	
	
	//Resultados.
	
	//Ingresos totales.
	cout << "\nLos ingresos totales obtenidos por la empresa son: " 
	<< una_empresa.GetIngresos() << "\n";

   //Salarios brutos.
	cout << "\nLos ingresos brutos obtenidos por el dise�ador seran: " 
	<< una_empresa.GetDesignerB();
   cout << "\nLos ingresos brutos obtenidos por cada uno de"
	<< " los fabricantes seran: " << una_empresa.GetFabricanteB() << "\n";

   //Salarios netos.
	cout << "\nLos ingresos netos obtenidos por el dise�ador seran: " 
	<< una_empresa.GetDesignerN();
   cout << "\nLos ingresos netos obtenidos por cada uno de"
	<< " los fabricantes seran: " << una_empresa.GetFabricanteN() << "\n";
 
	return (0);
	
}
