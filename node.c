#include <stdio.h>
#include <stdlib.h>

struct Node {
	int valor;
	struct Node* proximo;
};

void inserir_no_inicio(struct Node** inicio, int novo_valor) {
	struct Node* novo = (struct Node*)malloc(sizeof(struct Node));
	novo->valor = novo_valor;
	novo->proximo = *inicio;
	*inicio = novo;
}

void inserir_no_final(struct Node** inicio, int novo_valor) {
	struct Node* novo = (struct Node*)malloc(sizeof(struct Node));

	novo->valor = novo_valor;
	novo->proximo = NULL;
	
	if (*inicio == NULL) { *inicio = novo; }
	else { 
		struct Node* atual = *inicio; 
		while (atual->proximo != NULL) {
			atual = atual->proximo;
		}
		atual->proximo = novo;
	}
	
} 

void remover_valor(struct Node** inicio, int valor_remover) {
	if (*inicio == NULL) return; 

	struct Node* anterior = NULL;
	struct Node* atual = *inicio; 

	while(atual->proximo != NULL && atual->valor != valor_remover) {
		anterior = atual;
		atual = atual->proximo;
	}

	if (atual == NULL) return;

	if (anterior == NULL) { *inicio = atual->proximo; }
	else { anterior->proximo = atual-> proximo; }

	free(atual);
}



void imprimir_lista(struct Node* inicio) {
	struct Node* atual = inicio;

	while (atual != NULL) { 
		printf("val do nó %i\n", atual->valor);
		atual = atual->proximo;
	}
}

void metade(struct Node* inicio) {
	struct Node* rapido = inicio;

	while (rapido != NULL) {
		printf("Node lento: %i\nNode rapido: %i\n", inicio->valor, rapido->valor);
		rapido = rapido->proximo->proximo;
		inicio = inicio->proximo;
	}

	printf("\n\nMetade do nó\t%i\n\n", inicio->valor);
}

int main() {
	struct Node* inicio = NULL;

	inserir_no_inicio(&inicio, 42);
	inserir_no_inicio(&inicio, 882);
	inserir_no_inicio(&inicio, 754);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 633);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 676);
	inserir_no_inicio(&inicio, 999999);
	inserir_no_inicio(&inicio, 456);
	inserir_no_inicio(&inicio, 123);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 62);
	inserir_no_inicio(&inicio, 12);
	inserir_no_inicio(&inicio, 22);
	inserir_no_inicio(&inicio, 11);
	inserir_no_inicio(&inicio, 332);
	inserir_no_inicio(&inicio, 42);
	inserir_no_inicio(&inicio, 421);
	metade(inicio);

	imprimir_lista(inicio);

	printf("Print depois dos nós serem removidos\n");
	
	remover_valor(&inicio, 633);
	remover_valor(&inicio, 332);
	remover_valor(&inicio, 421);
	remover_valor(&inicio, 999999);
	
	imprimir_lista(inicio);
}
