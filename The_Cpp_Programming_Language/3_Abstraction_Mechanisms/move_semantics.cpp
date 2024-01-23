// Move semantics : Introduced in c++ 11
// Allows us to move objects from one place to another without copying them
//
// Usecase : Before c++11, there are cases where we don't want to copy an object
// from one place to another But, it's the copying is the only possible way by
// which we can achieve the above. Eg : 1. If I'm passing an object into a
// function, then the function is going to take ownership of the object Because
// of this, the caller has no choice but to create a copy of the object and then
// pass one of them to the function 2: Let's say I want to return a object from
// a function. I will again have to create the object inside the function and
// then return it. This means that again I'm copying the data :-)
// NOTE: 2 can also be optimized by something called as return value
// optimization.
