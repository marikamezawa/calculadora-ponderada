#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    double items[MAX_STACK_SIZE];
    int top;
} Pilha;

void inicializaPilha(Pilha* pilha) {
    pilha->top = -1;
}

int estaVazia(Pilha* pilha) {
    return pilha->top == -1;
}

void push(Pilha* pilha, double valor) {
    if (pilha->top >= MAX_STACK_SIZE - 1) {
        printf("Erro: Pilha cheia\n");
        exit(1);
    }
    pilha->items[++pilha->top] = valor;
}

double pop(Pilha* pilha) {
    if (estaVazia(pilha)) {
        printf("Erro: Pilha vazia\n");
        exit(1);
    }
    return pilha->items[pilha->top--];
}

int ehOperador(char* token) {
    return strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

int ehNumero(char* token) {
    char* endptr;
    strtod(token, &endptr);
    return *endptr == '\0';
}

double calcular(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Erro: Divisao por zero\n");
                exit(1);
            }
            return a / b;
        default: 
            printf("Erro: Operador invalido\n");
            exit(1);
    }
}

double avaliarRPN(char* expressao) {
    Pilha pilha;
    inicializaPilha(&pilha);
    
    char* token = strtok(expressao, " ");
    
    while (token != NULL) {
        if (ehNumero(token)) {
            push(&pilha, atof(token));
        } else if (ehOperador(token)) {
            double b = pop(&pilha);
            double a = pop(&pilha);
            double resultado = calcular(a, b, token[0]);
            push(&pilha, resultado);
        } else {
            printf("Erro: Token invalido\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    
    if (pilha.top != 0) {
        printf("Erro: Expressao mal formada\n");
        exit(1);
    }
    
    return pilha.items[0];
}

int main() {
    char expressao[1000];
    
    printf("Calculadora RPN\n");
    printf("Digite uma expressao (ex: 3 4 +): ");
    
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = 0;
    
    double resultado = avaliarRPN(expressao);
    printf("Resultado: %.2f\n", resultado);
    
    return 0;
}