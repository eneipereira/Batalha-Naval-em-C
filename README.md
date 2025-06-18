# Batalha-Naval-em-C

Repositório do trabalho 4 da disciplina **Introdução à Programação de Computadores**, do curso de **Engenharia de Software** da **UNESA (Universidade Estácio de Sá)**.

---

## Descrição

Este projeto tem como objetivo desenvolver, em linguagem **C**, uma versão simplificada do jogo **Batalha Naval**, dividido em três níveis de complexidade. O foco está na construção progressiva de funcionalidades que envolvem o uso de **vetores**, **matrizes**, **estruturas de repetição** e **condicionais**, além da simulação de habilidades especiais com áreas de efeito.

---

## Níveis do Projeto

- **Nível Novato (Implementado)**  
  Criação de um tabuleiro 10x10 utilizando matrizes, com posicionamento de dois navios de tamanho 3: um na horizontal e outro na vertical. Exibição no console com visualização clara do tabuleiro.

- **Nível Aventureiro (Implementado)**  
  Posicionamento de quatro navios no total: dois na horizontal/vertical e dois na diagonal. Garantia de que não haja sobreposição e que todos estejam dentro dos limites do tabuleiro.

- **Nível Mestre (Implementado)**  
  Implementação de habilidades especiais com áreas de efeito: Cone, Cruz e Octaedro. Sobreposição dinâmica das áreas de habilidade no tabuleiro com visualização diferenciada (água, navio, área afetada).

---

## Como compilar

Para compilar o programa, certifique-se de ter o compilador `gcc` instalado e rode o seguinte comando no terminal:

```bash
gcc batalha_naval.c -o batalha_naval
```

---

## Como executar

Após compilar, execute o programa com:

```bash
./batalha_naval
```

O programa exibirá o tabuleiro com os navios posicionados e as áreas de efeito das habilidades especiais.

---

## Estrutura do projeto

- `batalha_naval.c`: Código-fonte do programa em C.

- `.gitignore`: Arquivo para ignorar arquivos compilados e temporários.

- `README.md`: Documento com a descrição do projeto, instruções de uso e informações complementares.

- `LICENSE`: Arquivo contendo a licença de uso do projeto (MIT License).

## Autor

Enei - Curso de Engenharia de Software - UNESA

## Licença

Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.