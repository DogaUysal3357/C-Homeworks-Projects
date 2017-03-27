#include<stdio.h>

#define COL_COUNT 8
#define ROW_CAP 10

typedef struct {int x=0; int y=0} Point_t ;
typedef struct {Point_t left_up, Point_t right_down, double sum=0} Rectangle_t;

void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow);
/**/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle);
/**/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, 
		Point_t left_up);
/**/
Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow);

int main()
{
	double table[ROW_CAP][COL_COUNT];
	FILE* inFile;
	int nRow;
	double maxSum;
	int lUY, lUX, rDY, rDX;

	inFile=fopen("Table1.txt", "r");

	getArray(inFile, table, &nRow);

	maxSum=maxSumConstPoint(table, nRow, 0, 0, &rDY, &rDX);
	printf("MaxSum Rectangular starting from origin is %.2lf. Its right down coordinate (y,x) is %d, %d\n", maxSum, rDY, rDX);
	
	maxSum=maxSumRec(table, nRow, &lUY, &lUX, &rDY, &rDX);
	printf("MaxSum Rectangular is %.2lf. Its left upper coordinate (y,x) is %d, %d, right down coordinate is %d, %d\n", maxSum, lUY, lUX, rDY, rDX);

	fclose(inFile);
	return 0;
}

						/***********/
						/*Functions*/
						/***********/

Point_t construct_point(int x, int y)
{
	Point_t res_point;

	res_point.x=x;
	res_point.y=y;

	return res_point;
}

Rectangle_t construct_rectangle(Point_t left_up, Point_t right_down)
{
	Rectangle_t res_rectangle;

	res_rectangle.left_up=left_up;
	res_rectangle.rigt_down=right_down;

	return res_rectangle;
}

void print_rectangle(const Rectangle_t *rectangle)
{
	printf("Dikdortgenin sol ust kose kordinatları:\n-> X:\t%d\nY:\t%d\n",
		    rectangle->left_up.x, rectangle->left_up.y);
	printf("Dikdortgenin sag alt kose kordinatları:\n-> X:\t%d\nY:\t%d\n",
		    rectangle->right_down.x, right_down.y);
	printf("Diktortgenin icindeki degerlerin toplami : %d\n", rectangle->sum);

}

/*Reads the table from a file into a 2D array*/
void getArray(FILE* inFile, double table[][COL_COUNT], int* nRow)
{
	int row=0;
	int col;
	int status=EOF+1;/*Different from EOF*/

	/*one more row will be read but the values will not be recorded into the table
	therefore, it is safe to use a table having just enough capasity to hold the data*/
	while(status!=EOF){
		for(col=0; col<COL_COUNT; col++)
			status=fscanf(inFile, "%lf", &table[row][col]);
		++row;
	}

	*nRow=row-1;/*one more row read*/
}

/*Returns the sum inside a given rectangular*/
void getSum(double table[][COL_COUNT], Rectangle_t *rectangle)
{
	int row, col;
	
	for(row=rectangle->left_up.y; row<=rectangle->right_down.y; ++row)
		for(col=rectangle->left_up.x; col<=rectangle->right_down.x; ++col)
			rectangle->sum+=table[row][col];
}

/*Finds the rectangular left uppper point of which is specified having the max sum inside*/
Rectangle_t maxSumConstPoint(double table[][COL_COUNT], int nRow, Point_t left_up)
{
	rectangle res_rectangle;
	int rDX;	/*x coordinate of the right down corner of the rec*/
	int rDY;	/*y coordinate of the right down corner of the rec*/
	double temp;
	/*initialize the rectangular with the one including only one point*/
	double res_rectangle.sum=table[left_up.x][left_up.y];
	res_rectangle.right_down.y=left_up.y;
	res_rectangle.right_down.x=left_up.x;

	/*Try all feasible rectangulars by changing the right down corner*/
	for(rDY=left_up.y; rDY<nRow; ++rDY){
		for(rDX=left_up.x; rDX<COL_COUNT; ++rDX){
			temp=getSum(table, left_up.y, left_up.x, rDY, rDX);
			if(temp>res_rectangle.sum){
				/*a better rectangular is found, perform an update */
				res_rectangle.sum=temp;
				res_rectangle.right_down.y=rDY;
				res_rectangle.right_down.x=rDX;
			}
		}
	}

	return res_rectangle;
}
}


Rectangle_t maxSumRec(double table[][COL_COUNT], int nRow)
{
	Rectangle_t res_rectangle;
	Rectangle_t temp;
	int lUY, lUX;	/*coordinates of the left upper corner*/
	int rDY, rDX;	/*coordinates of the right down corner*/
	/*initialize the rectangular with the one including only origin point*/
	res_rectangle.sum=table[0][0];
	
	/*For all feasible starting points call maxSumConstPoint*/
	for(lUY=0; lUY<nRow; ++lUY){
		for(lUX=0; lUX<COL_COUNT; ++lUX){
			temp=maxSumConstPoint(table, nRow, lUY, lUX, &rDY, &rDX);
			if(temp.sum>res_rectangle.sum){
				/*a better rectangular found, perform an update*/
				res_rectangle.sum=temp.sum;
				res_rectangle.left_up.y=lUY;
				res_rectangle.left_up.x=lUX;
				res_rectangle.right_down.y=rDY;
				res_rectangle.right_down.x=rDX;
			}
		}
	}

	return res_rectangle;
}


