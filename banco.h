#include <string>
using namespace std;

class Cliente {
    	string nome, cpf;
public:
    	Cliente();
    	Cliente(string, string);
    	string getNome();
	void setNome(string n);
    	string getCPF();
    	void setCPF(string c);
};

class ContaBancaria {
    	int numero;
    	double saldo;
    	Cliente titular;
public:
	ContaBancaria(int, Cliente);
    	ContaBancaria(int, Cliente, double);
    	void depositar(double valor);
    	void sacar(double valor);
    	void transferir(double valor, ContaBancaria &destino);
   	void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);
 	void exibirSaldo();
	void exibirInformacoes();
};
