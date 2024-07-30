#include <stdio.h>  // Biblioteca padrão de entrada e saída
#include <stdlib.h> // Biblioteca padrão para funções utilitárias
#include <string.h> // Biblioteca para manipulação de strings

#define MAX_PARTICIPANTES 15       // Número máximo de participantes permitidos
#define MAX_LEILOES 15             // Número máximo de leilões permitidos
#define MAX_STRING_LENGTH 100      // Comprimento máximo de strings
#define MAX_OBSERVACOES_LENGTH 200 // Comprimento máximo das observações do veículo

/**
 * Esse typedef struct é como se fosse um OBJETO, aqui em C se chama ESTRUTURA
 * objeto é um conceito de POO e ainda não foi visto em sala, e é MUITO mais estruturado que isso ai
 * E  NAAAAAAAAO É DIFICIL, Pensa nele como se fosse uma variavel que recebe dois tipos de dados
 * Exemplo: a variavel INT só recebe número blz? se botar um caracter LETRA quebra o codigo blz
 * No caso dessa variavel customizada chamada de PARTICIPANT ela recebe um número float e também uma string PQ EU FIZ ELA ASSIM.
 * Não tem nada de mais blz, mas quem quiser tirar isso e dividir em duas variaveis é de boas, vamo na paz pessoal :)
 * Dúvidas é so perguntar :D
 * LINK EXPLICANDO O QUE É TYPE STRUCT
 * https://www.inf.pucrs.br/~pinho/LaproI/Structs/Structs.htm
 */

// Definição da estrutura de dados para participante
typedef struct
{
    char nome[MAX_STRING_LENGTH];   // Nome do participante
    long long cpf;                  // CPF do participante
    char uf[MAX_STRING_LENGTH];     // Estado do participante
    char bairro[MAX_STRING_LENGTH]; // Bairro do participante
    float numeroTelefoneUm;         // Número de telefone do participante
    float saldo;                    // Saldo disponível do participante
} Participante;

// Definição da estrutura de dados para leilão
typedef struct
{
    char nomeLocador[MAX_STRING_LENGTH];      // Nome do locador do veículo
    char nomeVeiculo[MAX_STRING_LENGTH];      // Nome do veículo em leilão
    char categoriaVeiculo[MAX_STRING_LENGTH]; // Categoria do veículo
    char placa[MAX_STRING_LENGTH];            // Placa do veículo
    char observacoes[MAX_OBSERVACOES_LENGTH]; // Observações sobre o veículo
    int kmRodados;                            // Quilometragem rodada pelo veículo
    Participante *participanteVencedor;       // Referência ao participante vencedor do leilão
    float maiorLance;                         // Maior lance dado até o momento no leilão
    float lanceMinimo;
} Leilao;

// Definição da estrutura de dados para o aluguel
typedef struct
{
    char nomeCliente[MAX_STRING_LENGTH]; // Nome do dono do veiculo
    char nomeVeiculo[MAX_STRING_LENGTH]; // Nome do veiculo
    int diasAluguel;                     // Dias que o carro estara disponivel para o aluguel
    float custoDiario;                   // Custo diario do veiculo
    float custoTotal;                    // Custo total do veiculo
} Aluguel;

/**A função limparBufferEntrada() é usada para remover caracteres extras deixados no buffer de entrada do teclado após a leitura de dados. Isso evita
 * interferências nas próximas operações de entrada. O loop while continua lendo caracteres até encontrar uma nova linha ('\n') ou o fim do arquivo
 * (EOF). Isso garante um buffer de entrada limpo para futuras operações de entrada. (-Marco Antônio)
 */
void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função para cadastrar um novo participante
void cadastrarParticipante(Participante participantes[], int *numParticipantes)
{
    if (*numParticipantes < MAX_PARTICIPANTES)
    {
        printf("=============================================");
        printf("\nCadastro de Participante\n");
        printf("Informe seu Nome:");
        fgets(participantes[*numParticipantes].nome, MAX_STRING_LENGTH, stdin);
        limparBufferEntrada();
        printf("Informe seu CPF:");
        scanf("%lld", &participantes[*numParticipantes].cpf);
        limparBufferEntrada();
        printf("Informe seu Endereco\n");
        printf("UF:");
        fgets(participantes[*numParticipantes].uf, MAX_STRING_LENGTH, stdin);
        printf("Bairro:");
        fgets(participantes[*numParticipantes].bairro, MAX_STRING_LENGTH, stdin);
        printf("Informe seu Telefone:");
        scanf("%f", &participantes[*numParticipantes].numeroTelefoneUm);
        limparBufferEntrada();
        printf("Informe seu Saldo:");
        scanf("%f", &participantes[*numParticipantes].saldo);
        limparBufferEntrada();
        printf("Cadastro concluido!\n");
        (*numParticipantes)++;
    }
    else
    {
        printf("=========================================================");
        printf("\nLimite maximo de participantes alcancado.\n");
    }
}

// Função para cadastrar um novo leilão
void cadastrarLeilao(Leilao leiloes[], int *numLeiloes)
{
    if (*numLeiloes < MAX_LEILOES) // Verifica se ainda há espaço para novos leilões
    {
        printf("=============================================");
        printf("\nCadastro de Leilao\n");
        printf("Informe o Nome do Locador: ");
        fgets(leiloes[*numLeiloes].nomeLocador, MAX_STRING_LENGTH, stdin); // Obtém o nome do locador
        printf("Informe o Nome do Veiculo: ");
        fgets(leiloes[*numLeiloes].nomeVeiculo, MAX_STRING_LENGTH, stdin); // Obtém o nome do veículo
        printf("Informe a Categoria do Veiculo: ");
        fgets(leiloes[*numLeiloes].categoriaVeiculo, MAX_STRING_LENGTH, stdin); // Obtém a categoria do veículo
        printf("Informe a Placa do Veiculo: ");
        fgets(leiloes[*numLeiloes].placa, MAX_STRING_LENGTH, stdin); // Obtém a placa do veículo
        printf("Informe Observacoes sobre o Veiculo: ");
        fgets(leiloes[*numLeiloes].observacoes, MAX_OBSERVACOES_LENGTH, stdin); // Obtém observações sobre o veículo
        printf("Informe a quantidade de Km Rodados do Veiculo: ");
        scanf("%d", &leiloes[*numLeiloes].kmRodados); // Obtém a quilometragem rodada pelo veículo
        printf("Informe o Lance Minimo: ");
        scanf("%f", &leiloes[*numLeiloes].lanceMinimo);
        limparBufferEntrada();           // Limpa o buffer de entrada após a leitura da quilometragem
        printf("Cadastro concluido!\n"); // Exibe uma mensagem de conclusão
        (*numLeiloes)++;                 // Incrementa o número de leilões cadastrados
    }
    else
    {
        printf("=========================================================");
        printf("\nLimite maximo de leiloes alcancado.\n");
    }
}

// função para cadastrar o veiculo do aluguel
void cadastrarAluguel(Aluguel alugueis[], int *numAlugueis)
{
    if (*numAlugueis < MAX_LEILOES)
    {
        printf("=============================================");
        printf("\nCadastro de Aluguel de Veiculo\n");
        printf("Informe o Nome do Cliente: ");
        fgets(alugueis[*numAlugueis].nomeCliente, MAX_STRING_LENGTH, stdin); // Obtém o nome do cliente
        printf("Informe o Nome do Veiculo: ");
        fgets(alugueis[*numAlugueis].nomeVeiculo, MAX_STRING_LENGTH, stdin); // Obtem o nome do veiculo
        printf("Informe o Numero de Dias de Aluguel: ");
        scanf("%d", &alugueis[*numAlugueis].diasAluguel); // Obtem a quanticdade de dias que o cliente quer deixar disponivel o carro para aluguel
        limparBufferEntrada();
        printf("Informe o Custo Diario: ");
        scanf("%f", &alugueis[*numAlugueis].custoDiario);                                                            // Obtem a quantia do valor pela diaria que o cliente quer
        limparBufferEntrada();                                                                                       // Limpa o buffer de entrada após a leitura do custo diario
        alugueis[*numAlugueis].custoTotal = alugueis[*numAlugueis].custoDiario * alugueis[*numAlugueis].diasAluguel; // Calcula o custo total do aluguel
        printf("Cadastro concluido! Custo Total: %.2f\n", alugueis[*numAlugueis].custoTotal);                        // Imprime o valor total de quanto vai ficar para alugar esse veiculo
        (*numAlugueis)++;                                                                                            // Incrementa o número de leilões cadastrados
    }
    else
    {
        printf("=========================================================");
        printf("\nLimite maximo de alugueis alcancado.\n");
    }
}

// Função para exibir os leilões disponíveis
void exibirLeiloesDisponiveis(Leilao leiloes[], int numLeiloes)
{
    printf("=============================================\n");
    printf("Leiloes disponiveis:\n");
    for (int i = 0; i < numLeiloes; i++)
    {
        printf("[%d] %s\n", i + 1, leiloes[i].nomeLocador);
    }
}

// Função para participar de um leilão
void participarLeilao(Participante participantes[], Leilao leiloes[], int numParticipantes, int numLeiloes)
{

    if (numLeiloes > 0 && numParticipantes > 0) // Verifica se existem leilões e participantes cadastrados para continuar
    {

        exibirLeiloesDisponiveis(leiloes, numLeiloes); // Exibe os leilões disponíveis para que o usuário escolha qual participar

        int idLeilaoParticipar;
        printf("Escolha o numero do leilao que deseja participar: ");
        scanf("%d", &idLeilaoParticipar);
        idLeilaoParticipar--;
        limparBufferEntrada();

        if (idLeilaoParticipar >= 0 && idLeilaoParticipar < numLeiloes) // Verifica se o número do leilão escolhido é válido
        {
            Leilao *leilao = &leiloes[idLeilaoParticipar]; // Obtém uma referência para o leilão escolhido
            printf("Iniciando leilao de %s\n", leilao->nomeLocador);

            printf("Lance minimo para este leilao: R$ %.2f\n", leilao->lanceMinimo); // Exibe o lance mínimo definido para este leilão

            for (int turno = 1; turno <= 5; turno++)
            { // Loop para simular os 5 turnos do leilão
                printf("Turno %d de 5\n", turno);
                printf("Lance anterior: R$ %.2f\n", leilao->maiorLance);

                for (int i = 0; i < numParticipantes; i++)
                { // Loop para permitir que cada participante dê um lance ou pule
                    printf("Vez de %s\n", participantes[i].nome);
                    printf("Saldo disponivel: R$ %.2f\n", participantes[i].saldo);
                    printf("Escolha uma opcao:\n");
                    printf("[1] Digitar lance\n");
                    printf("[2] Pular\n");

                    int opcao;
                    scanf("%d", &opcao);
                    limparBufferEntrada();

                    switch (opcao)
                    { // Processa a opção escolhida pelo participante
                    case 1:
                        printf("Informe o seu lance: ");
                        float lance;
                        scanf("%f", &lance);
                        limparBufferEntrada();

                        if (lance >= leilao->lanceMinimo)
                        { // Verifica se o lance é maior ou igual ao lance mínimo cadastrado
                            if (lance <= participantes[i].saldo)
                            { // Verifica se o lance é menor ou igual ao saldo do participante
                                if (lance > leilao->maiorLance)
                                { // Verifica se o lance atual é maior que o lance anterior
                                    leilao->maiorLance = lance;
                                    leilao->participanteVencedor = &participantes[i];
                                    participantes[i].saldo -= lance;
                                    printf("Lance dado com sucesso!\n");
                                }
                                else
                                {
                                    printf("O lance precisa ser maior que o lance anterior.\n");
                                    i--;
                                }
                            }
                            else
                            {
                                printf("Saldo insuficiente para dar este lance.\n");
                                i--; // Volta uma iteração para permitir que o participante tente novamente
                            }
                        }
                        else
                        {
                            printf("O lance precisa ser igual ou maior que o lance mínimo.\n");
                            i--;
                        }
                        break;
                    case 2:
                        printf("Você escolheu pular este lance.\n");
                        break;
                    default:
                        printf("Opcao invalida, tente novamente.\n");
                        i--; // Volta uma iteração para permitir que o participante tente novamente
                        break;
                    }
                }
            }

            printf("O vencedor do leilao é: %s\n", leilao->participanteVencedor->nome); // Exibe o participante vencedor e o maior lance após os 5 turnos
            printf("Maior lance: R$ %.2f\n", leilao->maiorLance);
        }
        else
        {
            printf("Número de leilao inválido!\n");
        }
    }
    else
    {
        printf("Nao e possivel participar de um leilao neste momento. Certifique-se de ter pelo menos 1 leilao e 2 participantes cadastrados.\n\n");
    }
}

// Função para exibir os participantes cadastrados
void exibirParticipantes(Participante participantes[], int numParticipantes)
{
    printf("=========================================================");
    printf("\nParticipantes Cadastrados:\n");
    for (int i = 0; i < numParticipantes; i++)
    {
        printf("=========================================================");
        printf("\nNome:%sCPF:%lld\nSaldo:%.f\n", participantes[i].nome, participantes[i].cpf, participantes[i].saldo); // Exibe os detalhes de cada participante
    }
}

// Função para exibir os leilões cadastrados
void exibirLeiloes(Leilao leiloes[], int numLeiloes)
{
    printf("=========================================================");
    printf("\nLeiloes Cadastrados:\n");
    for (int i = 0; i < numLeiloes; i++)
    {
        printf("Nome do Locador: %sVeiculo: %sCategoria: %sPlaca: %sObservacoes: %sKm Rodados: %d\n", leiloes[i].nomeLocador, leiloes[i].nomeVeiculo, leiloes[i].categoriaVeiculo, leiloes[i].placa, leiloes[i].observacoes, leiloes[i].kmRodados); // Exibe os detalhes de cada leilão
    }
}

// Função principal
int main()
{
    Participante participantes[MAX_PARTICIPANTES]; // Array para armazenar participantes
    Leilao leiloes[MAX_LEILOES];                   // Array para armazenar leilões
    Aluguel alugueis[MAX_LEILOES];
    int numAlugueis = 0;                               // Array para armazenar alugueis
    int escolha, numParticipantes = 0, numLeiloes = 0; // Variáveis para armazenar a escolha do usuário e o número de participantes/leilões

    printf("\nBem vindo ao Leilao e Aluguel de veiculos\n");

    // Pré-cadastro de participantes
    strcpy(participantes[numParticipantes].nome, "Robson Da Silva\n"); // Esta linha está copiando o nome para o campo de nome do participante na posição
    participantes[numParticipantes].cpf = 12345678901.0;               // O CPF  está sendo atribuído ao campo de CPF do participante na mesma posição do array
    strcpy(participantes[numParticipantes].uf, "SP");                  // Este trecho copia a sigla do estado para o campo de estado (UF) do participante na posição
    strcpy(participantes[numParticipantes].bairro, "Centro");          // Esta linha copia o nome do bairro para o campo de bairro do participante
    participantes[numParticipantes].numeroTelefoneUm = 987654321;      // Aqui, um número de telefone está sendo atribuído ao primeiro número de telefone do participante na posição 'numParticipantes'
    participantes[numParticipantes].saldo = 1000000.0;                 // Este trecho atribui um saldo ao campo de saldo do participante
    numParticipantes++;

    strcpy(participantes[numParticipantes].nome, "Mark Zuckerberg\n"); // Esta linha está copiando o nome para o campo de nome do participante na posição
    participantes[numParticipantes].cpf = 14765432109.0;               // O CPF  está sendo atribuído ao campo de CPF do participante na mesma posição do array
    strcpy(participantes[numParticipantes].uf, "NY");                  // Este trecho copia a sigla do estado para o campo de estado (UF) do participante na posição
    strcpy(participantes[numParticipantes].bairro, "White Plains");    // Esta linha copia o nome do bairro para o campo de bairro do participante
    participantes[numParticipantes].numeroTelefoneUm = 987654321;      // Aqui, um número de telefone está sendo atribuído ao primeiro número de telefone do participante na posição 'numParticipantes'
    participantes[numParticipantes].saldo = 1500000.0;                 // Este trecho atribui um saldo ao campo de saldo do participante
    numParticipantes++;

    strcpy(leiloes[numLeiloes].nomeLocador, "Unibra veiculos\n");              // Este trecho copia o nome do locador para o campo correspondente na posição 'numLeiloes' do array 'leiloes'.
    strcpy(leiloes[numLeiloes].nomeVeiculo, "Rolls-Royce Silver Spur II\n");   // Aqui, o nome do veículo é copiado para o campo correspondente na posição 'numLeiloes' do array 'leiloes'.
    strcpy(leiloes[numLeiloes].categoriaVeiculo, "Carro\n");                   // Similarmente, a categoria é copiada para o campo correspondente.
    strcpy(leiloes[numLeiloes].placa, "MK2009\n");                             // A placa é copiada para o campo correspondente.
    strcpy(leiloes[numLeiloes].observacoes, "Dirigido por Michael Jackson\n"); // Estas observações sobre o veículo são copiadas para o campo correspondente.
    leiloes[numLeiloes].kmRodados = 12900;                                     // Aqui, a quantidade de quilômetros rodados pelo veículo está sendo atribuída ao campo correspondente.
    leiloes[numLeiloes].lanceMinimo = 45000;
    numLeiloes++;

    do
    {
        // Exibe o menu de opções
        printf("=========================================================");
        printf("\nMenu:\n");
        printf("[1] Participar de um leilao\n");          // para o parcipante entrar em um leilão.
        printf("[2] Cadastrar Aluguel de Veiculo \n");    // para cadastrar um veiculo para se alugado.
        printf("[3] Cadastrar participante\n");           // para cadastrar um participante.
        printf("[4] Cadastrar Leilao\n");                 // para se cadastrar um leilão.
        printf("[5] Checar participantes cadastrados\n"); // checar os participantes que foram cadastrados.
        printf("[6] Checar leiloes cadastrados\n");       // para verificar se tem algum leilão cadastrado.
        printf("[7] Sair\n");                             // para sair do menu e fechar o cmd.
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha); // Obtém a escolha do usuário
        limparBufferEntrada(); // Limpa o buffer de entrada após a leitura da escolha

        switch (escolha)
        {
        case 1:
            participarLeilao(participantes, leiloes, numParticipantes, numLeiloes); // Chama a função para participar de um leilão
            break;

        case 2:
            cadastrarAluguel(alugueis, &numAlugueis);
            break;

        case 3:
            cadastrarParticipante(participantes, &numParticipantes); // Chama a função para cadastrar um novo participante
            break;

        case 4:
            cadastrarLeilao(leiloes, &numLeiloes); // Chama a função para cadastrar um novo leilão
            break;

        case 5:
            exibirParticipantes(participantes, numParticipantes); // Chama a função para exibir os participantes cadastrados
            break;

        case 6:
            exibirLeiloes(leiloes, numLeiloes); // Chama a função para exibir os leilões cadastrados
            break;
        case 7:
            printf("Saindo...\n"); // Exibe uma mensagem de saída
            break;

        default:
            printf("Entrada invalida, tente novamente...\n"); // Exibe uma mensagem se a escolha do usuário for inválida
            break;
        }
    } while (escolha != 7); // Repete o loop até que o usuário escolha sair

    return 0;
}
