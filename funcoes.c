#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct paciente_struct {
  int id;
  char nome[50];
  int tempoEntrada;
  int tempoLaudo;
  int estado;
};

struct nodePaciente_struct {
  Paciente *info;
  NodePaciente *next;
};

struct queue_paciente_struct {
  NodePaciente *first;
  NodePaciente *rear;
};

struct node_exame {
  int id;
  NodeExame *next;
};

struct fila_exame_struct {
  NodeExame *first;
  NodeExame *rear;
};

struct maquina_strucut {
  int id;    // id paciente
  int tempo; // tempo em que será concluido
};

Paciente *CreatePaciente(int tempo) {
  srand(tempo);
  char *nomes[5] = {"Joao", "pedsro", "Francisco", "Julia", "Alberto"};

  Paciente *p = (Paciente *)malloc(sizeof(Paciente));
  strcpy(p->nome, nomes[rand() % 5]);
  p->id = tempo;
  p->tempoEntrada = tempo;
  p->tempoLaudo = NULL;
  p->estado = NULL;

  return p;
}

ListaPaciente *llCreate_Paciente() {
  ListaPaciente *lista = (ListaPaciente *)malloc(sizeof(ListaPaciente));
  lista->first = NULL;
  lista->rear = NULL;

  return lista;
}

FilaExame *llCreate_FilaExame() {
  FilaExame *fila = (FilaExame *)malloc(sizeof(FilaExame));
  fila->first = NULL;
  fila->rear = NULL;

  return fila;
}

Maquina *criarArrayMaquinas() {
  Maquina *maquinas = (Maquina *)malloc(5 * sizeof(Maquina));

  for (int i = 0; i < 5; ++i) {
    maquinas[i].id = 0;
    maquinas[i].tempo = 0;
  }

  return maquinas;
}

void imprimirPaciente(ListaPaciente *l) {
  NodePaciente *n = (NodePaciente *)malloc(sizeof(NodePaciente));
  for (n = l->first; n != NULL; n = n->next) {
    printf("ID: %d\n", n->info->id);
    printf("Nome: %s\n", n->info->nome);
    printf("Tempo de Entrada: %d\n", n->info->tempoEntrada);
    printf("Tempo de Laudo: %d\n", n->info->tempoLaudo);
    printf("Estado: %d\n", n->info->estado);
  }
}

void imprimirExames(FilaExame *fila) {
  NodeExame *n;
  for (n = fila->first; n != NULL; n = n->next) {
    printf("ID Exame: %d\n", n->id);
  }
}

void imprimirMaquinas(Maquina *maquinas) {
  if (maquinas != NULL) {
    printf("Array de Maquinas:\n");
    for (int i = 0; i < 5; ++i) {
      printf("Maquina %d - ID: %d, Tempo: %d\n", i + 1, maquinas[i].id,
             maquinas[i].tempo);
    }
  }
}

void PacienteAppend(Paciente *p, ListaPaciente *lista) {
  NodePaciente *n = (NodePaciente *)malloc(sizeof(NodePaciente));
  n->info = p;
  n->next = NULL;

  if (lista->first == NULL) {
    lista->first = n;
  } else {
    lista->rear->next = n;
  }
  lista->rear = n;
}

void ExameAppend(Paciente *p, FilaExame *fila) {
  NodeExame *n = (NodeExame *)malloc(sizeof(NodeExame));
  n->id = p->id;
  n->next = NULL;

  if (fila->first == NULL) {
    fila->first = n;
  } else {
    fila->rear->next = n;
  }
  fila->rear = n;
}

int exameEnqueue(FilaExame *fila) {
  int id = NULL;
  if (fila->first != NULL) {
    NodeExame *n = fila->first;
    id = n->id;
    fila->first = n->next;
    free(n);
  }
  return id;
}

void verificaMaquinaLivre(Maquina *maquinas, FilaExame *fila, int instante) {
  for (int i = 0; i < 5; ++i) {
    if (maquinas[i].tempo <= instante) {
      int idExaminado = maquinas[i].id;
      maquinas[i].id = exameEnqueue(fila);
      maquinas[i].tempo = instante + rand() % 6 + 5;
      if(maquinas[i].id == NULL){ maquinas[i].tempo = 0;}
      //adicionar idExamiinado na fila de laudo
    }
  }
}
