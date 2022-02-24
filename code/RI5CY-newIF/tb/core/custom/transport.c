#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   /* input variables declaration */
   int (*costs)[3][3];
   (*costs)[0][0]=5; (*costs)[0][1]=8; (*costs)[0][2]=4;
   (*costs)[1][0]=6; (*costs)[1][1]=6; (*costs)[1][2]=3;
   (*costs)[2][0]=3; (*costs)[2][1]=9; (*costs)[2][2]=6;

   int demand[3]={20, 95, 35};
   int supply[3]={50, 40, 60};
   int total_cost;
   
   /* Others */
   int i, j, s, d, dest_i, src_i;
   int min_cost, max_demand, transfer;

   total_cost = 0;
   
   for (i=0; i<3; i++) {
       for (j=0; j<3; j++) {

           /* Minimum value */
           min_cost = 0x7FFFFFFF;
           for(s=0; s<3; s++) {
               for(d=0; d<3; d++) {
                   if( (*costs)[s][d] < min_cost ) min_cost = (*costs)[s][d];
                   printf("%d ", (*costs)[s][d]);
               }
               printf("\n");
           }
   
           printf("MIN %d\n", min_cost);

           /* Path computation: source and demand */
           max_demand = 0;
           for(s=0; s<3; s++) {
               for(d=0; d<3; d++) {
                   if( ((*costs)[s][d] == min_cost) && (demand[d]>=max_demand) ) {
                       max_demand = demand[d];
                       dest_i     = d;
                       src_i      = s;
                   }
               }
           }
           printf("COORDS src_i=%d, dest_i=%d\n", src_i, dest_i);

           /* Total cost update */
           if(supply[src_i] <= demand[dest_i])
               transfer = supply[src_i];
           else
               transfer = demand[dest_i];
           demand[dest_i] = demand[dest_i] - transfer;
           supply[src_i]  = supply[src_i] - transfer;
           (*costs)[src_i][dest_i] = (*costs)[src_i][dest_i] | 0x7FFFFFFF;
           total_cost = total_cost + (transfer * min_cost);
           printf("UPDATE demand[%d]=%d, supply[%d]=%d\n", dest_i, demand[dest_i], src_i, supply[src_i], src_i, dest_i);
           printf("TOT COST %d\n\n", total_cost);
       }
   }
   

   return EXIT_SUCCESS;
}

