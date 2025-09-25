
#include <utility>
#ifndef STACK_H
#define STACK_H 1

#include "nodes.h"
#include <stdexcept>

namespace containers {
    template<class _Typ> class stack {

      using ptr =  nodes::__line_node_with_two_direction__<_Typ>; 
      using llu = long long unsigned;

      ptr *__head; // stack need to make a
      llu _len_;

      public:
          stack() : __head(nullptr)  , _len_(0) {}
          ~stack(){
            while( __head != nullptr){
                auto tmp = __head;
                __head = __head->ref_prev();
                delete tmp;
            }
            _len_ = 0;
          }

          void push(const _Typ& val){
            auto *tmp = new nodes::__line_node_with_two_direction__<_Typ>(val);
            if (!this->__head){
                this->__head = tmp;
            }else{
                tmp->set_prev(__head);
                this->__head->set_next(tmp);
                this->__head = tmp;
            }
            this->_len_ +=1;
          }

          void pop(){
            if(!this->__head){ return; }
                auto tmp = this->__head;
                this->__head  = this->__head->ref_prev();
                delete tmp;
            this->_len_ -=0;
          }

          template<class... Args>void emplace(Args&&... vals){
            this->push(_Typ(std::forward<_Typ>(vals))... );
          }

          _Typ& top(){
            if(!this->__head){ throw std::out_of_range("Envalid operation"); }
            return this->__head->get_val();
          }
        
          llu size(){
            return this->_len_;
          }

          llu empty(){
            return this->__head == nullptr;
          }

    };
}



#endif