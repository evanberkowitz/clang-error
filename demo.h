#ifndef ND_ZETA
#define ND_ZETA

#include <set>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <functional>
#include <iostream> // Debugging

using namespace std;

template <class T>
inline T nSquared(const std::vector<T> &v){
    T total=0;
    for(auto i:v) total+=i*i;
    return total;
}

template <class T>
inline T square(T x){
    return x*x;
}

template <class T>
inline T square_root(T xsquared){
    return static_cast<T>(sqrt(xsquared)) ;
}

template <class T>
bool filter(T radius, std::vector<T> &squares){
    // Input is still squared!
    T t = 0;
    for(auto s:squares) t+=s;
    return t <= square(radius);
}

template<class T>
std::vector< std::vector<T> > enumerator(T D, T N){
    // Produce all sorted, primitive d-dimensional integer vectors
    auto squares = vector<T>();
    for(T x=0; x<1+N/2; x++){
        squares.push_back(square(x));
    }

    // Build a list of squares that we'll increase dimension-by-dimension.
    auto vs = set< vector<T> >();

    // Initialize with vectors of desired squares,
    // essentially doing the 1D process:
    for(auto s:squares){
        auto temp = vector<T>();
        temp.push_back(s);
        vs.insert(temp);
    }

    // Now, go beyond 1D, building up by dimension:
    for(T dimension=2; dimension <= D; dimension++){
        auto next = set<vector<T> >();
        for(auto v:vs){
            for(auto s:squares){
                auto temp = v;
                temp.push_back(s);
                // NOTE: STILL SQUARED!
                if(filter(N/2, temp)){
                    sort(temp.begin(), temp.end());
                    next.insert(temp);
                }
            }
        }
        vs = next;
    }

    // De-square-root:
    auto no_sqrt = vector<vector<T> >();
    for(auto v:vs){
        vector<T> temp;
        for(auto i:v) temp.push_back(square_root(i));
        no_sqrt.push_back(temp);
    }
    sort(no_sqrt.begin(), no_sqrt.end(),
        [](vector<T> &a, vector<T> &b){
            return nSquared(a) < nSquared(b);
        });

    return no_sqrt;
}

#endif
