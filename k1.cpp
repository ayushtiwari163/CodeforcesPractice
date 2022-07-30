#include <iostream>

using namespace std;

class F

{

};

class S :public F

{

};

template<typename X, typename Y>

class check {

class F { };

static F find( ... ); 

class T { F f[2]; };

static T find( Y* );

public:

enum

{

m = sizeof(T) == sizeof(find (static_cast<X*> (0)))

};

};