

#ifndef QUEUE_H
#define QUEUE_H 1

#include "nodes.h"
#include <stdexcept>

namespace containers {
    template<class _Typ> class queue{
        /*
         classic queue wrote to learn how to use template , ptr , and learn new logic and technics 
        */
       using ptr =  nodes::single_node<_Typ>*; 
       using size = std::size_t;

        ptr __head , __tail;
        size _len_;
        public:
            queue() :  __head(nullptr) , __tail(nullptr) , _len_(0){}
            ~queue() { 
               
                while (this->__head) {
                    auto tmp =this->__head;
                    this->__head = this->__head->ref_next();
                    delete tmp;
                }
                 this->_len_ = 0;
                  this->__tail = nullptr;
            }
            
            void push(const _Typ& val) {
                auto *tmp =  new nodes::single_node(val);
                if(!this->__head){
                    this->__head = tmp;
                    this->__tail =this->__head;
                }else{
                    this->__tail->set_next(tmp);
                    this->__tail = this->__tail->ref_next();
                }
                this->_len_ +=1;
            }

            void pop(){
                if(!this->__head ){ return; } 
                if (this->__tail == this->__head){ 
                      
                    delete this->__head ; 
                    this->__tail = nullptr;
                    }
                else{
                    auto tmp = this->__head;
                    this->__head = this->__head->ref_next();
                    delete tmp;
                }
                this->_len_ -=1;
            }

            _Typ& front(){ 
                if(!this->__head) throw  std::out_of_range("Queue is empty");
                
                return this->__head->get_val();
            }

            _Typ& back() {
                if(!this->__tail) throw  std::out_of_range("Queue is empty");
                 
                return this->__tail->get_val();
            }

            const _Typ& back() const {
                if(!this->__tail) throw  std::out_of_range("Queue is empty");
                 
                return this->__tail->get_val();
            }

            const _Typ& front() const{ 
                if(!this->__head) throw  std::out_of_range("Queue is empty");
                
                return this->__head->get_val();
            }

            //this function help to build the type of queu from type's constractor 
            template<class... Args> void emplace(Args&&... vals){ this->push( _Typ(std::forward<Args>(vals))... ); }
            
            bool empty() const { return this->__head == nullptr; }

            size len() const{
            if (this->_len_ = 0) return std::string::npos;
            return this->_len_;
          }
    };

}

#endif