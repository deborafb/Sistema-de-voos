#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;
	    
class Passagem {
	
    private:
        
        bool cancelada;
        string nome;
        string classe;
        string dataIda;
        string portao;
        string assento;
        string origem;
        string destino;
        int identificacao;
        string linha;
        float preco;
        string horario;
        string voo;
        
    public:
			
		void setEstado(bool cancelou) {
			cancelada = cancelou;
		}		
		void defineNome(string nome2) {
			nome = nome2;
		}
		void defineClasse(string classe1) {
			classe = classe1;
		}
		void defineDataIda(string dataIda1) {
			dataIda = dataIda1;
		}
		void defineHorario(string hora) {
			horario = hora;
		}
		void definePortao(string portao1) {
			portao = portao1;
		}
		void defineAssento(string assento1) {
			assento = assento1;
		}
		void defineOrigem(string origem1) {
			origem = origem1;
		}
		void defineDestino(string destino1) {
			destino = destino1;
		}
		void defineIdentificacao(int identificacao1) {
			identificacao = identificacao1;
		}
		void defineLinha(string linha1) {
			linha = linha1;
		}	
		void defineEstado() {
			cancelada = false;
		}
		
		void defineIdentificadorVoo(string identificador) {
			voo = identificador;
		}	
		void definePreco() {	
			preco = (rand()% 500000);
		}			
        string getNome() {
			return nome;
		}	
        string getClasse() {
			return classe;
		}	
        string getDataIda() {
            return dataIda;
        }    
        
		string getPortao() {
			return portao;
		}	
        string getAssento() {
			return assento;
		}	
        string getOrigem() {
			return origem;
		}	
        string getDestino() {
			return destino;
		}	
		
		string getHora() {
			return horario;
		}	
        int getIdentificacao() {
			return identificacao;
		}	
        string getLinha() {
			return linha;
		}	 
		string getEstado() {
			string saida;
			if (cancelada == true) {
				saida = "Cancelada";
			} else {
				saida = "Ativa";
			}		
			return saida; 
		}
		float getPreco() {
			return preco;
		}
		string getVoo() {
			return voo;
		}	
				
		  
};

class Voo {
    private:
	    string linha;
	    string identificacao;
	    int quantidadeClasses;
	    int quantidadeAssentos;	
	    std::vector<string> classes;
	    std::vector<string> assentos;
	    std::vector<bool> assentosOcupados;
	    string horas;
	    string datas;
	    string partir;
	    string chegar;
	    bool cancelado;
	    
	public:	    
	    void linhaAerea(string linhaAerea) {
			linha = linhaAerea;
		}	
		void identificacaoVoo(string identificacaoVoo) {
			identificacao = identificacaoVoo;
		}
		
		vector<bool> ocupados() {	
			return assentosOcupados;
		}	
		void setAssentoOcupado(string assento) {
			for (int i = 0; i < quantidadeAssentos; i++) {
			    if (assentos[i] == assento) {
				    assentosOcupados[i] = true;
				}  				    
			}			
		}			
		
	    string getLinha() {
			return linha;
		}	
	    string getIdentificacao() {
			return identificacao;
		}	
	    string getClasses() {
			string saida;
			for (int i = 0; i < quantidadeClasses; i++) 
				saida += classes[i] + "\n";
			return saida;	
		}		
	    string getAssentos() {		
			string saida;	
	        for (int i = 0; i < quantidadeAssentos; i++) 
	            if (assentosOcupados[i] == true) {
					saida += (assentos[i] + " - Ocupado\n");
			    }	
			    else {
			        saida += assentos[i] + " - Disponível\n";
			    }    
			return saida;	
		}
		
		void classesVoo(string nome) {		    				
			classes.push_back (nome);	         				
		}
		
		void assentosVoo(string assentosVoo) {
			assentos.push_back(assentosVoo);		
        }	
        
        void assentoOcupado(bool ocupado) {
			assentosOcupados.push_back(ocupado);
		}				
				
		void somaAssentos(int pessoas) {
		    quantidadeAssentos = pessoas;
		}
		void somaClasses(int classes) {
			quantidadeClasses = classes;
		}		
		void horario(string hora) {
			horas = hora;
		}
		void data(string dat) {
			datas = dat;
		}	
		string getHorario() {
			return horas;
		}	 
		
		void partida(string lugar) {
			partir = lugar;
		}
		void destino(string lugar) {
			chegar = lugar;
		}	
		string getPartida() {
			return partir;
		}
		string getChegar() {
			return chegar;
		}
		string getData() {
			return datas;
		}	
		void cancelou(bool cancelado1) {
			cancelado = cancelado1;
	    }
	    
	    string getCancelado() {
			string saida;
			if (cancelado == true) {
			    saida = "Sim";
			} else {
				saida = "Não";
			}	    	 
			return saida;
		}
		
		bool getAssentoDisponivel(string assento) {
			bool disponivel = true;
			for (int i = 0; i < quantidadeAssentos; i++){
			    if (assentos[i] == assento) {
					if (assentosOcupados[i] == true) {
					    disponivel = false;			
				  	}
				}
			}	
			return disponivel;	
		}	  		        
};

Voo voo;
Passagem passagem;
Voo vooAtual;

int quantidadeVoos = 0;
int quantidadePassagens = 0;
float taxa = 2.2;
float pagar = 10.32;
std::vector <Voo> voos;
std::vector <Passagem> passagens;
int identificadorPassagem = (rand()% 10000000);
string letras[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
string letra = (letras[rand()% 26]);

int main() {
		
    int opcao = 0;
    while (opcao != 3) {
		cout << "\nBem vindo(a)!\n" << endl;
		cout << "Linha aérea(1) \nPessoa(2)" << endl;
		cout << "Sair(3)\n" << endl;
		cout << "Escolha sua categoria:" << endl;   
		cin >> opcao;

		if (opcao == 1) {
			int escolha = 0;
			while(escolha != 4) {
				cout << "\nAdicionar voo(1) \nVerificar voo(2) \nCancelar voo(3) \nVoltar(4) \n\nO que deseja?" << endl;		
				cin >> escolha;		
				if (escolha == 1) {
					string linha;
					cout << "\nDigite a linha aérea:" << endl;
					cin >> linha;
					voo.linhaAerea(linha);		    
					string identificacao;
					cout << "\nDigite a identificação do voo:" << endl;
					cin >> identificacao;
					voo.identificacaoVoo(identificacao);
					cout << "\nDigite a quantidade de classes do voo:" << endl;
					int valor;
					cin >> valor;
					voo.somaClasses(valor);
					string nome;
					cout << "\nDigite o(s) nome(s) da(s) classe(s):" << endl;				
					for (int i = 0; i < valor; i++) {				
						cin >> nome;
						voo.classesVoo(nome);
					}	
					cout << "\nDigite a quantidade de assentos do voo:" << endl;
					int quantidade;
					cin >> quantidade;
					voo.somaAssentos(quantidade);
					string assento;
					cout << "\nDigite a(s) identificação(ões) do(s) assentos(s):" << endl;
					for (int i = 0; i < quantidade; i++) {				
						cin >> assento;				
						voo.assentosVoo(assento);
						voo.assentoOcupado(false);
					}	
							
					cout << "\nDigite a data de partida e/ou chegada(no formato partida e chegada: \ndia/mês/ano-dia/mês/ano ou partida: dia/mês/ano):" << endl;
					string data;
					cin >> data;
					voo.data(data);
					cout << "\nDigite o horário de partida e/ou chegada(no formato partida e chegada: \nhora:minuto-hora:minuto ou partida: hora:minuto):" << endl;
					string horario;
					cin >> horario;
					voo.horario(horario);
					cout << "\nDigite o local de partida:" << endl;
					string lugar1;
					cin >> lugar1;
					voo.partida(lugar1);
					cout << "\nDigite o local de destino:" << endl;
					string lugar2;
					cin >> lugar2;
					voo.destino(lugar2);	
					voos.push_back(voo);			
					quantidadeVoos += 1;				
					cout << "\nVoo registrado com sucesso!" << endl;						
				}
				
				if (escolha == 2) {
					cout << "\nDigite a identificação do voo:" << endl;
					string identificador;
					cin >> identificador;
					bool achou = false;
					for (int i = 0; i < quantidadeVoos; i++) {
						if (voos[i].getIdentificacao() == identificador) {
							cout << "\nData: " + voos[i].getData() << endl;
							cout << "\nHorário: " + voos[i].getHorario() << endl;
							cout << "\nAssentos: \n" + voos[i].getAssentos() << endl;
							cout << "Origem: " + voos[i].getPartida() << endl;
							cout << "\nDestino: " + voos[i].getChegar() << endl;
							cout << "\nCancelado: " + voos[i].getCancelado() + "\n";
							achou = true;
							break;
						}			    
					}
					if (achou == false) {
						cout << "\nVoo não existe!" << endl;
					}	        
				}
				if (escolha == 3) {
					cout << "\nDigite a identificação do voo:" << endl;
					string identificador;
					cin >> identificador;
					bool achou = false;					
					for (int i = 0; i < quantidadeVoos; i++) {
						if (voos[i].getIdentificacao() == identificador) {
							if (voos[i].getCancelado() == "Sim") {
								achou = true;
								cout << "\nVoo já foi cancelado!" << endl;
							} else {									
								voos[i].cancelou(true);
								achou = true;	
								for (int i = 0; i < quantidadePassagens; i ++) {
									passagens[i].setEstado(true);
								}								
								cout << "\nVoo cancelado com sucesso!" << endl;
							}    					
						}	 
					}
					if (achou == false) {
						cout << "\nVoo não existe!" << endl;
					}				
				}				     
			}
		}
		if (opcao == 2) {
			int escolha = 0;
			while (escolha != 4) {
				cout << vooAtual.getIdentificacao() << endl;
				cout << "\nComprar passagem(1)\nCancelar passagem(2)\nImprimir passagem(3)\nVoltar(4)\n\nO que deseja? " << endl;			
				cin >> escolha;
				if (escolha == 1) {						
					string lugar1;
					string lugar2;
					cout << "\nDigite o local de origem:" << endl;
					cin >> lugar1;
					cout << "\nDigite o local de destino:" << endl;
					cin >> lugar2;
					cout << "\nVoos disponíveis:\n" << endl;
					
					bool achado = false;
					for (int i = 0; i < quantidadeVoos; i++){
						if (voos[i].getPartida() == lugar1 && voos[i].getChegar() == lugar2 && voos[i].getCancelado() == "Não") {
							achado = true;
							cout << "Linha aérea: " + voos[i].getLinha() + " - " + voos[i].getIdentificacao() << endl;
							cout << "\nOrigem: " + voos[i].getPartida() << endl;
							cout << "\nDestino: " + voos[i].getChegar() << endl;
							cout << "\nData: " + voos[i].getData() << endl;
							cout << "\nHorário: " + voos[i].getHorario() << endl;
							cout << "\nClasses: \n" + voos[i].getClasses() << endl;
							cout << "Assentos: \n" + voos[i].getAssentos() << endl;
						}
					}
					if (achado == false) {
						cout << "\nVoo não encontrado!\n" << endl;
						cout << "\nComprar passagem(1)\nCancelar passagem(2)\nImprimir passagem(3)\nVoltar(4)\n\nO que deseja? " << endl;			
				        cin >> escolha;
					} else {	
						int valor = 0;      
						while (valor != 2) {
							bool achou = false;
							cout << "Comprar(1)\nVoltar(2)\nO que deseja?" << endl;
							cin >> valor;
							if (valor == 1) {
								cout << "\nDigite o identificador do voo:" << endl;           
								string identificador;
								cin >> identificador;
								for (int i = 0; i < quantidadeVoos; i++){
									if (voos[i].getIdentificacao() == identificador) {										
										achou = true;
										vooAtual = voos[i];
										break;
									}	
								}
								if (achou == true) {
									bool disponivel = true; 
									cout << "\nDigite seu nome:" << endl;
									string nome;
									cin >> nome;
									passagem.defineNome(nome);
									cout << "\nDigite sua classe:" << endl;
									string classe;
									cin >> classe;
									cout << "\nDigite o assento:" << endl;
									string assento;
									cin >> assento;
									if (vooAtual.getAssentoDisponivel(assento) == false) {
										disponivel = false;
									} 									
									if (disponivel == true) {
									    passagem.defineAssento(assento);
										passagem.defineClasse(classe);
										passagem.defineDataIda(vooAtual.getData());
										passagem.defineDestino(vooAtual.getChegar());
										passagem.defineIdentificacao(identificadorPassagem);
										passagem.defineOrigem(vooAtual.getPartida());
										passagem.defineHorario(vooAtual.getHorario());
										passagem.defineLinha(vooAtual.getLinha());
										passagem.defineIdentificadorVoo(vooAtual.getIdentificacao());
										passagem.definePortao(letra);
										passagens.push_back(passagem);
										vooAtual.setAssentoOcupado(assento);
										quantidadePassagens += 1;
										identificadorPassagem += 1;		
										cout << "\nA identificação da sua passagem é:" << endl;
										cout << identificadorPassagem - 1 << endl;
										cout << "\nPassagem comprada com sucesso!\n" << endl;	
										vooAtual.ocupados();										
									       
								    } else {
										cout << "\nAssento indisponível!\n" << endl;
											  
									}
								} else {
									cout << "\nVoo não existe!\n" << endl;
								} 
							}								            
						}	    
					}
				}	
				if (escolha == 2) {					
					cout << "\nDigite a identificação da sua passagem:" << endl;
					int ID;
					cin >> ID;
					bool achou = false;
					Passagem passagem1;		    
					for (int i = 0; i < quantidadePassagens; i++) {				
						if (passagens[i].getIdentificacao() == ID) {
							passagem1 = passagens[i];
							achou = true;
						}
					}	
					if (achou == true) {	
						if (passagem1.getEstado() == "Cancelada") {
							cout << "\nPassagem já foi cancelada!" << endl;
						} else {									
							passagem1.setEstado(true);
							cout << "\nA taxa de cancelamento é de R$" << setprecision(4) << (passagem1.getPreco() * taxa) << endl;
							taxa += 0.2;
							cout << "\nPassagem cancelada com sucesso!";														
						}									
					} else {					
						cout << "\nPassagem não encontrada." << endl;
					}			
				}	
				if (escolha == 3) {
					Passagem passagemAtual;
					cout << "\nDigite a identificação da sua passagem:" << endl;
					int ID;
					cin >> ID;
					bool encontrou = false;		    
					for (int i = 0; i < quantidadePassagens; i++) {				
						if (passagens[i].getIdentificacao() == ID) {
							encontrou = true;
							passagemAtual = passagens[i];
						}				
					}
					if (encontrou == true) {
						cout << "\nNome: " + passagemAtual.getNome() << endl;
						cout << "Origem: " + passagemAtual.getOrigem() << endl;
						cout << "Destino: " + passagemAtual.getDestino() << endl;
						cout << "Data: " + passagemAtual.getDataIda() << endl;
						cout << "Horário: " + passagemAtual.getHora() << endl;
						cout << "Portão: " + passagemAtual.getPortao() << endl;
						cout << "Classe: " + passagemAtual.getClasse() << endl;
						cout << "Assento: " + passagemAtual.getAssento() << endl;
						cout << "Linha Aérea: " + passagemAtual.getLinha() << endl;
						cout << "Identificador do voo: " + passagemAtual.getVoo() << endl;
						cout << "Estado: " + passagemAtual.getEstado() << endl;
						cout << "Preço: R$" << setprecision(4) << passagemAtual.getPreco() + pagar << endl;	
					} else {
						cout << "\nPassagem não encontrada." << endl;
					}					
				}												
			}
		}
	}		
    return 0;
}
