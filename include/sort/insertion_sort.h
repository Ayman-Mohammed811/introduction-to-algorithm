#ifndef INSERTION_SORT
#define INSERTION_SORT 1

namespace sort {
    namespace insertion_sort {
        #define llu  long long unsigned
        
        /* c-style array is working as pointer */
        template <class _Typ , llu size> void __sort( _Typ (&arr)[size] ) {
            // type must have operators ( > , < )
            //  insertion sort as what shown in CLRS
            
            if (size <= 1) return;
            for (llu i = 1; i < size; i++) {
                _Typ key = arr[i];  
                long long j = i - 1;

                while (j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }

        }
        
    }
}

#endif
