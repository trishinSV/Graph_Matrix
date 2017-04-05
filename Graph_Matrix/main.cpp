//
//  main.cpp
//  Graph_Matrix
//
//  Created by Сергей Тришин on 05.04.17.
//  Copyright © 2017 Сергей Тришин. All rights reserved.
//

#include <iostream>
#define SIZE 3
// из графа удалить все все всершины, из которых недостижима заданная

int graph[SIZE][SIZE]={
		  1, 1, 0
        , 0, 1, 1
        , 0, 0, 1
};

void DeleteNode(int Node) // занулить всю строку i
{
    printf("Обнуляем переходы из вершины : %d\n", Node);
    int k;
    for(k = 0 ; k<3; k++)
        graph[Node][k] = 0;
    return;
}

int DeleteUnreacheable(int NodeNumber) // удалить вершины недостижимые из вершины NodeNumber
{
    int i;
    int Counter = 0;
    for(i = 0 ; i<3; i++)
        if(graph[i][NodeNumber] == 0)  // вершина не имеет перехода в анализируемую вершину
        {
            DeleteNode(i);
            Counter ++;
        }
    
    return Counter;
}



void print_graph()
{
    printf("-------------------\n");
    int i, j;
    for(i = 0; i < 3 ; i++){
        for(j = 0; j < 3; j++){
            printf(" %d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    
    int vertex;
    
    print_graph();
    
    std:: cout << "Введите вершину: ";
    std:: cin >> vertex;
    printf("Удалено : %d вершин\n", DeleteUnreacheable(vertex));
    
    print_graph();
    
    getchar();
    return 0;
}


