#include<stdio.h>
int binary_search(double ar[],int first,int last,double num)
{
	int middle;
	if(first>last)
		return (-1);
	else
	{
		middle=(first+last)/2;
		if(num=ar[middle])
			return (middle);
		else if(middle<ar[middle])
			return (binary_search(ar,first,middle-1,num));
		else
			return (binary_search(ar,middle+1,last,num));
	}
		
}
