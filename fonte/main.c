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

/* Declara o cabeçalho geral. */

#include "cabecalhos/cabecalhogeral.h"

/* Declara os cabeçalhos locais. */

#include "cabecalhos/ferramentas.h"
#include "cabecalhos/visual.h"

/* Variáveis globais. */

Coordenadas_t tabuleiroEUA[ORDEM_MATRIZ_TABULEIRO][ORDEM_MATRIZ_TABULEIRO], tabuleiroURSS[ORDEM_MATRIZ_TABULEIRO][ORDEM_MATRIZ_TABULEIRO];
float pontuacaoEUA, pontuacaoURSS;
time_t tempoBruto;
char horarioFormatado[TAMANHO_HORARIO];
unsigned char nomeComandanteEUA[TAMANHO_NOME_CAPITAO], nomeComandanteURSS[TAMANHO_NOME_CAPITAO];
unsigned int jogoEmCurso = FALSE, programaEmFuncionamento = TRUE, qtdJogadas, turnoJogador, vitoria, acaso;

/* Função principal. */

int main(){
  char entradaTeclado[TAMANHO_ENTRADA], *parteStringComando;
  unsigned int quantidadeParametros, i, j;
  struct tm *infoTempo;
  pontuacaoEUA = pontuacaoURSS = 0;
  imprimirEntrada();
  while(programaEmFuncionamento){
    printf("Digite somente uma ação a ser executada (Até " STRINGIFY(TAMANHO_ENTRADA) " caracteres):");
    if(scanf("%" STRINGIFY(TAMANHO_ENTRADA) "[^\n]s", entradaTeclado) == VAZIO){
      printf("A ação deve ser preenchida.\n");
      limparStdin();
      continue;
    }
    limparStdin();
    parteStringComando = strtok(entradaTeclado, " ");
    if(strcmp(parteStringComando, COMANDO_ACASO) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO){
        if(jogoEmCurso){
          qtdJogadas = 0;
          acaso = TRUE;
          reiniciarTabuleiro(tabuleiroEUA[0]);
          reiniciarTabuleiro(tabuleiroURSS[0]);
          imprimirCarregando();
          popularArmadaNoTabuleiro(tabuleiroEUA[0]);
          popularArmadaNoTabuleiro(tabuleiroURSS[0]);
          teclaContinuar();
          imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
        }else
          printf("Não há jogo em curso. Para usar esse comando iniciei uma partida.\n");
      }else
        imprimirErroParametro(COMANDO_ACASO, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_AJUDA) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO)
        ajuda();
      else
        imprimirErroParametro(COMANDO_AJUDA, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_CARREGAR) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == UM_PARAMETRO){
        char *primeiroParametro = pegarSubstring(entradaTeclado, quantidadeParametros, 1, " ");
        FILE *arquivo = fopen(primeiroParametro, "r");
        if(arquivo == NULL)
          printf("Não foi possível abrir o arquivo.\n");
        else{
          unsigned int contador = 1;
          char buffer[COMPRIMENTO_BUFFER];
          while(fgets(buffer, COMPRIMENTO_BUFFER, arquivo)) {
            buffer[strlen(buffer) - 1] = '\0';
            if(contador == 1)
              strcpy(horarioFormatado, buffer);
            else if(contador == 2)
              turnoJogador = atoi(buffer);
            else if(contador == 3)
              qtdJogadas = atoi(buffer);
            else if(contador >= 4 && contador <= 19){
              unsigned int quantidadeSubstrings, contadorSubstring = 0;
              char *valoresCoordenadasString = strtok(buffer, "|");
              if(quantidadeSubstringsComPointeiroIncluso(valoresCoordenadasString, &quantidadeSubstrings, "|") == ORDEM_MATRIZ_TABULEIRO - 1){
                tabuleiroEUA[contador - 4][contadorSubstring].visivel = valoresCoordenadasString[0] - '0';
                tabuleiroEUA[contador - 4][contadorSubstring].conteudo[0] = valoresCoordenadasString[1];
                tabuleiroEUA[contador - 4][contadorSubstring].conteudo[1] = valoresCoordenadasString[2];
                contadorSubstring++;
                for(; contadorSubstring < ORDEM_MATRIZ_TABULEIRO; contadorSubstring++){
                  char *substring = pegarSubstring(buffer, quantidadeSubstrings, contadorSubstring, "|");
                  tabuleiroEUA[contador - 4][contadorSubstring].visivel = substring[0] - '0';
                  tabuleiroEUA[contador - 4][contadorSubstring].conteudo[0] = substring[1];
                  tabuleiroEUA[contador - 4][contadorSubstring].conteudo[1] = substring[2];
                }
              }
            }else if(contador >= 20 && contador <= 35){
              unsigned int quantidadeSubstrings, contadorSubstring = 0;
              char *valoresCoordenadasString = strtok(buffer, "|");
              if(quantidadeSubstringsComPointeiroIncluso(valoresCoordenadasString, &quantidadeSubstrings, "|") == ORDEM_MATRIZ_TABULEIRO - 1){
                tabuleiroURSS[contador - 20][contadorSubstring].visivel = valoresCoordenadasString[0] - '0';
                tabuleiroURSS[contador - 20][contadorSubstring].conteudo[0] = valoresCoordenadasString[1];
                tabuleiroURSS[contador - 20][contadorSubstring].conteudo[1] = valoresCoordenadasString[2];
                contadorSubstring++;
                for(; contadorSubstring < ORDEM_MATRIZ_TABULEIRO; contadorSubstring++){
                  char *substring = pegarSubstring(buffer, quantidadeSubstrings, contadorSubstring, "|");
                  tabuleiroURSS[contador - 20][contadorSubstring].visivel = substring[0] - '0';
                  tabuleiroURSS[contador - 20][contadorSubstring].conteudo[0] = substring[1];
                  tabuleiroURSS[contador - 20][contadorSubstring].conteudo[1] = substring[2];
                }
              }
            }else if(contador == 36)
              acaso = atoi(buffer);
            else if(contador == 37)
              strcpy(nomeComandanteEUA, buffer);
            else if(contador == 38)
              strcpy(nomeComandanteURSS, buffer);
            else if(contador == 39)
              pontuacaoEUA = atof(buffer);
            else if(contador == 40)
              pontuacaoURSS = atof(buffer);
            contador++;
          }
          fclose(arquivo);
          printf("O arquivo foi carregado com sucesso.\n");
          jogoEmCurso = TRUE;
        }
      }else
        imprimirErroParametro(COMANDO_CARREGAR, UM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_GRAVAR) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO){
        char nomeDoArquivo[TAMANHO_MAXIMO_NOME_DO_ARQUIVO];
        sprintf(nomeDoArquivo, "Tabuleiro-%d.txt", (int)time(NULL));
        FILE *arquivo = fopen(nomeDoArquivo, "w");
        if(arquivo == NULL)
          printf("Não foi possível abrir o arquivo.\n");
        else{
          fprintf(arquivo, "%s\n", horarioFormatado);
          fprintf(arquivo, "%d\n", turnoJogador);
          fprintf(arquivo, "%d\n", qtdJogadas);
          for(i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
            for(j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
              if(tabuleiroEUA[i][j].visivel)
                fputc(ASCII_CARACTERE_UM, arquivo);
              else
                fputc(ASCII_CARACTERE_ZERO, arquivo);
              fprintf(arquivo, "%s", tabuleiroEUA[i][j].conteudo);
              if(j != ORDEM_MATRIZ_TABULEIRO - 1)
                fputc(ASCII_CARACTERE_DELIMITADOR_CELULA, arquivo);
              else
                fputc('\n', arquivo);
            }
          }
          for(i = 0; i < ORDEM_MATRIZ_TABULEIRO; i++){
            for(j = 0; j < ORDEM_MATRIZ_TABULEIRO; j++){
              if(tabuleiroURSS[i][j].visivel)
                fputc(ASCII_CARACTERE_UM, arquivo);
              else
                fputc(ASCII_CARACTERE_ZERO, arquivo);
              fprintf(arquivo, "%s", tabuleiroURSS[i][j].conteudo);
              if(j != ORDEM_MATRIZ_TABULEIRO - 1)
                fputc(ASCII_CARACTERE_DELIMITADOR_CELULA, arquivo);
              else
                fputc('\n', arquivo);
            }
          }
        }
        fprintf(arquivo, "%d\n", acaso);
        fprintf(arquivo, "%s\n", nomeComandanteEUA);
        fprintf(arquivo, "%s\n", nomeComandanteURSS);
        fprintf(arquivo, "%f\n", pontuacaoEUA);
        fprintf(arquivo, "%f\n", pontuacaoURSS);
        fclose(arquivo);
        printf("O arquivo foi gravado com sucesso.\n");
      }else
        imprimirErroParametro(COMANDO_GRAVAR, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_LIMPAR) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO)
        limparTela();
      else
        imprimirErroParametro(COMANDO_LIMPAR, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_POW) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == UM_PARAMETRO){
        if(jogoEmCurso){
          char *primeiroParametro = pegarSubstring(entradaTeclado, quantidadeParametros, 1, " ");
          if(strlen(primeiroParametro) == 2){
            if(primeiroParametro[0] >= ASCII_CARACTERE_A_MAIUSCULO && primeiroParametro[0] <= ASCII_CARACTERE_P_MAIUSCILO && primeiroParametro[1] >= ASCII_CARACTERE_UM && primeiroParametro[1] <= ASCII_CARACTERE_NOVE){
              int x = (int) (primeiroParametro[0] - ASCII_CARACTERE_A_MAIUSCULO);
              int y = (int) (primeiroParametro[1] - ASCII_CARACTERE_UM);
                if(turnoJogador == TURNO_EUA){
                  if(verificarCoordenadaNaoBombardeada(tabuleiroURSS[0], x, y)){
                    pontuarJogador(tabuleiroURSS[0], bombardearTabuleiro(tabuleiroURSS[0], x, y), &pontuacaoEUA);
                    turnoJogador = TURNO_URSS;
                    qtdJogadas++;
                    verificarVitoria(tabuleiroEUA[0], tabuleiroURSS[0], &vitoria);
                    imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
                  }else
                    printf("Essa coordenada já foi bombardeada.\n");
                }else{
                  if(verificarCoordenadaNaoBombardeada(tabuleiroEUA[0], x, y)){
                    pontuarJogador(tabuleiroEUA[0], bombardearTabuleiro(tabuleiroEUA[0], x, y), &pontuacaoURSS);
                    turnoJogador = TURNO_EUA;
                    qtdJogadas++;
                    verificarVitoria(tabuleiroEUA[0], tabuleiroURSS[0], &vitoria);
                    imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
                  }else
                    printf("Essa coordenada já foi bombardeada.\n");
                }
            }else
              printf("Coordenada malformada, fora do intervalo ou incorreta.\n");
          }else if(strlen(primeiroParametro) == 3){
            if(primeiroParametro[0] >= ASCII_CARACTERE_A_MAIUSCULO && primeiroParametro[0] <= ASCII_CARACTERE_P_MAIUSCILO && primeiroParametro[1] == ASCII_CARACTERE_UM && primeiroParametro[2] >= ASCII_CARACTERE_ZERO && primeiroParametro[2] <= ASCII_CARACTERE_SEIS){
              int x = (int) (primeiroParametro[0] - 'A');
              char yString[2] = {primeiroParametro[1], primeiroParametro[2]};
              int y = atoi(yString) - 1;
              if(turnoJogador == TURNO_EUA){
                if(verificarCoordenadaNaoBombardeada(tabuleiroURSS[0], x, y)){
                  pontuarJogador(tabuleiroURSS[0], bombardearTabuleiro(tabuleiroURSS[0], x, y), &pontuacaoEUA);
                  turnoJogador = TURNO_URSS;
                  qtdJogadas++;
                  verificarVitoria(tabuleiroEUA[0], tabuleiroURSS[0], &vitoria);
                  imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
                }else
                  printf("Essa coordenada já foi bombardeada.\n");
              }else{
                if(verificarCoordenadaNaoBombardeada(tabuleiroEUA[0], x, y)){
                  pontuarJogador(tabuleiroEUA[0], bombardearTabuleiro(tabuleiroEUA[0], x, y), &pontuacaoURSS);
                  turnoJogador = TURNO_EUA;
                  qtdJogadas++;
                  verificarVitoria(tabuleiroEUA[0], tabuleiroURSS[0], &vitoria);
                  imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
                }else
                  printf("Essa coordenada já foi bombardeada.\n");
              }
            }else
              printf("Coordenada malformada, fora do intervalo ou incorreta.\n");
          }else
            printf("A coordenada deve conter de dois à três caracteres.\n");
        }else if(vitoria != 0)
          printf("A partida já foi encerada.\n");
        else
          printf("Não há jogo em curso. Para usar esse comando iniciei uma partida.\n");
      }else
        imprimirErroParametro(COMANDO_POW, UM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_RESET) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO){
        time (&tempoBruto);
        infoTempo = localtime(&tempoBruto);
        strftime(horarioFormatado, TAMANHO_HORARIO, "%H:%M:%S - %d/%m/%Y.", infoTempo);
        jogoEmCurso = TRUE;
        pontuacaoEUA = pontuacaoURSS = qtdJogadas = 0;
        acaso = FALSE;
        turnoJogador = TURNO_EUA;
        nomeComandanteEUA[0] = nomeComandanteURSS[0] = '\0'; 
        printf("------------------------------Iniciar partida------------------------------------------------------\n");
        do{
          printf("Digite o nome do comandante americano (Até " STRINGIFY(TAMANHO_NOME_CAPITAO) " caracteres):");
          scanf("%" STRINGIFY(TAMANHO_NOME_CAPITAO) "[^\n]s", nomeComandanteEUA);
          if(nomeComandanteEUA[0] == '\0')
            printf("O nome do comandante americano deve ser preenchido.\n");
          limparStdin();
        }while(nomeComandanteEUA[0] == '\0');
        do{
          printf("Digite o nome do comandante soviético (Até " STRINGIFY(TAMANHO_NOME_CAPITAO) " caracteres):");
          scanf("%" STRINGIFY(TAMANHO_NOME_CAPITAO) "[^\n]s", nomeComandanteURSS);
          if(nomeComandanteURSS[0] == '\0')
            printf("O nome do comandante soviético deve ser preenchido.\n");
          limparStdin();
        }while(nomeComandanteURSS[0] == '\0');
        imprimirDialogoPartida(nomeComandanteEUA, nomeComandanteURSS);
        reiniciarTabuleiro(tabuleiroEUA[0]);
        reiniciarTabuleiro(tabuleiroURSS[0]);
        imprimirCarregando();
        popularArmadaNoTabuleiro(tabuleiroEUA[0]);
        popularArmadaNoTabuleiro(tabuleiroURSS[0]);
        teclaContinuar();
        imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
      }else
        imprimirErroParametro(COMANDO_RESET, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_SAIR) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO){
        printf("Saindo...\n");
        programaEmFuncionamento = FALSE;
      }else
        imprimirErroParametro(COMANDO_SAIR, SEM_PARAMETRO);
    }else if(strcmp(parteStringComando, COMANDO_VISUALIZAR) == 0){
      if(quantidadeSubstringsComPointeiroIncluso(parteStringComando, &quantidadeParametros, " ") == SEM_PARAMETRO){
        if(jogoEmCurso)
          imprimirPartida(tabuleiroEUA[0], tabuleiroURSS[0], horarioFormatado, qtdJogadas, turnoJogador, nomeComandanteEUA, nomeComandanteURSS, pontuacaoEUA, pontuacaoURSS, vitoria, acaso);
        else
          printf("Não existe uma partida em andamento.\n");
      }else
        imprimirErroParametro(COMANDO_VISUALIZAR, SEM_PARAMETRO);
    }
    else
      imprimirErroComandoInexistente(parteStringComando);
    }
  return EXIT_SUCCESS;
}
