
#include <cassert>
#include <cstdint>
#include <iostream>

typedef int64_t i64;
typedef int32_t i32;

template <class T>
class M22
{
	public:
		T xx, xy, yx, yy;

		M22()
		{}

		M22( T axx, T axy, T ayx, T ayy )
			: xx( axx )
			, xy( axy )
			, yx( ayx )
			, yy( ayy )
		{}

		const M22 operator% ( T m ) const
		{
			return M22( xx % m, xy % m, yx % m, yy % m );
		}

		const M22 operator* ( const M22& a ) const
		{
			return M22(
					xx * a.xx + xy * a.yx,
					xx * a.xy + xy * a.yy,
					yx * a.xx + yy * a.yx,
					yx * a.xy + yy * a.yy);
		}
};

typedef M22< i64 > m22;

// TODO: must be in class
#define SIZE 60

// TODO: must be in class
m22 Q[ SIZE ]; // Q^(2^i)

class Fibonacci final
{
	public:
		static i32 get_remainder( i64 n, i32 m )
		{
			assert( n >= 1 );
			assert( m >= 2 );

			Q[ 0 ] = { 1, 1
					 , 1, 0 };

			for( i32 i = 1; i < SIZE; ++i )
				Q[ i ] = Q[ i-1 ] * Q[ i-1 ] % m;

			n--;
			m22 ans = { 1, 0
					  , 0, 1 };

			for( i32 i = 0; i < SIZE; ++i )
			{
				if( n & ( 1ll << i ) )
					ans = ans * Q[ i ] % m;
			}

			return ans.xx;
		}
};

#undef SIZE

int main( void )
{
	i64 n;

	std::cin >> n;
	std::cout << Fibonacci::get_remainder( n, 1000000007 ) << std::endl;

	return 0;
}

