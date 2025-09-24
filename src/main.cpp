#include <cstdio>
#include <memory>

#include "../include/datastructure/nodes.hpp"
using namespace nodes;

int main() {
    __line_node_with_one_direction__<double> single;
    __line_node_with_two_direction__<double> dble(50);
    single.set_val(10.5);
    auto z = std::make_shared<__line_node_with_one_direction__<double>>(100.58);
    single.set_next(z);
        auto y = std::make_shared<__line_node_with_two_direction__<double>>(200.58);

            auto c = std::make_shared<__line_node_with_two_direction__<double>>(300.58);

    dble.set_next(y);
    dble.set_prev(c);

    printf(" single info : val : %f , next_val : %f  \n|| double info : val : %f , next : %f , prev : %f"
               , single.get_val() , single.next()->get_val() , dble.get_val() , dble.next()->get_val() , dble.prev()->get_val() );

    printf(" \n \n  %d \n\n" , ( dble==dble ));

}
