#include<stdio.h>
void dsort(int n);
void readf();
void knapsack(int,int);
void display(int);
double x[20],d[20],temp,res=0.0,sum=0.0;
int p[20],w[20],m,n;
void readf(){
    int m,n,i;
    printf("Enter the n of profits and weights: \n");
    scanf("%d",&n);
    printf("Enter maximum capacity of knapsack: \n");
    scanf("%d",&m);
    printf("Enter %d profits of the weights: \n",n);
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    printf("\n Enter %d weights: ",n);
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);
    for(i=0;i<n;i++)
        d[i]=(double) p[i]/w[i];
    dsort(n);
    knapsack(m,n);
    display(n);
}
void dsort(int n){
    int i,j,t;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(d[j]<d[j+1]){
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
                t=w[j];
                w[j]=w[j+1];
                w[j+1]=t;
            }
        }
    }
}
void display(int n){
    int i,j,m;
    printf("\n The required optimal solution is: ");
    printf("Profits weights x value\n");
    for(i=0;i<n;i++){
        printf("%d\t %d\t %f\n",p[i],w[i],x[i]);
        sum=sum+(p[i]*x[i]);
        res=res+(w[i]+x[i]);
    }
    printf("\n The total resultant profit is: %f",sum);
    printf("\n The total resultant weight into the knapsack is: %f",res);
}
void knapsack(int n,int m){
    int i,cu;
    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    for(i=0;i<n;i++){
        if(w[i]<cu){
            x[i]=1.0;
            cu=cu-w[i];
        }else{
            break;
        }if(i<=n){
            x[i]=(double)cu/w[i];
        }
    }
}
int main(){
    readf();
    knapsack(n,m);
    dsort(n);
    display(n);
    return 0;
}
