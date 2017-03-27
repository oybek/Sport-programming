
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
string s;

typedef int i32;

bool is_anagram( string s1, string s2 )
{
    sort( s1.begin(), s1.end() );
    sort( s2.begin(), s2.end() );
    return s1 == s2;
}

int main()
{
    cin >> T;
    while( T-- )
    {
        i32 ans = 0;
        
        cin >> s;
        
        for( i32 i = 0; i < s.size(); ++i )
        {
            for( i32 j = i+1; j < s.size(); ++j )
            {
                for( i32 len = 1; j+len-1 < s.size(); ++len )
                {
                    if( is_anagram( s.substr( i, len ), s.substr( j, len ) ) )
					{
						printf("(%d,%d) - (%d,%d)\n", i, len, j, len);
                        ++ans;
					}
                }
            }
        }
        
        cout << ans << endl;
    }
    
	return 0;
}
