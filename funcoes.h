#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct nodePaciente_struct NodePaciente;
typedef struct queue_paciente_struct ListaPaciente;
typedef struct paciente_struct Paciente;
typedef struct fila_exame_struct FilaExame;
typedef struct node_exame NodeExame;
typedef struct maquina_strucut Maquina;

void verificaMaquinaLivre(Maquina *maquinas, FilaExame* fila, int instante);
void ExameAppend(Paciente *p, FilaExame *fila);
void imprimirMaquinas(Maquina *maquinas);
void imprimirPaciente(ListaPaciente *l);
void imprimirExames(FilaExame *fila);
Paciente *CreatePaciente(int tempo);
ListaPaciente *llCreate_Paciente();
FilaExame *llCreate_FilaExame();
Maquina *criarArrayMaquinas();
void PacienteAppend(Paciente *p, ListaPaciente *l);

#endif