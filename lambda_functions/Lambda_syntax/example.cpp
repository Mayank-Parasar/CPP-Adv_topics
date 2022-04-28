/***********************************************************************
* Course: Advance Topics in C++
* Created by: Mayank Parasar
* Created on: 04/25/2021
* Email-ID: mayankparasar@gmail.com
* Topic: 
* 
* ***********************************************************************
*/

#include <cstdio>
#include <locale>
#include <algorithm>

using namespace std;

constexpr size_t _maxlen = 128;

static size_t strnlen(const char* s,size_t maxlen) {
    for (size_t i=0; i < maxlen ; i++ ){
        if (s[i] == '\0')
            return i;
    }
    return maxlen;
}

class ftitle {
	char lastc;
public:
    // char lastc;
	ftitle(): lastc(0) {};
	char operator () (const char & c);
	~ftitle();
	
};

char ftitle::operator() ( const char & c ) {
	const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
	lastc = c;
	return r;
}

int main(int argc, char const *argv[])
{
	/* code */
	char lastc = 0;
	char s[] = "big light in sky slated to appear in east";

	// transform( s, s + strnlen(s, _maxlen), s, ftitle() );
	// lambda (or closure) equilant of above expression:

	transform( s, s + strnlen(s, _maxlen), s, [&lastc] (const char & c) -> char {
		const char r = (lastc == ' ' || lastc == 0) ? toupper(c) : tolower(c);
		lastc = c;
		return r;
	} );

	puts(s);
	return 0;
}