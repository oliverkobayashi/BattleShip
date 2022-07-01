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

// Coloque TRUE para diferenciar os tabuleiros, mas isso gera um grande gargalo no carregamento.

unsigned int geracaoRandomicaPesada = TRUE;

char* bombardearTabuleiro(Coordenadas_t *_tabuleiro, unsigned int _coordenadaX, unsigned int _coordenadaY){
	_tabuleiro[_coordenadaY * ORDEM_MATRIZ_TABULEIRO + _coordenadaX].visivel = TRUE;
	return _tabuleiro[_coordenadaY * ORDEM_MATRIZ_TABULEIRO + _coordenadaX].conteudo;
}

void criarBarcaca(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] + 3 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 3) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){

			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, _identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, _identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, _identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 3) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, _identificadorEmbarcacao);
			criado = TRUE;
		}
	}
}

void criarCouracado(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] - 2 >= 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] - 1 >= 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] + 1 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] + 1 <= 15 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){

			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1 ) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			criado = TRUE;
		}
	}
}

void criarEmbarcacaoDeDesembarque(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] - 1 >= 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){

			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, _identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, _identificadorEmbarcacao);			
			criado = TRUE;
		}
	}
}

void criarHidroAviao(Coordenadas_t *_tabuleiro, char _identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, 	 _identificadorEmbarcacao);
			criado = TRUE;
		}
	}
}

void criarPortaAvioes(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] - 2 >= 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] - 1 >= 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] + 2 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] + 2 <= 15 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 2].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] - 1 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] + 2 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){
			
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 2].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 2) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			criado = TRUE;
		}
	}
}

void criarTorpedeiro(Coordenadas_t *_tabuleiro, char __identificadorEmbarcacao[2], int _parOrdenadoAleatorioDeCoordenada[2]){
	unsigned int criado = FALSE;
	while(criado != TRUE){
		gerarParOrdenadoAleatorio(&_parOrdenadoAleatorioDeCoordenada[0]);
		if(strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] - 2>= 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] - 1 >= 0 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[0] + 1 <= 15 &&
			strcmp(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0 &&
			_parOrdenadoAleatorioDeCoordenada[1] + 1 <= 15 &&
			strcmp(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) == 0){

			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 2].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] - 1].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] - 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[(_parOrdenadoAleatorioDeCoordenada[0] + 1) * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1]].conteudo, __identificadorEmbarcacao);
			strcpy(_tabuleiro[_parOrdenadoAleatorioDeCoordenada[0] * ORDEM_MATRIZ_TABULEIRO  + _parOrdenadoAleatorioDeCoordenada[1] + 1].conteudo, __identificadorEmbarcacao);
			criado = TRUE;
		}
	}
}

void gerarParOrdenadoAleatorio(int *_parOrdenadoAleatorioDeCoordenada){
	if(geracaoRandomicaPesada)
		srand((unsigned) time(NULL));
	_parOrdenadoAleatorioDeCoordenada[0] = (int) (((float) ORDEM_MATRIZ_TABULEIRO) * (rand() / (RAND_MAX + 1.0)));
	_parOrdenadoAleatorioDeCoordenada[1] = (int) (((float) ORDEM_MATRIZ_TABULEIRO) * (rand() / (RAND_MAX + 1.0)));
}

char* pegarSubstring(char *_stringTokenizada, unsigned int _quantidadeDeParametros, unsigned int _numeroParametro, char *_caractere){
	for (unsigned int i = 0; i < _quantidadeDeParametros + 1; ++i){
		if(i == _numeroParametro)
			return _stringTokenizada;
        _stringTokenizada += strlen(_stringTokenizada) + 1;
        _stringTokenizada += strspn(_stringTokenizada, _caractere);
    }
}

void pontuarJogador(Coordenadas_t *_tabuleiro, char *_conteudoAlvo, float *_pontuacaoJogador){
	if(strcmp(_conteudoAlvo, "42") != 0){
		unsigned int quantidadeDePecasAtingidas = quantidadeDePecasAtingidasDaEmbarcacao(_tabuleiro, _conteudoAlvo);
		if(_conteudoAlvo[0] == PECA_PORTA_AVIOES_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_PORTA_AVIAO_TOTAL * (QUANTIDADE_PECAS_PORTA_AVIAO_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
		else if(_conteudoAlvo[0] == PECA_COURACADO_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_COURACADO_TOTAL * (QUANTIDADE_PECAS_COURACADO_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
		else if(_conteudoAlvo[0] == PECA_TORPEDO_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_TORPEDO_TOTAL * (QUANTIDADE_PECAS_TORPEDO_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
		else if(_conteudoAlvo[0] == PECA_HIDRO_AVIAO_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_HIDRO_AVIAO_TOTAL * (QUANTIDADE_PECAS_HIDRO_AVIAO_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
		else if(_conteudoAlvo[0] == PECA_EMBARCACAO_DE_DESEMBARQUE_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_EMBARCACAO_DE_DESEMBARQUE_TOTAL * (QUANTIDADE_PECAS_EMBARCACAO_DE_DESEMBARQUE_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
		else if(_conteudoAlvo[0] == PECA_BARCACA_1[0])
			*_pontuacaoJogador += (QUANTIDADE_PECAS_BARCACA_TOTAL * (QUANTIDADE_PECAS_BARCACA_TOTAL - quantidadeDePecasAtingidas)) / pow(ORDEM_MATRIZ_TABULEIRO, 2);
	}else
		*_pontuacaoJogador -= 0.3 * (1 - (QUANTIDADE_EMBARCACOES_TOTAL / pow(ORDEM_MATRIZ_TABULEIRO, 2)));
}

void popularArmadaNoTabuleiro(Coordenadas_t *_tabuleiro){
	int parOrdenadoAleatorioDeCoordenada[2];
	if(!geracaoRandomicaPesada)
		srand((unsigned) time(NULL));
	criarPortaAvioes(_tabuleiro, PECA_PORTA_AVIOES_1, parOrdenadoAleatorioDeCoordenada);
	criarPortaAvioes(_tabuleiro, PECA_PORTA_AVIOES_2, parOrdenadoAleatorioDeCoordenada);
	criarCouracado(_tabuleiro, PECA_COURACADO_1, parOrdenadoAleatorioDeCoordenada);
	criarCouracado(_tabuleiro, PECA_COURACADO_2, parOrdenadoAleatorioDeCoordenada);
	criarCouracado(_tabuleiro, PECA_COURACADO_3, parOrdenadoAleatorioDeCoordenada);
	criarTorpedeiro(_tabuleiro, PECA_TORPEDO_1, parOrdenadoAleatorioDeCoordenada);
	criarTorpedeiro(_tabuleiro, PECA_TORPEDO_2, parOrdenadoAleatorioDeCoordenada);
	criarTorpedeiro(_tabuleiro, PECA_TORPEDO_3, parOrdenadoAleatorioDeCoordenada);
	criarHidroAviao(_tabuleiro, PECA_HIDRO_AVIAO_1, parOrdenadoAleatorioDeCoordenada);
	criarHidroAviao(_tabuleiro, PECA_HIDRO_AVIAO_2, parOrdenadoAleatorioDeCoordenada);
	criarHidroAviao(_tabuleiro, PECA_HIDRO_AVIAO_3, parOrdenadoAleatorioDeCoordenada);
	criarHidroAviao(_tabuleiro, PECA_HIDRO_AVIAO_4, parOrdenadoAleatorioDeCoordenada);
	criarHidroAviao(_tabuleiro, PECA_HIDRO_AVIAO_5, parOrdenadoAleatorioDeCoordenada);
	criarEmbarcacaoDeDesembarque(_tabuleiro, PECA_EMBARCACAO_DE_DESEMBARQUE_1, parOrdenadoAleatorioDeCoordenada);
	criarEmbarcacaoDeDesembarque(_tabuleiro, PECA_EMBARCACAO_DE_DESEMBARQUE_2, parOrdenadoAleatorioDeCoordenada);
	criarEmbarcacaoDeDesembarque(_tabuleiro, PECA_EMBARCACAO_DE_DESEMBARQUE_3, parOrdenadoAleatorioDeCoordenada);
	criarEmbarcacaoDeDesembarque(_tabuleiro, PECA_EMBARCACAO_DE_DESEMBARQUE_4, parOrdenadoAleatorioDeCoordenada);
	criarBarcaca(_tabuleiro, PECA_BARCACA_1, parOrdenadoAleatorioDeCoordenada);
	criarBarcaca(_tabuleiro, PECA_BARCACA_2, parOrdenadoAleatorioDeCoordenada);
	criarBarcaca(_tabuleiro, PECA_BARCACA_3, parOrdenadoAleatorioDeCoordenada);
}

unsigned int quantidadeSubstringsComPointeiroIncluso(char *_parteStringComando, unsigned int *_quantidadeParametros, char *_caractere){
	*_quantidadeParametros = 0;
	for(_parteStringComando = strtok(NULL, _caractere); _parteStringComando != NULL; _parteStringComando = strtok(NULL, _caractere))
		*_quantidadeParametros += 1;
	return *_quantidadeParametros;
}

unsigned int quantidadeDePecasAtingidasDaEmbarcacao(Coordenadas_t *_tabuleiro, char *_conteudoAlvo){
	int qtd = 0;
	for(unsigned int i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
		for(unsigned int j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
			if(_tabuleiro[i * ORDEM_MATRIZ_TABULEIRO + j].visivel == TRUE && strcmp(_tabuleiro[i * ORDEM_MATRIZ_TABULEIRO + j].conteudo , _conteudoAlvo) == 0)
				qtd++;
		}
	}
	return qtd;
}

void reiniciarTabuleiro(Coordenadas_t *_tabuleiro){
	for(unsigned int i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
		for(unsigned int j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
			strcpy(_tabuleiro[i * ORDEM_MATRIZ_TABULEIRO + j].conteudo , ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING);
			_tabuleiro[i * ORDEM_MATRIZ_TABULEIRO + j].visivel = FALSE;
		}
	}
}

unsigned int verificarCoordenadaNaoBombardeada(Coordenadas_t *_tabuleiro, unsigned int _coordenadaX, unsigned int _coordenadaY){
	return !_tabuleiro[_coordenadaY * ORDEM_MATRIZ_TABULEIRO + _coordenadaX].visivel;
}

void verificarVitoria(Coordenadas_t *_tabuleiroEUA, Coordenadas_t *_tabuleiroURSS, int *_vitoria){
	unsigned int i, j;
	*_vitoria = VITORIA_EUA;
	for(i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
		for(j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
			if(strcmp(_tabuleiroURSS[i * ORDEM_MATRIZ_TABULEIRO + j].conteudo , ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) != 0 && _tabuleiroURSS[i * ORDEM_MATRIZ_TABULEIRO + j].visivel == FALSE)
				*_vitoria = NENHUMA_VITORIA;
		}
	}
	if(*_vitoria == NENHUMA_VITORIA){
		*_vitoria = VITORIA_URSS;
		for(i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
			for(j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
				if(strcmp(_tabuleiroEUA[i * ORDEM_MATRIZ_TABULEIRO + j].conteudo , ASCII_CARACTERE_SIMBOLO_DA_AGUA_STRING) != 0 && _tabuleiroEUA[i * ORDEM_MATRIZ_TABULEIRO + j].visivel == FALSE)
					*_vitoria = NENHUMA_VITORIA;
			}
		}
	}
}
