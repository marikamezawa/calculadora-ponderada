

# Calculadora RPN 

## Descrição da Implementação
&emsp; O projeto consiste em uma calculadora que utiliza a notação polonesa reversa (RPN), implementada na linguagem C.

&emsp; O funcionamento do algoritmo se baseia em uma estrutura de pilha, que armazena os números temporariamente enquanto as operações são realizadas.

## Lógica de Funcionamento

1. **Leitura da expressão:**

   * O usuário digita a expressão RPN no formato de texto (por exemplo: `3 4 +`).
   * A entrada é lida usando `fgets()`.

2. **Tokenização:**

   * A expressão é dividida em partes (tokens) separadas por espaço usando a função `strtok()`.
   * Cada token pode ser um número ou um operador matemático (`+`, `-`, `*`, `/`).

3. **Processamento dos tokens:**

   * Se o token for um número, ele é convertido para `double` e empilhado (função `push()`).
   * Se for um operador, dois números são retirados da pilha (função `pop()`), a operação é realizada (função `calcular()`) e o resultado é empilhado novamente.

4. **Validação:**

   * O programa verifica se, ao final, há exatamente um valor na pilha (que será o resultado final da expressão).
   * Também são tratados erros como **divisão por zero**, **expressão mal formada** ou **token inválido**.

5. **Exibição do resultado:**

   * O resultado final é mostrado ao usuário com duas casas decimais.

## Principais Funções

* **inicializaPilha():** Inicia a pilha vazia.
* **push() e pop():** Adicionam e removem elementos da pilha.
* **ehNumero() e ehOperador():** Fazem a validação dos tokens.
* **calcular():** Executa a operação matemática.
* **avaliarRPN():** Faz todo o processamento da expressão.


## Como rodar

**1. Salve o código em um arquivo chamado:
calculadora.c**

**2. Abra o terminal e navegue até a pasta onde o arquivo está salvo.**

**3. Compile o código usando o GCC:**

``` bash
gcc calculadora.c -o calculadora
```

**4. Execute o programa:**

``` bash
./calculadora
```

**5. Após executar, o programa pedirá a expressão**      



