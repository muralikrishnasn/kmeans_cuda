/*
 * load_cifar10_data.h
 *
 *  Created on: 04/06/2013
 *      Author: gustavo
 */

#ifndef CIFAR10_DATA_H_
#define CIFAR10_DATA_H_


class Cifar10Dataset {

private:
	int load_cifar_data_from_batches();
	static const int nExamples_perbatch = 10000;
	void processBatch(int batchNumber);
public:
	Cifar10Dataset();
	double *X;
	int *y;
	static const int nExamples = 50000;
	static const int nDim = 3072;

};

#endif /* CIFAR10_DATA_H_ */