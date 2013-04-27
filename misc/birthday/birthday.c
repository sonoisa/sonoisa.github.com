#include <stdio.h>
#include <mathlink.h>

#define MAX_BUFF	8192
#define MAX_M		200

MLINK lp;
MLEnvironment env;

int	n, m;
int	p[MAX_M + 1];
int	mult[MAX_M + 1];
char	buff[MAX_BUFF];
char	sum[MAX_BUFF];

int	rank = 0;

char *calc(char *expr) {
	char	*result;
    MLPutFunction(lp, "EvaluatePacket", 1);
    MLPutFunction(lp, "ToExpression", 1);
    MLPutString(lp, expr);
    MLEndPacket(lp);

    while (MLNextPacket(lp) != RETURNPKT) MLNewPacket(lp);
	
    MLGetString(lp, &result);
    return result;
}

void free_string(char *str) {
	MLDisownString(lp, str);
}

void par(int min, int max, int level) {
	int	i, j;
	
	/*if (max == 0) {
		printf("{");
		for (j = 1; j < level; j++) {
			printf("{%d,%d},", p[j], mult[j]);
		}
		printf("{%d,%d}", p[level], mult[level]);
		printf("},\n");
	}*/
	
	if (max == 0) {
		if (rank != mult[1]) {
			printf("sum: %s\n", sum);
			rank = mult[1];
			printf("%d\n", rank);
		}
		
		int	l = 0;
		for (j = 1; j <= level; j++) {
			l += mult[j];
		}
		
		int	offset;
		offset = sprintf(buff, "%d %d!%d!/%d!", mult[1], m, n, n - l);
		for (j = 1; j <= level; j++) {
			int ki = p[j];
			int	li = mult[j];
			offset += sprintf(buff + offset, " 1/(%d!(%d!)^%d)", li, ki, li);
		}
		//printf("%s\n", buff);
		char	*result = calc(buff);
		sprintf(buff, "%s + %s", sum, result);
		//printf("%s\n", result);
		free_string(result);

		char	*sum2 = calc(buff);
		strncpy(sum, sum2, MAX_BUFF - 1);
		free_string(sum2);
		
		return;
	}
	
	for (i = min; i <= max; i++) {
		if (p[level] == i) {
			int	m = mult[level]++;
			par(i, max - i, level);
			mult[level] = m;
		} else {
			p[level + 1] = i;
			mult[level + 1] = 1;
			par(i, max - i, level + 1);
		}
	}
}

void partitions(int max) {
	p[1] = 1;
	mult[1] = 1;
	par(1, max - 1, 1);
}

void init_mathlink() {
	int argc = 4;
	char *argv[] = {"-linkname",
		"/Applications/Science/Mathematica\\ 4.2.app/Contents/MacOS/MathKernel -mathlink",
		"-linkmode",
		"launch",
		NULL};
	env = MLInitialize(NULL);
	if (env == NULL) exit(1);
	lp = MLOpen(argc, argv);
	if (lp == NULL) exit(1);
}

void deinit_mathlink() {
	MLClose(lp);
	MLDeinitialize(env);
}

int main(int argc, char **argv) {

	init_mathlink();
	
	if (argc <= 2) return;
	sscanf(argv[1], "%d", &n);
	sscanf(argv[2], "%d", &m);
	
	sum[0] = '0'; sum[1] = NULL;
	p[0] = 0;
	mult[0] = 0;
	partitions(m);
	
	printf("sum: %s\n", sum);
	sprintf(buff, "N[%s/(%d^%d)]", sum, n ,m);
	char	*avg = calc(buff);
	printf("avg: %s\n", avg);
	free_string(avg);
	
	deinit_mathlink();
	
	return 0;
}