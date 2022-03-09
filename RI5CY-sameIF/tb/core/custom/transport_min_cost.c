#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
   /* input variables declaration */
   int (*costs)[3][3] = 0x30000;
   (*costs)[0][0]=5; (*costs)[0][1]=8; (*costs)[0][2]=4;
   (*costs)[1][0]=6; (*costs)[1][1]=6; (*costs)[1][2]=3;
   (*costs)[2][0]=3; (*costs)[2][1]=9; (*costs)[2][2]=6;

   int *demand = 0x30030;
   demand[0]=20; demand[1]=95; demand[2]=35;
   int *supply = 0x30040;
   supply[0]=50; supply[1]=40; supply[2]=60;
   int *total_cost = 0x30060;

   /* Others */
   int i, j, s, d, dest_i, src_i;
   int min_cost, max_demand, transfer;

   *total_cost = 0;
   
   for (i=0; i<3; i++) {
       for (j=0; j<3; j++) {

           /* Minimum value */
           min_cost = 0x7FFFFFFF;
           for(s=0; s<3; s++) {
               for(d=0; d<3; d++) {
                   if( (*costs)[s][d] < min_cost ) min_cost = (*costs)[s][d];
               }
           }

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

           /* Total cost update */
           if(supply[src_i] <= demand[dest_i])
               transfer = supply[src_i];
           else
               transfer = demand[dest_i];
           demand[dest_i] = demand[dest_i] - transfer;
           supply[src_i]  = supply[src_i] - transfer;
           (*costs)[src_i][dest_i] = (*costs)[src_i][dest_i] | 0x7FFFFFFF;
           *total_cost = *total_cost + (transfer * min_cost);
       }
   }

   return EXIT_SUCCESS;
}

