#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
// Структура для представления списка смежности узла
struct AdjListNode
{
    int dest;
    int num;
    struct AdjListNode* next;
};

// Структура для представления списка смежности
struct AdjList
{
    struct AdjListNode *head; // указатель на головной узел списка
};

// Структура для представления графа. Граф представляет собой массив из
// Размер массива будет V (число вершин в графе)
struct Graph
{
    int V;
    struct AdjList* array;
};

// вспомогательная функция для создания узла нового списка смежности
struct AdjListNode* newAdjListNode(int dest,int num)
{
    struct AdjListNode* newNode =
    (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->num= num;
    newNode->next = NULL;
    return newNode;
}

// Служебная функция, которая создает граф с V вершинами
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;

    // Создание массива списков смежности. Размер массива будет V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));

    // Инициализация каждого списка смежности как пустого, сделав начало=
    int i;
    for (i = 0; i < V; ++i)
    graph->array[i].head = NULL;

    return graph;
}

//Добавляет ребро неориентированного графа
void addEdge(struct Graph* graph, int src, int dest,int num)
{
    // Добавляет ребро из src в построение. Новый узел добавляется в список

    // Список src.Узел добавляется в начале
    struct AdjListNode* newNode = newAdjListNode(dest,num);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Поскольку граф неориентированный, также добавим ребро от Dest в SRC
    newNode = newAdjListNode(src,num);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Вершина %d\n имеет связь ", v);

        while (pCrawl)
        {
            if(pCrawl->dest>0 && pCrawl->dest<10000)
                if(pCrawl->num != 0)
                     printf("-> %d(%d)", pCrawl->dest,pCrawl->num);
        pCrawl = pCrawl->next;
    }
    printf("\n");
}
}

void DeleteNode(struct Graph* graph,int num){
    for(int i=0;i<graph->V;++i){
        struct AdjListNode* pCrawl = graph->array[i].head;
        if(i+1<graph->V){
            struct AdjListNode* pCrawl1= graph->array[i+1].head;
        }
        while(pCrawl){
            if(pCrawl->num==num){
                free(pCrawl);
                pCrawl=pCrawl;
                }
            pCrawl=pCrawl->next;
        }
    }
}

void DeleteVertex(struct Graph* graph,int dest){
    for(int i=0;i<graph->V;++i){
        struct AdjListNode* pCrawl = graph->array[i].head;
        if(i+1<graph->V){
            struct AdjListNode* pCrawl1= graph->array[i+1].head;
        }
        if (i == dest)
        {
            free(pCrawl);
        }
        while(pCrawl){
            if(pCrawl->dest==dest){
                free(pCrawl);
                pCrawl=pCrawl;
                }
            pCrawl=pCrawl->next;
        }
    }
}

void Matrix(struct Graph* graph)
{
    int matrix[7][7];
    int v;
    for(int i = 0; i < 7; ++i)
        for(int j = 0; j < 7; ++j)
            matrix[i][j] = 0;
    for (v = 0; v < graph->V; v++)
    {
        struct AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl)
        {
            if(pCrawl->dest>0 && pCrawl->dest<10000)
            {
                matrix[v][pCrawl->dest] = 1;
                matrix[pCrawl->dest][v] = 1;
            }
            else
            {
                matrix[v][pCrawl->dest] = 0;
                matrix[pCrawl->dest][v] = 0;
            }
        pCrawl = pCrawl->next;
        }
    }
    printf("  0 1 2 3 4 5 6\n");
    for(int i = 0; i < v; ++i)
    {
         printf("%d ", i);
        for(int j = 0; j < v; ++j)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

    // вызов фунцкий в main
int main()
{
    // создать граф, согласно сазданнй выше фигуре
    int V = 7, choose = 0, cycle = 1;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1,5);
    addEdge(graph, 0, 2,8);
    addEdge(graph, 1, 5,9);
    addEdge(graph, 1, 3,12);
    addEdge(graph, 2, 4,8);
    addEdge(graph, 2, 5,4);
    addEdge(graph, 2, 6,2);
    addEdge(graph, 3, 4,3);
    addEdge(graph, 3, 5,6);
    addEdge(graph, 4, 6,7);
    struct Graph* graph_t = createGraph(V);
    addEdge(graph_t, 0, 1,5);
    addEdge(graph_t, 0, 2,8);
    addEdge(graph_t, 1, 5,9);
    addEdge(graph_t, 1, 3,12);
    addEdge(graph_t, 2, 4,8);
    addEdge(graph_t, 2, 5,4);
    addEdge(graph_t, 2, 6,2);
    addEdge(graph_t, 3, 4,3);
    addEdge(graph_t, 3, 5,6);
    addEdge(graph_t, 4, 6,7);
    printf("---------------");
    printGraph(graph);
    printf("---------------\n");
    Matrix(graph);
    printf("---------------");
    DeleteNode(graph, 8);
    printf("---------------");
    printGraph(graph);
    printf("---------------\n");
//    DeleteVertex(graph_t, 5);
//    printf("---------------");
//    printGraph(graph_t);
//    printf("---------------");

}
