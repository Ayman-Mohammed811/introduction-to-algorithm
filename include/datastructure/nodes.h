  
#ifndef NODES_HPP
#define NODES_HPP 1
namespace nodes{
    template<typename  _Typ > class __line_node_with_one_direction__ {
        using node_type = __line_node_with_one_direction__<_Typ>;

       node_type* __next;
        _Typ __elem;

        public:
        
        explicit __line_node_with_one_direction__(const _Typ& val = _Typ()) : __elem(val) , __next(nullptr){}
        
        ~__line_node_with_one_direction__()=default;
        
        _Typ& get_val() { return this->__elem; }
        
        const _Typ& get_val () const { return this->__elem; }
        
        void set_val(const _Typ& value) { this->__elem = value; }
        
        void set_next( node_type* next) { this->__next = next; }
        
        const node_type* next () const { return this->__next; }
        
        node_type*& ref_next () { return this->__next; }

        node_type* next () { return this->__next; }
        
        bool equal_val( const node_type &other) { return this->__elem == other.get_val(); }
        
        bool operator==( node_type &other){
            return this->__elem == other.get_val() &&
                   this->__next == other.next();
        }
        
        bool operator!=( node_type &other) { return !(*this == other); }
    };

    template<typename  _Typ > class __line_node_with_two_direction__ {

        using node_type = __line_node_with_two_direction__<_Typ>;

        node_type* __next;
        node_type* __prev;
        _Typ __elem;

        public:
        
        explicit  __line_node_with_two_direction__(const _Typ& val = _Typ()) : __elem(val) , __next(nullptr) , __prev(nullptr){}
        
        ~__line_node_with_two_direction__()= default;
        
        _Typ& get_val() { return this->__elem;  }
        
        const _Typ& get_val () const { return this->__elem; }
        
        void set_val(const _Typ& value) { this->__elem = value; }
        
        void set_next( node_type* next) { this->__next = next; }
        
        const node_type* next () const { return this->__next; }
        
        node_type*& ref_next () { return this->__next; }
        
        node_type* next () { return this->__next; }
        
        void set_prev(node_type* prev) { this->__prev = prev; }

        const node_type* prev() const { return this->__prev; }

        node_type*& ref_prev() { return this->__prev; }

        node_type* prev() { return this->__prev; }

        bool equal_val( const node_type &other) { return this->__elem == other.get_val(); }
        
        bool operator==( node_type &other){
            return this->__elem == other.get_val() &&
                   this->__next == other.next() &&
                   this->__prev == other.prev();
        }
       
        bool operator!=( node_type &other) { return !(*this == other); }
    };
}

#endif

