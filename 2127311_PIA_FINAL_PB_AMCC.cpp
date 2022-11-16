#include <iostream>
#include <string>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

//Declaración de variables
int* item, * fecha, registro; //item: articulo
string* nombre, * clasificacion, * caracteristicas, * descripcion, * genero;
float* precio, * iva, * total;
int opcion2, opcion3, opcion4, desicion, n=1;

//Funciones void
void alta();
void eliminar();
void lista();
void modificacion();
void archivo();

int main()
{
	int opcion;
	printf("\t **Gameplay Force Store** \n");
	printf("Seleccione una opcion:\n");
	printf("1.-Agregar Articulo\n 2.-Modificar Articulo\n 3.-Eliminar Articulo\n 4.-Lista de Articulos\n 5.-Limpiar Pantalla\n 6.-Salir\n");
	scanf_s("%d", &opcion);
	switch (opcion)
	{
	case 1://Agregar Articulo
		alta();
		system("pause");
		return main();
		break;

	case 2: //Modificar Articulo
		modificacion();
		system("pause");
		return main();
		break;

	case 3://Eliminar Articulo
		eliminar();
		system("pause");
		return main();
		break;

	case 4: //Lista de Articulos
		lista();
		system("pause");
		return main();
		break;

	case 5: //Limpiar Pantalla
		system("cls");
		return main();
		break;

	case 6: //Salir
		archivo();
		exit(1);
		break;

	default:
		printf("Opcion incorrecta...\n");
		return main();
		break;
	}
}

void alta()
{
	printf("Cuantos registros desea dar de alta? \n");
	scanf_s("%d", &registro);

	item = new int[registro];
	fecha = new int[registro];
	nombre = new string[registro];
	descripcion = new string[registro];
	genero = new string[registro];
	caracteristicas = new string[registro];
	clasificacion = new string[registro];
	precio = new float[registro];
	iva = new float[registro];
	total = new float[registro];

	for (int i = 0; i < registro; i++)
	{
		printf("Ingrese el numero del articulo\n"); //Numero del articulo (item)
		scanf_s("%d", &item[i]);
		do
		{
			if (item[i] != item[i - n])
			{
				n = n + 1;
			}
			else
			{
				printf("El articulo ya existe\n");
				printf("Ingrese el articulo\n");
				scanf_s("%d", &item[i]);
			}
		} while (n < registro);

		printf("Ingrese el nombre del articulo:\n"); //Nombre del articulo
		cin.ignore();
		getline(cin, nombre[i]);

		printf("Ingrese el a%o de lanzamiento:\n", 164); //Fecha de lanzamiento
		scanf_s("%d", &fecha[i]);

		printf("Ingrese la clasificacion del articulo\n 1.-Todos\n 2.-Adolescentes\n 3.-Maduro +17\n 4.-Adultos unicamente +18\n"); //Clasificación
		scanf_s("%d", &opcion2);
		switch (opcion2)
		{
		case 1:
			clasificacion[i] = "Todos\n";
			system("pause");
			break;
		case 2:
			clasificacion[i] = "Adolescentes\n";
			system("pause");
			break;
		case 3:
			clasificacion[i] = "Maduro +17\n";
			system("pause");
			break;
		case 4:
			clasificacion[i] = "Adultos unicamente +18\n";
			system("pause");
			break;
		default:
			printf("Opción invalida\n");
			break;
		}

		printf("Ingrese el genero del articulo\n 1.-Accion\n 2.-Aventura\n 3.-Deportes\n 4.-Estrategia\n 5.-Simulacion\n 6.-Musical\n"); //Género
		scanf_s("%d", &opcion3);
		switch (opcion3)
		{
		case 1:
			genero[i] = "Accion\n";
			system("pause");
			break;
		case 2:
			genero[i] = "Aventura\n";
			system("pause");
			break;
		case 3:
			genero[i] = "Deportes\n";
			system("pause");
			break;
		case 4:
			genero[i] = "Estrategia\n";
			system("pause");
			break;
		case 5:
			genero[i] = "Simulacion\n";
			system("pause");
			break;
		case 6:
			genero[i] = "Musical\n";
			system("pause");
			break;
		default:
			printf("Opción invalida\n");
			break;
		}

		printf("Ingrese la descripcion del articulo:\n"); //Descripcion
		cin.ignore();
		getline(cin, descripcion[i]);

		printf("Ingrese las caracteristicas del articulo:\n"); //Caracteristicas
		cin.ignore();
		getline(cin, caracteristicas[i]);

		printf("Ingrese el precio del articulo:\n"); //Precios
		scanf_s("%f", &precio[i]);
		iva[i] = precio[i] * 0.16;
		total[i] = precio[i] + iva[i];
	
		system("pause");
		system("cls");
	
		if ((registro - 1) == i)//Registro extra
		{
			int desicion;
			printf("Desea dar de alta otro registro?\n si=1 \n");
			scanf_s("%d", &desicion);
			if (desicion == 1)
			{
				registro = registro + 1;
			}
		}
	}
}

void eliminar()
{
	int eliminar;
	printf("Ingrese el numero de articulo a eliminar\n");
	scanf_s("%d", &eliminar);

	for (int i = 0; i < registro; i++)
	{
		if (eliminar == item[i])
		{
			item[i] = 0;
		}
	}
}

void lista()
{
	int op2, op3, op4;
	do
	{
		system("cls");
		printf("1.-Articulos Vigentes\n 2.-Clasificacion\n 3.-Genero\n 4.-Salir\n");
		scanf_s("%d", &op2);
		system("cls");
		switch (op2)
		{
		case 1: //Lista po articulos Vigentes
			for (int i = 0; i < registros; i++)
			{
				if (item[i] != 0)
				{
					printf("ARTICULO: %d \n", item[i]);
					printf("Nombre: %s \n", name[i].c_str());
					printf("A%co: %d \n", 164, year[i]);
					printf("Descripcion: %s\n", descr[i].c_str());
					printf("Clasificacion: %s\n", clas[i].c_str());
					printf("Caracteristicas: %s\n", caract[i].c_str());
					printf("Genero: %s\n", genre[i].c_str());
					printf("subtotal: %f \n", subtotal[i]);
					printf("iva: %f \n", iva[i]);
					printf("total: %f \n ", total[i]);
				}
			}
			system("pause");
			break;
		case 2: //Lista por clasificacion
			printf("Ingrese la opcion deseada de busqueda\n 1.-Todos\n 2.-Adolescentes\n 3.-Maduro +17\n 4.-Adultos unicamente +18\n");
			scanf_s("%d", &op3);
			for (int i = 0; i < registro; i++)
			{
				switch (op3)
				{
				case 1: //Todos
					if (clasificacion[i] == "Todos")
					{
						if (item[i] != 0)
						{
							printf("Numero de articulo: %d \n", item[i]);
							printf("Nombre: %s \n", nombre[i].c_str());
							printf("Fecha: %d \n", fecha[i]);
							printf("Clasificacion: %s \n", clasificacion[i].c_str());
							printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
							printf("Descripcion: %s \n", descripcion[i].c_str());
							printf("Genero: %s \n", genero[i].c_str());
							printf("Precio Unitario: %f \n", precio[i]);
							printf("IVA: %f \n", iva[i]);
							printf("Total: %f \n", total[i]);
						}
					}
					system("pause");
					break;

				case 2: //Adolescentes
					if (clasificacion[i] == "Adolescentes")
					{
						if (item[i] != 0)
						{
							printf("Numero de articulo: %d \n", item[i]);
							printf("Nombre: %s \n", nombre[i].c_str());
							printf("Fecha: %d \n", fecha[i]);
							printf("Clasificacion: %s \n", clasificacion[i].c_str());
							printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
							printf("Descripcion: %s \n", descripcion[i].c_str());
							printf("Genero: %s \n", genero[i].c_str());
							printf("Precio Unitario: %f \n", precio[i]);
							printf("IVA: %f \n", iva[i]);
							printf("Total: %f \n", total[i]);
						}
					}
					system("pause");
					break;

				case 3: //Maduro +17
					if (clasificacion[i] == "Maduro +17")
					{
						if (item[i] != 0)
						{
							printf("Numero de articulo: %d \n", item[i]);
							printf("Nombre: %s \n", nombre[i].c_str());
							printf("Fecha: %d \n", fecha[i]);
							printf("Clasificacion: %s \n", clasificacion[i].c_str());
							printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
							printf("Descripcion: %s \n", descripcion[i].c_str());
							printf("Genero: %s \n", genero[i].c_str());
							printf("Precio Unitario: %f \n", precio[i]);
							printf("IVA: %f \n", iva[i]);
							printf("Total: %f \n", total[i]);
						}
					}
					system("pause");
					break;

				case 4: //Adultos unicamente +18
					if (clasificacion[i] == "Adultos unicamente +18")
					{
						if (item[i] != 0)
						{
							printf("Numero de articulo: %d \n", item[i]);
							printf("Nombre: %s \n", nombre[i].c_str());
							printf("Fecha: %d \n", fecha[i]);
							printf("Clasificacion: %s \n", clasificacion[i].c_str());
							printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
							printf("Descripcion: %s \n", descripcion[i].c_str());
							printf("Genero: %s \n", genero[i].c_str());
							printf("Precio Unitario: %f \n", precio[i]);
							printf("IVA: %f \n", iva[i]);
							printf("Total: %f \n", total[i]);
						}
					}
					system("pause");
					break;

				default:
					printf("La opcion es incorrecta \n");
					system("pause");
					break;
				}
			}
			system("pause");
			break;

		case 3: //Lista por genero
			printf("Ingrese la opcion deseada de busqueda\n 1.-Accion\n 2.-Aventura\n 3.-Deportes\n 4.-Estrategia\n 5.-Simulación\n 6.-Musical\n");
			scanf_s("%d", &op4);
			for (int i = 0; i < registro; i++)
			{
				switch (op4)
				{
				case 1: //Accion
					if (genero[i] == "Accion")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				case 2: //Aventura
					if (genero[i] == "Aventura")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				case 3: //Deportes
					if (genero[i] == "Deportes")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				case 4: //Estrategia
					if (genero[i] == "Estrategia")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				case 5: //Simulacion
					if (genero[i] == "Simulacion")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				case 6: //Musical
					if (genero[i] == "Musical")
					{
						printf("Numero de articulo: %d \n", item[i]);
						printf("Nombre: %s \n", nombre[i].c_str());
						printf("Fecha: %d \n", fecha[i]);
						printf("Clasificacion: %s \n", clasificacion[i].c_str());
						printf("Caracteristicas: %s \n", caracteristicas[i].c_str());
						printf("Descripcion: %s \n", descripcion[i].c_str());
						printf("Genero: %s \n", genero[i].c_str());
						printf("Precio Unitario: %f \n", precio[i]);
						printf("IVA: %f \n", iva[i]);
						printf("Total: %f \n", total[i]);
					}
					system("pause");
					break;

				default:
					printf("La opcion es incorrecta \n");
					system("pause");
					break;
				}
			}
			system("pause");
			break;

		case 4:
			printf("Saliendo... \n");
			system("pause");
			break;

		default:
			printf("La opcion es incorrecta \n");
			system("pause");
			break;
		}
	} while (op2 != 4);
	system("cls");
}

void modificacion()
{
	int modificar;
	int opc1,opc2,opc3;
	
	do
	{
		printf("Ingrese el numero de articulo a modificar\n");
		scanf_s("%d", &modificar);
	} while (modificar <= 0);
	
	for (int i = 0; i < registro; i++)
	{
		if (modificar == item[i])
		printf("Opcion a modificar:\n 1.Nombre\n 2.-Fecha de lanzamiento\n 3.-Clasificacion\n 4.-Genero\n 5.-Caracteristicas\n 6.-Descripcion\n 7.-Precio\n");
		scanf_s("%d", &opcion4);
		switch (opcion4)
		{
		case 1: //Nombre
			printf("Ingrese el nombre del articulo:\n");
			cin.ignore();
			getline(cin, nombre[i]);
			break;

		case 2: //Fecha
			printf("Ingrese el a%o de lanzamiento:\n", 164);
			scanf_s("%d", &fecha[i]);
			break;

		case 3: //Clasificacion
			printf("Modifique la clasificacion\n 1.-Todos\n 2.-Adolescentes\n 3.-Maduro +17\n 4.-Adultos unicamente +18\n");
			scanf_s("%d", &opc2);
			switch (opc2)
			{
			case 1:
				clasificacion[i] = "Todos\n";
				break;
			case 2:
				clasificacion[i] = "Adolescentes\n";
				break;
			case 3:
				clasificacion[i] = "Maduro +17\n";
				break;
			case 4:
				clasificacion[i] = "Adultos unicamente +18\n";
				break;
			default:
				printf("Opción invalida\n");
				break;
			}
			break;

		case 4://Genero

			printf("Modifique el genero\n 1.-Accion\n 2.-Aventura\n 3.-Deportes\n 4.-Estrategia\n 5.-Simulación\n 6.-Musical\n");
			scanf_s("%d", &opc3);
			switch (opc3)
			{
			case 1:
				genero[i] = "Accion\n";
				break;
			case 2:
				genero[i] = "Aventura\n";
				break;
			case 3:
				genero[i] = "Deportes\n";
				break;
			case 4:
				genero[i] = "Estrategia\n";
				break;
			case 5:
				genero[i] = "Simulacion\n";
				break;
			case 6:
				genero[i] = "Musical\n";
				break;
			default:
				printf("Opción invalida\n");
				break;
			}
			break;

		case 5: //Caracteristicas
			printf("Ingrese las caracteristicas del articulo:\n");
			cin.ignore();
			getline(cin, caracteristicas[i]);
			break;

		case 6: //Descripcion
			printf("Ingrese la descripcion del articulo:\n");
			cin.ignore();
			getline(cin, descripcion[i]);
			break;

		case 7: //Precio
			printf("Ingrese el precio del articulo:\n");
			scanf_s("%f", &precio[i]);
			iva[i] = precio[i] * 0.16;
			total[i] = precio[i] + iva[i];
			break;

		default:
			printf("Opcion invalida, intente de nuevo...\n");
			break;
			system("pause");
			return modificacion();
		}
	}
}

void archivo()
{
	ofstream archivo; //Funcion para abrir el archivo
	string nombrearchivo;

	nombrearchivo="ListaArticulos_Gameplay Force Store"

	archivo.open(nombrearchivo.c_str(), ios::out);

	if (archivo.fail())
	{
		printf("No se genero el archivo \n");
		system("pause");
		exit(1);
	}

	for (int i = 0; i < registro; i++)
		if(item[i]!=0)
		{
			archivo << "Videojuego\n" << i + 1 << endl;
			archivo <<"\t"<< "item[i]" << endl;
			archivo << "\t" << "Nombre:" << endl;
			archivo << "\t" << "Fecha:" << endl;
			archivo << "\t" << "Clasificacion:" << endl;
			archivo << "\t" << "Genero:" << endl;
			archivo << "\t" << "Descripcion:" << endl;
			archivo << "\t" << "Caracteristicas:" << endl;
			archivo << "\t" << "Precio:" << endl;
			archivo << "\t" << "IVA:" << endl;
			archivo << "\t" << "Total:" << endl;
		}
	archivo.close();
}
