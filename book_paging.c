#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int p;
    scanf("%d",&p);
    int paging_count1 = 0, paging_count2 = 0, page_pos;

       if (n%2==0) ++n;
       for (page_pos = n-1; page_pos > p; page_pos-=2, ++paging_count1);
       for (page_pos = 1; page_pos < p; page_pos+=2, ++paging_count2 );

    printf("%d",(paging_count1 < paging_count2) ? paging_count1 : paging_count2);
    return 0;
}
