#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include "controle.h"

void menu(){
    int op;
    do{
        printf("\n1 - Cadastro de Departamento\n2 - Cadastro de Funcionário\n3 - Alterar Funcionário\n4 - Alterar Departamento Funcionário\n5 - Alterar o Gerente de um Departamento\n");
        printf("6 - Consultar Matrícula do Funcionário\n7 - Gerar Folha Pagamento\n8 - Alterar o Salário de um Funcionário\n9 - Relatório de Funcionários por departamento\n10 - Histórico do Salário em um período\n11 - Gerentes de um departamento :");
        scanf("%d",&op);
        switch(op){
        case 1:
            if(cadastro_dept(arq_dept)==1){
                system("clear || cls");
                printf("\nCadastro de Departamento Realizado!\n");

            }
        break;
        case 2:
            exibeDept(arq_dept);
            break;
        }
    }while(op>0 && op<12);
}


void exibeDept(FILE *a){
    TDepartamento dept;
    fseek(a,0,SEEK_SET);
    while(fread(&dept, sizeof(TDepartamento), 1, a)==1){
        printf("id: %li\n", dept.id);
        printf("id gerente: %li\n", dept.id_gerente);
        printf("nome: %s\n", dept.nome);
        printf("ramal: %hu\n", dept.Ramal);
        printf("sigla: %s\n", dept.sigla);
    }
}

//Essa função recebe como parâmetro uma string
//E tira o espaço e também o "ENTER", que não foi utilizado
void retiraEnter(char *string){
	int tamanho = strlen(string) - 1;
	if (string[tamanho] == '\n'){
		string[tamanho] = '\0';
	}
	else {
		while (getc(stdin) != '\n')
			continue;
	}
}

//Essa função recebe como parâmetro uma string
//E verifica, se a variável contém ao menos uma palavra
//Retorna 0, caso a variável estiver vazia
int verificaVazio(char *palavra){
    int i,t;
    if(strlen(palavra)==0)
        return 0;
    if(palavra[0]==' ')
        return 0;
    for(i=0;i<strlen(palavra);i++){
        t=isdigit(palavra[i]);
        printf("%d",t);
        if(t==1)
            return 0;
    }
    return 1;
}

int verificaNum(char *ramal){
    int i;
    for(i=0;i<strlen(ramal);i++){
        if(isalpha(ramal[i])!=0){
            return 0;
        }
    }
    return 1;
}
int cadastro_dept(FILE *arq_dept){
    TDepartamento dept;
    int sair;
    char verificaRamal[10];
    do{
        do{
            system("clear || cls");
            setbuf(stdin,NULL);
            printf("\nInforme o Nome do Departamento: ");
            fgets(dept.nome, NOME_DEP, stdin);
            retiraEnter(dept.nome);
        }while(verificaVazio(dept.nome)==0);
        printf("Digite o nome da sigla: ");
        setbuf(stdin,NULL);
        fgets(dept.sigla, SIGLA, stdin);
        retiraEnter(dept.sigla);
        //Colocar o DO/WHILE, e fazer a verificação do dept->ramal, sendo que só pode aceitar numeros
        do{
            printf("Digite o Número do RAMAL: ");
            setbuf(stdin,NULL);
            fgets(verificaRamal, 10, stdin);
            retiraEnter(verificaRamal);
        }while(verificaNum(verificaRamal)==0);
        dept.Ramal = strtol(verificaRamal, NULL, 10);
        fseek(arq_dept,0,SEEK_END);
        dept.id = (ftell(arq_dept)/sizeof(TDepartamento)) + 1;
        fwrite(&dept, sizeof(TDepartamento), 1, arq_dept);
        printf("Deseja sair:1-Sim 2-Não");
        scanf("%d",&sair);
    }while(sair != 1);
    return 1;
}
