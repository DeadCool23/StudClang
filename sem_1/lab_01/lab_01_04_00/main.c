#include <stdio.h>

#define BOTTLE_PRICE 45 //Стоимость бутылки воды
#define EMPTY_BOTTLE_PRICE 20 //Цена за пустую бутылку
/*Программа считает макс кол-во бутылок, которое
можно купить по определенному правилу*/ 
int main(void)
{
    int cent;
    printf("Input number of cent: ");
    scanf("%d", &cent);

    int num = (cent - EMPTY_BOTTLE_PRICE) / (BOTTLE_PRICE - EMPTY_BOTTLE_PRICE); //Поиск кол-ва бутылок по выделенной формуле
    printf("Bottle count = %d", num);
}
