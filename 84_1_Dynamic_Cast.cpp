class A{
public:
    virtual ~A() {}
};

class B : public A{
public:
    void work4B() {}
};

class C : public A{
public:
    void work4C() {}
};

void non_polymorphic_work(A *ap){
    if (B *bp = dynamic_cast<B *>(ap))
        bp->work4B();
    if (C *cp = dynamic_cast<C *>(ap))
        cp->work4C();
}

int main()
{
    return 0;
}