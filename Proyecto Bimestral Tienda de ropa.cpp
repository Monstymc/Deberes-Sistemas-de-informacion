#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char inventario[100][20] = {
	"Camiseta",
		"Pantalon",
		"Chaqueta",
		"Zapatos",
		"Gorra"
};
float precios[100] = {
	15.99,
		25.50,
		40.00,
		35.75,
		10.25
};
int cantidadInventario = 5;
char carrito[100][20];
float preciosCarrito[100];
int cantidadCarrito = 0;
void mostrarInventario() {
	system("cls");
	printf("===== INVENTARIO =====\n\n");
	for(int i = 0; i < cantidadInventario; i++) {
		printf("%d. %s - $%.2f\n",
			   i + 1,
			   inventario[i],
			   precios[i]);
	}
}
void agregarCarrito(int opcion) {
	strcpy(carrito[cantidadCarrito],
		   inventario[opcion]);
	preciosCarrito[cantidadCarrito] =
		precios[opcion];
	cantidadCarrito++;
	printf("\nProducto agregado al carrito.\n");
}
void mostrarCarrito() {
	system("cls");
	if(cantidadCarrito == 0) {
		printf("Carrito vacio.\n");
		return;
	}
	float total = 0;
	printf("===== CARRITO =====\n\n");
	for(int i = 0; i < cantidadCarrito; i++) {
		printf("%d. %s - $%.2f\n",
			   i + 1,
			   carrito[i],
			   preciosCarrito[i]);
		total += preciosCarrito[i];
	}
	printf("\nTotal: $%.2f\n", total);
}
void eliminarCarrito(int posicion) {
	for(int i = posicion;
	i < cantidadCarrito - 1;
	i++) {
		strcpy(carrito[i], carrito[i + 1]);
		preciosCarrito[i] =
			preciosCarrito[i + 1];
	}
	cantidadCarrito--;
	printf("\nProducto eliminado.\n");
}
void agregarInventario() {
	char nombre[20];
	float precio;
	printf("\nIngrese nombre del producto: ");
	scanf("%s", nombre);
	printf("Ingrese precio: ");
	scanf("%f", &precio);
	strcpy(inventario[cantidadInventario],
		   nombre);
	precios[cantidadInventario] = precio;
	cantidadInventario++;
	printf("\nProducto agregado correctamente.\n");
}
void eliminarInventario(int posicion) {
	for(int i = posicion;
	i < cantidadInventario - 1;
	i++) {
		strcpy(inventario[i],
			   inventario[i + 1]);
		
		precios[i] = precios[i + 1];
	}	
	cantidadInventario--;	
	printf("\nProducto eliminado del inventario.\n");
}
int main() {	
	int menuPrincipal;
	do {
		system("cls");
		printf("===== SISTEMA TIENDA =====\n\n");
		printf("1. Cliente\n");
		printf("2. Administrador\n");
		printf("3. Salir\n");
		printf("\nSeleccione una opcion: ");
		if(scanf("%d", &menuPrincipal) != 1) {			
			printf("\nOpcion invalida.\n");			
			scanf("%*s");			
			system("pause");			
			continue;
		}		
		if(menuPrincipal == 1) {			
			int opcionCliente;			
			do {				
				system("cls");
				printf("===== MENU CLIENTE =====\n\n");
				printf("1. Ver inventario\n");
				printf("2. Ver carrito\n");
				printf("3. Finalizar compra\n");				
				printf("\nSeleccione una opcion: ");				
				if(scanf("%d",
						 &opcionCliente) != 1) {					
					printf("\nOpcion invalida.\n");					
					scanf("%*s");					
					system("pause");				
					continue;
				}				
				switch(opcionCliente) {					
				case 1: {					
					mostrarInventario();					
					int producto;					
					printf("\nSeleccione producto: ");					
					if(scanf("%d",
							 &producto) != 1) {						
						printf("\nEntrada invalida.\n");						
						scanf("%*s");						
						system("pause");						
						continue;
					}					
					if(producto >= 1 &&
					   producto <= cantidadInventario) {						
						agregarCarrito(producto - 1);
					}					
					system("pause");
					break;
				}				
				case 2: {					
					mostrarCarrito();					
					if(cantidadCarrito > 0) {						
						int eliminar;						
						printf("\nIngrese producto a eliminar (0 volver): ");						
						if(scanf("%d",
								 &eliminar) != 1) {							
							printf("\nEntrada invalida.\n");							
							scanf("%*s");							
							system("pause");							
							continue;
						}						
						if(eliminar != 0) {
							eliminarCarrito(eliminar - 1);
						}
					}
					system("pause");
					break;
				}
				case 3:
					printf("\nCompra realizada con exito.\n");
					system("pause");
					break;
				default:
					printf("\nOpcion invalida.\n");
					system("pause");
				}
			} while(opcionCliente != 3);
		}
		else if(menuPrincipal == 2) {
			char contrasena[20];
			system("cls");
			printf("Ingrese contraseña de administrador: ");
			scanf("%s", contrasena);
			if(strcmp(contrasena, "admin123") == 0) {
				int opcionAdmin;			
				do {
					system("cls");
					printf("===== MENU ADMIN =====\n\n");					
					printf("1. Ver inventario\n");
					printf("2. Agregar producto\n");
					printf("3. Eliminar producto\n");
					printf("4. Salir\n");					
					printf("\nSeleccione una opcion: ");					
					if(scanf("%d",
							 &opcionAdmin) != 1) {						
						printf("\nOpcion invalida.\n");					
						scanf("%*s");						
						system("pause");						
						continue;
					}					
					switch(opcionAdmin) {						
					case 1:						
						mostrarInventario();						
						system("pause");
						break;						
					case 2:						
						mostrarInventario();						
						agregarInventario();						
						system("pause");
						break;						
					case 3: {						
						mostrarInventario();						
						int eliminar;						
						printf("\nSeleccione producto a eliminar: ");						
						if(scanf("%d",
								 &eliminar) != 1) {							
							printf("\nEntrada invalida.\n");							
							scanf("%*s");							
							system("pause");							
							continue;
						}						
						if(eliminar >= 1 &&
						   eliminar <= cantidadInventario) {							
							eliminarInventario(eliminar - 1);
						}						
						system("pause");
						break;
					}					
					case 4:
						break;						
					default:						
						printf("\nOpcion invalida.\n");						
						system("pause");
					}					
				} while(opcionAdmin != 4);
			}
			else {				
				printf("\nContraseña incorrecta.\n");
				
				system("pause");
			}
		}
	} while(menuPrincipal != 3);
	return 0;
}
