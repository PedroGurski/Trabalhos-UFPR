#include <stdlib.h>
#include "libagenda.h"

/* Cria uma agenda vazia:
   O mes_atual deve ser inicializado com 1; ptr_mes_atual deve ser definido. */
agenda_t *cria_agenda()
{
    agenda_t *agenda = (agenda_t *)malloc(sizeof(agenda_t));

    if (agenda)
    {
        agenda->mes_atual = 1;
        mes_t *primeiro_mes = (mes_t *)malloc(sizeof(mes_t));

        if (primeiro_mes)
        {
            primeiro_mes->mes = 1;
            primeiro_mes->dias = NULL;
            primeiro_mes->prox = primeiro_mes;
            primeiro_mes->ant = primeiro_mes;
            agenda->ptr_mes_atual = primeiro_mes;
        }
        else
        {
            free(agenda);
            agenda = NULL;
        }
    }
    return agenda;
}

/* Cria um compromisso:
   Retorna um compromisso com as informacoes de data de hc, um identificador
   id e uma string de descricao. A funcao deve alocar um novo espaco de
   armazenamento para receber a string descricao. */
compromisso_t *cria_compromisso(horario_compromisso_t hc, int id, char *descricao)
{
    compromisso_t* compr = (compromisso_t*)malloc(sizeof(compromisso_t));

    if (compr)
    {
        compr->id = id;
        compr->descricao = (char*)malloc((strlen(descricao) + 1) * sizeof(char));
        if (!compr->descricao)
        {
            free(compr);
            return NULL;
        }
        strcpy(compr->descricao, descricao);

    }
    else
        return NULL;

    return compr;
}

/* Libera toda memoria associado a agenda. */
void destroi_agenda(agenda_t *agenda)
{
}

/* Marca um compromisso na agenda:
   valores de retorno possiveis:
    -1: compromisso tem interseccao com outro
     0: erro de alocacao de memoria
     1: sucesso

    A lista de compromisso eh ordenada pelo horario de inicio. Eh necessario
    testar a interseccao entre horarios de inicio e de fim no compromisso novo
    considerando o  compromisso anterior e o proximo, caso existam. */
int marca_compromisso_agenda(agenda_t *agenda, int dia, compromisso_t *compr)
{
}

/* Desmarca o compromisso compr da agenda:
   O parametro compr eh um ponteiro para um compromisso existente da agenda.
   valores de retorno possiveis:
    1: em caso de sucesso
    0: caso nao tenha encontrado o compr */
int desmarca_compromisso_agenda(agenda_t *agenda, int dia, compromisso_t *compr)
{
}

/* Imprime a agenda do mes atual (mes atual) */
void imprime_agenda_mes(agenda_t *agenda)
{
}

/* Retorna o mes atual da agenda. */
int mes_atual_agenda(agenda_t *agenda)
{
    return agenda->mes_atual;
}

/* Ajusta o mes_atual para 1 e aponta prt_mes_atual para o mes 1 na Lista de
 * meses  */
void prim_mes_agenda(agenda_t *agenda)
{
}

/* Avanca a agenda para o proximo mes, incrementando mes_atual.
 * O ponteiro ptr_mes_atual deve ser atualizado para apontar para o novo mes_atual.
 * Se o novo mes_atual nao existir deve ser alocado. A funcao retorna o inteiro
 * mes_atual em caso de sucesso ou 0 caso contrario.  */
int prox_mes_agenda(agenda_t *agenda)
{
}

/* Analogo ao prox_mes_agenda porem decrementa mes_atual. */
int ant_mes_agenda(agenda_t *agenda)
{
}

/* Retorna um ponteiro para a lista ligada de compromissos de um dia do mes
   ou NULL se vazia. A lista de compromissos retornada pode ser percorrida
   usando-se a funcao prox_compr. */
compromisso_t *compr_agenda(agenda_t *agenda, int dia)
{
}

/* Retorna o primeiro compromisso da lista de compromissos compr e avanca
 * para o prox. Retorna NULL se a lista esta vazia, ou seja, sem compromissos.*/
compromisso_t *prox_compr(compromisso_t *compr)
{
}

/* As funcoes abaixo sao usadas para acessar os membros da struct compromisso
   obtidos com a funcao prox_compr. */
horario_compromisso_t hc_compr(compromisso_t *compr)
{
}
int id_compr(compromisso_t *compr)
{
}
char *descricao_compr(compromisso_t *compr)
{
}

/* Essa funcao nao eh extritamente necessaria, o objetivo e' que o programa
principal apresente os dados. Porem pode ser util para voces durante o desenvolvimento */
void imprime_agenda_mes(agenda_t *agenda)
{
}