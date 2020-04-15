#include<stdio.h>
int main(void)
{
	FILE *inp=fopen("sentences.txt","r");
	char words[200][20],ch;
	//200kelime var ve her biri 20harflik olsun
	//ch de dosyadan alma sonra arraye atamak i�in
	int row=0,col=0; //while in i�indeki art�rma i�lemi i�in
	int r,c;
	while(!feof(inp))
	{
		fscanf(inp, "%c",&ch);
		//bo�luk ya da yeni sat�r g�rmeyene kadar kelimeyi al
		if(ch != '\n' && ch != ' ') //buras� biraz d���nd�r�c�
		{
			words[row][col]=ch;
			col++;
		}
		else 
		{
			words[row][col]='.';
			//columun gidece�i yer i�in nokta koyduk,nokta olana kadar d�ncek d�ng�
			row++;
			col=0;
		}
	}
	for(r=0;r<row;r++)
	{
		for(c=0;words[r][c] != '.';c++)
		{
			printf("%c",words[r][c]);
		}
		printf("\n");
	}
	printf("there are %d words in the txt file.",row);
	fclose(inp);
	
}
