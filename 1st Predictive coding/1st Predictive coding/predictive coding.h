#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP_CONNECT_NUM 3
#define SUB_CONNECT_NUM 3

//非全连接版本
//typedef struct neuron
//{
//	struct neuron* upNeu[UP_CONNECT_NUM];
//	int upConNum;
//	struct neuron* subNeu[SUB_CONNECT_NUM];
//	float weight[SUB_CONNECT_NUM];
//	struct e_neuron* eNeu;
//	float val;
//
//}neuron;
//
//typedef struct e_neuron
//{
//	struct neuron* upENeu[SUB_CONNECT_NUM];
//	int upConNum;
//	struct neuron* subENeu[UP_CONNECT_NUM];
//	float weight[UP_CONNECT_NUM];
//	struct e_neuron* neu;
//	float val;
//
//}e_neuron;

//非全连接版本
//void genTopNeu(int nums) {
//
//	srand((unsigned)time(NULL));
//	int i = 0;
//	int j = 0;
//	neuron** top_neuron = (neuron**)calloc(nums, sizeof(neuron*));//生成顶层神经组
//	for (;i<nums;i++) {
//		top_neuron[i] = (neuron*)calloc(1, sizeof(neuron));//添加神经进入组
//		top_neuron[i]->val = ((float)(rand()%101))/100;//设置随机初始数值
//		for (;j < UP_CONNECT_NUM;j++) {       //取消上层神经
//			top_neuron[i]->upNeu[j] = NULL;
//		}
//		j = 0;
//		for(;j < SUB_CONNECT_NUM;j++) {       //设置初始随机权重
//			top_neuron[i]->weight[j]= ((float)((rand() % 201)-100)) / 100;
//		}
//
//	}
//}


typedef struct neuron
{
	float* weight;
	float val;
	float err;

}neuron;

//typedef struct e_neuron
//{
//	float* weight;
//	float val;
//
//}e_neuron;

neuron** genNeuLayer(int neuNums, int subNeuNums);

neuron*** genNeuNet(int* arr, int layer);

void forwordCon(neuron*** net, int* arr, int layerNum);

void printVW(neuron*** net, int* arr, int layerNum);

void charInputTop(neuron*** net, char* s);

void charInputBottom(neuron*** net, char* s, int layer);

char* readFloatToChar(neuron*** net, int layer, int botNum);

void loadDate(neuron*** net, int* arr, int layerNum);

void saveDate(neuron*** net, int* arr, int layerNum);