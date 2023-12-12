#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main() {
  srand(time(NULL));
  int tempo;

  // listas
  ListaPaciente *listaPacientes = llCreate_Paciente();
  FilaExame *filaExames = llCreate_FilaExame();
  Maquina *maquinas = criarArrayMaquinas();

  // loop tempo
  for (tempo = 0; tempo < 50; tempo++) {
    if (rand() % 100 < 20) { // chance de paciente chegar
      Paciente *pc1 = CreatePaciente(tempo);
      PacienteAppend(pc1, listaPacientes);
      ExameAppend(pc1, filaExames); // insere na fila de exames
    }

    verificaMaquinaLivre(maquinas, filaExames, tempo);
    imprimirMaquinas(maquinas);
  }

  imprimirMaquinas(maquinas);
  //  imprimirPaciente(listaPacientes);
  //  imprimirExames(filaExames);
  return 0;
}