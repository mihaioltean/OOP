#ifndef model_h
#define model_h

#include "events.h"

struct t_eq2_solution {
	float re, im;
};

class t_eq2_model {
private:
	float a, b, c;
	t_eq2_solution x1, x2;
	t_abstract_controller* observer;

public:
	t_eq2_model(void);

	void set_a(float a);
	void set_b(float b);
	void set_c(float c);
	
	void solve(void);
	
	float get_x1_re(void);
	float get_x1_im(void);
	float get_x2_re(void);
	float get_x2_im(void);

	void set_observer(t_abstract_controller* observer);
};

#endif