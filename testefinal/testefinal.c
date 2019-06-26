#include <stdio.h>
#include <time.h> // para usar a funcao time
#include <stdlib.h> // para usar a funcao srand
int la, ca; // quantidade de linhas de A, quantidade de colunas de A
int lb, cb; // quantidade de linhas de B, quantidade de colunas de B
int lc, cc; // quantidade de linhas de A, quantidade de colunas de A

void atribuir_random_a(int la, int ca, float a[50][50]) { //OPCAO 3
  int i, j;//inicializa as variaveis de contagem
  srand(time(NULL));//inicializa o gerador de numeros aleatorio
  //vetor pra manipular a matriz
  for (i = 0; i < la; i++) {
    for (j = 0; j < ca; j++) {
      //salva o valor aleatorio de 0 a 100 dentro de uma celula da matiz a
      a[i][j] = rand() % 100;
    }
  }
}

void atribuir_random_b(int lb, int cb, float b[50][50]) { //OPCAO 4
  int i, j;//inicializa as variaveis de contagem
  srand(time(NULL));//inicializa o gerador de numeros aleatorio
  //vetor pra manipular a matriz
  for (i = 0; i < lb; i++) {
    for (j = 0; j < cb; j++) {
      //salva o valor aleatorio de 0 a 100 dentro de uma celula da matiz b
      b[i][j] = rand() % 100;
    }
  }
}
void atribuir_a(int la, int ca, float a[50][50]) { //OPCAO 5
  int i, j;       // Nesta etapa o lanço de repetição varre a matriz A para preenchimento dos termos
  for (i = 0; i < la; i++) {
    for (j = 0; j < ca; j++) {
      //solicita o valor e salva o valor digitado na celula especificada
      printf("\n\nDigite um valor para a linha %d e coluna %d da Matriz A: ", i, j);
      scanf("%f", &a[i][j]);
    }
  }
}
void atribuir_b(int lb, int cb, float b[50][50]) { //OPCAO 6
  int i, j;       // Nesta etapa o lanço de repetição varre a matriz B para preenchimento dos termos
  for (i = 0; i < lb; i++) {
    for (j = 0; j < cb; j++) {
      //solicita o valor e salva o valor digitado na celula especificada
      printf("\n\nDigite um valor para a linha %d e coluna %d da Matriz B: ", i, j);
      scanf("%f", &b[i][j]);
    }
  }
}
void soma(int la, int lb, int ca, int cb, float a[50][50], float b[50][50], float c[50][50]) { //OPCAO 7
  int i, j; // Nesta etapa o lanço de repetição varre a matriz A e B(caso tenha quantidade de linhas e colunas iguais) somando termo a termo.
  if (ca == cb && la == lb)
  {
    //varre as matrizes
    for (i = 0; i < la; i++) {
      for (j = 0; j < ca; j++) {
        //soma os termos
        c[i][j] = a[i][j] + b[i][j];
      }
    }
  }
  //mensagem de erro
  else {
    printf("Essas matrizes NAO podem ser somadas");
  }
  //salva as dimensões da matriz c
  lc = lb;
  cc = cb;

}

void subtracao(int la, int lb, int ca, int cb, float a[50][50], float b[50][50], float c[50][50]) { //OPCAO 8
  int i, j;       // Nesta etapa o lanço de repetição varre a matriz A e B(caso tenha quantidade de linhas e colunas iguais) subtraindo termo a termo.
  if (ca == cb && la == lb)
  {
    //varre as matrizes
    for (i = 0; i < la; i++) {
      for (j = 0; j < ca; j++) {
        //subtrai os termos
        c[i][j] = a[i][j] - b[i][j];
      }
    }
  }
  //mensagem de erro
  else {
    printf("Essas matrizes NAO podem ser somadas");
  }
  //salva as dimensões da matriz c
  lc = lb;
  cc = cb;
}

void mult(int la, int lb, int ca, int cb, float a[50][50], float b[50][50], float c[50][50]) { // OPCAO 9
  int sum, i, j, k;     // Nesta etapa o lanço de repetição varre a matriz A e B(caso tenha quantidade de colunas de A igual a quantidade delinhas de B) multiplicando as matrizes
  if (ca == lb) {
    //varre as matrizes
    for (i = 0; i < la; i++) {
      for (j = 0; j < cb; j++) {
        for (k = 0; k < lb; k++) {
          //multiplica os termos e soma
          sum = sum + a[i][k] * b[k][j];
        }
        //salva o resultado na celula especificada
        c[i][j] = sum;
        sum = 0;
      }
    }
  }
  //mensagem de erro
  else {
    printf("nao pode");

  }
  //salva as dimensões de c
  lc = la;
  cc = cb;
}

void imprimir_a(int la, int ca, float a[50][50]) { //OPCAO 10
  int i, j;        // Nesta etapa o lanço de repetição varre a matriz A e imprime na tela a matriz termo a termo.
  printf("\n");
  //varre a matriz
  for (i = 0; i < la; i++) {
    for (j = 0; j < ca; j++) {
      //imprime o valor
      printf("%3.2f    ", a[i][j] );
    }
    printf("\n");
  }
}
void imprimir_b(int lb, int cb, float b[50][50]) { //OPCAO 11
  int i, j;       // Nesta etapa o lanço de repetição varre a matriz B e imprime na tela a matriz termo a termo.
  printf("\n");
  //varre a matriz
  for (i = 0; i < lb; i++) {
    for (j = 0; j < cb; j++) {
      //imprime o valor
      printf("%3.2f    ", b[i][j] );
    }
    printf("\n");
  }
}
void imprimir_c(int la, int cb, float c[50][50]) { //OPCAO 12
  int i, j;       // Nesta etapa o lanço de repetição varre a matriz C(Matriz resultante) e imprime na tela a matriz termo a termo.
  printf("\n");
  //varre a matriz
  for (i = 0; i < la; i++) {
    for (j = 0; j < cb; j++) {
      //imprime o valor
      printf("%3.2f    ", c[i][j] );
    }
    printf("\n");
  }
}

void extrair_a(int la, int ca, float a[50][50]) { //op13
  // file guardarah as informacoes do arquivo a ser aberto
  FILE *file;
  //nome do arquivo
  file =
    fopen("textoa.txt", "r");
  //variavel pra salvar os valores em forma de strings
  char m[50][50];
  //contadores do vetor
  int nl, nc, i, j;

  fscanf(file, "%d %d", &nl, &nc);
  la = nl;
  ca = nc;
  //varre a matriz
  for (i = 0; i < nc; i++) {
    for (j = 0; j < nl; j++) {
      //salva o valor da matriz num vetor de carazcteres
      fscanf(file, "%d", &m[i][j]);
      //converte em numero
      a[i][j] = m[i][j];
    }
  }

}

void extrair_b(int lb, int cb, float b[50][50]) //op14
{
  // file guardarah as informacoes
  // do arquivo a ser aberto
  FILE *file;
  file = fopen("textob.txt", "r");

  //variavel pra salvar os valores em forma de strings
  char m[50][50];
  //contadores do vetor
  int nl, nc, i, j;

  fscanf(file, "%d %d", &nl, &nc);
  lb = nl;
  cb = nc;
  //varre a matriz
  for (i = 0; i < nc; i++) {
    for (j = 0; j < nl; j++) {
      //salva o valor da matriz num vetor de carazcteres
      fscanf(file, "%d", &m[i][j]);
      //converte em numero
      b[i][j] = m[i][j];
    }
  }

}


void gravar_c(int la, int cb, float c[50][50]) { //op15

  char nc[50];
  char nl[50];
  int i;
  int j;
  char m[50][50];
  // file guardarah as informacoes
  // do arquivo a ser aberto
  FILE *file;
  file = fopen("arquivo.txt", "w");
  printf("%d %d\n", cb, la);
  //imprime o numero de linhas e colunas no arquivo
  fprintf(file, "%d %d\n", cb, la);
  //varre a matriz
  for ( i = 0; i < cb; i++) {
    for ( j = 0; j < la; j++) {
      //imprime a celula no arquivo
      fprintf(file, "%3.2f ", c[j][i]);
    }
    //quebra de linha
    fprintf(file, "\n");
  }
  fclose(file);

}




int main() {

  int la, ca; // quantidade de linhas de A, quantidade de colunas de A
  int lb, cb; // quantidade de linhas de B, quantidade de colunas de B
  int i, j; //Variaveis do loop das matrizes
  int opcao;//variavel da opção selecionada
  float a[50][50], b[50][50], c[50][50]; // Matrizes de trabalho e Matriz resultado
  int op;

  do {
    //imprime o menu na tela
    printf("   \n\nPROGRAMA DE MANIPULACAO DE MATRIZES   \n\n");
    printf("   (1) Definir o tamanho da matriz A   \n");
    printf("   (2) Definir o tamanho da matriz B   \n");
    printf("   (3) Preencher a matriz A com valores aleatorios   \n");
    printf("   (4) Preencher a matriz B com valores aleatorios  \n");
    printf("   (5) Atribuir valores manualmente para os elementos da matriz A  \n");
    printf("   (6) Atribuir valores manualmente para os elementos da matriz B  \n");
    printf("   (7) Calcular A+B  \n");
    printf("   (8) Calcular A-B  \n");
    printf("   (9) Calcular A*B  \n");
    printf("   (10) Imprimir matriz A  \n");
    printf("   (11) Imprimir matriz B  \n");
    printf("   (12) Imprimir matriz C  \n");
    printf("   (13) Ler a matriz A de um arquivo  \n");
    printf("   (14) Ler a matriz B de um arquivo  \n");
    printf("   (15) Escrever a matriz C em um arquivo  \n");
    printf("   (16) Sair  \n");
    printf("\n\n Escolha uma das opcoes: ");
    scanf("%d", &opcao);
    //selecionador
    switch (opcao) {
      //opções de 1 a 16 descritas no menu, cada uma chama uma função excluindo 1 e 2
      case 1:
        printf("\nDigite a quantidade de linhas da Matriz A: ");
        scanf("%d", &la);
        printf("\nDigite a quantidade de colunas da Matriz A: ");
        scanf("%d", &ca);
        break;
      case 2:
        printf("\nDigite a quantidade de linhas da Matriz B: ");
        scanf("%d", &lb);
        printf("\nDigite a quantidade de colunas da Matriz B: ");
        scanf("%d", &cb);
        break;

      case 3:
        atribuir_random_a(la, ca, a);
        break;
      case 4:
        atribuir_random_b(lb, cb, b);
        break;
      case 5:
        atribuir_a(la, ca, a);
        break;
      case 6:
        atribuir_b(lb, cb, b);
        break;

      case 7:
        soma(la, lb, ca, cb, a, b, c);
        break;
      case 8:
        subtracao(la, lb, ca, cb, a, b, c);
        break;
      case 9:
        mult(la, lb, ca, cb, a, b, c);
        break;
      case 10:
        imprimir_a(la, ca, a);
        break;

      case 11:
        imprimir_b(lb, cb, b);
        break;

      case 12:
        imprimir_c(la, cb, c);
        break;
      case 13:
        extrair_a(la, ca, a);
        break;
      case 14:
        extrair_b(lb, cb, b);
        break;
      case 15:
        gravar_c(la, cb, c);
        break;
      case 16:
        printf("\n SAINDO . . . . . . .\n");
        break;

      default: printf("\n\n OPCAO INEXISTENTE!!\n");
    }

  } while (opcao != 16);

  return 0;
}
