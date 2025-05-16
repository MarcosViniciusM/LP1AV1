#include <iostream>
#include "banco.h"
using namespace std;

Cliente::Cliente(){}

Cliente::Cliente(string n, string c){
    nome = n;
    cpf = c;
}

string Cliente::getNome(){
	return nome;
}

void Cliente::setNome(string s){
	nome = s;
}

string Cliente::getCPF(){
	return cpf;
}

void Cliente::setCPF(string c){
	cpf = c;
}

ContaBancaria::ContaBancaria(int n, Cliente t){
    numero = n;
    titular.setNome(t.getNome());
    titular.setCPF(t.getCPF());
    saldo=0;
}

ContaBancaria::ContaBancaria(int n, Cliente t, double s){
    numero = n;
    titular.setNome(t.getNome());
    titular.setCPF(t.getCPF());
    saldo = s;
}

void ContaBancaria::depositar(double valor){
	// Impede a operação se for um valor negativo
	if(valor<0){
        return;
    }
    saldo+=valor;
}

void ContaBancaria::sacar(double valor){
	// Impede a operação se for um valor negativo
    if (valor<0){
        return;
    }
	// Impede a operação se o valor for maior do que o saldo disponível
    if(valor>saldo){
        return;
    }
    saldo-=valor;
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino){
	// Impede a operação se o valor for maior do que o saldo disponível
    if(valor>saldo){
        return;
    }
	// Saca o valor da conta original, e depois deposita na conta alvo
    sacar(valor);
    destino.depositar(valor);
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2){
	// Impede a operação se o valor for maior do que o saldo disponível
    if(valor>saldo){
        return;
    }
	// Saca o valor da conta original, e depois deposita nas duas contas alvo
    sacar(valor);
    destino1.depositar(valor/2);
    destino2.depositar(valor/2);
}

void ContaBancaria::exibirSaldo(){
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes(){
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCPF() << endl;
    cout << "Numero da conta: " << numero << ", Saldo : R$ " << saldo << endl;
}