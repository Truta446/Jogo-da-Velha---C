#include<stdio.h> /*printf(), scanf(), fflush(stdin)*/
#include<stdlib.h> /*system()*/
#include<string.h> /*strlen(),*/
#include<math.h> /*pow()*/
#include<locale.h> /*setlocale()*/
#include<ctype.h> /*isalpha()*/
#include<windows.h> /*Beep(), Sleep()*/

char matrix[3][3];/*Matriz do jogo*/
char check(void); /* Cheka a matriz para saber se há um vencedor*/
void init_matrix(void); /* Inicializa a matriz com vazio*/
char init_matrix_ex(void); /* Inicializa a matriz exemplo*/
char get_player_move(char nome1[30], int opcao); /* Jogada do participante*/
char get_computer_move(int x, int num, int opcao,char nome2[30]); /*jogada do computador*/
void disp_matrix(void); /* Aparece na tela a matriz atual*/
void desenho(); /* Desenho do boneco*/
void desenho2(); /* Desenho da caveira*/
void musica(void); /*Música Mário*/

int main(int argc, char **argv){
    char done = ' ', resp;
    char nome1[30], nome2[30];
    int cont,tobe,num,i=0,j=0,we;
    int opcao,opcao2;

    /*Silenciar Warning*/
    argc = argc;
    argv = argv;

    do{
        setlocale(LC_ALL,"Portuguese");
        system("color 47");
        printf("\n\t__________________________________________________________\n");
        printf("\t__________________________________________________________\n");
        printf("\t__________________________________________________________\n");
        printf("\t__________________                    ____________________\n");
        printf("\t__________________                    ____________________\n");
        printf("\t__________________   JOGO  DA  VELHA  ____________________\n");
        printf("\t__________________                    ____________________\n");
        printf("\t__________________________________________________________\n");
        printf("\t__________________________________________________________\n");
        printf("\t__________________________________________________________\n\t\t\t\t\tCreated by: Juan Versolato\n\n\n");
        printf("\tEscolha uma das opções abaixo:\n\n");
        printf("\t%c 1 - Jogar;\n\t%c 2 - Ajuda;\n\t%c 3 - Sair.\n\n\n",16,16,16);
        printf("\tOpção: ");
        scanf("%d", &opcao2);/*ESCOLHA DA OPÇÃO DO MENU.......*/
        while(opcao2<1 || opcao2>3){
            printf("Digite uma opção válida!\n\n");
            printf("\tOpção: ");
            scanf("%d", &opcao2);
        }
        system("cls");
        switch(opcao2){
        case 1:
            system("color 10");
            desenho(); //DESENHO DO BONECO
            /*musica();*/ /*Desativado pois não é uma função assincrona*/
            printf("\n\n\t\t\t  ENTER PARA CONTINUAR.....");
            printf("\n\n\n\n");
            system("pause");
            system("cls");
            system("color 30");
            printf("\n\n\tEscolha um modo de jogo:\n\n\n");
            printf("\n\t%c 1 - Fácil;\n\t%c 2 - Médio;\n\t%c 3 - Difícil;\n\t%c 4 - Impossível;\n\t%c 5 - Dois Jogadores.\n\n\n",16,16,16,16,16);
            printf("\tOpção: ");
            scanf("%d", &opcao);
            while(opcao<1 || opcao>5){
                printf("Digite uma opção válida!\n\n");
                printf("\tOpção: ");
                scanf("%d", &opcao);
            }
            system("cls");
            if(opcao==5){
                printf("\n\n\tDigite o nome do(a) primeiro(a) jogador(a): ");
                fflush(stdin);
                scanf("%[^\n]", nome1);
                while(strlen(nome1)==2){
                    printf("Por favor, complete a pergunta abaixo!\n");
                    printf("\n\n\tDigite o nome do(a) primeiro(a) jogador(a): ");
                    fflush(stdin);
                    scanf("%[^\n]", nome1);
                }
                printf("\n\n\tDigite o nome do(a) segundo(a) jogador(a): ");
                fflush(stdin);
                scanf("%[^\n]", nome2);
                we = strlen(nome2);
                while(we==0){
                    printf("Por favor, complete a pergunta abaixo!\n");
                    printf("\n\n\tDigite o nome do(a) segundo(a) jogador(a): ");
                    fflush(stdin);
                    scanf("%[^\n]", nome2);
                    we = strlen(nome2);
                }
            }else{
                printf("\n\n\tDigite o nome do(a) jogador(a): ");
                fflush(stdin);
                scanf("%[^\n]", nome1);
                while(strlen(nome1)==2){
                    printf("Por favor, complete a pergunta abaixo!\n");
                    printf("\n\n\tDigite o nome do(a) primeiro(a) jogador(a): ");
                    fflush(stdin);
                    scanf("%[^\n]", nome1);
                }
            }
            fflush(stdin);
            printf("\n\n");
            resp = 's';
            cont = 2;
            i = 0;
            j = 0;
            while(resp=='s' || resp=='S'){
                tobe = 1;
                init_matrix();
                do{
                    if((cont%2)==0){//get_player_move first
                        num = 0; //defesa
                        system("cls");
                        init_matrix_ex();
                        disp_matrix();
                        get_player_move(nome1, opcao);
                        done = check(); //Verifica se existe um vencedor
                        if(done != ' ') break; //vencedor
                        if(opcao==5){
                            system("cls");
                            init_matrix_ex();
                            disp_matrix();
                        }
                        get_computer_move(tobe,num,opcao,nome2);
                        tobe++;
                        done = check(); //vencedor
                    }else{ // get_computer_move first
                        num = 1; // ataque
                        system("cls");
                        if(opcao==5){
                            init_matrix_ex();
                            disp_matrix();
                        }
                        get_computer_move(tobe,num,opcao,nome2);
                        init_matrix_ex();
                        disp_matrix();
                        tobe++;
                        done = check(); //vencedor
                        if(done != ' ') break; //vencedor
                        if(opcao==5){
                            system("cls");
                            init_matrix_ex();
                            disp_matrix();
                        }
                        get_player_move(nome1, opcao);
                        done = check(); //Verifica se existe um vencedor
                    }
                }while(done == ' ');
                system("cls");
                printf("\n\n\n");
                disp_matrix(); //Mostra as posições finais
                if(done=='X'){
                    if(opcao==5){
                        printf("%s VENCEU!!!\n",nome1);
                        Beep(1000,1000);
                        Beep(2000,500);
                        Beep(3000,500);
                        Beep(4000,500);
                    }else{
                        printf("Você VENCEU!!!\n");
                        Beep(1000,1000);
                        Beep(2000,500);
                        Beep(3000,500);
                        Beep(4000,500);
                    }
                    i++;
                }else
                    if(done == 'O'){
                        if(opcao==5){
                            printf("%s VENCEU!!!\n",nome2);
                            Beep(1000,1000);
                            Beep(2000,500);
                            Beep(3000,500);
                            Beep(4000,500);
                        }else{
                            printf("Computador VENCEU!!!\n");
                            Beep(4000,500);
                            Beep(3000,500);
                            Beep(2000,500);
                            Beep(1000,1000);
                        }
                        j++;
                    }else
                        if(done == 'E'){
                            printf("Empate!\n");
                            Beep(1000,3600);
                        }
                do{
                    if(opcao==5){
                        printf("\t\t\t\t\t\t%s  |  %s\n", nome1, nome2);
                    }else{
                        printf("\t\t\t\t\t\t%s    |   Computer\n", nome1);
                    }
                    printf("\t\t\t\t\t\t   %d          %d\n", i, j);
                    if(done == 'O'){
                        printf("Você aceita uma revanche?<s/n>:");
                    }else{
                        printf("Deseja jogar novamente?<s/n>:");
                    }
                    scanf(" %c", &resp);
                }while(resp!='s' && resp!='n' && resp!='S' && resp!='N');
                printf("\n-------------------------------------------------------------------------\n");
                cont++;
            }
            system("cls");
            break;
        case 2://Mostra as informações do jogo
            system("color 90");
            printf("\n\n\t_________________________ O QUE É O JOGO? __________________________");
            printf("\n\t     O jogo da velha é constituído por um tabuleiro quadrático,\n\tdividido em 9 quadrados,sendo assim, um tabuleiro 3x3.\n\tExitem 3 linhas que estão na posição  vertical,\n\te com 3 colunas na posição horizantal.\n");
            printf("\n\t__________________________  O OBJETIVO  ____________________________");
            printf("\n\n\t     Fazer uma sequência de 'X' ou 'O' horizontalmente, ou\n\tverticalmente, ou diagonalmente.\n\tQuem fizer a sequência primeiro, é o vencedor!\n\n");
            printf("\n\t__________________________ REGRAS DO JOGO ___________________________");
            printf("\n\n\t1 - Escolher um número de 1 a 9 para realizar sua jogada;\n\t2 - Faça apenas uma jogada de cada vez;\n\t3 - A vez de começar é intercalado pelos jogadores;\n\t4 - Só é permitido a jogada se o campo desejado estiver livre.\n");
            printf("\t____________________________________________________________________\n\n\n\n");
            system("pause");
            system("cls");
            break;
        case 3://PARA SAIR DO JOGO......
            system("color 70");
            desenho2(); // desenho caveira
            printf("\n\n\t\t\t\t\tFIM DO JOGO\n\n");
            break;
        }
    }while(opcao2!=3);
    system("Pause");
    return 0;
}
void init_matrix(void){ //Inicializa a matriz com vazio
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matrix[i][j] = ' ';
        }
    }
}
char init_matrix_ex(void){ //Inicializa uma matriz exemplo
    int t,k=1, cont=0;
    printf("Exemplo a ser seguido:\n");
    for(t=0;t<3;t++){
        printf(" %d | %d | %d ", k,k+1,k+2);
        k = 4;
        if(t!=2){
            printf("\n---|---|---\n");
            cont++;
            if(cont == 2) k = 7;
        }
    }
    printf("\n");
}
char get_player_move(char nome1[30],int opcao){ //Obtem a sua jogada
    int n,x=0;
    if(opcao==5) printf("\n\nÉ a vez do(a) %s\n\n", nome1);
    printf("Digite o número do quadrante a ser jogado<1...9>:");
    scanf("%d", &n);
    while((n<1 || n>9)){
        printf("Por favor, digite uma posição válida\n");
        printf("Digite o número do quadrante a ser jogado<1...9>: ");
        scanf("%d", &n);
    }
    do{
        switch(n){
        case 1:
            if(matrix[0][0] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[0][0] = 'X';
                return matrix[0][0];
            }
        case 2:
            if(matrix[0][1] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[0][1] = 'X';
                return matrix[0][1];
            }
        case 3:
            if(matrix[0][2] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[0][2] = 'X';
                return matrix[0][2];
            }
        case 4:
            if(matrix[1][0] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[1][0] = 'X';
                return matrix[1][0];
            }
        case 5:
            if(matrix[1][1] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[1][1] = 'X';
                return matrix[1][1];
            }
        case 6:
            if(matrix[1][2] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[1][2] = 'X';
                return matrix[1][2];
            }
        case 7:
            if(matrix[2][0] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[2][0] = 'X';
                return matrix[2][0];
            }
        case 8:
            if(matrix[2][1] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[2][1] = 'X';
                return matrix[2][1];
            }
        case 9:
            if(matrix[2][2] != ' '){
                do{
                    printf("Por favor, digite uma posição válida\n");
                    printf("Digite o número do quadrante a ser jogado<1...9>: ");
                    scanf("%d", &n);
                }while(n<1 || n>9);
                x = 1;
                break;
            }else{
                matrix[2][2] = 'X';
                return matrix[2][2];
            }
        }
    }while(x==1);
}
char get_computer_move(int x, int num,int opcao, char nome2[30]){ // Obtem a jogada do computador
    int i, j, cont=0,n=0,o,numero,piriz;
    switch(opcao){
    case 1: //Fácil
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(matrix[i][j] == ' '){
                    matrix[i][j] = 'O';
                    return matrix[i][j];
                }
            }
        }
    case 2: //médio
        srand((unsigned)time(NULL));
        numero = 1 + (rand()%9);
        do{
            switch(numero){
            case 1:
                if(matrix[0][0] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[0][0] = 'O';
                    return matrix[0][0];
                }
            case 2:
                if(matrix[0][1] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[0][1] = 'O';
                    return matrix[0][1];
                }
            case 3:
                if(matrix[0][2] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[0][2] = 'O';
                    return matrix[0][2];
                }
            case 4:
                if(matrix[1][0] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[1][0] = 'O';
                    return matrix[1][0];
                }
            case 5:
                if(matrix[1][1] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }
            case 6:
                if(matrix[1][2] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[1][2] = 'O';
                    return matrix[1][2];
                }
            case 7:
                if(matrix[2][0] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[2][0] = 'O';
                    return matrix[2][0];
                }
            case 8:
                if(matrix[2][1] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[2][1] = 'O';
                    return matrix[2][1];
                }
            case 9:
                if(matrix[2][2] != ' '){
                    n = 1 + (rand()%9);
                    x = 1;
                    break;
                }else{
                    matrix[2][2] = 'O';
                    return matrix[2][2];
                }
            }
        }while(x==1);
    case 3: //Difícil
        // Chekando se há uma tentativa de Vitória
        // Método de vitória horizontal
        for(i=0;i<3;i++){
            if((matrix[i][0] == 'O' && matrix[i][1] == 'O') && matrix[i][2] == ' '){
                matrix[i][2] = 'O';
                return matrix[i][2];
            }else
                if((matrix[i][0] == 'O' && matrix[i][2] == 'O') && matrix[i][1] == ' '){
                    matrix[i][1] = 'O';
                    return matrix[i][1];
                }else
                    if((matrix[i][1] == 'O' && matrix[i][2] == 'O') && matrix[i][0] == ' '){
                        matrix[i][0] = 'O';
                        return matrix[i][0];
                    }
        }
        //Método de vitória vertical
        for(j=0;j<3;j++){
            if((matrix[0][j] == 'O' && matrix[1][j] == 'O') && matrix[2][j] == ' '){
                matrix[2][j] = 'O';
                return matrix[2][j];
            }else
                if((matrix[0][j] == 'O' && matrix[2][j] == 'O') && matrix[1][j] == ' '){
                    matrix[1][j] = 'O';
                    return matrix[1][j];
                }else
                    if((matrix[1][j] == 'O' && matrix[2][j] == 'O') && matrix[0][j] == ' '){
                        matrix[0][j] = 'O';
                        return matrix[0][j];
                    }
        }
        //Método de vitória 1º diagonal
        if((matrix[0][0] == 'O' && matrix[1][1] == 'O') && matrix[2][2] == ' '){
            matrix[2][2] = 'O';
            return matrix[2][2];
        }else
            if((matrix[0][0] == 'O' && matrix[2][2] == 'O') && matrix[1][1] == ' '){
                matrix[1][1] = 'O';
                return matrix[1][1];
            }else
                if((matrix[1][1] == 'O' && matrix[2][2] == 'O') && matrix[0][0] == ' '){
                    matrix[0][0] = 'O';
                    return matrix[0][0];
                }
        //Método de vitória 2º diagonal
        if((matrix[0][2] == 'O' && matrix[1][1] == 'O') && matrix[2][0] == ' '){
            matrix[2][0] = 'O';
            return matrix[2][0];
        }else
            if((matrix[0][2] == 'O' && matrix[2][0] == 'O') && matrix[1][1] == ' '){
                matrix[1][1] = 'O';
                return matrix[1][1];
            }else
                if((matrix[1][1] == 'O' && matrix[2][0] == 'O') && matrix[0][2] == ' '){
                    matrix[0][2] = 'O';
                    return matrix[0][2];
                }
        //Escaneia a matrix para saber se precisa se defender
        // Método de defesa horizontal
        for(i=0;i<3;i++){
            if((matrix[i][0] == 'X' && matrix[i][1] == 'X') && matrix[i][2] == ' '){
                matrix[i][2] = 'O';
                return matrix[i][2];
            }else
                if((matrix[i][0] == 'X' && matrix[i][2] == 'X') && matrix[i][1] == ' '){
                    matrix[i][1] = 'O';
                    return matrix[i][1];
                }else
                    if((matrix[i][1] == 'X' && matrix[i][2] == 'X') && matrix[i][0] == ' '){
                        matrix[i][0] = 'O';
                        return matrix[i][0];
                    }
        }
        //Método de defesa vertical
        for(j=0;j<3;j++){
            if((matrix[0][j] == 'X' && matrix[1][j] == 'X') && matrix[2][j] == ' '){
                matrix[2][j] = 'O';
                return matrix[2][j];
            }else
                if((matrix[0][j] == 'X' && matrix[2][j] == 'X') && matrix[1][j] == ' '){
                    matrix[1][j] = 'O';
                    return matrix[1][j];
                }else
                    if((matrix[1][j] == 'X' && matrix[2][j] == 'X') && matrix[0][j] == ' '){
                        matrix[0][j] = 'O';
                        return matrix[0][j];
                    }
        }
        //Método de defesa 1º diagonal
        if((matrix[0][0] == 'X' && matrix[1][1] == 'X') && matrix[2][2] == ' '){
            matrix[2][2] = 'O';
            return matrix[2][2];
        }else
            if((matrix[0][0] == 'X' && matrix[2][2] == 'X') && matrix[1][1] == ' '){
                matrix[1][1] = 'O';
                return matrix[1][1];
            }else
                if((matrix[1][1] == 'X' && matrix[2][2] == 'X') && matrix[0][0] == ' '){
                    matrix[0][0] = 'O';
                    return matrix[0][0];
                }
        //Método de defesa 2º diagonal
        if((matrix[0][2] == 'X' && matrix[1][1] == 'X') && matrix[2][0] == ' '){
            matrix[2][0] = 'O';
            return matrix[2][0];
        }else
            if((matrix[0][2] == 'X' && matrix[2][0] == 'X') && matrix[1][1] == ' '){
                matrix[1][1] = 'O';
                return matrix[1][1];
            }else
                if((matrix[1][1] == 'X' && matrix[2][0] == 'X') && matrix[0][2] == ' '){
                    matrix[0][2] = 'O';
                    return matrix[0][2];
                }
        //Último caso
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(matrix[i][j] == ' '){
                    matrix[i][j] = 'O';
                    return matrix[i][j];
                }
            }
        }
    case 4: // Impossível
        switch(num){
        case 0://defesa
            if(x==1){ // só faz uma vez
                if(matrix[1][1]=='X'){
                    matrix[0][0]='O';
                    return matrix[0][0];
                }else{
                    matrix[1][1] = 'O'; //Defesa
                    return matrix[1][1];
                }
            }
            // Chekando se há uma tentativa de Vitória
            // Método de vitória horizontal
            for(i=0;i<3;i++){
                if((matrix[i][0] == 'O' && matrix[i][1] == 'O') && matrix[i][2] == ' '){
                    matrix[i][2] = 'O';
                    return matrix[i][2];
                }else
                    if((matrix[i][0] == 'O' && matrix[i][2] == 'O') && matrix[i][1] == ' '){
                        matrix[i][1] = 'O';
                        return matrix[i][1];
                    }else
                        if((matrix[i][1] == 'O' && matrix[i][2] == 'O') && matrix[i][0] == ' '){
                            matrix[i][0] = 'O';
                            return matrix[i][0];
                        }
            }
            //Método de vitória vertical
            for(j=0;j<3;j++){
                if((matrix[0][j] == 'O' && matrix[1][j] == 'O') && matrix[2][j] == ' '){
                    matrix[2][j] = 'O';
                    return matrix[2][j];
                }else
                    if((matrix[0][j] == 'O' && matrix[2][j] == 'O') && matrix[1][j] == ' '){
                        matrix[1][j] = 'O';
                        return matrix[1][j];
                    }else
                        if((matrix[1][j] == 'O' && matrix[2][j] == 'O') && matrix[0][j] == ' '){
                            matrix[0][j] = 'O';
                            return matrix[0][j];
                        }
            }
            //Método de vitória 1º diagonal
            if((matrix[0][0] == 'O' && matrix[1][1] == 'O') && matrix[2][2] == ' '){
                matrix[2][2] = 'O';
                return matrix[2][2];
            }else
                if((matrix[0][0] == 'O' && matrix[2][2] == 'O') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'O' && matrix[2][2] == 'O') && matrix[0][0] == ' '){
                        matrix[0][0] = 'O';
                        return matrix[0][0];
                    }
            //Método de vitória 2º diagonal
            if((matrix[0][2] == 'O' && matrix[1][1] == 'O') && matrix[2][0] == ' '){
                matrix[2][0] = 'O';
                return matrix[2][0];
            }else
                if((matrix[0][2] == 'O' && matrix[2][0] == 'O') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'O' && matrix[2][0] == 'O') && matrix[0][2] == ' '){
                        matrix[0][2] = 'O';
                        return matrix[0][2];
                    }
            //Escaneia a matrix para saber se precisa se defender
            // Método de defesa horizontal
            for(i=0;i<3;i++){
                if((matrix[i][0] == 'X' && matrix[i][1] == 'X') && matrix[i][2] == ' '){
                    matrix[i][2] = 'O';
                    return matrix[i][2];
                }else
                    if((matrix[i][0] == 'X' && matrix[i][2] == 'X') && matrix[i][1] == ' '){
                        matrix[i][1] = 'O';
                        return matrix[i][1];
                    }else
                        if((matrix[i][1] == 'X' && matrix[i][2] == 'X') && matrix[i][0] == ' '){
                            matrix[i][0] = 'O';
                            return matrix[i][0];
                        }
            }
            //Método de defesa vertical
            for(j=0;j<3;j++){
                if((matrix[0][j] == 'X' && matrix[1][j] == 'X') && matrix[2][j] == ' '){
                    matrix[2][j] = 'O';
                    return matrix[2][j];
                }else
                    if((matrix[0][j] == 'X' && matrix[2][j] == 'X') && matrix[1][j] == ' '){
                        matrix[1][j] = 'O';
                        return matrix[1][j];
                    }else
                        if((matrix[1][j] == 'X' && matrix[2][j] == 'X') && matrix[0][j] == ' '){
                            matrix[0][j] = 'O';
                            return matrix[0][j];
                        }
            }
            //Método de defesa 1º diagonal
            if((matrix[0][0] == 'X' && matrix[1][1] == 'X') && matrix[2][2] == ' '){
                matrix[2][2] = 'O';
                return matrix[2][2];
            }else
                if((matrix[0][0] == 'X' && matrix[2][2] == 'X') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'X' && matrix[2][2] == 'X') && matrix[0][0] == ' '){
                        matrix[0][0] = 'O';
                        return matrix[0][0];
                    }
            //Método de defesa 2º diagonal
            if((matrix[0][2] == 'X' && matrix[1][1] == 'X') && matrix[2][0] == ' '){
                matrix[2][0] = 'O';
                return matrix[2][0];
            }else
                if((matrix[0][2] == 'X' && matrix[2][0] == 'X') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'X' && matrix[2][0] == 'X') && matrix[0][2] == ' '){
                        matrix[0][2] = 'O';
                        return matrix[0][2];
                    }

            //Ataque Fulminante
            if((matrix[0][0] == 'X' && matrix[2][2] == 'X') || (matrix[0][2] == 'X' && matrix[2][0] == 'X')){
                if(matrix[1][0] == ' '){
                    matrix[1][0] = 'O';
                    return matrix[1][0];
                }
            }
            // Ataque alternativo
            if((matrix[1][0] == 'X' || matrix[2][1] == 'X') && matrix[0][2] == 'X'){
                if(matrix[2][0] == ' '){
                    matrix[2][0] = 'O';
                    piriz = 1;
                    return matrix[2][0];
                }
            }else
                if((matrix[1][2] == 'X' || matrix[2][1] == 'X') && matrix[0][0] == 'X'){
                    if(matrix[2][2] == ' '){
                        matrix[2][2] = 'O';
                        piriz = 2;
                        return matrix[2][2];
                    }
                }else
                    if((matrix[1][2] == 'X' || matrix[0][1] == 'X') && matrix[2][0] == 'X'){
                        if(matrix[0][2] == ' '){
                            matrix[0][2] = 'O';
                            piriz = 3;
                            return matrix[0][2];
                        }
                    }else
                        if((matrix[1][0] == 'X' || matrix[0][1] == 'X') && matrix[2][2] == 'X'){
                            if(matrix[0][0] == ' '){
                                matrix[0][0] = 'O';
                                piriz = 4;
                                return matrix[0][0];
                            }
                        }
            switch(piriz){
            case 1:
                if(matrix[0][0] == ' '){
                    matrix[0][0] =  'O';
                    return matrix[0][0];
                }else{
                    matrix[2][2] = 'O';
                    return matrix[2][2];
                }
            case 2:
                if(matrix[0][2] == ' '){
                    matrix[0][2] =  'O';
                    return matrix[0][2];
                }else{
                    matrix[2][0] = 'O';
                    return matrix[2][0];
                }
            case 3:
                if(matrix[2][2] == ' '){
                    matrix[2][2] =  'O';
                    return matrix[2][2];
                }else{
                    matrix[0][0] = 'O';
                    return matrix[0][0];
                }
            case 4:
                if(matrix[2][0] == ' '){
                    matrix[2][0] =  'O';
                    return matrix[2][0];
                }else{
                    matrix[0][2] = 'O';
                    return matrix[0][2];
                }
            }
            if(matrix[1][1] == 'X' && matrix[2][2] == 'X' && matrix[0][2] == ' '){
                matrix[0][2] = 'O';
                return matrix[0][2];
            }
             //Último caso
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(matrix[i][j] == ' '){
                        matrix[i][j] = 'O';
                        return matrix[i][j];
                    }
                }
            }
        case 1://ataque
            if(x<3){
                if(x==1 && matrix[2][2] == ' '){ //Realiza apenas umas vez
                    matrix[2][2] = 'O';
                    return matrix[2][2];
                }else
                    if(x==2 && matrix[0][0] == 'X'){ // Movimento de triangulação
                        matrix[1][1] = 'O';
                        n = 2;
                        return matrix[1][1];
                    }else{ // Jogada especial
                        matrix[0][1] = 'O';
                        n=1;
                        return matrix[0][1];
                    }
            }
            // Chekando se há uma tentativa de Vitória
            // Método de vitória horizontal
            for(i=0;i<3;i++){
                if((matrix[i][0] == 'O' && matrix[i][1] == 'O') && matrix[i][2] == ' '){
                    matrix[i][2] = 'O';
                    return matrix[i][2];
                }else
                    if((matrix[i][0] == 'O' && matrix[i][2] == 'O') && matrix[i][1] == ' '){
                        matrix[i][1] = 'O';
                        return matrix[i][1];
                    }else
                        if((matrix[i][1] == 'O' && matrix[i][2] == 'O') && matrix[i][0] == ' '){
                            matrix[i][0] = 'O';
                            return matrix[i][0];
                        }
            }
            //Método de vitória vertical
            for(j=0;j<3;j++){
                if((matrix[0][j] == 'O' && matrix[1][j] == 'O') && matrix[2][j] == ' '){
                    matrix[2][j] = 'O';
                    return matrix[2][j];
                }else
                    if((matrix[0][j] == 'O' && matrix[2][j] == 'O') && matrix[1][j] == ' '){
                        matrix[1][j] = 'O';
                        return matrix[1][j];
                    }else
                        if((matrix[1][j] == 'O' && matrix[2][j] == 'O') && matrix[0][j] == ' '){
                            matrix[0][j] = 'O';
                            return matrix[0][j];
                        }
            }
            //Método de vitória 1º diagonal
            if((matrix[0][0] == 'O' && matrix[1][1] == 'O') && matrix[2][2] == ' '){
                matrix[2][2] = 'O';
                return matrix[2][2];
            }else
                if((matrix[0][0] == 'O' && matrix[2][2] == 'O') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'O' && matrix[2][2] == 'O') && matrix[0][0] == ' '){
                        matrix[0][0] = 'O';
                        return matrix[0][0];
                    }
            //Método de vitória 2º diagonal
            if((matrix[0][2] == 'O' && matrix[1][1] == 'O') && matrix[2][0] == ' '){
                matrix[2][0] = 'O';
                return matrix[2][0];
            }else
                if((matrix[0][2] == 'O' && matrix[2][0] == 'O') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'O' && matrix[2][0] == 'O') && matrix[0][2] == ' '){
                        matrix[0][2] = 'O';
                        return matrix[0][2];
                    }
            //Escaneia a matrix para saber se precisa se defender
            // Método de defesa horizontal
            for(i=0;i<3;i++){
                if((matrix[i][0] == 'X' && matrix[i][1] == 'X') && matrix[i][2] == ' '){
                    matrix[i][2] = 'O';
                    cont = 1;
                    return matrix[i][2];
                }else
                    if((matrix[i][0] == 'X' && matrix[i][2] == 'X') && matrix[i][1] == ' '){
                        matrix[i][1] = 'O';
                        cont = 1;
                        return matrix[i][1];
                    }else
                        if((matrix[i][1] == 'X' && matrix[i][2] == 'X') && matrix[i][0] == ' '){
                            matrix[i][0] = 'O';
                            cont = 1;
                            return matrix[i][0];
                        }
            }
            //Método de defesa vertical
            for(j=0;j<3;j++){
                if((matrix[0][j] == 'X' && matrix[1][j] == 'X') && matrix[2][j] == ' '){
                    matrix[2][j] = 'O';
                    cont = 1;
                    return matrix[2][j];
                }else
                    if((matrix[0][j] == 'X' && matrix[2][j] == 'X') && matrix[1][j] == ' '){
                        matrix[1][j] = 'O';
                        cont = 1;
                        return matrix[1][j];
                    }else
                        if((matrix[1][j] == 'X' && matrix[2][j] == 'X') && matrix[0][j] == ' '){
                            matrix[0][j] = 'O';
                            cont = 1;
                            return matrix[0][j];
                        }
            }
            //Método de defesa 1º diagonal
            if((matrix[0][0] == 'X' && matrix[1][1] == 'X') && matrix[2][2] == ' '){
                matrix[2][2] = 'O';
                cont = 1;
                return matrix[2][2];
            }else
                if((matrix[0][0] == 'X' && matrix[2][2] == 'X') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    cont = 1;
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'X' && matrix[2][2] == 'X') && matrix[0][0] == ' '){
                        matrix[0][0] = 'O';
                        cont = 1;
                        return matrix[0][0];
                    }
            //Método de defesa 2º diagonal
            if((matrix[0][2] == 'X' && matrix[1][1] == 'X') && matrix[2][0] == ' '){
                matrix[2][0] = 'O';
                cont = 1;
                return matrix[2][0];
            }else
                if((matrix[0][2] == 'X' && matrix[2][0] == 'X') && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    cont = 1;
                    return matrix[1][1];
                }else
                    if((matrix[1][1] == 'X' && matrix[2][0] == 'X') && matrix[0][2] == ' '){
                        matrix[0][2] = 'O';
                        cont = 1;
                        return matrix[0][2];
                    }
            }
        //Ataque Fulminante
            if(n==1){ // Ataque especial
                n = 3;
                matrix[0][0] = 'O';
                return matrix[0][0];
            }
            if(n==2 && matrix[0][2] == ' '){ // Ataque Ninja
                matrix[0][2] = 'O';
                return matrix[0][2];
            }else
                if(n==2 && matrix[2][0] == ' '){
                    matrix[2][0] = 'O';
                    return matrix[2][0];
                }
            if(n==3){
                matrix[1][0] = 'O';
                return matrix[1][0];
            }
            if(cont==0){ // Ataque alternativo
                if(matrix[0][0] == 'X' && matrix[1][1] == ' '){
                    matrix[1][1] = 'O';
                    return matrix[1][1];
                }
                if(matrix[0][2] == ' '){
                    matrix[0][2] = 'O';
                    return matrix[0][2];
                }
            }
            if(matrix[1][0] == 'X' && matrix[0][2] == 'X' && matrix[1][1] == ' '){ // Edmar Wins
                matrix[1][1] = 'O';
                return matrix[1][1];
            }
        //Último caso
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(matrix[i][j] == ' '){
                        matrix[i][j] = 'O';
                        return matrix[i][j];
                    }
                }
            }
        case 5:
            printf("\n\nÉ a vez do(a) %s\n\n", nome2);
            printf("Digite o número do quadrante a ser jogado<1...9>:");
            scanf("%d", &o);
            while((o<1 || o>9)){
                printf("Por favor, digite uma posição válida\n");
                printf("Digite o número do quadrante a ser jogado<1...9>: ");
                scanf("%d", &o);
            }
            do{
                switch(o){
                case 1:
                    if(matrix[0][0] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[0][0] = 'O';
                        return matrix[0][0];
                    }
                case 2:
                    if(matrix[0][1] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[0][1] = 'O';
                        return matrix[0][1];
                    }
                case 3:
                    if(matrix[0][2] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[0][2] = 'O';
                        return matrix[0][2];
                    }
                case 4:
                    if(matrix[1][0] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[1][0] = 'O';
                        return matrix[1][0];
                    }
                case 5:
                    if(matrix[1][1] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[1][1] = 'O';
                        return matrix[1][1];
                    }
                case 6:
                    if(matrix[1][2] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[1][2] = 'O';
                        return matrix[1][2];
                    }
                case 7:
                    if(matrix[2][0] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[2][0] = 'O';
                        return matrix[2][0];
                    }
                case 8:
                    if(matrix[2][1] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[2][1] = 'O';
                        return matrix[2][1];
                    }
                case 9:
                    if(matrix[2][2] != ' '){
                        do{
                            printf("Por favor, digite uma posição válida\n");
                            printf("Digite o número do quadrante a ser jogado<1...9>: ");
                            scanf("%d", &o);
                        }while(o<1 || o>9);
                        x = 1;
                        break;
                    }else{
                        matrix[2][2] = 'O';
                        return matrix[2][2];
                    }
                }
            }while(x==1);
    }
}
void disp_matrix(void){ //Mostra a matrix na tela
    int t;
    for(t=0;t<3;t++){
        printf("\t\t\t\t %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
        if(t!=2) printf("\n\t\t\t\t---|---|---\n");
    }
    printf("\n");
}
char check(void){ //Verifica se há um vencedor
    int i,j,cont=0;
    for(i=0;i<3;i++){ // Verifica as linhas
        if(matrix[i][0]==matrix[i][1] && matrix[i][1]==matrix[i][2]) return matrix[i][0];
    }
    for(i=0;i<3;i++){ // Verifica as colunas
        if(matrix[0][i]==matrix[1][i] && matrix[1][i]==matrix[2][i]) return matrix[0][i];
    } //Verifica as Diagonais
    if(matrix[0][0]==matrix[1][1] && matrix[1][1]==matrix[2][2]) return matrix[0][0];
    if(matrix[0][2]==matrix[1][1] && matrix[1][1]==matrix[2][0]) return matrix[0][2];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(matrix[i][j] != ' '){
                cont++;
            }
        }

    }
    if(cont == 9){
        return ('E');
    }
    return ' ';
}
void desenho(){
     printf("\n\n\n\t\t\t0000000000000000000000000000\n\t\t\t000000000__________000000000\n\t\t\t000000________________000000\n\t\t\t0000____________________0000\n\t\t\t000_____00________00_____000\n\t\t\t00_____0000______0000_____00\n\t\t\t00_____0000______0000_____00\n\t\t\t00______00________00______00\n\t\t\t00________________________00\n\t\t\t00______0__________0______00\n\t\t\t000______00______00______000\n\t\t\t0000_______000000_______0000\n\t\t\t000000________________000000\n\t\t\t000000000___________00000000\n\t\t\t0000000000000000000000000000\n");
}
void desenho2(){
     printf("\n\t\t\t´´´¶¶¶¶´´´´´´´´´´s¶¶¶¶¶´´´´´´´´´´´s¶¶¶\n\t\t\t´´´´¶¶¶¶¢´´´´´7¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´´´´¶¶¶¶\n\t\t\t´´´7¶¶¶¶¢´´´¢¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´´´´s¶¶¶¶s\n\t\t\t´´¶¶¶¶¶¶¶¶´ø¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶1´¶¶¶¶¶¶¶¶\n\t\t\t´´¢øs$¶¶¶¶1¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶´¶¶¶¶¢¢$$\n\t\t\t´´´´´´´´7¢ø¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶s´ø\n\t\t\t´´´´´´´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶\n\t\t\t´´´´´´´´´´1¶¶¶¶ø´´7¶¶¶¶¶1´ø¶¶¶¶¶s\n\t\t\t´´´´´´´´´´´¶¶´´´´´´´¶¶¶´´´´´´s¶¶\n\t\t\t´´´´´´´´´´1¶¶´´´´´´$¶¶¶1´´´´´´¶¶1\n\t\t\t´´´´´´´´´´´¶¶¶´´s¶¶¶´´ø¶¶s´´¶¶¶¶\n\t\t\t´´´´´´´´´´´7¶¶¶¶¶¶¶¶´´´¶¶¶¶¶¶¶¶1\n\t\t\t´´´´´´´´´´´´´¶¶¶¶¶¶¶s$s¶¶¶¶¶¶\n\t\t\t´´´´´´´´´´´ø¶´¶s¶¶¶¶¶¶¶¶¶¶¶´¶´¶s\n\t\t\t´´´´7´´´´$¶¶¶´¶´´´´´´´´´´´$´¶¶¶¶¶\n\t\t\t´1¶¶¶¶¶¶¶¶¶¶ø´¶´¶¶$¶¶$¶¶$¶7¶1´¶¶¶¶¶¶¶¶¶¶¶\n\t\t\t´´¶¶¶¶¶¶¶¶´´´´¶¶¶¶¶¶¶¶¶¶¶¶¶¶1´´´¶¶¶¶¶¶¶¶¶\n\t\t\t´´´ø¶¶¶¶¶´´´´´´1¶¶¶¶¶¶¶¶¶¶¢´´´´´´¶¶¶¶¶¶¶\n\t\t\t´´´´´s¶¶ø´´´´´´´´´$¶¶¶¶¶s´´´´´´´´1¶¶¶\n");
}

void musica(void){ //Vinheta do Mario
    int i = 90, j = 10;
    Beep(660,100-j);Sleep(150-i); //Beep que faz a emissão do som e Sleep para esperar um tempo para o outro som ser emitido.
    Beep(660,100-j);Sleep(300-i);
    Beep(660,100-j);Sleep( 300-i);
    Beep(510,100-j);Sleep( 100-i);
    Beep(660,100-j);Sleep( 300-i);
    Beep(770,100-j);Sleep( 550-i);
    Beep(380,100-j);Sleep( 575-i);
    Beep(510,100-j);Sleep( 450-i);
    Beep(380,100-j);Sleep( 400-i);
    Beep(320,100-j);Sleep( 500-i);
    Beep(440,100-j);Sleep( 300-i);
    Beep(480,80-j);Sleep( 330-i);
    Beep(450,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 200-i);
    Beep(660,80-j);Sleep( 200-i);
    Beep(760,50-j);Sleep( 150-i);
    Beep(860,100-j);Sleep( 300-i);
    Beep(700,80-j);Sleep( 150-i);
    Beep(760,50-j);Sleep( 350-i);
    Beep(660,80-j);Sleep( 300-i);
    Beep(520,80-j);Sleep( 150-i);
    Beep(580,80-j);Sleep( 150-i);
    Beep(480,80-j);Sleep( 500-i);
    Beep(510,100-j);Sleep( 450-i);
    Beep(380,100-j);Sleep( 400-i);
    Beep(320,100-j);Sleep( 500-i);
    Beep(440,100-j);Sleep( 300-i);
    Beep(480,80-j);Sleep( 330-i);
    Beep(450,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 200-i);
    Beep(660,80-j);Sleep( 200-i);
    Beep(760,50-j);Sleep( 150-i);
    Beep(860,100-j);Sleep( 300-i);
    Beep(700,80-j);Sleep( 150-i);
    Beep(760,50-j);Sleep( 350-i);
    Beep(660,80-j);Sleep( 300-i);
    Beep(520,80-j);Sleep( 150-i);
    Beep(580,80-j);Sleep( 150-i);
    Beep(480,80-j);Sleep( 500-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,150-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 100-i);
    Beep(570,100-j);Sleep( 220-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,200-j);Sleep( 300-i);
    Beep(1020,80-j);Sleep( 300-i);
    Beep(1020,80-j);Sleep( 150-i);
    Beep(1020,80-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 300-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,150-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep(150-i);
    Beep(500,100-j);Sleep(300-i);
    Beep(430,100-j);Sleep(150-i);
    Beep(500,100-j);Sleep( 100-i);
    Beep(570,100-j);Sleep(420-i);
    Beep(585,100-j);Sleep(450-i);
    Beep(550,100-j);Sleep( 420-i);
    Beep(500,100-j);Sleep(360-i);
    Beep(380,100-j);Sleep(300-i);
    Beep(500,100-j);Sleep(300-i);
    Beep(500,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep(300-i);
    Beep(500,100-j);Sleep(300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,150-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 100-i);
    Beep(570,100-j);Sleep( 220-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,200-j);Sleep( 300-i);
    Beep(1020,80-j);Sleep( 300-i);
    Beep(1020,80-j);Sleep( 150-i);
    Beep(1020,80-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 300-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(760,100-j);Sleep( 100-i);
    Beep(720,100-j);Sleep( 150-i);
    Beep(680,100-j);Sleep( 150-i);
    Beep(620,150-j);Sleep( 300-i);
    Beep(650,150-j);Sleep( 300-i);
    Beep(380,100-j);Sleep( 150-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(430,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 100-i);
    Beep(570,100-j);Sleep( 420-i);
    Beep(585,100-j);Sleep( 450-i);
    Beep(550,100-j);Sleep( 420-i);
    Beep(500,100-j);Sleep( 360-i);
    Beep(380,100-j);Sleep( 300-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(500,100-j);Sleep( 150-i);
    Beep(500,100-j);Sleep( 300-i);
    Beep(500,60-j);Sleep( 150-i);
    Beep(500,80-j);Sleep( 300-i);
    Beep(500,60-j);Sleep( 350-i);
    Beep(500,80-j);Sleep( 150-i);
    Beep(580,80-j);Sleep( 350-i);
    Beep(660,80-j);Sleep( 150-i);
    Beep(500,80-j);Sleep( 300-i);
    Beep(430,80-j);Sleep( 150-i);
    Beep(380,80-j);Sleep( 600-i);
    Beep(500,60-j);Sleep( 150-i);
    Beep(500,80-j);Sleep( 300-i);
    Beep(500,60-j);Sleep( 350-i);
    Beep(500,80-j);Sleep( 150-i);
    Beep(580,80-j);Sleep( 150-i);
    Beep(660,80-j);Sleep( 550-i);
    Beep(870,80-j);Sleep( 325-i);
    Beep(760,80-j);Sleep( 600-i);
    Beep(500,60-j);Sleep( 150-i);
    Beep(500,80-j);Sleep( 300-i);
    Beep(500,60-j);Sleep( 350-i);
    Beep(500,80-j);Sleep( 150-i);
    Beep(580,80-j);Sleep( 350-i);
    Beep(660,80-j);Sleep( 150-i);
    Beep(500,80-j);Sleep( 300-i);
    Beep(430,80-j);Sleep( 150-i);
    Beep(380,80-j);Sleep( 600-i);
    Beep(660,100-j);Sleep( 150-i);
    Beep(660,100-j);Sleep( 300-i);
    Beep(660,100-j);Sleep( 300-i);
    Beep(510,100-j);Sleep( 100-i);
    Beep(660,100-j);Sleep( 300-i);
    Beep(770,100-j);Sleep( 550-i);
    Beep(380,100-j);Sleep( 575-i);
}
