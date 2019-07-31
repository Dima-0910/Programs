#include <stdio.h>
#include <math.h>

int count = 0;
int iter = 0;
double func(double x)
{
	count++;
	return fabs(x-M_PI);
}
int gold(double a,double b,double(*func)(double), double *x)
{
	double c,d,fc,fd,eps,phi;
	eps=1.e-15;
	phi=(3-sqrt(5))/2; 
	c=a+phi*(b-a);
	d=b-(b-a)*phi;
	fc=func(c);
	fd=func(d);
	while(fabs(a-b)>eps && fabs(a-b)>eps*fabs(a))
	{
		if(c<a) printf("***   ");
		if(d<c) printf("###   ");
		if(b<d) printf("$$$   ");
		
		printf("a=%.15lf  c=%.15lf  d=%.15lf  b=%.15lf\n",a,c,d,b);
		
		iter++;
		if(fc<fd)
			{
				b=d;
				d=c;
				fd=fc;
				c=a+phi*(b-a);
				fc=func(c);
			}
		else
			{
				a=c;
				c=d;
				fc=fd;
				d=b-(b-a)*phi;
				fd=func(d);
			}
			
	}
	*x = c;
	return 0;
}
int main(void)
{
	double a,b,m;
	double c;
	scanf("%le %le",&a,&b);
	if( gold(a,b,(*func),&c) == 1 ) {printf("ой\n"); return 1;}
	m=func(c);
	printf("c=%lf (%le), func(c)=%lf (%le), iter=%d, count=%d\n",c,c,m,m,iter,count);
	return 0;
}

