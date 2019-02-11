#include <iostream>
#include <string>
#include <memory>
#include <vector>

// --------------------------    Shared Pointers     -------------------------- // 
class Entity
{
public: 
    Entity()
    {
        std::cout << "Created Entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed Entity" << std::endl;
    }
    void Print()
    {
        std::cout << "Printing function" << std::endl;
    }
};

int entity_main() 
{
    // Seperate scope, to show how unique_ptr works
    {
        // Can be done this way...
        std::unique_ptr<Entity> entity1(new Entity());
        // But the preferred way is this...
        std::unique_ptr<Entity> entity2 = std::make_unique<Entity>();
        entity1->Print();
        entity2->Print();
    } // Deletes unique_ptr here!

    // Scope for share_ptr, here we copy a ptr to another ptr
    {   
        std::shared_ptr<Entity> shared_entity;
        {
            std::shared_ptr<Entity> entity = std::make_shared<Entity>();
            shared_entity = entity;
        }
        std::cout << shared_entity << std::endl;
    } // Deletes share_ptr here!
    return 0;
}

/* Smart Pointers
std::shared_ptr
- it deletes itself only when the reference count has reached a level of zero.
- a resource (stored in memory) is shared among a number of shared pointers.
*/


int main() 
{
    template<typename T>
        using SP = std::shared_ptr<T>;
    using value_type = double;
    // Creating shared pointers with default deleters
    SP<value_type> sp1;
    SP<value_type> sp2(nullptr);
    SP<value_type> sp3(new value_type(148.413));
    SP<value_type> sp4(sp3);
    SP<value_type> sp5(sp4);

    std::cout << "sp2 shared # " << sp2.use_count() << "\n";
    std::cout << "sp3 shared # " << sp3.use_count() << "\n";
    std::cout << "sp4 shared # " << sp4.use_count() << "\n";
    sp3 = sp2;

    std::cout << "sp3 shared # " << sp3.use_count() << '\n';
    std::cout << "sp4 shared # " << sp4.use_count() << '\n'; 
    return 0;
}