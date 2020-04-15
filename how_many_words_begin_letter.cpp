#include<stdio.h>
int main(void)
{
	FILE *inp=fopen("sentences.txt","r");
	char words[200][20],ch;
	//200kelime var ve her biri 20harflik olsun
	//ch de dosyadan alma sonra arraye atamak için
	int row=0,col=0; //while in içindeki artýrma iþlemi için
	int r,c;
	while(!feof(inp))
	{
		fscanf(inp, "%c",&ch);
		//boþluk ya da yeni satýr görmeyene kadar kelimeyi al
		if(ch != '\n' && ch != ' ') //burasý biraz düþündürücü
		{
			words[row][col]=ch;
			col++;
		}
		else 
		{
			words[row][col]='.';
			//columun gideceði yer için nokta koyduk,nokta olana kadar döncek döngü
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
