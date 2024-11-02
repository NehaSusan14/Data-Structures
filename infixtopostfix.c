#include <stdio.h>
#include<stdlib.h>
#define max 30
char arr[max];
int top=-1;
void push(char c){
    arr[++top]=c;
}
char pop(){


    if(top>=0)
 return arr[top--];
}
char peek(){
    return arr[top];
}
int precedence(char c){

    if(c== '*'|| c== '/')
    return 2;
    else if(c== '+'|| c== '-')
    return 1;
    else
    return 0;

}
int isoperator(char c){

    return ( c== '*' || c== '+' || c=='/' || c=='-');
}
int isoperand(char c){

    return( c>='a' && c<='z')|| (c>='A' && c<='Z')|| (c>=1 && c<=9);
}
int main(){
    char infix[max];
    printf("enter an infix expression");
    fgets(infix, sizeof(infix),stdin);
    char postfix[max];
    int j=-1;
    int i=0;

    for(i=0;infix[i];++i){

     if(isoperand(infix[i])){


         postfix[++j]=infix[i];
     }
     else if(infix[i]=='('){

         push(infix[i]);
     }
     else if(infix[i]==')'){

           while (top!=-1 && peek() != '(') {

                postfix[++j] = pop();
           }
           pop();


     }
     else if(isoperator(infix[i])){

         while(top!=-1 && precedence(peek())>= precedence(infix[i])){
             postfix[++j]=pop();
         }

         push(infix[i]);
     }


    }
         while(top!=-1)
     postfix[++j]=pop();
   for(i=0;postfix[i];i++){
        printf("%c",postfix[i]);
    }
}
