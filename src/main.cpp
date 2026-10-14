#include <Arduino.h>
// #include <string.h> //* strlen, strcpy, strcat, strcmp, strchr
// #include <stdlib.h> //* atoi

void setup()
{
  Serial.begin(9600);
  Serial.println();
}

void loop()
{
}

void textoTipoC()
{
  //* Texto literal
  //* Use const char* quando o texto não será alterado
  const char *cidade = "São Paulo";
  const char outraCidade[] = "São Caetano";
  Serial.println(cidade);
  Serial.println(outraCidade);

  //* descobrindo o tamanho do texto
  //* strlen conta quantos caracteres antes do '/0'

  int tamanhoTextoCidade = strlen(cidade);
  int tamanhoOutraCidade = strlen(outraCidade);

  Serial.print("Comprimento do texto em caracteres: ");
  Serial.println(tamanhoTextoCidade);

  Serial.print("Comprimento do conteudo do ponteiro: ");
  Serial.println(tamanhoOutraCidade);

  //* descobrindo o tamanho ocupado

  int tamanhoVariavel = sizeof(outraCidade);
  int tamanhoPonteiro = sizeof(cidade);

  //* Quando usando o sizeof em uma string sempre retornará
  //* um byte a mais do que a quantidade de caracteres por
  //* causa do '/0' que finaliza o texto
  Serial.println("Tamanho da variavel em bytes = ");
  Serial.println(tamanhoVariavel);

  //* Quando usamos o sizeof em ponteiros retorna sempre 4 bytes
  //* pois o conteúdo dele é um endereço de memória como 0xFF00C245
  Serial.println("Tamanho do ponteiro: = ");
  Serial.println(tamanhoPonteiro);

  //* o caractere '/0' é colocado automaticamente quando escrevemos
  //* um texto entre aspas duplas " "
  const char vetorTexto[7] = {'T', 'h', 'i', 'a', 'g', 'o'};
  Serial.println(vetorTexto);

  //* Comparar texto
  const char *cidade1 = "Porto Alegre";
  const char *cidade2 = "Porto Alegre";

  if (strcmp(cidade1, cidade2) == 0)
    Serial.print("as strings são iguais");
  else
    Serial.print("as strings são diferentes");

  //* strcmp analisa a ordem léxica das palavras, se a primeira palavra vem antes
  //* que a segunda o valor retornado será menor que zero, se a primeira vem após
  //* a segunda o retorno será maior que zero

  //*=======================
  //* Texto editavel com char()
  //*=========================

  char nomeAluno[7] = "Thiagp";
  Serial.println(nomeAluno);

  nomeAluno[5] = 'o';
  Serial.println(nomeAluno);

  //* Copiando outro texto para dentro do vetor
  //! CUIDADO: O vetor precisa ter espaço suficiente

  strcpy(nomeAluno, "Tadeu");
  Serial.println(nomeAluno);

  //* Concatenando texto ao final
  char frase[40] = "Ola ";
  strcat(frase, "Mundo Cruel!");
  Serial.println(frase);

  //* Procurando um caractere no texto
  char *posicaoLetra = strchr(frase, 'M');

  if (posicaoLetra != NULL)
  {
    Serial.println("Letra encontrada");
    Serial.println(posicaoLetra);
  }

  else
    Serial.println("Letra não encontrada");

  //* Convertendo texto númerico para inteiro
  char idadeTexto[] = "39"; //* [0x33, 0x57, 0x00]
  int idade = atoi(idadeTexto);

  //* Montando texto
  char buffer[100];
  char *local = "Sala de Aula";
  float temperatura = 26.4;
  int umidade = 72;

  snprintf(buffer, sizeof(buffer), "%s | Temp: %f C | Umid: %d %% \n\r", local, temperatura, umidade);
  Serial.print(buffer);

  //* snprintf monta texto dentro de um vetor de char
  //* isso é muito útil quando depois que você quer
  //* - enviar por MQTT
  //* - salvar em variavel
  //* - mandar para o display
  //* - imprimir na serial
  //*
  //* ESPECIFICADORES
  //*
  //* %d ou %i    -int
  //* %u          -unsigned int
  //* %ld         -long
  //* %lu         -unsigned long
  //* %f          -float
  //* %e          -notação cientifica
  //* %g          -float, formato mais curto
  //* %c          -char
  //* %s          -char*
  //* %x ou %X    -hexadecimal, minusculo e maiusculo
  //* %o          -octal
  //* %p          -ponteiro
  //* %%          -o própio %
  //*
  //* Flags, largura e precisão
  //*
  //* %5d         -imprime com largura máxima de 5, alinhado a direita   [     3] [   100] [100000]
  //* %-2d        -imprime com largura minima de 2, alinhado a esquerda
  //* %04d        -completa com zeros, ex: 0022
  //* %+d         -sempre mostra o sinal, ex: +5
  //* %.2f        -2 casas decimais
  //* %4.2f       -largura de 4 com 2 casas
  //* %02X        -hexadecimal com 2 digitos
  //* %#x         -prefixo x
  //* %.3s        -só os primeiros 3 caracteres da string
  //* %*d         -largura passada como argumento, ex: snprintf(buffer, sizeof(buffer)), "%*d", 5, 42) [   42]
}

void textoTipoString()
{
  String nome = "Luy";
  String curso = "Lógica de Programação";
  String mensagem = "OLa";

  mensagem = mensagem + "," + nome + "! Bem vindo ao curso de " + curso + ".";
  Serial.println(mensagem);

  //* Tamanho da String
  int tamanhoMensagem = mensagem.length();
  Serial.printf("Tamanho da String em letras : %u\n\r", tamanhoMensagem);

  //* Acessando caractere em uma posição especifica
  char primeiraLetra = mensagem.charAt(0);
  Serial.printf("primeira letra: %c/n/r", primeiraLetra);

  //* Tambem é possivel acessar com colchetes
  char ultimaLetra = mensagem[tamanhoMensagem];
  Serial.printf("ultima letra: %c\n\r", ultimaLetra);

  //* Procurando um texto dentro da string
  int posicaoTextoProcurado = mensagem.indexOf("curso");
  Serial.printf("A palavra procurada está na posição %d\n\r", posicaoTextoProcurado);

  int inicioNomeDoCurso = posicaoTextoProcurado + 9; //* posição da palavra curso + 9 posições a frente

  String nomeDoCursoTexto = mensagem.substring(inicioNomeDoCurso, tamanhoMensagem - 1);
  Serial.printf("Nome do curso: %s\n\r", nomeDoCursoTexto.c_str()); 

  //* Substituindo um trecho dentro da string
  mensagem.replace("Ola,", "Boa tarde! ");
  Serial.println(mensagem);

  //* Convertendo tudo em maiusculas
  mensagem.toUpperCase();
  Serial.println(mensagem);

  char letraMinuscula = mensagem[0] + 32;
  Serial.println(letraMinuscula);

  //* Convertendo tudo em minusculas
  mensagem.toLowerCase();
  Serial.println(mensagem);

  //* Verificando se uma string está vazia
  String textoVazio = "";
  if(textoVazio.length() == 0);
  Serial.println("O texto está vazio");

  //* Convertendo texto numerico para inteiro
  String textoNumero = "725";
  int numero = textoNumero.toInt();
  Serial.println(numero / 5);

  //* Convertendo String para const char* (texto tipo c)
  //* Isso é util quando alguma biblioteca espera texto tipo c
  const char*  textoComoChar = mensagem.c_str();
  Serial.println(textoComoChar);
}
