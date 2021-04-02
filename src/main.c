#include <stdio.h>
#include <stdlib.h>

#include "task.h"
#define maxTask 6

void printScreen() {
    printf("#  #   ####     #     #    ####     ####    #     #\n");
    printf("# #    #  #     ##    #    #   #    #  #    ##    #\n");
    printf("##     #  #     # #   #    #  #     #  #    # #   #\n");
    printf("#      ####     #  #  #    ###      ####    #  #  #\n");
    printf("##     #  #     #   # #    #  #     #  #    #   # #\n");
    printf("# #    #  #     #    ##    #   #    #  #    #    ##\n");
    printf("#  #   #  #     #     #    ####     #  #    #     #\n");
    printf("\n");
    printf("1)Visualizar dados.\n");
    printf("2)Inserir Dados.\n");
    printf("3)Quit.\n");
    int op, op2, prioridade, dataCriacao;
    char pessoa;
    scanf("%d", &op);
     TAREFA *head = NULL;
    
    switch (op)
    {
    case 1:
        printf("1)Visualizar o quadro das tarefas.\n");
        printf("2)Visualizar as tarefas de uma pessoa.\n");
        printf("3)Visualizar todas as tarefas ordenadas por data de criação.\n");
        scanf("%d", &op2);
        switch(op2){
            case 1:
             printList(head);
                break;
            case 2:
            printf("Introduza o nome da pessoa:\n");
            scanf("%hhd", &pessoa);
                break;
            case 3:
                break;
            default:
                printf("Opção inválida!\n");
                 break;
                
        }
        
        break;
    case 2:
        printf("Nova tarefa.\n");
        int i=1;
        while(i<=maxTask){
        printf("Introduza a prioridade:");
        scanf("%d", &prioridade);
        while(!(prioridade>0 && prioridade<=10)){
            printf("Valor inválido! Introduza um valor entre 1 e 10\n");
            scanf("%d", &prioridade);
        }
        printf("Introduza a data de criaçao:");
      
         scanf("%d", &dataCriacao);

        newTask(&head, 0, prioridade, dataCriacao);
           i++;
        }
        printList(head);
       
        break;
    case 3:
        printf("Bye!\n");
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}


int main() {

   // TAREFA *head = NULL;
    printScreen();
   // newTask(&head,0);
   // newTask(&head,0);
  // newTask(&head,0);
    //printList(&head);
}
