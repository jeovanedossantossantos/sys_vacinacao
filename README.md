
# Projeto pratico para a disciplina estrutura de dados. 

- O Centro de Saúde de Paris está entrando na 5ª fase de vacinação contra a COVID-19.
Nessa 5ª fase o primeiro grupo de risco que tomará a vacina são os idosos que vivem em
asilos. O Centro abriu uma vaga para estágio e como tarefa para fase de seleção está
solicitando o desenvolvimento de um programa que contribua para a celeridade e
segurança no processo de vacinação. Loucos por desafios, os alunos de computação da
UFRB se candidataram para a vaga.
- Assim, os candidatos deverão desenvolver um sistema que possibilite o cadastro dos
idosos contendo os seguintes dados:
- Nome, Identificador e Idade
- Após o cadastro, o sistema deverá ordenar os idosos de acordo com a sua idade e mostrar
os dados dos idosos ordenados de forma que o Centro de Saúde possa começar de
imediato a vacinação seguindo a ordem proposta pelo seu programa (olha a
responsabilidade).
- Além disso, o Centro de Saúde também deseja buscar no cadastro os idosos pelo nome ou
identificador.


- Atenção:
- O projeto deverá ser apresentado no dia 20/04/23;
- O código deverá estar bem estruturado e a saída legível;
- O código deve ser implementado na linguagem C++;
- Devem ser utilizados os algoritmos MergeSort e QuickSort para ordenação.
- O algoritmo de pesquisa deve ser escolhido entre os que já foram vistos em sala de aula.
- Deverá ser feita a análise de complexidade dos algoritmos utilizados.
- Equipe com até 5 pessoas.



# Analise de complexibilidade 

### int main()

É O(n), onde n é o número de vezes que o usuário insere uma opção até que ele escolha a opção 0 para sair do loop.

### int menu()

Essa função é da complexibilidade O(1), pois só executa apenas um vez para cada chamada.

### void Cadastra(int &quantidadePacientes)

Essa função é da complexibilidade O(n), pois ele vai se repedir até que a variavel unique seja 1.

### void SalvarDados(int &quantidadePacientes)

Essa função é da complexibilidade O(1), pois só executa apenas um vez para cada chamada.

### void CarregarDados(int &quantidadePacientes)

Este é de O(n) pois depende da quantidade de pacientes cadastados.

### int BuscarPeloNome(int &quantidadePacientes)

Dentro dela usamos o quickSort que tem a complexibilidade O(log n) e também o busca binaria que no nosso caso o número de iterações depende de n; limite vai-se subdividindo a cada iteração; sendo o laço O(log n); logo, o a funação tem o O(log n) do quickSort e O(log n) da busca binaria. Por tando fica O(log(n)log(n))=O([log(n)]^2).

### int buscaIndentificador(int &quantidadePacientes)

Usamos dentro dele o quickSorte que tem complexidade de ordenação quicksort é O(n log n) no caso médio e O(n^2) no pior caso e com a busca binaria temos O(nlog(n)log(n)) = O(n(logn)^2).

### void Listar(int &quantidadePacientes, int tipo)

No pior caso sera O(n) pois ira depender da quandidade de pacientes que no maximo é 10 logo fica O(10) no melhor caso sera O(1) pois dependera da escolha do usuaraio.

### void MergeSort(Paciente pacientes[], int inicio, int fim) e void MergeIndentificador(Paciente v[], int a, int b, int c)

Foi usado para ordenar pela idade de forma crecente, e a complexibilidade e O(nlogn) para o melhor e pior caso.





