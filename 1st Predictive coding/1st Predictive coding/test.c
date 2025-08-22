#define _CRT_SECURE_NO_WARNINGS

#include "predictive coding.h"

int main() {
	
	int layer = 4;
	int arr[5] = { 10,4,4,10 };
	char s[10] = { "你好。" };
	char bs[10] = { "你好！" };
	char* ret = NULL;
	neuron*** net = genNeuNet(arr, layer);
	//printVW(net, arr, layer);

	//charInputTop(net, s);
	//printVW(net, arr, layer);

	//charInputBottom(net, bs, layer);
	//printVW(net, arr, layer);

	//forwordCon(net, arr, layer);
	//printVW(net, arr, layer);

	loadDate(net, arr, layer);
	printVW(net, arr, layer);


	ret = readFloatToChar(net, layer, 10);
	printf("%s\n", ret);

	free(ret);
	ret = NULL;

	saveDate(net, arr, layer);


	free(net);
	net = NULL;
	return 0;
}


neuron** genNeuLayer(int neuNums, int subNeuNums) {

	srand((unsigned)time(NULL));


	neuron** neuron_layer = (neuron**)calloc(neuNums, sizeof(neuron*));//生成神经层

	while (neuron_layer == NULL) {

		neuron** top_neuron = (neuron**)calloc(neuNums, sizeof(neuron*));
	}


	for (int i = 0;i < neuNums;i++) {

		neuron_layer[i] = (neuron*)calloc(1, sizeof(neuron));//添加神经进入层

		while (neuron_layer[i] == NULL) {

			neuron_layer[i] = (neuron*)calloc(1, sizeof(neuron));
		}

		neuron_layer[i]->val = ((float)(rand() % 101)) / 100;//设置随机初始数值

		neuron_layer[i]->weight = (float*)malloc(sizeof(float) * subNeuNums);//开辟权重空间

		while (neuron_layer[i]->weight == NULL) {

			neuron_layer[i]->weight = (float*)malloc(sizeof(float) * subNeuNums);

		}

		for (int j = 0;j < subNeuNums;j++) {       //设置初始随机权重
			

			neuron_layer[i]->weight[j] = ((float)((rand() % 201) - 100)) / 100;
			//printf("w=%.3f\n", neuron_layer[i]->weight[j]);//查看
		}
	}
	//e_neuron** top_e_neuron = (e_neuron**)calloc(neuNums, sizeof(e_neuron*));//生成顶层误差神经组
	//while (top_e_neuron == NULL) {
	//	e_neuron** top_e_neuron = (e_neuron**)calloc(neuNums, sizeof(e_neuron*));
	//}
	return neuron_layer;

}

neuron*** genNeuNet(int* arr, int layer) {
	
	neuron*** neu_Net = (neuron***)malloc(layer * sizeof(neuron**));
	for (int i = 0;i < layer;i++)
	{
		neu_Net[i] = genNeuLayer(arr[i], (i + 1 != layer) ? arr[i + 1] : 0);
	}
	return neu_Net;
}

void forwordCon(neuron*** net, int* arr, int layerNum) {
	
	float pre = 0;
	//遍历神经元
	for (int layer = 1;layer < layerNum;layer++) {
		for (int i = 0 ;i < arr[layer];i++) {

			//遍历上层神经元
			for (int j = 0;j < arr[layer - 1];j++) {
				pre += (net[layer - 1][j]->val) * (net[layer - 1][j]->weight[i]);
				printf("p=%.2f\n", pre);		
			}
			net[layer][i]->err = (net[layer][i]->val - pre);
			printf("e=%.2f\n", net[layer][i]->err);
			pre = 0;
			printf("\n");
		}
	}
}



void printVW(neuron*** net, int* arr, int layerNum) {

	int layer = 0, i = 0;
	int j = 0;

	for (;layer < layerNum;layer++) {
		for (;i < arr[layer];i++) {
			
			printf("v=%.2f ", net[layer][i]->val);
			printf("e=%.2f ",net[layer][i]->err);
			
		}
		i = 0;
		printf("\n");
	}
	printf("打印完毕\n\n");
}

void charInputTop(neuron*** net, char* s) {
	int size = 0;
	for (;s[size];size++) {

	}
	size++;
	for (int i = 0;i < size;i++) {
		net[0][i]->val = (float)((float)s[i]) / 255;
	}
	printf("字符成功载入到顶层神经元\n");
}

void charInputBottom(neuron*** net, char* s,int layer ) {
	int size = 0;
	for (;s[size];size++) {

	}
	size++;
	for (int i = 0;i < size;i++) {
		net[layer - 1][i]->val = (float)((float)s[i]) / 255;
	}
	printf("字符成功载入到底层神经元\n");
}

char* readFloatToChar(neuron*** net, int layer,int botNum) {
	
	char* ret = (char*)calloc(botNum, sizeof(char));
	for (int i = 0;i < botNum;i++) {
		ret[i] = (char)(net[layer - 1][i]->val * 255);
	}
	printf("读入网络输出成功\n");
	return ret;
}



void loadDate(neuron*** net, int* arr, int layerNum) {

	FILE* pread = fopen("Date.txt", "r");

	while (pread == NULL) {
		FILE* pread = fopen("Date.txt", "r");

	}

	neuron tmp = { 0 };

	for (int layer = 0;layer < layerNum;layer++) {
		for (int i = 0;i < arr[layer];i++) {
			fread(&tmp, sizeof(neuron), 1, pread);
			*(net[layer][i]) = tmp;
		}
	}

	fclose(pread);
	pread = NULL;

	printf("读取数据成功\n");
}

void saveDate(neuron*** net, int* arr, int layerNum) {
	FILE* pwrite = fopen("Date.txt", "w");

	while (pwrite == NULL) {
		FILE* pwrite = fopen("Date.txt", "w");

	}

	//int sum = 0;
	//for (int i = 0;i < layerNum;i++) {
	//	sum += arr[i];
	//}

	for (int layer = 0;layer < layerNum;layer++) {
		for (int i = 0;i < arr[layer];i++) {
			fwrite(*(*(net + layer) + i), sizeof(neuron), 1, pwrite);
		}
	}

	fclose(pwrite);
	pwrite = NULL;

	printf("保存数据成功\n");

}