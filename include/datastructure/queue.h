

#include "nodes.h"
#include <stdexcept>
#include <utility>

namespace containers {
    template<class _Typ> class queue{
        nodes::__line_node_with_one_direction__<_Typ>* __head ,* __tail;
        unsigned long long _len_;
        public:
            queue() :  __head(nullptr) , __tail(nullptr) , _len_(0){}
            ~queue() { 
               
                while (this->__head) {
                    auto tmp =this->__head;
                    this->__head = this->__head->ref_next();
                    delete tmp;
                }
            }
            
            void push(const _Typ& val) {
                if(!this->__head){
                    this->__head = new nodes::__line_node_with_one_direction__(val);
                    this->__tail =this->__head;
                }else{
                    auto *tmp =  new nodes::__line_node_with_one_direction__(val);
                    this->__tail->set_next(tmp);
                    this->__tail = this->__tail->ref_next();
                }
                this->_len_ +=1;
            }

            void pop(){
                if(!this->__head ){ return; } 
                if (this->__tail == this->__head){ 
                     this->__tail =nullptr; 
                     this->__head =nullptr; 
                    }
                else{
                    auto tmp = this->__head;
                    this->__head = this->__head->ref_next();
                    delete tmp;
                }
                this->_len_ -=1;
            }

            _Typ& front(){ 
                if(!this->__head) throw  std::out_of_range("Envalid operation");
                
                return this->__head->get_val();
            }

            _Typ& back(){
                if(!this->__tail) throw  std::out_of_range("Envalid operation");
                 
                return this->__tail->get_val();
            }

            const _Typ& back() const {
                if(!this->__tail) throw  std::out_of_range("Envalid operation");
                 
                return this->__tail->get_val();
            }

            const _Typ& front() const{ 
                if(!this->__head) throw  std::out_of_range("Envalid operation");
                
                return this->__head->get_val();
            }

            template<class... Args> void emplace(Args&&... vals){ this->push( _Typ(std::forward<_Typ>(vals))... ); }
            
            bool empty() { return this->__head == nullptr; }

            unsigned long long size() { return this->_len_;}
    };

}