struct CClass {
	int x_, y_;
};

void Set(struct CClass* this, int a, int b) {
	this->x_ = a;
	this->y_ = b;
}

int GetX(struct CClass* this) {
	return this->x_;
}

struct CClass cobj;

int main() {
	Set(&cobj, 10, 20);
	return GetX(&cobj);
}