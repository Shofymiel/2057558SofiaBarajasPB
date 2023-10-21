#include <iostream>
#include <string>
using namespace std;

struct Cafe_Express
{
	string Datos_generales;
	int num_ticket; //no se puede repetir
	string nom_vendedor;
	int fecha;
	char lista_art;
	float precio_art;
	float precio_unitario_total;//Precio unitario del total de los articulos
	float descuento;
	float propina; //Propina 10%,15%,20% sobre el precio unitario.
	float impuesto;
	float total;
	string platillo;
	int cant;
	int numOrden;
	int EliminarOrden;
	int CambiarOrden;
};

int main()
{
	Cafe_Express ticket[100]; //arreglo
	int op, numOrden = 1, EliminarOrden = 0, CambiarOrden = 0, i = 0;
	float total = 0.0;
	do
	{
		printf("Cafe Express, Restaurante XYZ S.A. de C.V. \n");
		printf("\nEscoja una opcion:\n1.- Alta de ordenes\n 2.- Modificar orden\n 3.- Cancelar orden\n 4.- Lista de ordenes\n 5.- Limpiar\n 6.- Salir \n");;
		cin >> op; /*use cin, porque no me deja usar scanf o scanf_s, me marca demasiadas advertencias y eso de que puse la libreria <cstdio> y escribi su sintaxis correcta*/
		switch (op)
		{
		case 1: //Alta de ordenes
		{
			ticket[i].num_ticket = numOrden;
			printf("\nNombre del vendedor, solo un nombre y una letra en mayuscula para indicar el apellido\n");
			cin >> ticket[i].nom_vendedor;
			printf("\nIngrese el alimento o bebida para ordenar\n");
			cin >> ticket[i].platillo;
			printf("\nIngrese la cantidad con numeros: \n");
			cin >> ticket[i].cant;
			printf("\nEl costo del alimento escogido es de: $ \n");
			cin >> ticket[i].precio_art;
			total = ticket[i].precio_art * 0.16;
			printf("\nSu orden ha sido guardada correctamente :) \n");
			printf("su numero de orden: %d", numOrden);
			numOrden++;
			break;
		}
		case 2: //modificar orden
		{
			printf("\nIngrese el número de orden que desea modificar: \n");
			cin >> CambiarOrden;
			if (CambiarOrden >= 1 && CambiarOrden < numOrden)
			{
				printf("Modificar detalles para la orden # %d\n", CambiarOrden);
				printf("\nNombre del vendedor\n");
				cin >> ticket[i].nom_vendedor;
				printf("\nIngrese el alimento o bebida para ordenar\n");
				cin >> ticket[i].platillo;
				printf("\nIngrese la cantidad: \n");
				cin >> ticket[i].cant;
				printf("\nSe ha modificado su pedido exitosamente!!\n");
			}
			else
			{
				printf("\nNúmero de orden inválido.");
			}
			break;
		}
		case 3: //cancelar orden
		{
			printf("\nIngrese el número de orden que desea eliminar: \n");
			cin >> EliminarOrden;
			if (EliminarOrden >= 1)
			{
				EliminarOrden = numOrden;
				numOrden--;
				printf("\nSe ha cancelado su pedido exitosamente!!\n");
			}
			else
			{
				printf("\nNo fue posible hacer esa operacion \n");
			}
			break;
		}
		case 4: //lista de ordenes,  mostrar todas las órdenes almacenadas en ese momento.
		{
			printf("\nLista de ordenes: \n");
			for (int i = 0; i < numOrden; ++i)
			{
				printf("Orden #%d\n", ticket[i].num_ticket);
				printf("Vendedor: %s\n", ticket[i].nom_vendedor.c_str());
				printf("Platillo: %s\n", ticket[i].platillo.c_str());
				printf("Cantidad: %d\n", ticket[i].cant);
				printf("Precio del articulo $: %.2f\n", ticket[i].precio_art);
				printf("Total con IVA $: %.2f\n", total);
				printf("----------------------------------\n");
			}
			break;
		}
		case 5: //limpiar pantalla
		{
			system("cls");
			break;
		}
		case 6: //salir
		{
			return 0;
			break;
		}
		default: //para marcar un error
		{
			printf("\nOpción inválida. Seleccione otra opcion\n");
			break;
		}
		}
	} while (op != 6);//para cuando se presione 6, se pueda salir del switch y do-while
	return 0;
	system("pause");
}