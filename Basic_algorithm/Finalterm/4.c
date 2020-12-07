#include <stdio.h>

#define MAX_SIZE 100

typedef struct Bag
{
    int weight;
    int benefit;
}Bag;

int size, num;

int bag = 0;
int value = 0;

Bag goods[MAX_SIZE];

void packing(int i)
{
    if (i == num)
        return;

    if (size >= goods[i].weight + bag)
    {
        value += goods[i].benefit;
        bag += goods[i].weight;

        packing(i + 1);
    }
    else
    {
        value += goods[i].benefit * (size - bag) / goods[i].weight;
        return;
    }
}

void sort()
{
    int i, j;
    Bag temp;
    for (i = 0; i < num; i++)
        for (j = i + 1; j < num; j++)
        {
            if (goods[i].benefit / goods[i].weight < goods[j].benefit / goods[j].weight)
            {
                temp = goods[i];
                goods[i] = goods[j];
                goods[j] = temp;
            }
        }
}

int main()
{
    int i;

    scanf("%d", &size);
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        scanf("%d%d", &goods[i].weight, &goods[i].benefit);
    }

    sort();
    packing(0);

    printf("%d", value);

    return 0;
}
