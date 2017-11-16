#include <stdlib.h>
#include <stdio.h>

struct _cadastro{
  char nome[150];
  int cep;
  int telefone;
};

typedef struct _cadastro Cadastro; //produto

struct _cadastrado{
  Cadastro* v;
  int n;
  int maximo;
};

typedef struct _cadastrado Cadastrado; //catalogo

void imprimeCadastro(const Cadastro* p){
  printf("Nome: %s\n", p->nome);
  printf("CEP: %d\n", p->cep);
  printf("Tel: %d\n", p->telefone);
}

void imprimeCadastrado(Cadastrado c){
  int i;
  for (i=0;i<c.n;i++){
    imprimeCadastro(c.v + i);
  }
}

Cadastrado criaCadastrado(int n){
  Cadastrado c;
  c.n = 0;
  c.v = malloc(sizeof(Cadastro) * n);
  c.maximo = n;
  return c;
}

void destroiCadastrado(Cadastrado c){
  free(c.v);
}

void tiraLinha(char *str){
  int i = 0;
  while(str[i] != '\0' && str[i] != '\n'){
    i++;
  }
  str[i] = '\0';
}

void insereCadastrado(Cadastrado* c){
  fflush(stdin);
  if (c->n >= c->maximo){
    puts("Buffer overflow!");
    return;
  }
  puts("Home");
  fgets(c->v[c->n].nome, 150, stdin);
  tiraLinha(c->v[c->n].nome);
  puts("CEP");
  scanf("%d", &(c->v[c->n].cep));
  puts("Tel");
  scanf("%d", &(c->v[c->n].telefone));
  c->n++;
}

void leiaPrimeiros(Cadastrado* c, int n){
  int i;
  for (i=0;i<n;i++){
    insereCadastrado(c);
  }
}

int main(){
  Cadastrado c = criaCadastrado(100);
  printf("Quantos cadastros serao feitos? ");
  int n;
  scanf("%d", &n);
  leiaPrimeiros(&c, n);
  imprimeCadastrado(c);
  destroiCadastrado(c);
  return 0;
}
