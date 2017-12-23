#include "./tuple_binding.hpp"
#include <cassert>

int main()
{

    struct s
    {
    int a;
    char b;
    double c;
    float d;
    int* e;
    };
    s s_;
    s_.a = 1;
    s_.b = '2';
    s_.c = 3.0;
    s_.d = 4.0f;
    s_.e = nullptr;
    auto ts_ = tuple_binding( s_ );
    static_assert( std::is_same_v<decltype(ts_), std::tuple<int, char, double, float, int*> > );
    assert( std::get<0>(ts_) == 1 );
    assert( std::get<1>(ts_) == '2' );
    assert( std::get<2>(ts_) == 3.0 );
    assert( std::get<3>(ts_) == 4.0f );
    assert( std::get<4>(ts_) == nullptr );

    return 0;
}

