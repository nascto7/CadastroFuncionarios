#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED

/// Constantes Estrutura Funcionários
#define MATRICULA 10
#define NOME 60
#define DATA 11
#define CPF 11
#define RUA 40
#define BAIRRO 30
#define COMPLEMENTO 30
#define CIDADE 40
#define UF 3
#define CEP 9
#define EMAIL 40

/// Constantes Estrutura Departamento
#define NOME_DEP 40
#define SIGLA 10



/// Estrutura Funcionários
typedef struct{
    long id, id_departamento;
    char matricula[MATRICULA], nome[NOME], dataNascimento[DATA],
         cpf[CPF], rua[RUA], bairro[BAIRRO], complemento[COMPLEMENTO],
         cidade[CIDADE], uf[UF], cep[CEP], email[EMAIL];
    unsigned int Numero;
    float salario;
}TFuncionario;


/// Estrutura HistoricoFuncionarios
typedef struct{
    long int id_funcionario, id_departamento;
    char data[DATA];
}THistoricoFuncionario;


/// Estrutura Departamento
typedef struct{
    long int id, id_gerente;
    char nome[NOME_DEP], sigla[SIGLA];
    unsigned short int Ramal;
}TDepartamento;


/// Estrutura Historico Departamento
typedef struct{
    long id_departamento, id_gerente;
    char data[DATA];
}THistoricoDepartamento;


/// Estrutura Historico Salario
typedef struct{
    long id_funcionario;
    float salario;
    unsigned short int mes, ano;
}THistoricoSalario;



FILE *arq_func, *arq_hist_func, *arq_dept,*arq_hist_dept,*arq_hist_sal;


void menu();
int cadastro_dept(FILE*);
int verificaVazio(char*);
void retiraEnter(char*);
int verificaNum(char*);
void exibeDept(FILE*);


#endif // CONTROLE_H_INCLUDED
