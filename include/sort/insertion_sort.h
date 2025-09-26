#ifndef INSERTION_SORT
#define INSERTION_SORT 1

#include <array>
namespace sort {
    namespace insertion_sort {
        #define llu  long long unsigned
        
        /* c-style array is working as pointer */
        template <class _Typ , llu size> void c_style_array_ref_sort( _Typ (&arr)[size] ) {
            // type must have operators ( > , < )
            //  insertion sort as what shown in CLRS

            // insertion sort depend on compare between the current element and element before 
            // so it will unlogic to start with first element 
            for (llu i = 1; i < size; i++) {
                // copy  save current element
                _Typ key = arr[i];  
                // to save the current location we use either variable to move 
                // this variable may be -1 so it must be signed
                long long j = i - 1;

                // we can't use negative value as index 
                // if key less than element that has index j we move it forward one step 
                while (j >= 0 && key < arr[j]) {
                    // here we move element forward if condition right
                    arr[j + 1] = arr[j];
                    // here we move to prev element
                    j--;
                }
                // when ( while loop ) end we acheive to element less than key so we but key directly after it
                arr[j + 1] = key;
            }
        }
        
        template <class _Typ , llu size> void stl_array_ref_sort(  std::array<_Typ , size>& arr ){
             long long j =0;
           for(llu i =1; i < arr.size() ; i++){
            auto key = arr[i];
            j = i -1;

            while( j >= 0 && arr[j] > key){

                arr[j+1] = arr[j];
                j--;
            }
                arr[j + 1] =key;
           } 
        }
   
    }
}

#endif
