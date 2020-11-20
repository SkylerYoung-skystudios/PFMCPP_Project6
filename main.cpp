/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* let) : 
    value(v),
    name(let)
    {} //1
    int value;//2
    std::string name;//3
};

struct Judge                                //4
{
    T* compare(T* a, T* b) //5
    {
        if ( a != nullptr && b != nullptr)
        {
            if( a->value < b->value ) return a;
            if( a->value > b->value ) return b;
        }
        return nullptr;
    }
};

struct U
{
    float up { 0.2f }, down { 2.0f };
    float stuff(float* updatedValue)      //12
    {
        if (updatedValue != nullptr)
        {
            std::cout << "U's up value: " << this->up << std::endl;
            this->up = *updatedValue;
            std::cout << "U's up updated value: " << this->up << std::endl;
            while( std::abs(this->up - this->down) > 0.001f )
            {
                this->down += (this->up - this->down) / 100.f;
            }
            std::cout << "U's down updated value: " << this->up << std::endl;
            return this->up * this->down;
        }
        return 0;
    }
};

struct Jury
{
    static float look(U* that, float* updatedValue )        //10
    {
        if ( that != nullptr && updatedValue != nullptr)
        {
            std::cout << "U's up value: " << that->up << std::endl;
            that->up = *updatedValue;
            std::cout << "U's up updated value: " << that->up << std::endl;
            while( std::abs(that->up - that->down) > 0.001f )
            {
                /*
                 write something that makes the distance between that-><#name2#> and that-><#name1#> get smaller
                 */
                that->down += (that->up - that->down) / 100.f;
            }
            std::cout << "U's down updated value: " << that->up << std::endl;
            return that->up * that->down;
        }
        std::cout << "One or both arguments is nullptr! returning 0" << std::endl;
        return 0;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T yes( 44 , "t");                                             //6
    T no( 84 , "w");                                             //6
    
    Judge f;                                            //7
    auto* smaller = f.compare( &yes, &no); 
    if (smaller != nullptr)
    {                             //8
    std::cout << "the smaller one is " << smaller->name << std::endl; //9
    }
    
    U check;
    float updatedValue = 5.f;
    std::cout << "[static func] check's multiplied values: " << Jury::look( &check, &updatedValue) << std::endl;                  //11
    
    U dog;
    std::cout << "[member func] dog's multiplied values: " << dog.stuff( &updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
