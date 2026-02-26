Análise Comparativa de Complexidade: O(n²) vs O(n log n)

Objetivo

Este repositório apresenta um estudo comparativo entre dois algoritmos de ordenação implementados em C++, com foco na análise de complexidade assintótica e no impacto prático do crescimento das funções de custo computacional.

Os algoritmos analisados foram:

Varreduras Sucessivas: f(n) ~ (n²) / 2 - crescimento quadrático (~49.995.000 operações).

Junções Sucessivas (Merge Sort): f(n) ≤ n · log₂(n) - crescimento quase linear (~132.800

A análise considera o pior caso, utilizando um vetor de entrada em ordem decrescente.

Para rodar via terminal
1 - g++ -o nome_que_quiser arquivo.cpp
2 - ./nome_que_quiser
