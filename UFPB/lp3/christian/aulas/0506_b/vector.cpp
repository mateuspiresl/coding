class Vector {

	float v_[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float mean_ = 0.0f;

	void setMean() {
		mean_ = (v_[0] + v_[1] + v_[2] + v_[3]) * 0.25f;
	}

public:
	Vector() { }
	~Vector() { }

	Vector(float v) :
		v_ { v, v, v, v },
		mean_ = v
	{ }

	Vector(float v0, float v1, float v2, float v3) :
		v_ { v0, v1, v2, v3 },
		mean_ ((v0, v1, v2, v3) / 4)
	{ }

	Vector(const Vector& v) :
		v_ { v.v_[0], v.v_[1], v.v_[2], v.v_[3] },
		mean_ (v.mean_)
	{ }

	void setValues(float v0, float v1, float v2, float v3) {
		v_[0] = v0;
		v_[1] = v1;
		v_[2] = v2;
		v_[3] = v3;
		setMean();
	}

	void getValues(float& v0, float& v1, float& v2, float& v3) const {
		v0 = v_[0];
		v1 = v_[1];
		v2 = v_[2];
		v3 = v_[3];
	}

	float getMean() const {
		return mean_;
	}

	void copyFrom(const Vector& a) {
		v_[0] = a.v_[0];
		v_[1] = a.v_[1];
		v_[2] = a.v_[2];
		v_[3] = a.v_[3];
		mean_ = a.mean_;
	}

	void sum(const Vector& a) {
		v_[0] += a.v_[0];
		v_[1] += a.v_[1];
		v_[2] += a.v_[2];
		v_[3] += a.v_[3];
		mean_ += a.mean_;
	}
};


class Color {
public:
	const Vector rgba_;
};


int main()
{
	Color c;
	//c.rgba_.setValues(1.0f, 0.0f, 0.0f, 1.0f);

	return c.rgba_.getMean() * 100;
}