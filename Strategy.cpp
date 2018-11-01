class algorithm {
public:
    virtual void alg(int value) = 0;
    virtual ~algorithm();
};

class sort1 : public algorithm {
    virtual void alg(int value)
    {
    }
};

class Factory {
    algorithm* newAlgorithm()
    {
        return new sort1();
    }
};

class Calculate {
public:
    int cal(Factory* factory)
    {
        this->alg = factory->newAlgorithm();
    }

private:
    algorithm* alg;
}