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