#include <stdio.h>
#include <stdlib.h>

#define MAX_TAREFAS 100

typedef struct {
    char descricao[100];
    int concluida;
} Tarefa;

void adicionarTarefa(Tarefa lista[], int *numTarefas) {
    if (*numTarefas < MAX_TAREFAS) {
        printf("Digite a descrição da tarefa: ");
        scanf(" %[^\n]", lista[*numTarefas].descricao);
        lista[*numTarefas].concluida = 0; // Tarefa inicialmente não concluída
        (*numTarefas)++;
        printf("Tarefa adicionada com sucesso!\n");
    } else {
        printf("Limite máximo de tarefas atingido!\n");
    }
}

void exibirTarefas(Tarefa lista[], int numTarefas) {
    if (numTarefas > 0) {
        printf("\nLista de Tarefas:\n");
        for (int i = 0; i < numTarefas; i++) {
            printf("%d. %s [%s]\n", i + 1, lista[i].descricao, lista[i].concluida ? "Concluída" : "Pendente");
        }
    } else {
        printf("Nenhuma tarefa cadastrada!\n");
    }
}

void marcarConcluida(Tarefa lista[], int numTarefas) {
    int indice;
    printf("Digite o número da tarefa concluída: ");
    scanf("%d", &indice);

    if (indice >= 1 && indice <= numTarefas) {
        lista[indice - 1].concluida = 1;
        printf("Tarefa marcada como concluída!\n");
    } else {
        printf("Tarefa não encontrada!\n");
    }
}

int main() {
    Tarefa listaTarefas[MAX_TAREFAS];
    int numTarefas = 0;
    int opcao;

    printf("Programa de Lista de Tarefas\n");
    printf("---------------------------\n");

    while (1) {
        printf("\nSelecione a opção:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Exibir Tarefas\n");
        printf("3. Marcar Tarefa como Concluída\n");
        printf("4. Sair\n");

        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarTarefa(listaTarefas, &numTarefas);
                break;
            case 2:
                exibirTarefas(listaTarefas, numTarefas);
                break;
            case 3:
                marcarConcluida(listaTarefas, numTarefas);
                break;
            case 4:
                printf("Encerrando o programa...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
