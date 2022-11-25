#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

typedef struct
{
    char login[30];
    char senha[30];
} pessoa;
pessoa p[1];

struct person
{

    int dia, mes;
    long int cep;
    long long int telefone, cpf, ano;
    char nome[50], sobrenome[50];
    char estado[10], cidade[20], bairro[20], ruaN[20];
    char comorbidade[205], confi_comorbidade;
    char email[205];
};


struct dates
{

    int day, month;
    long long int yaer;


};




int main()
{
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);

    long int currentYear = data_hora_atual->tm_year+1900;



    struct person patient;
    struct dates getDate;

    int operacao, age;
    char line[50], diagnosticoDate[50], cepGet[10], cpfGet[10], tel_fone[10];
    char name[10], dataNas[50], address[20];
    strcpy(address, "Endereco: ");
    strcpy(tel_fone, "Telefone: ");
    strcpy(name, "Nome: ");
    strcpy(dataNas, "Data de nascimento: ");
    strcpy(cepGet, "CEP: ");
    strcpy(cpfGet, "CPF: ");
    strcpy(diagnosticoDate, "Diagnostico:");
    strcpy(line, "------------------------------");
    char refazer;

    char login[30];
    char senha[30];

    char new_registration[1];

    strcpy(p[0].login, "cad@host");
    strcpy(p[0].senha, "1034");

    printf("||||||||||||||||||||||||||||||||||||||\n");
    printf("--------------------------------------\n");
    printf("       Sistema de monitoriamento\n");
    printf("--------------------------------------\n");
    printf("--------------------------------------\n");
    printf("\n");

    //================================================================================//
    // Validação de usúario e senha.

    while ((strcmp(login, p[0].login) != 0))
    {
        printf("\nLogin: ");
        scanf("%s", login);
        if ((strcmp(login, p[0].login) != 0))
        {
            setlocale(LC_ALL, "Portuguese");
            printf("\nUser inválido ou não existe. Digite novamente.");
        }
    }

    while ((strcmp(senha, p[0].senha) != 0))
    {

        printf("\nSenha: ");
        scanf("%s", senha);
        if ((strcmp(senha, p[0].senha) != 0))
        {
            setlocale(LC_ALL, "Portuguese");
            printf("\nSenha inválida! Digite novamente.");
        }
    }

    //================================================================================//

    char open = 's';
    char exite;

    // Seleção de operação
    do
    {

        printf(" \n");
        printf(" \n");
        printf("-------------------------------------------------\n");
        setlocale(LC_ALL, "Portuguese");
        printf("          AREA DE CADASTRO E CONSULTA           |\n");
        printf("    Pacientes diagnosticados com covid-19       |\n");
        printf("-------------------------------------------------\n");
        printf("-------------------------------------------------\n");
        setlocale(LC_ALL, "Portuguese");
        printf(" DIGITE UM NUMERO CONFORME A OPERECAO DESEJADA  |\n");
        printf("                                                |\n");
        printf("        (1 - Cadastrar novo paciente )          |\n");
        printf("                                                |\n");
        printf("     (2 - Listar pacientes cadastrados )        |\n");
        printf("                                                |\n");
        printf("    (3 - Listar dados de grupo de risco )       |\n");
        printf("                                                |\n");
        printf("-------------------------------------------------\n");
        printf(" \n");
        printf("\nSelecionar: ");
        scanf("%d", &operacao);
        printf(" \n");

        // Cadastro de novo paciente ----------------
        FILE *arq;

        arq = fopen("data_Base_person.txt", "a");

        if (arq == NULL)
        {
            printf("Erro ao tentar abrir o arquivo!");
            exit(1);
        }

        switch (operacao)
        {

        case 1:

            printf("\nNome: ");
            scanf("%s", &patient.nome);
            printf("\nSobrenome: ");
            scanf("%s", &patient.sobrenome);

            printf("\nData de Nascimento.");
            printf("\nDia: ");
            scanf("%d", &patient.dia);
            setlocale(LC_ALL, "Portuguese");
            printf("\nMes: ");
            scanf("%d", &patient.mes);
            printf("\nAno: ");
            scanf("%lli", &patient.ano);


            //Data de diagnostico ------------------
            printf("\nData de diagnostico.");
            printf("\nDia: ");
            scanf("%d", &getDate.day);
            setlocale(LC_ALL, "Portuguese");
            printf("\nMes: ");
            scanf("%d", &getDate.month);
            printf("\nAno: ");
            scanf("%lli", &getDate.yaer);
            //--------------------------------------

            //Endereço ------------------
            printf("Endereco completo\n ");
            printf("\nEstado(somente a sigla): ");
            scanf("%s", &patient.estado);
            printf("\nCidade: ");
            scanf("%s", &patient.cidade);
            printf("\nCEP: ");
            scanf("%li", &patient.cep);
            //--------------------------------------

            //Dados e contato------------------
            printf("\nDigite o CPF: ");
            scanf("%lli", &patient.cpf);
            printf("\nTelefone: ");
            scanf("%lli", &patient.telefone);
            printf("\nE-mail: ");
            scanf("%s", &patient.email);
            printf(" \n");
            printf("\nPaciente tem algunha comorbidade?(s/n)");
            scanf("%s", &patient.confi_comorbidade);
            //--------------------------------------

            switch(patient.confi_comorbidade)
            {

            case 's':
                printf("\nQual comorbidade?: ");
                scanf("%s", &patient.comorbidade);
                break;

            }

            fprintf(arq, "%s ", name);
            fprintf(arq, "%s ", patient.nome);
            fprintf(arq, "%s \n", patient.sobrenome);

            fprintf(arq, "%s ", dataNas);
            fprintf(arq, "%d ", patient.dia);
            fprintf(arq, "%d ", patient.mes);
            fprintf(arq, "%lli \n", patient.ano);

            fprintf(arq, "%s ", diagnosticoDate);
            fprintf(arq, "%d ", getDate.day);
            fprintf(arq, "%d ", getDate.month);
            fprintf(arq, "%lli \n", getDate.yaer);

            fprintf(arq, "%s ", address);
            fprintf(arq, "%s ", patient.estado);
            fprintf(arq, "%s \n", patient.cidade);
            fprintf(arq, "%s ", cepGet);
            fprintf(arq, "%li \n", patient.cep);
            fprintf(arq, "%s ", cpfGet);
            fprintf(arq, "%lli \n", patient.cpf);
            fprintf(arq, "%lli \n", patient.telefone);
            fprintf(arq, "%s \n", patient.email);
            fprintf(arq, "%s \n", line);



            fclose(arq);

            age = currentYear - patient.ano;

            if((age >= 65) || ( patient.confi_comorbidade == 's'))
            {


                FILE *monitoring;

                monitoring = fopen("data_Base_monitoring.txt", "a");

                if (monitoring == NULL)
                {
                    printf("Erro ao tentar abrir o arquivo!");
                    exit(1);
                }


                fprintf(monitoring, "%s \n", line);
                fprintf(monitoring, "%s ", cepGet);
                fprintf(monitoring, "%li \n", patient.cep);
                fprintf(monitoring, "%li \n", age);


                if (monitoring == NULL)
                {
                    printf("===");
                    exit(1);
                }
                else
                {

                    fprintf(arq, "%s \n", patient.comorbidade);

                }
                fprintf(monitoring, "%s \n", line);
                fclose(monitoring);

            }


            break;

            getch();
        }

        // Listagem de pacientes cadastrados -----
        char ler[2000];

        arq = fopen("data_Base_person.txt", "r");

        switch (operacao)
        {

        case 2:

            while (fgets(ler, 2000, arq) != NULL)
                printf("%s\n", ler);

            fclose(arq);

            break;
        }



        if(operacao == 3)
        {
            FILE *monitoring;
            char letLer[2000];

            monitoring = fopen("data_Base_monitoring.txt", "r");



            while (fgets(letLer, 2000, monitoring) != NULL)
                printf("%s\n", letLer);

            fclose(monitoring);


        }




        getch();

        printf("----------------------------------------- \n");
        printf("\nDeseja voltar ao inicio? (s/n): ");
        scanf("%s", &exite);
        printf("                                          \n");
        printf("----------------------------------------- \n");

    }
    while (exite == open);

    system("pause");

    return 0;
}
