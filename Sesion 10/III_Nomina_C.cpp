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
            Calcular salario neto y bruto de cada uno de los trabajadores
            de una empresa teniendo en cuenta la parte que le corresponde
            a cada uno del total de ganancias, y la retenci�n aplicada,
            introduciendo todos los datos necesarios desde un archivo
            de texto.
           
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
		const double RET_FAB;
		const double RET_DESIG;
		
		//Variables para los ingresos de la empresa y las ganacias brutas y 
		//netas de cada uno de los integrantes de la empresa, as� como la
		//retenci�n a aplicar.
		double ingresos;
		double salar_b_desig;
		double salar_b_fabr;
		double salar_n_desig;
		double salar_n_fabr;
		
		int numero_fabricantes;
      int parte_de_ganancias;
		
	
	
	//M�todos y constructor p�blicos de la clase.	
	public:
		
		Nomina(double total_ingresos, int numero_fab, int parte_ganancias,
	   double ret_desig, double ret_fab )
	   :DESIGNER ( 1.0 / parte_ganancias * 1.0 ),
		FABRICANTE ( ( ( (parte_ganancias - 1) * 1.0 ) / parte_ganancias * 1 ) ),
		RET_FAB ( ret_fab ),
		RET_DESIG ( ret_desig )
		
		{
			
			ingresos = total_ingresos;
			numero_fabricantes = numero_fab;
			parte_de_ganancias = parte_ganancias;
			
			salar_b_desig = SalarioBDesig();
			salar_b_fabr = SalarioBFab();
			
	      salar_n_desig = SalarioN(salar_b_desig, RET_DESIG);
	      salar_n_fabr = SalarioN(salar_b_fabr, RET_FAB);
		 	
		}		
		
		
	//Funci�n para hallar el salario bruto de cada una de las partes en funci�n
	//de los ingresos totales de la empresa y de la parte que le corrresponde 
	//a cada uno de los miembros de la empresa.
	//Entrada: Parte del total de los ingresos de la empresa 
	//que le corresponden.
	//Salida: Salario bruto de trabajador.
	double SalarioBDesig(){
		
		double salario_b_desig;
		
		
		salario_b_desig = DESIGNER * ingresos;
		
		return salario_b_desig;
	
   }
   
   
   //Funci�n para hallar el salario bruto de cada una de las partes en funci�n
	//de los ingresos totales de la empresa y de la parte que le corrresponde 
	//a cada uno de los miembros de la empresa.
	//Entrada: Parte del total de los ingresos de la empresa 
	//que le corresponden.
	//Salida: Salario bruto de trabajador.
	double SalarioBFab(){
		
		double salario_b_fab;
		
		
		salario_b_fab = ( FABRICANTE * ingresos) / numero_fabricantes;
		
		return salario_b_fab;
	
   }
   
   //Funci�n para hallar el salario neto de cada una de las partes en funci�n
	//del salario bruto y de la retenci�n a aplicar.
	//Entrada: Salario bruto del trabajador.
	//Salida: Salario neto de trabajador.
   double SalarioN(double bruto, double retencion){
		
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

	double GetParte(){
		
		return DESIGNER;
		
	}
	
	double GetNumFabri(){
		
		return numero_fabricantes;
		
	}
	
	double GetRetFab(){
		
		return RET_FAB;
		
	}
	
	double GetRetDesigner(){
		
		return RET_DESIG;
		
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

//Filtro para introducir una valor entero positivo.
//Entrada:Mensaje a mostrar.
//Salida:Valor pedido.
int FiltroInt(string mensaje){
	
	bool valores_correctos;
	double numero_double;
	int numero;
	
	do{
		
	cout << mensaje;            
	cin >> numero_double;
	
	numero = numero_double;
	
	valores_correctos = ( numero >= 0 ) && 
	(numero_double - numero == 0);
	
	}while(!valores_correctos);
	
	return numero;
	
}


int main(){ // Programa Principal.
              
            
   // Declara variables para guardar.
   
   double ingresos_empresa;
   double ret_desig;
   double ret_fab;
   
   int sucursal;
   int parte_de_ganancias;
   int num_fab;
   int i;
   
   
  sucursal = FiltroInt("");
  
	for ( (i = 1) ; (i <= sucursal) ; (i++) ){
  
      //Entrada de datos mediante filtros definidos en las funiones.
   
      ingresos_empresa = Filtro("");
      num_fab = FiltroInt("");
	   parte_de_ganancias = FiltroInt("");
	   ret_desig = Filtro("");
	   ret_fab = Filtro("");


	   //C�lculos.
	
	   Nomina una_empresa(ingresos_empresa, num_fab, parte_de_ganancias, 
	   ret_desig, ret_fab ); //Uso del constructor.
	
	
	   //Resultados.
	
	   //Ingresos totales.
	   cout << "\nSucursal " << i;
 	   cout << "\nIngresos totales a repartir: " 
	   << una_empresa.GetIngresos() << "\n";
	   cout << "Numero de fabricantes: " 
	   << una_empresa.GetNumFabri() << "\n";
	   cout << "Parte del total de ingresos correspondiente al designer: " 
	   << una_empresa.GetParte() << "\n";
	   cout << "Retencion aplicada al designer: " 
	   << una_empresa.GetRetDesigner() << "\n";
	   cout << "Retencion aplicada al fabricante: " 
	   << una_empresa.GetRetFab() << "\n";
   
	   //Salarios netos.
	   cout << "\nLos ingresos netos obtenidos por el dise�ador seran: " 
	   << una_empresa.GetDesignerN();
      cout << "\nLos ingresos netos obtenidos por cada uno de"
	   << " los fabricantes seran: " << una_empresa.GetFabricanteN() << "\n";
	
   }
 
	return (0);
}
