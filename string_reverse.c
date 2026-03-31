#include<stdio.h>
#include<string.h>

void reverse(char* A){
    int front = 0;
    int back = strlen(A) - 1;
    
    while(front < back){
        char temp;
        temp = A[front];
        A[front] = A[back];
        A[back] = temp;
        front++;
        back--;

    }

}

void reverse_wptr(char* A){
    char* front = A;
    char* back = A + strlen(A) - 1;

    while(front < back){
        char temp = *front;
        *front = *back;
        *back = temp;
        front++;
        back--;
    }
}

int main(){
    char input[1000];
    scanf("%s", input);
    reverse(input);
    printf("%s\n", input);
    reverse_wptr(input);
    printf("%s\n", input);
   return 0; 
}