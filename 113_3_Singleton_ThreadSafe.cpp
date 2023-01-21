class Foo
{
public:
    static Foo &instance()
    {
        static Foo inst;
        return inst;
    }

private:
    Foo() {}
    Foo(const Foo &) = delete;
    Foo &operator=(const Foo &) = delete;
};