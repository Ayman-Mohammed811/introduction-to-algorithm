
#ifndef STACK_H
#define STACK_H 1

#include "nodes.h"
#include <stdexcept>


namespace containers {
    template<class _Typ> class stack {

      using ptr =  nodes::double_node<_Typ>*; 
      using size = std::size_t;

      ptr __head; // stack need to make a
      size _len_;

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
            auto *tmp = new nodes::double_node<_Typ>(val);
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
            this->_len_ -=1;
          }

          template<class... Args>void emplace(Args&&... vals){ this->push(_Typ(std::forward<Args>(vals))... ); }

          _Typ& top(){
            if(!this->__head){ throw std::out_of_range("Stack is empty"); }
            return this->__head->get_val();
          }
        
          size len() const{
            if (this->_len_ = 0) return std::string::npos;
            return this->_len_;
          }

          bool empty() const{
            return this->__head == nullptr;
          }

    };
}



#endif