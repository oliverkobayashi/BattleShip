/*
==========================================================================================================================================
Name: BattleShip.
Description: O famoso jogo de barquinhos e explosões agora na linguagem favorita de qualquer estudante de Engenharia, a linguagem C.
Fique à vontade para editá-lo, modificá-lo e distribuí-lo, uma vez que, os códigos fontes desse projeto são LIVRES.
Data: 26/06/2022.
Version: 1.0.
Authors (Copyleft): Daniel Alquete e Oliver Kobayashi.
==========================================================================================================================================
*/

/* Declara os cabeçalhos padrões do C que serão usados. */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

/* Define as macros de todo o projeto. */

/** Macros: Booleanas e relacionadas. **/

#define FALSE 															0
#define TRUE  															1
#define NENHUMA_VITORIA													0
#define VITORIA_EUA														1
#define SEM_PARAMETRO               									0
#define UM_PARAMETRO                									1
#define SEM_QUEBRA_DE_LINHA 											0
#define COM_QUEBRA_DE_LINHA 											1
#define TURNO_EUA														0
#define TURNO_URSS														1
#define VAZIO															0
#define VITORIA_URSS													2

/** Macros: Informações referente ao processo de desenvolvimento. **/

#define CRIADOR_1 														"Daniel Alquete"
#define CRIADOR_2 														"Oliver Kobayashi"
#define VERSAO 															1.0

/** Macros: Cores no Select Graphic Rendition subset (SGR). **/

#define ASCII_COR_AMARELO     											"\033[1;33m"
#define ASCII_COR_AZUL     												"\033[1;34m"
#define ASCII_COR_CINZA     											"\033[1;90m"
#define ASCII_COR_PADRAO												"\033[0;0m"
#define ASCII_COR_VERMELHO												"\033[1;31m" 

/** Macros: Comandos do jogo. **/

#define COMANDO_ACASO               									"acaso"
#define COMANDO_AJUDA               									"ajuda"
#define COMANDO_CARREGAR            									"carregar"
#define COMANDO_GRAVAR              									"gravar"
#define COMANDO_LIMPAR													"limpar"
#define COMANDO_POW                 									"pow"
#define COMANDO_RESET               									"reset"
#define COMANDO_SAIR                									"sair"
#define COMANDO_VISUALIZAR												"visualizar"

/** Macros: Descrição dos comandos do jogo. **/

#define DESC_ACASO               										"Inicia novos tabuleiros aleatórios, preservando a pontuação dos jogadores, o tempo da partida e os dados remanescentes.\n"
#define DESC_AJUDA               										"Imprime os comandos disponíveis do jogo e informações sobre eles.\n"
#define DESC_CARREGAR            										"Carrega uma partida localizada em um arquivo de texto.\n"
#define DESC_GRAVAR              										"Grava a atual partida em um arquivo de texto no padrão Tabuleiro-{timestamp}.txt.\n"
#define DESC_LIMPAR														"Limpa a tela.\n"
#define DESC_POW                 										"Dispara a artilharia na coordenada informada p.Sendo p ∈ C = {(x, y)/ x ∈ [A, P] ^ y ∈ [1, 16] ∈ N}.\n"
#define DESC_RESET               										"Inicia uma nova partida.\n"
#define DESC_SAIR                										"Sai da partida e consequentemente do jogo.\n"
#define DESC_VISUALIZAR													"Visualiza a partida em andamento.\n"

/** Macros: Tamanho de Vetores. **/

#define ORDEM_MATRIZ_TABULEIRO                							16
#define TAMANHO_ENTRADA             									40
#define TAMANHO_HORARIO													23
#define TAMANHO_MAXIMO_NOME_DO_ARQUIVO									31
#define TAMANHO_NOME_CAPITAO        									30
#define TAMANHO_NOME_ARQUIVO											31

/** Macros: Caracteres codificados na tabela ASCII e relacionados **/

#define ASCII_CARACTERE_A_MAIUSCULO										65
#define ASCII_CARACTERE_P_MAIUSCILO										80
#define ASCII_CARACTERE_ARROBA											64
#define ASCII_CARACTERE_DELIMITADOR_CELULA								124
#define ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING							STRINGIFY(42)
#define ASCII_CARACTERE_ZERO											48
#define ASCII_CARACTERE_UM												49
#define ASCII_CARACTERE_SEIS											54
#define ASCII_CARACTERE_NOVE											57

/** Macros: Qualidades quantitativas referentes às peças. **/ 

#define QUANTIDADE_PECAS_BARCACA_TOTAL         							9
#define QUANTIDADE_PECAS_COURACADO_TOTAL								24
#define QUANTIDADE_PECAS_EMBARCACAO_DE_DESEMBARQUE_TOTAL			 	8
#define QUANTIDADE_PECAS_HIDRO_AVIAO_TOTAL								5
#define QUANTIDADE_PECAS_PORTA_AVIAO_TOTAL	 							22
#define QUANTIDADE_PECAS_TORPEDO_TOTAL 									18
#define QUANTIDADE_EMBARCACOES_TOTAL 									20

/** Macros: Qualidades qualitativas referentes às peças. **/ 

#define PECA_BARCACA_1													"B1"
#define PECA_BARCACA_2													"B2"
#define PECA_BARCACA_3													"B3"
#define PECA_COURACADO_1												"C1"
#define PECA_COURACADO_2												"C2"
#define PECA_COURACADO_3												"C3"
#define PECA_EMBARCACAO_DE_DESEMBARQUE_1								"E1"
#define PECA_EMBARCACAO_DE_DESEMBARQUE_2								"E2"
#define PECA_EMBARCACAO_DE_DESEMBARQUE_3								"E3"
#define PECA_EMBARCACAO_DE_DESEMBARQUE_4								"E4"
#define PECA_HIDRO_AVIAO_1												"H1"
#define PECA_HIDRO_AVIAO_2												"H2"
#define PECA_HIDRO_AVIAO_3												"H3"
#define PECA_HIDRO_AVIAO_4												"H4"
#define PECA_HIDRO_AVIAO_5												"H5"
#define PECA_PORTA_AVIOES_1												"A1"
#define PECA_PORTA_AVIOES_2												"A2"
#define PECA_TORPEDO_1													"T1"
#define PECA_TORPEDO_2													"T2"
#define PECA_TORPEDO_3													"T3"

/** Macros: Outras. **/

#define COMPRIMENTO_BUFFER												255
#define STRINGIFY(x)                									STRINGIFY2(x)
#define STRINGIFY2(x)               									#x
#define TOTAL_DE_POSICOES												pow(ORDEM_MATRIZ, 2)

/* Estruras. */

typedef struct{
	unsigned char conteudo[2];
	unsigned int visivel;
}Coordenadas_t;

/* Assinaturas dos procedimentos. */

void ajuda(void);																															// Exibe os comandos disponíveis.
void criarBarcaca(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);					// Cria uma peça do tipo barcaça no tabuleiro escolhido.
void criarCouracado(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);				// Cria uma peça do tipo couraçado no tabuleiro escolhido.
void criarEmbarcacaoDeDesembarque(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);	// Cria uma peça do tipo embarcação de desembarque no tabuleiro escolhido.
void criarHidroAviao(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);				// Cria uma peça do tipo hidro avião no tabuleiro escolhido.
void criarPortaAvioes(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);				// Cria uma peça do tipo porta aviões no tabuleio escolhido.
void criarTorpedeiro(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]);				// Cria uma peça do tipo torpedeiro no tabuleiro escolhido.
void gerarParOrdenadoAleatorio(int *_parOrdenadoAleatorioDeCoordenada);																		// Gera um par de coordenadas aleatório.
void imprimirCadeiaCaractere(char _caractere, unsigned int _qtd, char *_cor, int quebraDeLinha);											// Imprime uma cadeia de tamanho definido do caractere especificado.
void imprimirCarregando(void);																												// Imprime o carregamento do jogo.
void imprimirDialogoPartida(char* _nomeComandanteEUA, char* _nomeComandanteURSS);															// Exibe a contextualização da batalha.
void imprimirEntrada(void);																													// Exibe a entrada do jogo.
void imprimirErroComandoInexistente(char *_comando);																						// Imprime o erro de comando inexistente.
void imprimirErroParametro(char *_comando, int _qtdParametro);																				// Imprime o erro referente à quantidade de parametros.
void imprimirPartida(Coordenadas_t *_tabuleiroEUA, Coordenadas_t *_tabuleiroURSS, char _horarioFormatado[TAMANHO_HORARIO], unsigned int _qtdJogadas, unsigned int _turnoJogador, unsigned char _nomeComandanteEUA[TAMANHO_NOME_CAPITAO], unsigned char _nomeComandanteURSS[TAMANHO_NOME_CAPITAO], float _pontuacaoEUA, float _pontuacaoURSS, unsigned int _vitoria, unsigned int _acaso); //Imprime a atual situação da partida.
void limparStdin(void);																														// Limpa a stdin.
void limparTela(void);																														// Limpa a tela do jogador.
void pontuarJogador(Coordenadas_t *_tabuleiro, char *_conteudoAlvo, float *_pontuacaoJogador);												// Pontua um jogodar específico, sendo a pontuação diferenciada pelo conteúdo da coordenada.
void popularArmadaNoTabuleiro(Coordenadas_t *_tabuleiro);																					// Adiciona ao tabuleiro escolhido a armada predefinida com posições aleatórias.
void reiniciarTabuleiro(Coordenadas_t *_tabuleiro);																							// Limpa a armada do tabuleiro e esconde todas as peças.
void teclaContinuar(void);																													// Espera o usuário apertar uma tecla.
void verificarVitoria(Coordenadas_t *_tabuleiroEUA, Coordenadas_t *_tabuleiroURSS, int *_vitoria);											// Verifica se existe um vencedor.

/* Assinaturas das funções. */

char* bombardearTabuleiro(Coordenadas_t *_tabuleiro, unsigned int _coordenadaX, unsigned int _coordenadaY);									// Atira sobre a peça escolhida.
char* pegarSubstring(char *_stringTokenizada, unsigned int _quantidadeDeParametros, unsigned int _numeroParametro, char *_caractere);		// Captura determinado parametro da ação.
unsigned int quantidadeDePecasAtingidasDaEmbarcacao(Coordenadas_t *_tabuleiro, char *_conteudoAlvo);										// Contabiliza a quantidade de peças derrubadas de um determinada embarcação.
unsigned int quantidadeSubstringsComPointeiroIncluso(char *_parteStringComando, unsigned int *_quantidadeParametros, char *_caractere);		// Contabiliza a quantidade de paramentros da ação.
unsigned int verificarCoordenadaNaoBombardeada(Coordenadas_t *_tabuleiro, unsigned int _coordenadaX, unsigned int _coordenadaY);			// Verifica se a coordenada não foi bombardeada anteriormente.
