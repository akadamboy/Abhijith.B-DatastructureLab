#include<stdio.h>
int main(){
    
    int top=-1,a[100],i,n,choice,element;
    printf("enter the size of stack  : ");
    scanf("%d",&n);
    
    printf("\n stack operations........\n");
    
    while(1){
        printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    
   
        printf("\nenter your choice  :");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:{
                if(top>=n){
                    printf("stack is full please pop any element to insert new element......\n");
                }
                else{
                        printf("enter you  element  : ");
                        scanf("%d",&element);
                        a[top]=element;
       
                    }
            break;    
            }
            case 2:{
                if(top==-1){
                    printf("stack underflow......\n");
                }
                else{
                    top--;
                    }
                
            break;    
            }
            case 3:{
                if(top==-1){
                    printf("stack underflow nothing to display......\n");
                }
                else{
                    for(i=top;i>=0;i--){
                        printf("%d",a[i]);
                    }
                }
            break;    
            }
            case 4:{
                return 0;
            }
            default: {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
            
        }    
    }
        
}
