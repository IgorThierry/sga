// SGA = Sistema de Gerenciamento de Alunos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct
{
  char nome[MAX_NAME_LENGTH];
  int matricula;
  int idade;
  char genero;
  float mediaNotas;
} Aluno;

Aluno alunos[MAX_STUDENTS];
int quantidadeAlunos = 0;

void cadastrarAluno()
{
  if (quantidadeAlunos >= MAX_STUDENTS)
  {
    printf("Limite de alunos atingido.\n");
    return;
  }

  printf("Cadastrar Aluno:\n");

  printf("Nome: ");
  scanf(" %[^\n]s", alunos[quantidadeAlunos].nome);

  printf("Matrícula: ");
  scanf("%d", &alunos[quantidadeAlunos].matricula);

  printf("Idade: ");
  scanf("%d", &alunos[quantidadeAlunos].idade);

  printf("Gênero: ");
  scanf(" %c", &alunos[quantidadeAlunos].genero);

  printf("Média das notas: ");
  scanf("%f", &alunos[quantidadeAlunos].mediaNotas);

  quantidadeAlunos++;

  printf("Aluno cadastrado com sucesso.\n");
}

void listarAlunos()
{
  if (quantidadeAlunos == 0)
  {
    printf("Nenhum aluno cadastrado.\n");
    return;
  }

  printf("Lista de Alunos:\n");
  for (int i = 0; i < quantidadeAlunos; i++)
  {
    printf("Aluno %d:\n", i + 1);
    printf("Nome: %s\n", alunos[i].nome);
    printf("Matrícula: %d\n", alunos[i].matricula);
    printf("Idade: %d\n", alunos[i].idade);
    printf("Gênero: %c\n", alunos[i].genero);
    printf("Média das notas: %.2f\n", alunos[i].mediaNotas);
    printf("-----------------------\n");
  }
}

float calcularMediaGeral()
{
  float somaNotas = 0;
  for (int i = 0; i < quantidadeAlunos; i++)
  {
    somaNotas += alunos[i].mediaNotas;
  }

  return somaNotas / quantidadeAlunos;
}

void pesquisarAluno()
{
  int matricula;
  printf("Digite a matrícula do aluno: ");
  scanf("%d", &matricula);

  for (int i = 0; i < quantidadeAlunos; i++)
  {
    if (alunos[i].matricula == matricula)
    {
      printf("Aluno encontrado:\n");
      printf("Nome: %s\n", alunos[i].nome);
      printf("Matrícula: %d\n", alunos[i].matricula);
      printf("Idade: %d\n", alunos[i].idade);
      printf("Gênero: %c\n", alunos[i].genero);
      printf("Média das notas: %.2f\n", alunos[i].mediaNotas);
      return;
    }
  }

  printf("Aluno não encontrado.\n");
}

void atualizarAluno()
{
  int matricula;
  printf("Digite a matrícula do aluno que deseja atualizar: ");
  scanf("%d", &matricula);

  for (int i = 0; i < quantidadeAlunos; i++)
  {
    if (alunos[i].matricula == matricula)
    {
      printf("Atualizar dados do aluno:\n");

      printf("Nome: ");
      scanf(" %[^\n]s", alunos[i].nome);

      printf("Idade: ");
      scanf("%d", &alunos[i].idade);

      printf("Gênero: ");
      scanf(" %c", &alunos[i].genero);

      printf("Média das notas: ");
      scanf("%f", &alunos[i].mediaNotas);

      printf("Dados do aluno atualizados com sucesso.\n");
      return;
    }
  }

  printf("Aluno não encontrado.\n");
}

void removerAluno()
{
  int matricula;
  printf("Digite a matrícula do aluno que deseja remover: ");
  scanf("%d", &matricula);

  for (int i = 0; i < quantidadeAlunos; i++)
  {
    if (alunos[i].matricula == matricula)
    {
      // Movendo todos os alunos à frente do aluno removido
      for (int j = i; j < quantidadeAlunos - 1; j++)
      {
        strcpy(alunos[j].nome, alunos[j + 1].nome);
        alunos[j].matricula = alunos[j + 1].matricula;
        alunos[j].idade = alunos[j + 1].idade;
        alunos[j].genero = alunos[j + 1].genero;
        alunos[j].mediaNotas = alunos[j + 1].mediaNotas;
      }

      quantidadeAlunos--;
      printf("Aluno removido com sucesso.\n");
      return;
    }
  }

  printf("Aluno não encontrado.\n");
}

int desenharMenu()
{
  int opcao;

  printf("\n");
  printf("1. Cadastrar aluno\n");
  printf("2. Listar alunos\n");
  printf("3. Calcular média geral\n");
  printf("4. Pesquisar aluno por matrícula\n");
  printf("5. Atualizar dados do aluno\n");
  printf("6. Remover aluno\n");
  printf("0. Sair\n");
  printf("Digite a opção desejada: ");
  scanf("%d", &opcao);

  return opcao;
}

int main()
{
  setlocale(LC_ALL, "Portuguese_Brasil");
  printf("SGA - Sistema de Gerenciamento de Alunos");

  int opcao;

  do
  {
    opcao = desenharMenu();

    switch (opcao)
    {
    case 1:
      cadastrarAluno();
      break;
    case 2:
      listarAlunos();
      break;
    case 3:
    {
      float media = calcularMediaGeral();
      printf("Média geral dos alunos: %.2f\n", media);
      break;
    }
    case 4:
      pesquisarAluno();
      break;
    case 5:
      atualizarAluno();
      break;
    case 6:
      removerAluno();
      break;
    case 0:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}