namespace lang {
    class Object {
    public:
        Object();
	virtual ~Object();
	virtual bool Equals(Object &object);
	virtual bool operator==(Object &object);
	virtual char* ToString();
	virtual int HashCode();
    };
}
