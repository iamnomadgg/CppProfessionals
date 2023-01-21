#include <memory>
#include <string>

class Animal
{
public:
    virtual std::shared_ptr<Animal> clone() const = 0;
    virtual std::string getname() const = 0;
};
class Bear : public Animal
{
public:
    virtual std::shared_ptr<Animal> clone() const override
    {
        return std::make_shared<Bear>(*this);
    }
    virtual std::string getname() const override
    {
        return "bear";
    }
};
class Cat : public Animal
{
public:
    virtual std::shared_ptr<Animal> clone() const override
    {
        return std::make_shared<Cat>(*this);
    }
    virtual std::string getname() const override
    {
        return "cat";
    }
};
class AnimalFactory
{
public:
    static std::shared_ptr<Animal> getAnimal(const std::string &name)
    {
        if (name == "bear")
            return std::make_shared<Bear>();
        if (name == "cat")
            return std::shared_ptr<Cat>();
        return nullptr;
    }
};

int main(){
    return 0;
}