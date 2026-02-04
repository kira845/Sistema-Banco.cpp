#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "cuentas.h"

void CrearCuenta(Cuentas cuentas[], int &contador){
    if (contador >=100){
        std::cout << "No se pueden crear mas cuentas.\n";
        return;
    }
    
    cuentas[contador].id = contador + 1;
    std::cout << "Su ID: " << cuentas[contador].id << std::endl;
    std::cout << "Ingrese nombre del titular: ";
    std::cin.ignore();
    std::getline(std::cin, cuentas[contador].nombre);
    if (cuentas[contador].nombre.empty()){
        std::cout << "El nombre no puede estar vacio. Cuenta no creada.\n";
        return;
    }
    std::cout << "Ingrese saldo inicial: ";
    std::cin >> cuentas[contador].saldo;

    if (cuentas[contador].saldo <0){
        std::cout << "El saldo inicial no puede ser negativo. Se establece en 0.\n";
        cuentas[contador].saldo=0;
    }
    cuentas[contador].activa= true;
    contador++;
    std::cout << "Cuenta creada exitosamente.\n";
}

int BuscarCuenta(Cuentas cuentas[], int contador, int id) {
    for (int i = 0; i < contador; i++) {
        if (cuentas[i].id == id) {
            return i;  // regresamos la posición
        }
    }
    return -1; // no encontrada
}
void MostrarSaldo(Cuentas cuentas[], int contador) {
    int id;
    std::cout << "Ingrese ID de la cuenta: ";
    std::cin >> id;
    int pos = BuscarCuenta(cuentas, contador, id);

    if (pos == -1) {
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    if (!cuentas[pos].activa) {
        std::cout << "Cuenta inactiva.\n";
        return;
    }
    std::cout << "Saldo de la cuenta ID " << id << ": $" << cuentas[pos].saldo << "\n";
}
void GuardarCuentas(Cuentas cuentas[], int contador) {
    std::ofstream archivo("cuentas.txt");

    if (!archivo.is_open()) {
        std::cout << "Error al guardar el archivo.\n";
        return;
    }

    for (int i = 0; i < contador; i++) {
        archivo 
            << cuentas[i].id << ","
            << cuentas[i].nombre << ","
            << cuentas[i].saldo << ","
            << cuentas[i].activa << "\n";
    }

    archivo.close();
}
int CargarCuentas(Cuentas cuentas[]) {
    std::ifstream archivo("cuentas.txt");
    std::string linea;

    int contador = 0;

    if (!archivo.is_open()) {
        return 0;
    }

    while (std::getline(archivo, linea)) {
         if (contador >= 100) {
            std::cout << "Limite de cuentas alcanzado al cargar archivo.\n";
            break;
        }
        std::stringstream ss(linea);
        std::string dato;

        std::getline(ss, dato, ',');
        cuentas[contador].id = std::stoi(dato);

        std::getline(ss, dato, ',');
        cuentas[contador].nombre = dato;

        std::getline(ss, dato, ',');
        cuentas[contador].saldo = std::stof(dato);

        std::getline(ss, dato, ',');
        cuentas[contador].activa = std::stoi(dato);

        contador++;
    }

    archivo.close();
    return contador;
}


void DepositarSaldo(Cuentas cuentas[], int contador){
    int id;
    float cantidad;
    std::cout << "Ingrese ID de la cuenta: ";
    std::cin >> id;
    int pos = BuscarCuenta (cuentas, contador, id);

    if (pos == -1) {
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    if (!cuentas[pos].activa) {
    std::cout << "Cuenta inactiva.\n";
    return;
}

    std::cout << "Ingrese cantidad a depositar: ";
    std::cin >> cantidad;
    if (cantidad <=0){
        std::cout << "Cantidad invalida.\n";
        return;
    }
    cuentas[pos].saldo += cantidad;
    std::cout << "Deposito exitoso. Nuevo saldo: $" << cuentas[pos].saldo << "\n";
}

void RetirarSaldo(Cuentas cuentas[], int contador){
    int id;
    float cantidad;
    std::cout << "Ingrese ID de la cuenta: ";
    std::cin >>id;
    int pos = BuscarCuenta (cuentas, contador, id);

    if (pos == -1) {
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    if (!cuentas[pos].activa) {
    std::cout << "Cuenta inactiva.\n";
    return;
}
    std::cout << "Ingrese cantidad a retirar: ";
    std::cin >> cantidad;
    if (cantidad <=0 || cantidad > cuentas[pos].saldo){
        std::cout << "Fondos insuficientes o cantidad invalida.\n";
        return;
    }
    cuentas[pos].saldo -= cantidad;
    std::cout << "Retiro exitoso. Nuevo saldo: $" << cuentas[pos].saldo << "\n";
}

void MostrarTodasC(Cuentas cuentas[], int contador){
    if (contador ==0){
        std::cout << "No hay cuentas disponibles.\n";
        return;
    }
    for (int i=0; i<contador; i++){
        std::cout << "ID: " << cuentas[i].id << ", Nombre: " << cuentas[i].nombre 
                  << ", Saldo: $" << cuentas[i].saldo 
                  << ", Activa: " << (cuentas[i].activa ? "Si" : "No") << "\n";
    }
}
void BajaCuenta(Cuentas cuentas[], int contador){
    int id;
    std::cout << "Ingrese ID de la cuenta a dar de baja: ";
    std::cin >> id;
    int pos = BuscarCuenta(cuentas, contador, id);
    if(pos == -1){
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    if (!cuentas[pos].activa) {
    std::cout << "La cuenta ya esta dada de baja.\n";
    return;
}
    cuentas[pos].activa = false;
    std::cout << "Cuenta dada de baja exitosamente.\n";
}

void EditarTitular(Cuentas cuentas[], int contador){
    int id;
    std::cout << "Ingrese ID de la cuenta a editar: ";
    std::cin >> id;
    int pos = BuscarCuenta(cuentas, contador, id);
    if (pos == -1) {
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    std::cout << "Ingrese nuevo nombre del titular: ";
    std::cin.ignore();
     std::getline(std::cin, cuentas[pos].nombre);
    if (cuentas[pos].nombre.empty()){
        std::cout << "El nombre no puede estar vacio. Cuenta no editada.\n";
        return;
    }
    std::cout << "Nombre actualizado correctamente.\n";

}

void ReactivarCuenta(Cuentas cuentas[], int contador){
    
    int id;
    std::cout << "Ingrese ID de la cuenta a reactivar: ";
    std::cin >> id;
    int pos = BuscarCuenta(cuentas, contador, id);
    if(pos == -1){
        std::cout << "Cuenta no encontrada.\n";
        return;
    }
    if (cuentas[pos].activa) {
    std::cout << "La cuenta ya esta activa.\n";
    return;
}
    cuentas[pos].activa = true;
    std::cout << "Cuenta reactivada exitosamente.\n";

}