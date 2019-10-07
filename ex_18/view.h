#ifndef view_h
#define view_h

class t_eq2_view {
private:
public:
	float read_a(void);
	float read_b(void);
	float read_c(void);

	void print_solutions(float x1_re, float x1_im, float x2_re, float x2_im);
};

#endif
