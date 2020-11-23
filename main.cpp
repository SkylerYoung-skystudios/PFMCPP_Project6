/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float up { 0.2f }, down { 2.0f };
    float stuff(const float& updatedValue)      //12
    {
        std::cout << "U's up value: " << this->up << std::endl;
        this->up = updatedValue;
        std::cout << "U's up updated value: " << this->up << std::endl;
        while( std::abs(this->up - this->down) > 0.001f )
        {
            this->down += (this->up - this->down) / 100.f;
        }
        std::cout << "U's down updated value: " << this->down << std::endl;
        return this->up * this->down;
    }
};

struct Jury
{
    static float look(U& that, const float& updatedValue )        //10
    {
        std::cout << "U's up value: " << that.up << std::endl;
        that.up = updatedValue;
        std::cout << "U's up updated value: " << that.up << std::endl;
        while( std::abs(that.up - that.down) > 0.001f )
        {
            that.down += (that.up - that.down) / 100.f;
        }
        std::cout << "U's down updated value: " << that.up << std::endl;
        return that.up * that.down;
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
    auto smaller = f.compare( yes, no); 
    if (smaller != nullptr)
    {                             //8
        std::cout << "the smaller one is " << smaller->name << std::endl;
    }
    
    U check;
    float updatedValue = 5.f;
    std::cout << "[static func] check's multiplied values: " << Jury::look( check, updatedValue) << std::endl;                  //11
    
    U dog;
    std::cout << "[member func] dog's multiplied values: " << dog.stuff( updatedValue ) << std::endl;
}

        
        
        
        
        
        
        
