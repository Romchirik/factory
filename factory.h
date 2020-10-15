#include "unit.h"
#include <unordered_map>
#include <iostream>

template<class Product, class id>
struct DefaultErrorPolicy{
    static Product* IdNotFound(const id& name){
        /*
         * можно так
        std::cerr<< "Id not found!" << name << std::endl;
        return nullptr;
          * или
          */
        throw std::runtime_error("B U S T E D ! ! !");
    }
};

template<class Product, class id, typename Creator, class ErrorPolicy = DefaultErrorPolicy<Product, id>>
class Factory {
public:
    Product* makeUnit(const id& name){
        auto it = creators_.find(name);
        if(it == creators_.end()){
            return ErrorPolicy::IdNotFound(name);
            //return nullptr;
        }
        std::pair<id, Creator> element = *it;//хз вообще зачем
        return element.second();
    }
    void addCreator(const id name, creator_t c){
        creators_[name] = c;
    }

    static Factory*getInstance(){
        static Factory f;
        return &f;
    }
private:
    Factory() = default;
    ~Factory() = default;
    Factory(const Factory&);
    Factory& operator=(const Factory&);

    std::unordered_map<id, Creator> creators_;
};

//extern Factory f; //объявление, но не определение