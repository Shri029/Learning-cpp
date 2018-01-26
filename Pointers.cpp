//Input: Two Integers a,b say 5,6
//Output:
//1) a'=a+b            a'=5+6=11
//2) b'=|a-b|          b'=|5-6|=1

#include <stdio.h>

void update(int *a,int *b) {
    
    int p=*a;
    int q=*b;
    *a=p+q;
    *b=p-q>0 ? p-q : -(p-q);
    
}

int main() {
    
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}