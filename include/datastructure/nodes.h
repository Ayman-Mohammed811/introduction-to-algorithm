  
#ifndef NODES_HPP
#define NODES_HPP 1

#include <memory>
namespace nodes{
template<typename _Typ>
class single_node {
    using ptr = single_node<_Typ>*;  // Alias for easier usage

    ptr __next;     // Raw pointer to next node
    _Typ __elem;    // Data element

public:
    // Constructor with default value
    explicit single_node(const _Typ& val = _Typ()) 
        : __elem(val), __next(nullptr) {}

    ~single_node() = default; // Do not delete __next to avoid recursive delete

    // Accessors

    void set_val(const _Typ& value) { this->__elem = value; }

    void set_next(ptr next) { this->__next = next; }

    _Typ& get_val() { return this->__elem; }
    const _Typ& get_val() const { return this->__elem; }

    ptr next() { return this->__next; }
    const ptr next() const { return this->__next; }
    ptr& ref_next() { return this->__next; }  // For direct pointer manipulation

    // Comparison
    bool equal_val(const ptr& other) const {
        return other && ( this->__elem == other->get_val() );
    }

    bool equal_val(const single_node<_Typ>& other) const {
        return this->__elem == other.get_val();
    }

    bool operator==(const ptr& other) const {
        if (!other) return false;
        return  ( __elem == other->get_val() ) &&
                ( __next == other->next() );
    }

    bool operator==(const single_node<_Typ>& other) const {
        return ( __elem == other.get_val() ) &&
               ( __next == other.next() );
    }

    bool operator!=(const ptr& other) const {
        return !(*this == other);
    }

    bool operator!=(const single_node<_Typ>& other) const {
        return !(*this == other);
    }
};

    template<typename  _Typ > class double_node {

        using ptr = double_node<_Typ>*;

        ptr __next;
        ptr __prev;
        _Typ __elem;

        public:
        
        explicit  double_node(const _Typ& val = _Typ()) : __elem(val) , __next(nullptr) , __prev(nullptr){}
        
        ~double_node()= default;
        
        void set_val(const _Typ& value) { this->__elem = value; }

        void set_next( ptr next) { this->__next = next; }

        void set_prev(ptr prev) { this->__prev = prev; }

        _Typ& get_val() { return this->__elem;  }
        const _Typ& get_val () const { return this->__elem; }
                
        ptr next () { return this->__next; }
        const ptr next () const { return this->__next; }
        ptr& ref_next () { return this->__next; }
        
        ptr prev() { return this->__prev; }
        const ptr prev() const { return this->__prev; }
        ptr& ref_prev() { return this->__prev; }

        bool equal_val( const ptr &other) { return this->__elem == other->get_val(); }
        bool equal_val( const double_node<_Typ> &other) { return this->__elem == other.get_val(); }

        
        bool operator==( const ptr &other){
            return this->__elem == other->get_val() &&
                   this->__next == other->next() &&
                   this->__prev == other->prev();
        }
        bool operator==( const double_node<_Typ> &other){
            return this->__elem == other.get_val() &&
                   this->__next == other.next() &&
                   this->__prev == other.prev();
        }
       
        bool operator!=( const ptr &other) { return !(*this == other); }
        bool operator!=( const double_node<_Typ> &other) { return !(*this == other); }
    };

    template<typename  _Typ > class smart_single_node: public std::enable_shared_from_this<smart_single_node<_Typ>>{
        // in a lot of datastrucure delete pointers manually is very expensive
        using ptr = std::shared_ptr< smart_single_node< _Typ> >;

        _Typ __elem;
        ptr next;

        public: 

        explicit smart_single_node(const _Typ& value = _Typ()) : __elem(value) , next(nullptr) {}

        ~smart_single_node() = default; // we don't need to delete object maually

        void set_val(const _Typ& value) { this->__elem = value; }

        void set_next(const ptr& next) { __next = next; }

        _Typ& get_val() { return this->__elem;  }
        const _Typ& get_val () const { return this->__elem; }

        ptr next() { return __next; }
        const ptr next() const { return __next; }

        // Comparison
        bool equal_val(const ptr& other) const {
            return other && (__elem == other->get_val());
        }

        bool equal_val(const smart_single_node<_Typ>& other) const {
            return __elem == other.get_val();
        }

        bool operator==(const ptr& other) const {
            if(!other) return false;

            return (__elem == other->get_val()) &&
                   (__next == other->next());
        }

        bool operator==(const smart_single_node<_Typ>& other) const {
            return (__elem == other.get_val()) &&
                   (__next == other.next());
        }

        bool operator!=(const ptr other) const {
            return !(*this == other);
        }

        bool operator!=(const smart_single_node<_Typ>& other) const {
            return !(*this == other);
        }
    };

    template<class _Typ> class smart_double_node : public std::enable_shared_from_this<smart_double_node<_Typ>> {
            using ptr = std::shared_ptr<smart_double_node<_Typ>>;
            using wptr = std::weak_ptr<smart_double_node<_Typ>>;

            ptr __next;
            wptr __prev;
            _Typ __elem;

        public:
            explicit smart_double_node(const _Typ& value = _Typ())
            : __next(nullptr), __prev(), __elem(value) {}

            ~smart_double_node() = default;

            // Value Access
            void set_val(const _Typ& value) { __elem = value; }
            _Typ& get_val() { return __elem; }
            const _Typ& get_val() const { return __elem; }

            // Next Node Access
            void set_next(const ptr& next) { __next = next; }
            ptr next() { return __next; }
            const ptr next() const { return __next; }

            // Prev Node Access
            void set_prev(const ptr& prev) { __prev = prev; }
            ptr prev() { return __prev.lock(); }
            const ptr prev() const { return __prev.lock(); }

            // Value comparison
            bool equal_val(const ptr& other) const {
                return other && (__elem == other->get_val());
            }

            bool equal_val(const smart_double_node<_Typ>& other) const {
                return __elem == other.get_val();
            }

            // Full node comparison
            bool operator==(const ptr& other) const {
                return other &&
                       (__elem == other->get_val()) &&
                       (__next == other->next()) &&
                       (__prev.lock() == other->prev());
            }

            bool operator==(const smart_double_node<_Typ>& other) const {
                return (__elem == other.get_val()) &&
                       (__next == other.next()) &&
                       (__prev.lock() == other.prev());
            }

            bool operator!=(const ptr& other) const { return !(*this == other); }
            bool operator!=(const smart_double_node<_Typ>& other) const { return !(*this == other); }
    
        };


}

#endif

