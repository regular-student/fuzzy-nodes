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

void imprimir_lista(struct Node* inicio) {
	struct Node* atual = inicio;

	while (atual != NULL) {
		printf("Valor do nó:\t%i\n", atual->valor);
		atual = atual->proximo;
	}
}

int main() {
	struct Node* inicio = NULL;

	inserir_no_inicio(&inicio, 21);
	inserir_no_inicio(&inicio, 11);
	inserir_no_inicio(&inicio, 99);
	inserir_no_inicio(&inicio, 59);

	imprimir_lista(inicio);
	
}
