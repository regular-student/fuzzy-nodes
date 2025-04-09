#include <stdio.h>
#include <stdlib.h>

struct Node {
	int valor;
	struct Node* proximo;
};

void imprimir_lista(struct Node* inicio) {
	struct Node* atual = inicio;

	while (atual != NULL) {
		printf("Valor: %i\n", atual->valor);
		atual = atual->proximo;
	}
}

int main() {
	struct Node* primeiro = (struct Node*)malloc(sizeof(struct Node));
	struct Node* segundo = (struct Node*)malloc(sizeof(struct Node));

	primeiro->valor = 42;
	segundo->valor = 13;
	primeiro->proximo = segundo;
	segundo->proximo = NULL;

	// printf("Valor do nó: %i\n", primeiro->valor);
	// printf("Valor do nó proximo: %i\n", primeiro->proximo->valor);

	imprimir_lista(primeiro);
	
	free(segundo);
	free(primeiro);

	return 0;
	
}
