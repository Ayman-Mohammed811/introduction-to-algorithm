
#ifndef NODES_HPP
#define NODES_HPP 1

#include <memory>

namespace nodes{
    template<typename  _Typ > class __line_node_with_one_direction__ : public std::enable_shared_from_this<__line_node_with_one_direction__<_Typ>>{
        using node_type = __line_node_with_one_direction__<_Typ>;

        std::shared_ptr<node_type> __next;
        _Typ __elem;

        public:
        explicit __line_node_with_one_direction__(const _Typ& val = _Typ()) : __elem(val) , __next(){}
        _Typ& get_val(){
            return this->__elem;
        }
        const _Typ& get_val () const{
            return this->__elem;
        }
        void set_val(const _Typ& value){
            this->__elem = value;
        }
        void set_next( const std::shared_ptr<node_type>& next){
            this->__next = next;
        }
        
        std::shared_ptr<const node_type> next () const{
            return this->__next;
        }
        
        std::shared_ptr< node_type> next () {
            return this->__next;
        }
        bool equal_val( const node_type &other){
            return this->__elem == other.get_val();
        }
        bool operator==( node_type &other){
            return this->__elem == other.get_val() &&
                   this->__next == other.next();
        }
        bool operator!=( node_type &other){
            return !(*this == other);
        }
       
     

    };
    template<typename  _Typ > class __line_node_with_two_direction__ :public  std::enable_shared_from_this<__line_node_with_two_direction__<_Typ>> {

        using node_type = __line_node_with_two_direction__<_Typ>;

        std::shared_ptr<node_type> __next;
        std::weak_ptr<node_type> __prev;
        _Typ __elem;

        public:
        explicit  __line_node_with_two_direction__(const _Typ& val = _Typ()) : __elem(val) , __next() , __prev(){}

        _Typ& get_val(){
            return this->__elem;
        }
        const _Typ& get_val () const{
            return this->__elem;
        }
        void set_val(const _Typ& value){
            this->__elem = value;
        }
        void set_next( const std::shared_ptr<node_type>& next){
            this->__next = next;
        }
        
        std::shared_ptr<const node_type> next () const{
            return this->__next;
        }
        
        std::shared_ptr< node_type> next () {
            return this->__next;
        }
        void set_prev(const std::shared_ptr<node_type>& prev){
            this->__prev = prev;
        }


            std::shared_ptr<const node_type> prev() const{
            return this->__prev.lock();
        }

        std::shared_ptr< node_type> prev() {
            return this->__prev.lock();
        }

        bool equal_val( const node_type &other){
            return this->__elem == other.get_val();
        }
        bool operator==( node_type &other){
            return this->__elem == other.get_val() &&
                   this->__next == other.next() &&
                   this->__prev.lock() == other.prev();
        }
        bool operator!=( node_type &other){
            return !(*this == other);
        }

    };

}


#endif

