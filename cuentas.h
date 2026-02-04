#ifndef CUENTAS_H
#define CUENTAS_H

#include <string>

struct Cuentas {
    int id;
    std::string nombre;
    double saldo;
    bool activa;
};

void CrearCuenta(Cuentas cuentas[], int &contador);
int BuscarCuenta(Cuentas cuentas[], int contador, int id);
void MostrarSaldo(Cuentas cuentas[], int contador);
void GuardarCuentas(Cuentas cuentas[], int contador);
int CargarCuentas(Cuentas cuentas[]);
void DepositarSaldo(Cuentas cuentas[], int contador);
void RetirarSaldo(Cuentas cuentas[], int contador);
void MostrarTodasC(Cuentas cuentas[], int contador);
void BajaCuenta(Cuentas cuentas[], int contador);
void EditarTitular(Cuentas cuentas[], int contador);
void ReactivarCuenta(Cuentas cuentas[], int contador);
#endif // CUENTAS_H