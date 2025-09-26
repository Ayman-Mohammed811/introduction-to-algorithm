#include <cstdio>

// #include "../include/datastructure/nodes.h"
// #include "../include/datastructure/queue.h"
// #include "../include/datastructure/stack.h"
#include "../include/sort/insertion_sort.h"

int main() {
    // __line_node_with_one_direction__<double> single(1);
    // __line_node_with_two_direction__<double> dble(50);
    // single.set_val(10.5);
    // single.set_next(new __line_node_with_one_direction__<double>(2.88));
    // dble.set_next(new __line_node_with_two_direction__<double>(60.74588));
    // dble.set_prev(new __line_node_with_two_direction__<double>(280.88));

    // printf(" single info : val : %f , next_val : %f  \n|| double info : val : %f , next : %f , prev : %f"
    //            , single.get_val() , single.next()->get_val() , dble.get_val() , dble.next()->get_val() , dble.prev()->get_val() );

    // printf(" \n \n  %d \n\n" , ( dble==dble ));

    // containers::stack<double> q ;

    
    // q.push(50.501);
    // q.push(60.89);
    // q.push(8258.2588);
    // q.push(89522);
    // q.emplace(100);
    // printf("q size : %llu \n q top : %f \n" , q.size() , q.top() );
    //  q.pop(); q.pop(); q.pop(); q.pop(); q.pop();
   
    //  printf("size : %f" , q.top());

    // auto x = 99;
    // auto& y = x;

    // y++;
    // printf("%d" , x);
    double arry []= { 1 , 2 , 8 , 9 , -78 , 0 ,14 , 8 , 3 , 5};

    sort::insertion_sort::__sort(arry);

    printf("original arr = { 1 , 2 , 8 , 9 , -78 , 0 ,14 , 8 , 3 , 5} \n");

    printf("ordar arr = { ");
    for ( unsigned long long i =0 ; i < 10 ; i++){
        printf(" %f , " , arry[i]);
    }
    printf("}  \n");

}
