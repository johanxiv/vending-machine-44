#include "dispenser.h"
#include "vending.h"
#include "cashregister.h"
#include "inventory.h"

int productQuantity (int selected) {
	int c[4];
	int i = 0;
	char line[256];
	//
	FILE *fp;
	char* filename = "inventory.txt";
	fp = fopen(filename, "r");
	//
	switch(selected) {
		case 1 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == 1) {
							fscanf(fp, "%d", &c[0]);
							}}
					fclose (fp);
					fp = NULL;
					//
					return c[0];
					break;
					
		case 2 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == 2) {
							fscanf(fp, "%d", &c[1]);
							}}
					fclose (fp);
					fp = NULL;
					//
					return c[1];
					break;
					
		case 3 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == 2) {
							fscanf(fp, "%d", &c[2]);
							}}
					fclose (fp);
					fp = NULL;
					//
					return c[2];
					break;
					
		case 4 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == 2) {
							fscanf(fp, "%d", &c[3]);
							}}
					fclose (fp);
					fp = NULL;
					//
					return c[3];
					break;
					}
}

int calculateQuantity (int selected, int quantity) {
	int c[4];
	int total;
	int i = 0;
	char line[256];
	//
	FILE *fp;
	char* filename = "inventory.txt";
	fp = fopen(filename, "r");
	//
	switch(selected) {
		case 1 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == selected) {
							fscanf(fp, "%d", &c[0]);
							if(c[0] > 0) 
								total = c[0] - quantity;	
							}}
					fclose (fp);
					fp = NULL;
					//
					break;
					
		case 2 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == selected) {
							fscanf(fp, "%d", &c[1]);
							if(c[1] > 0) 
								total = c[1] - quantity;
							}}
					fclose (fp);
					fp = NULL;
					//
					break;
					
		case 3 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == selected) {
							fscanf(fp, "%d", &c[2]);
							if(c[2] > 0) 
								total = c[2] - quantity;
							}}
					fclose (fp);
					fp = NULL;
					//
					break;
					
		case 4 :	while (fgets(line, sizeof(line), fp)) {
						i++;
						if(i == selected) {
							fscanf(fp, "%d", &c[3]);
							if(c[3] > 0) 
								total = c[3] - quantity;
							}}
					fclose (fp);
					fp = NULL;
					//
					break;
					}					
	storeQuantity(selected, total);
	duplicateInv(selected);
}

int storeQuantity (int selected, int total) {
	int i = -1;
	int n, k;
	char line[256];
	//
	FILE *fp, *fq;
	char* filename = "inventory.txt";
	fp = fopen(filename, "r");
	fq = fopen("tempinv.txt", "w+");
	//
	k = total;
	//
	while (fgets(line, 256, fp) != NULL) {
		i++;
		if (i == selected)
			fprintf(fq, "%d\n", total);
		else
			fputs(line, fq);
		}
	fclose (fp);
	fclose (fq);
}

int duplicateInv (int selected) {
	int n, k;
	char line[256];
	//
	FILE *fp, *fq;
	char* filename = "inventory.txt";
	fp = fopen(filename, "w+");
	fq = fopen("tempinv.txt", "r");
	//
	while (fgets(line, 256, fq) != NULL) {
		fputs(line, fp);
		}
	fclose (fp);
	fclose (fq);
	remove("tempinv.txt");
}
