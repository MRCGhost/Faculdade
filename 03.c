/*
    Autor: Mateus Rigon Cichelero
    3) Um colecionador de carros contratou você para desenvolver um programa para calcular o
valor do IPVA (Imposto sobre a Propriedade de Veículos Automotores) dos seus veículos. Após
aceitar o desafio, você buscou saber como é calculado o valor do IPVA e chegou às seguintes
informações:
        • O valor do imposto é de 3% do veículo;
        • O valor pode ter desconto conforme o mês de pagamento, sendo:
        Ø 15% se o pagamento for realizado em dezembro;
        Ø 10% se o pagamento for realizado em janeiro;
        Ø 6% se o pagamento for realizado em fevereiro;
        Ø 3% se o pagamento for realizado em março;
        • Há desconto de 15% para bons motoristas (que não tiveram multa no último ano);
        • Há desconto de 5% para participantes do programa Bom Cidadão (nota fiscal gaúcha);
        • Veículos com 20 anos ou mais são isentos de pagamento do imposto;
    Sabendo disso, desenvolva um programa em C para realizar o cálculo do IPVA de um veículo.
O programa deve solicitar ao usuário os seguintes dados:
        • Marca do veículo;
        • Modelo do veículo;
        • Ano de fabricação do veículo;
        • Valor do veículo;
    O programa também deve solicitar ao usuário as seguintes informações:
        • Se é participante do programa Bom Cidadão;
        • Se não teve multas no último ano; e
        • Qual o mês que pretende pagar o imposto (dezembro a março);
    Ao final da execução, o programa deve apresentar os dados do veículo, qual a porcentagem
de desconto obtido e o valor do imposto a ser pago.

*/

#include <stdio.h>

int main(void){

    const dataano = 2023;

    char marca [50];
    char modelo [50];
    int ano, bomcid_opc, bomcid, multas_opc, multas, mes_opc, mes, desconto;
    float valor, imposto, impostodesc, impostototal;

    printf(" Qual a marca do veiculo?\n");
    scanf("%s", &marca);
    printf("\n Qual o modelo do veiculo?\n");
    scanf("%s", &modelo);
    printf("\n Qual o ano de fabricacao do veiculo?\n");
    scanf("%d", &ano);
    printf("\n Qual o valor do veiculo?\n");
    scanf("%f", &valor);

    if(ano + 20 <= dataano){
        printf("\n \n Dados do veiculo:\n Marca: %s\n Modelo: %s\n Ano de fabricacao: %d\n Valor do veiculo: %f", marca, modelo, ano, valor);
        printf("\n \n Veiculo isento de impostos!");
    }
    else{
        printf("\n Voce eh participante do programa Bom Cidadao?\n Para sim, digite 1\n para nao, digite 0\n ");
        scanf("%d", &bomcid_opc);
        printf("\n Voce teve multas no ultimo ano?\n Para sim, digite 1\n Para nao, digite 0\n ");
        scanf("%d", &multas_opc);
        printf("\n Qual o mes que voce deseja pagar o imposto?\n 1 - Dezembro\n 2 - Janeiro\n 3 - Fevereiro\n 4 - Marco\n ");
        scanf("%d", &mes_opc);

        switch(bomcid_opc){
        case 0:
            bomcid = 0;
            break;
        case 1:
            bomcid = 5;
            break;
        default:
            printf("\n Resposta Bom cidadao invalido!");
            break;
        }

        switch(multas_opc){
        case 0:
            multas = 15;
            break;
        case 1:
            multas = 0;
            break;
        default:
            printf("\n Resposta de multas invalido!");
            break;
        }

        switch(mes_opc){
        case 1:
            mes = 15;
            break;
        case 2:
            mes = 10;
            break;
        case 3:
            mes = 6;
            break;
        case 4:
            mes = 3;
            break;
        default:
            printf("\n Mes de pagamento invalido!");
            break;
        }

        desconto = bomcid + multas + mes;
        imposto = (valor / 100.0) * 3;
        impostodesc = (imposto / 100.0) * desconto;
        impostototal = imposto - impostodesc;
        

        printf("\n \n Dados do veiculo:\n Marca: %s\n Modelo: %s\n Ano de fabricacao: %d\n Valor do veiculo: %f", marca, modelo, ano, valor);
        printf("\n \n Descontos:\n Bom Cidadao: %d %%\n Bons Motoristas: %d %%\n Mes de pagamento: %d %%\n Desconto total: %d %%\n", bomcid, multas, mes, desconto);
        printf("\n Valor do imposto a ser pago: %f", impostototal);
    }

    printf("\n \n \n Fim do Programa!");

    return 0;

}


