namespace lang {
    class Object {
    public:
        Object();
	virtual ~Object();
	virtual bool Equals(Object &o);
	virtual bool operator==(Object &o) {
	    return this == &o;
	}
    };
}
